import re
import sys

# -----------------------------
# Opcode Table
# -----------------------------
OPCODES = {
    "NOP":  0b000000,
    "ADD":  0b000001,
    "ADDI": 0b000010,
    "SUB":  0b000011,
    "SLL":  0b000100,
    "LW":   0b000101,
    "SW":   0b000110,
    "BLT":  0b000111,
    "BGE":  0b001000,
    "BLE":  0b001001,
    "J":    0b001010,
}

# -----------------------------
# Helpers
# -----------------------------
def reg_num(r):
    return int(r.replace("r", ""))

def sign_extend(value, bits):
    if value < 0:
        value = (1 << bits) + value
    return value & ((1 << bits) - 1)

def encode_instruction(opcode, rs=0, rt=0, rd=0, imm=0):
    instr = 0
    instr |= (opcode & 0x3F) << 26
    instr |= (rs & 0xF) << 22
    instr |= (rt & 0xF) << 18
    instr |= (rd & 0xF) << 14
    instr |= (imm & 0xFFF) << 2
    return instr

# -----------------------------
# Assembler
# -----------------------------
def assemble(lines):
    labels = {}
    instructions = []

    # First pass: collect labels
    pc = 0
    for line in lines:
        line = line.split("//")[0].strip()  # remove comments
        if not line:
            continue
        if ":" in line:
            label = line.replace(":", "").strip()
            labels[label] = pc
        else:
            instructions.append((pc, line))
            pc += 4

    # Second pass: encode
    machine_code = []

    for pc, line in instructions:
        tokens = re.split(r'[,\s()]+', line)
        tokens = [t for t in tokens if t]

        op = tokens[0].upper()
        opcode = OPCODES[op]

        rs = rt = rd = imm = 0
        
        if op == "NOP":
            instr = 0x00000000
            machine_code.append(f"{instr:08X}")
            continue

        if op == "ADD":
            rd = reg_num(tokens[1])
            rs = reg_num(tokens[2])
            rt = reg_num(tokens[3])

        elif op == "ADDI":
            rd = reg_num(tokens[1])
            rs = reg_num(tokens[2])
            imm = sign_extend(int(tokens[3]), 12)

        elif op == "SUB":
            rd = reg_num(tokens[1])
            rs = reg_num(tokens[2])
            rt = reg_num(tokens[3])

        elif op == "SLL":
            rd = reg_num(tokens[1])
            rs = reg_num(tokens[2])
            imm = sign_extend(int(tokens[3]), 12)

        elif op == "LW":
            rd = reg_num(tokens[1])
            imm = sign_extend(int(tokens[2]), 12)
            rs = reg_num(tokens[3])

        elif op == "SW":
            rt = reg_num(tokens[1])
            imm = sign_extend(int(tokens[2]), 12)
            rs = reg_num(tokens[3])

        elif op in ["BLT", "BGE", "BLE"]:
            rs = reg_num(tokens[1])
            rt = reg_num(tokens[2])
            label = tokens[3]
            target = labels[label]
            offset = (target - (pc + 4)) >> 2
            imm = sign_extend(offset, 12)

        elif op == "J":
            target = labels[tokens[1]]
            offset = (target >> 2) & 0x1FF
            imm = offset

        instr = encode_instruction(opcode, rs, rt, rd, imm)
        machine_code.append(f"{instr:08X}")

    return machine_code


# -----------------------------
# Main Entry
# -----------------------------
if __name__ == "__main__":
    import sys
    import os

    if len(sys.argv) != 2:
        print("Usage: py my_isa_assembler.py program.asm")
        sys.exit(1)

    asm_file = sys.argv[1]

    # Read assembly file
    with open(asm_file, "r") as f:
        lines = f.readlines()

    # Assemble
    hex_output = assemble(lines)

    # Create output file name automatically
    base_name = os.path.splitext(asm_file)[0]
    output_file = base_name + ".coe"

    # Write .coe file
    with open(output_file, "w") as f:
        f.write("memory_initialization_radix=16;\n")
        f.write("memory_initialization_vector=\n")

        for i, h in enumerate(hex_output):
            if i == len(hex_output) - 1:
                f.write(h + ";\n")
            else:
                f.write(h + ",\n")

    print(f"{output_file} generated successfully.")