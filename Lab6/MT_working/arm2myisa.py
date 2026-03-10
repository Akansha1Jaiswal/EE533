#!/usr/bin/env python3
"""
arm_mini_compiler.py
Mini-compiler: ARMv4t-subset -> custom ISA (16 regs, r0 reserved zero, 64-bit datapath)

Usage:
    python3 arm_mini_compiler.py -i arm_input.s -o out_custom.s

Notes/assumptions:
 - PHYS regs: r1..r14 are allocatable. r0 reserved for zero, r15 reserved (PC).
 - Word size = 8 bytes (64-bit datapath). LW/SW immediates emitted as byte offsets multiplied by 8 when numeric.
 - Core ARM patterns supported: ldr/str (literal, [fp,#imm], [base, idx, lsl #k]), add/sub/mov/cmp/rsb/lsl, branches, bx lr.
 - Inserts NOP immediately after every LW.
 - Tries to convert BX lr -> J imm when lr was assigned a constant label/address earlier.
 - Conservative register allocator (greedy).
 - Emits label-free assembly with computed branch immediates.
"""

import re, sys, argparse
from collections import namedtuple, OrderedDict

# ---------- Configuration ----------
PHYS_REGS = [f"r{i}" for i in range(1, 15)]  # r1..r14
ZERO_REG = "r0"
PC_REG = "r15"
WORD_BYTES = 8    # 64-bit datapath -> element size scaling
INSTR_BYTES = 4   # instruction size (for branch PC math)

# ---------- Parsing ----------
Inst = namedtuple("Inst", ["raw", "op", "args", "label", "directive"])
re_comment = re.compile(r'(@|;).*')
re_label = re.compile(r'^\s*([A-Za-z_\.]\w*):\s*(?:@.*|;.*)?$')

def strip_comment(line):
    m = re_comment.search(line)
    return line[:m.start()].rstrip() if m else line.rstrip()

def parse_file(path):
    with open(path, 'r') as f:
        lines = f.readlines()
    insts = []
    for L in lines:
        raw = L.rstrip("\n")
        s = strip_comment(raw)
        if not s.strip():
            insts.append(Inst(raw=raw, op=None, args=[], label=None, directive=None))
            continue
        ml = re_label.match(s)
        if ml:
            insts.append(Inst(raw=raw, op=None, args=[], label=ml.group(1), directive=None))
            continue
        md = re.match(r'^\s*\.(\w+)\b(.*)$', s)
        if md:
            insts.append(Inst(raw=s.strip(), op=None, args=[], label=None, directive=s.strip()))
            continue
        m = re.match(r'^\s*([A-Za-z]+)\s*(.*)$', s)
        if not m:
            insts.append(Inst(raw=raw, op=None, args=[], label=None, directive=None))
            continue
        op = m.group(1).lower(); rest = m.group(2).strip()
        args = []
        cur = ""; depth = 0
        for ch in rest:
            if ch == '[': depth += 1
            elif ch == ']': depth -= 1
            if ch == ',' and depth == 0:
                if cur.strip(): args.append(cur.strip()); cur = ""
            else:
                cur += ch
        if cur.strip(): args.append(cur.strip())
        insts.append(Inst(raw=raw, op=op, args=args, label=None, directive=None))
    return insts

# ---------- IR ----------
IR = namedtuple("IR", ["op","args","raw"])
# op strings: LABEL, DIRECTIVE, LOAD_LIT, LOAD_LOCAL, STORE_LOCAL, LOAD_IDX, STORE_IDX,
# ADDI, ADD, SUBI, SUB, MOV_IMM, MOV_REG, CMP, RSB, SLL, BR, BX, OTHER

def lower_to_ir(insts):
    ir = []
    for i in insts:
        if i.label:
            ir.append(IR("LABEL",[i.label], i.raw)); continue
        if i.directive:
            ir.append(IR("DIRECTIVE",[i.directive], i.raw)); continue
        if not i.op:
            continue
        op = i.op; a = i.args
        # literal load: ldr rd, .L8 or ldr rd, =label
        if op == "ldr" and len(a)==2 and not (a[1].startswith('[') and a[1].endswith(']')):
            ir.append(IR("LOAD_LIT",[a[0], a[1]], i.raw)); continue
        # ldr/str with bracket forms
        if op in ("ldr","str") and len(a)==2 and a[1].startswith('[') and a[1].endswith(']'):
            mem = a[1][1:-1].strip()
            # [fp, #imm]
            m = re.match(r'^(fp)\s*,\s*#(-?\d+)$', mem)
            if m:
                slot = int(m.group(2))
                if op=="ldr": ir.append(IR("LOAD_LOCAL",[a[0], slot], i.raw))
                else: ir.append(IR("STORE_LOCAL",[a[0], slot], i.raw))
                continue
            # [base, index, lsl #k]
            m2 = re.match(r'^([^,]+)\s*,\s*([^,]+)\s*,\s*lsl\s*#(-?\d+)$', mem)
            if m2:
                base = m2.group(1).strip(); index = m2.group(2).strip(); shift = int(m2.group(3))
                if op=="ldr": ir.append(IR("LOAD_IDX",[a[0], base, index, shift], i.raw))
                else: ir.append(IR("STORE_IDX",[a[0], base, index, shift], i.raw))
                continue
            # unknown bracket form
            ir.append(IR("OTHER",[i.raw], i.raw)); continue
        # pre-index writeback str ...]!
        if op == "str" and len(a)==2 and a[1].endswith(']!'):
            mm = re.match(r'^\[([^,]+)\s*,\s*#(-?\d+)\]!\s*$', a[1])
            if mm:
                base = mm.group(1); off = int(mm.group(2))
                ir.append(IR("OTHER",[f"ADDI {base}, {base}, {off}"], i.raw))
                ir.append(IR("OTHER",[f"SW {a[0]}, 0({base})"], i.raw))
                continue
        # add/sub/mov/cmp/rsb/lsl
        if op == "add" and len(a)==3:
            rd,rn,op3 = a
            if op3.startswith('#'): ir.append(IR("ADDI",[rd,rn,int(op3[1:])], i.raw))
            else: ir.append(IR("ADD",[rd,rn,op3], i.raw)); continue
        if op == "sub" and len(a)==3:
            rd,rn,op3 = a
            if op3.startswith('#'): ir.append(IR("SUBI",[rd,rn,int(op3[1:])], i.raw))
            else: ir.append(IR("SUB",[rd,rn,op3], i.raw)); continue
        if op == "mov" and len(a)==2:
            rd,src = a
            if src.startswith('#'): ir.append(IR("MOV_IMM",[rd,int(src[1:])], i.raw))
            else: ir.append(IR("MOV_REG",[rd,src], i.raw)); continue
        if op == "cmp" and len(a)==2:
            ir.append(IR("CMP",[a[0], a[1]], i.raw)); continue
        if op == "rsb" and len(a)==3:
            rd,rn,imm = a
            if imm.startswith('#'): ir.append(IR("RSB",[rd,rn,int(imm[1:])], i.raw)); continue
        if op in ("lsl","lsr") and len(a)==3:
            rd,rn,sh=a; ir.append(IR("SLL",[rd,rn,int(sh[1:])], i.raw)); continue
        if op in ("b","bl","ble","blt","bge","beq","bne") and len(a)==1:
            ir.append(IR("BR",[op,a[0]], i.raw)); continue
        if op == "bx" and len(a)==1:
            ir.append(IR("BX",[a[0]], i.raw)); continue
        # post-index or other raw: keep as OTHER
        ir.append(IR("OTHER",[i.raw], i.raw))
    return ir

# ---------- Collect stack slots ----------
def collect_stack_slots(ir):
    slots = OrderedDict()
    for node in ir:
        if node.op in ("LOAD_LOCAL","STORE_LOCAL"):
            slot = node.args[1]
            if slot not in slots:
                slots[slot] = f"vslot{abs(slot)}"
    return slots  # slot -> vname

# ---------- Promote locals to virtual regs ----------
def promote_locals(ir, slots):
    vmap = {slot: slots[slot] for slot in slots}
    new_ir = []
    for n in ir:
        if n.op == "LOAD_LOCAL":
            dst,slot = n.args
            v = vmap[slot]
            new_ir.append(IR("MOVV",[dst, v], n.raw))   # dst = v
        elif n.op == "STORE_LOCAL":
            src, slot = n.args
            v = vmap[slot]
            new_ir.append(IR("MOVV",[v, src], n.raw))   # v = src
        else:
            new_ir.append(n)
    return new_ir, vmap

# ---------- Simple greedy allocation ----------
def allocate(vmap):
    # vmap: slot->vname, but we also track all virtual names seen in IR (vslot names)
    vnames = set(vmap.values())
    # also other vnames may appear; but for our constrained IR it's fine
    phys = PHYS_REGS.copy()
    v2phys = {}
    spills = {}
    phys_idx = 0
    spill_base = -1024  # some negative offset for spill area (bytes)
    for v in sorted(vnames):
        if phys_idx < len(phys):
            v2phys[v] = phys[phys_idx]; phys_idx += 1
        else:
            spills[v] = spill_base; spill_base -= WORD_BYTES
    return v2phys, spills

# ---------- Lower IR to target templates (with labels preserved initially) ----------
def lower_ir_to_templates(ir, v2phys, spills):
    templates = []   # items: ("LABEL",name) or ("DIR",text) or ("INST", text) or ("BR", op, label) or ("BX", reg)
    # track assignments to lr for static resolution (label -> index resolution later)
    lr_assignments = {}  # template_index -> label_pc will be filled later when label -> pc known
    for node in ir:
        op = node.op; a = node.args
        if op == "LABEL":
            templates.append(("LABEL", a[0]))
        elif op == "DIRECTIVE":
            templates.append(("DIR", a[0]))
        elif op == "LOAD_LIT":
            dst,label = a
            # ADDI r6, r0, label ; LW dst, 0(r6) ; NOP
            templates.append(("INST", f"ADDI r6, {ZERO_REG}, {label}"))
            templates.append(("INST", f"LW {dst}, 0(r6)"))
            templates.append(("INST", "NOP"))
        elif op == "LOAD_IDX":
            dst, base, index, shift = a
            templates.append(("INST", f"SLL r8, {index}, {shift}"))
            templates.append(("INST", f"ADD r6, {base}, r8"))
            templates.append(("INST", f"LW {dst}, 0(r6)"))
            templates.append(("INST", "NOP"))
        elif op == "STORE_IDX":
            src, base, index, shift = a
            templates.append(("INST", f"SLL r8, {index}, {shift}"))
            templates.append(("INST", f"ADD r6, {base}, r8"))
            templates.append(("INST", f"SW {src}, 0(r6)"))
        elif op == "MOVV":
            dst, src = a
            # dst/src may be virtual names like vslotNN -> map to phys or spill
            def fetch_reg(x):
                if isinstance(x, str) and x.startswith("vslot"):
                    if x in v2phys: return v2phys[x], None
                    else: return "r14", ("LOAD_SPILL", spills[x])  # load to r14
                return x, None
            pdst, pre = fetch_reg(dst)
            psrc, pre2 = fetch_reg(src)
            if pre2:
                _, off = pre2
                templates.append(("INST", f"ADDI r6, {ZERO_REG}, {off}"))
                templates.append(("INST", f"LW r14, 0(r6)"))
                templates.append(("INST", "NOP"))
                psrc = "r14"
            templates.append(("INST", f"ADD {pdst}, {psrc}, {ZERO_REG}"))
            if dst.startswith("vslot") and dst not in v2phys:
                off = spills[dst]
                templates.append(("INST", f"ADDI r6, {ZERO_REG}, {off}"))
                templates.append(("INST", f"SW {pdst}, 0(r6)"))
        elif op == "ADDI":
            rd,rn,imm = a
            templates.append(("INST", f"ADDI {rd}, {rn}, {imm}"))
            # record if it's setting lr to constant label (pattern: ADDI lr, r0, label) - we'll record later via label->pc resolve
        elif op == "ADD":
            rd,rn,rm = a; templates.append(("INST", f"ADD {rd}, {rn}, {rm}"))
        elif op == "SUBI":
            rd,rn,imm = a; templates.append(("INST", f"SUB {rd}, {rn}, {imm}"))
        elif op == "SUB":
            rd,rn,rm = a; templates.append(("INST", f"SUB {rd}, {rn}, {rm}"))
        elif op == "MOV_IMM":
            rd,imm = a; templates.append(("INST", f"ADDI {rd}, {ZERO_REG}, {imm}"))
        elif op == "MOV_REG":
            rd,rs = a; templates.append(("INST", f"ADD {rd}, {rs}, {ZERO_REG}"))
        elif op == "RSB":
            rd,rn,imm = a
            templates.append(("INST", f"ADDI r10, {ZERO_REG}, {imm}"))
            templates.append(("INST", f"SUB {rd}, r10, {rn}"))
        elif op == "SLL":
            rd,rn,sh = a; templates.append(("INST", f"SLL {rd}, {rn}, {sh}"))
        elif op == "CMP":
            a1,a2 = a; templates.append(("INST", f"SUB r9, {a1}, {a2}"))
        elif op == "BR":
            btype, tgt = a; templates.append(("BR", btype.upper(), tgt))
        elif op == "BX":
            templates.append(("BX", a[0]))
        elif op == "OTHER":
            raw = a[0].strip()
            # try a few simple fallbacks: ldr/str [fp,#imm]
            m_load = re.match(r'^\s*ldr\s+(\w+)\s*,\s*\[([^,]+)\s*,\s*#(-?\d+)\]\s*$', raw, re.I)
            m_store = re.match(r'^\s*str\s+(\w+)\s*,\s*\[([^,]+)\s*,\s*#(-?\d+)\]\s*$', raw, re.I)
            if m_load:
                dst = m_load.group(1); base = m_load.group(2); off = int(m_load.group(3))
                templates.append(("INST", f"ADDI r6, {base}, {off * 1}"))
                templates.append(("INST", f"LW {dst}, 0(r6)")); templates.append(("INST", "NOP"))
                continue
            if m_store:
                src = m_store.group(1); base = m_store.group(2); off = int(m_store.group(3))
                templates.append(("INST", f"ADDI r6, {base}, {off * 1}"))
                templates.append(("INST", f"SW {src}, 0(r6)"))
                continue
            # else drop unknown OTHER (conservative)
            continue
        else:
            # unknown op: ignore (conservative)
            continue
    return templates

# ---------- Resolve labels to PCs and finalize instruction stream ----------
def finalize_and_emit(templates):
    # First pass: compute mapping label -> instruction index (count INST and BR/BX as instructions)
    instrs = []
    label_to_idx = {}
    for t in templates:
        if t[0] == "LABEL":
            label_to_idx[t[1]] = len(instrs)
        elif t[0] == "DIR":
            # keep directives at end; do not count here
            pass
        elif t[0] in ("INST","BR","BX"):
            instrs.append(t)
        else:
            # ignore other template types here
            pass

    # Second pass: produce final textual instructions, resolving branches and BX lr -> J imm when possible
    # Also scale numeric immediates in LW/SW by WORD_BYTES
    final_lines = []
    # helper to multiply numeric immediate in patterns like "LW rX, 0(r6)" => multiply 0 by WORD_BYTES
    lw_pattern = re.compile(r'^\s*LW\s+(\w+)\s*,\s*(-?\d+)\((\w+)\)\s*$', re.I)
    sw_pattern = re.compile(r'^\s*SW\s+(\w+)\s*,\s*(-?\d+)\((\w+)\)\s*$', re.I)
    # We need to track assignments to lr: a simplistic scan for patterns like "ADDI lr, r0, label" or "ADDI lr, r0, <num>"
    lr_assign_map = {}  # instr_index -> target_pc (byte) if resolvable
    # Build textual form with placeholders first to detect lr assigns
    textual = []
    for idx, t in enumerate(instrs):
        typ = t[0]
        if typ == "INST":
            textual.append(t[1])
        elif typ == "BR":
            textual.append(("BR", t[1], t[2]))  # keep as tuple for now
        elif typ == "BX":
            textual.append(("BX", t[1]))
        else:
            textual.append(None)
    # detect lr assignments: pattern "ADDI lr, r0, LABEL" -> textual string like that
    for i, tok in enumerate(textual):
        if isinstance(tok, str):
            m = re.match(r'^\s*ADDI\s+lr\s*,\s*' + re.escape(ZERO_REG) + r'\s*,\s*([A-Za-z_\.]\w*|\-?\d+)\s*$', tok)
            if m:
                imm = m.group(1)
                if imm.isdigit() or re.match(r'^-?\d+$', imm):
                    # direct numeric -> address in bytes (we assume numeric given is PC byte address)
                    lr_assign_map[i] = int(imm)
                else:
                    if imm in label_to_idx:
                        lr_assign_map[i] = label_to_idx[imm] * INSTR_BYTES
    # Now finalize textual instructions and resolve BR/BX
    for i, tok in enumerate(textual):
        pc = i * INSTR_BYTES
        if isinstance(tok, str):
            # scale LW/SW immediates by WORD_BYTES when immediate numeric
            m1 = lw_pattern.match(tok)
            if m1:
                rd, imm, base = m1.group(1), int(m1.group(2)), m1.group(3)
                new_imm = imm * WORD_BYTES
                final_lines.append(f"LW {rd}, {new_imm}({base})")
                final_lines.append("NOP")
                continue
            m2 = sw_pattern.match(tok)
            if m2:
                rd, imm, base = m2.group(1), int(m2.group(2)), m2.group(3)
                new_imm = imm * WORD_BYTES
                final_lines.append(f"SW {rd}, {new_imm}({base})")
                continue
            # otherwise direct INST
            final_lines.append(tok)
        elif isinstance(tok, tuple) and tok[0] == "BR":
            _, btype, tgtlabel = tok
            tgt_pc = label_to_idx.get(tgtlabel, len(textual)) * INSTR_BYTES
            imm = (tgt_pc - (pc + INSTR_BYTES)) // INSTR_BYTES
            final_lines.append(f"{btype} {imm}")
        elif isinstance(tok, tuple) and tok[0] == "BX":
            _, reg = tok
            if reg == "lr":
                # find last assignment to lr before index i
                resolved = None
                for j in range(i-1, -1, -1):
                    if j in lr_assign_map:
                        resolved = lr_assign_map[j]; break
                if resolved is not None:
                    imm = resolved // INSTR_BYTES
                    final_lines.append(f"J {imm}")
                else:
                    final_lines.append("JLR lr")
            else:
                final_lines.append(f"JLR {reg}")
        else:
            # unknown -> skip
            pass

    # Finally append any data directives that were in the original templates (we omitted direct inclusion)
    # For safety, return only final_lines here; directives were preserved earlier in parsing stage if needed
    return final_lines

# ---------- Main compile pipeline ----------
def compile_arm_to_custom(in_path, out_path):
    insts = parse_file(in_path)
    ir = lower_to_ir(insts)
    slots = collect_stack_slots(ir)
    ir_promoted, vmap = promote_locals(ir, slots)
    v2phys, spills = allocate(vmap)
    templates = lower_ir_to_templates(ir_promoted, v2phys, spills)
    final_lines = finalize_and_emit(templates)
    # Write final assembly (pure lines)
    with open(out_path, 'w') as f:
        for L in final_lines:
            f.write(L.rstrip() + "\n")
    print(f"Wrote {out_path} ({len(final_lines)} lines)")

# ---------- CLI ----------
def main():
    p = argparse.ArgumentParser(description="ARM -> custom ISA mini-compiler")
    p.add_argument("-i","--input", required=True, help="ARM assembly input")
    p.add_argument("-o","--output", required=True, help="Output custom ISA file")
    args = p.parse_args()
    compile_arm_to_custom(args.input, args.output)

if __name__ == "__main__":
    main()