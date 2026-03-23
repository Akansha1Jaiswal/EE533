#!/usr/bin/perl -w
use lib "/usr/local/netfpga/lib/Perl5";
use strict;

# Addresses from registers.v: SIMPLE_GPU_BLOCK_ADDR=19'h8, REG_ADDR_WIDTH=4
# Full addr = 0x2000000 + (0x8 << 6) + (reg_offset << 2) = 0x2000200 + offset*4
my $SIMPLE_GPU_COMMAND_REG          = 0x2000200;  # offset 0x0
my $SIMPLE_GPU_ADDRESS_REG          = 0x2000204;  # offset 0x1 (NOT 0x2000205)
my $SIMPLE_GPU_IMEM_REG             = 0x2000208;  # offset 0x2
my $SIMPLE_GPU_DMEM_WRITE_LOWER32   = 0x200020C;  # offset 0x3
my $SIMPLE_GPU_DMEM_WRITE_UPPER32   = 0x2000210;  # offset 0x4
my $SIMPLE_GPU_DMEM_READ_LOWER32    = 0x2000214;  # offset 0x5
my $SIMPLE_GPU_DMEM_READ_UPPER32    = 0x2000218;  # offset 0x6
my $SIMPLE_GPU_REGFILE_READ_LOWER32 = 0x200021C;  # offset 0x7
my $SIMPLE_GPU_REGFILE_READ_UPPER32 = 0x2000220;  # offset 0x8

# ============================================================
# Helpers
# ============================================================

sub regwrite {
    my ($addr, $value) = @_;
    my $cmd = sprintf("regwrite 0x%08x 0x%08x", $addr, $value);
    system($cmd) == 0 or die "Failed: $cmd\n";
}

sub regread {
    my ($addr) = @_;
    my $cmd = sprintf("regread 0x%08x", $addr);
    my @out = `$cmd`;
    my $result = $out[0];
    if ($result =~ m/Reg (0x[0-9a-f]+).*:\s+(0x[0-9a-f]+)/i) {
        return hex($2);
    }
    die "Unexpected regread output: $result\n";
}

sub write_imem {
    my ($addr, $instr) = @_;
    regwrite($SIMPLE_GPU_ADDRESS_REG, $addr);
    regwrite($SIMPLE_GPU_IMEM_REG,    $instr);
    regwrite($SIMPLE_GPU_COMMAND_REG, 0x8);
    regwrite($SIMPLE_GPU_COMMAND_REG, 0x0);
}

sub read_regfile {
    my ($regnum) = @_;
    regwrite($SIMPLE_GPU_ADDRESS_REG, $regnum);
    regwrite($SIMPLE_GPU_COMMAND_REG, 0x20);
    my $lower = regread($SIMPLE_GPU_REGFILE_READ_LOWER32);
    my $upper = regread($SIMPLE_GPU_REGFILE_READ_UPPER32);
    regwrite($SIMPLE_GPU_COMMAND_REG, 0x0);
    # Return as two separate 32-bit values to avoid 32-bit Perl overflow
    return ($upper, $lower);
}

sub read_dmem {
    my ($addr) = @_;
    regwrite($SIMPLE_GPU_ADDRESS_REG, $addr);
    regwrite($SIMPLE_GPU_COMMAND_REG, 0x10);
    my $lower = regread($SIMPLE_GPU_DMEM_READ_LOWER32);
    my $upper = regread($SIMPLE_GPU_DMEM_READ_UPPER32);
    regwrite($SIMPLE_GPU_COMMAND_REG, 0x0);
    return ($upper, $lower);
}

sub start_cpu {
    regwrite($SIMPLE_GPU_COMMAND_REG, 0x1);
    regwrite($SIMPLE_GPU_COMMAND_REG, 0x0);
}

sub stop_cpu {
    regwrite($SIMPLE_GPU_COMMAND_REG, 0x2);
    regwrite($SIMPLE_GPU_COMMAND_REG, 0x0);
}

# ============================================================
# compare two 32-bit halves against expected hex string
# avoids 64-bit integer overflow on 32-bit Perl
# ============================================================
sub check_reg {
    my ($regnum, $upper, $lower, $exp_upper, $exp_lower, $desc) = @_;
    my $hex    = sprintf("0x%08x%08x", $upper, $lower);
    my $exp    = sprintf("0x%08x%08x", $exp_upper, $exp_lower);
    if ($upper == $exp_upper && $lower == $exp_lower) {
        printf("  PASS  R%-2d = %s   (%s)\n", $regnum, $hex, $desc);
        return 1;
    } else {
        printf("  FAIL  R%-2d = %s   expected %s   (%s)\n",
               $regnum, $hex, $exp, $desc);
        return 0;
    }
}

# ============================================================
# Step 1: Stop CPU
# ============================================================
print "=== Stopping CPU ===\n";
stop_cpu();
sleep(1);

# ============================================================
# Step 2: Load instruction memory
# ============================================================
print "=== Loading instruction memory ===\n";

my @program = (
    [ 0,  0x0110000A, "ADDI  r1, r0, 10"              ],
    [ 1,  0x00000000, "NOP"                            ],
    [ 2,  0x00000000, "NOP"                            ],
    [ 3,  0x00000000, "NOP"                            ],
    [ 4,  0x30211000, "VADD  r2, r1, r1"               ],
    [ 5,  0x00000000, "NOP"                            ],
    [ 6,  0x00000000, "NOP"                            ],
    [ 7,  0x00000000, "NOP"                            ],
    [ 8,  0x30321000, "VADD  r3, r2, r1"               ],
    [ 9,  0x00000000, "NOP"                            ],
    [ 10, 0x00000000, "NOP"                            ],
    [ 11, 0x00000000, "NOP"                            ],
    [ 12, 0x30432000, "VADD  r4, r3, r2"               ],
    [ 13, 0x00000000, "NOP"                            ],
    [ 14, 0x00000000, "NOP"                            ],
    [ 15, 0x00000000, "NOP"                            ],
    [ 16, 0x40543000, "VMUL  r5, r4, r3"               ],
    [ 17, 0x00000000, "NOP"                            ],
    [ 18, 0x00000000, "NOP"                            ],
    [ 19, 0x00000000, "NOP"                            ],
    [ 20, 0x48651200, "VMAC  r6, r5, r1, r2"           ],
    [ 21, 0x00000000, "NOP"                            ],
    [ 22, 0x00000000, "NOP"                            ],
    [ 23, 0x00000000, "NOP"                            ],
    [ 24, 0x01900005, "ADDI  r9, r0, 5"                ],
    [ 25, 0x00000000, "NOP"                            ],
    [ 26, 0x00000000, "NOP"                            ],
    [ 27, 0x00000000, "NOP"                            ],
    [ 28, 0x08190000, "STORE MEM[r9] = r1"             ],
    [ 29, 0x00000000, "NOP"                            ],
    [ 30, 0x00000000, "NOP"                            ],
    [ 31, 0x00000000, "NOP"                            ],
    [ 32, 0x00000000, "NOP -- BRAM write drain"        ],
    [ 33, 0x00000000, "NOP -- BRAM write drain"        ],
    [ 34, 0x00000000, "NOP -- BRAM write drain"        ],
    [ 35, 0x00000000, "NOP -- BRAM write drain extra"  ],
    [ 36, 0x00000000, "NOP -- BRAM write drain extra"  ],
    [ 37, 0x00A90000, "LOAD  r10, MEM[r9]"             ],
    [ 38, 0x00000000, "NOP"                            ],
    [ 39, 0x00000000, "NOP"                            ],
    [ 40, 0x00000000, "NOP"                            ],
    [ 41, 0x30BA1000, "VADD  r11, r10, r1"             ],
    [ 42, 0x00000000, "NOP"                            ],
    [ 43, 0x00000000, "NOP"                            ],
    [ 44, 0x00000000, "NOP"                            ],
    [ 45, 0xC0C12300, "MMA   r12, r1, r2, r3"          ],
    [ 46, 0x00000000, "NOP"                            ],
    [ 47, 0x00000000, "NOP"                            ],
    [ 48, 0x00000000, "NOP"                            ],
    [ 49, 0x00000000, "NOP -- tensor drain"            ],
    [ 50, 0x00000000, "NOP -- tensor drain"            ],
    [ 51, 0x00000000, "NOP -- tensor drain"            ],
    [ 52, 0x00000000, "NOP -- tensor drain"            ],
    [ 53, 0x30DC2000, "VADD  r13, r12, r2"             ],
    [ 54, 0x00000000, "NOP"                            ],
    [ 55, 0x00000000, "NOP"                            ],
    [ 56, 0x00000000, "NOP"                            ],
);

for my $entry (@program) {
    my ($addr, $instr, $comment) = @$entry;
    write_imem($addr, $instr);
    printf("  IMEM[%2d] = 0x%08X   # %s\n", $addr, $instr, $comment);
}
print "Instruction memory loaded.\n\n";

# ============================================================
# Step 3: Start CPU and wait
# ============================================================
print "=== Starting CPU ===\n";
start_cpu();
print "Waiting for program to complete...\n";
sleep(3);

# ============================================================
# Step 4: Stop CPU
# ============================================================
print "=== Stopping CPU ===\n";
stop_cpu();
sleep(1);

# ============================================================
# Step 5: Read and verify register file
# Expected values split into (upper32, lower32) to avoid
# 64-bit overflow on 32-bit Perl
#
# R1  = 0x000a000a_000a000a  -> upper=0x000a000a lower=0x000a000a
# R2  = 0x00140014_00140014  -> upper=0x00140014 lower=0x00140014
# R3  = 0x001e001e_001e001e  -> upper=0x001e001e lower=0x001e001e
# R4  = 0x00320032_00320032  -> upper=0x00320032 lower=0x00320032
# R5  = 0x05dc05dc_05dc05dc  -> upper=0x05dc05dc lower=0x05dc05dc
# R6  = 0x3aac3aac_3aac3aac  -> upper=0x3aac3aac lower=0x3aac3aac
# R9  = 0x00050005_00050005  -> upper=0x00050005 lower=0x00050005
# R10 = 0x000a000a_000a000a  -> upper=0x000a000a lower=0x000a000a
# R11 = 0x00140014_00140014  -> upper=0x00140014 lower=0x00140014
# R12 = 0x00e600e6_00e600e6  -> upper=0x00e600e6 lower=0x00e600e6
# R13 = 0x00fa00fa_00fa00fa  -> upper=0x00fa00fa lower=0x00fa00fa
# ============================================================

print "\n=== REGISTER FILE RESULTS ===\n";

my %expected = (
    1  => [0x000a000a, 0x000a000a, "ADDI  r1=10 per lane"    ],
    2  => [0x00140014, 0x00140014, "VADD  r2=20 per lane"    ],
    3  => [0x001e001e, 0x001e001e, "VADD  r3=30 per lane"    ],
    4  => [0x00320032, 0x00320032, "VADD  r4=50 per lane"    ],
    5  => [0x05dc05dc, 0x05dc05dc, "VMUL  r5=1500 per lane"  ],
    6  => [0x3aac3aac, 0x3aac3aac, "VMAC  r6=15020 per lane" ],
    9  => [0x00050005, 0x00050005, "ADDI  r9=5 per lane"     ],
    10 => [0x000a000a, 0x000a000a, "LOAD  r10=MEM[5]=r1"     ],
    11 => [0x00140014, 0x00140014, "VADD  r11=20 per lane"   ],
    12 => [0x00e600e6, 0x00e600e6, "MMA   r12=230 per lane"  ],
    13 => [0x00fa00fa, 0x00fa00fa, "VADD  r13=250 per lane"  ],
);

my $pass = 0;
my $fail = 0;

for my $r (0..15) {
    my ($upper, $lower) = read_regfile($r);
    my $hex = sprintf("0x%08x%08x", $upper, $lower);

    if (exists $expected{$r}) {
        my ($exp_u, $exp_l, $desc) = @{$expected{$r}};
        if (check_reg($r, $upper, $lower, $exp_u, $exp_l, $desc)) {
            $pass++;
        } else {
            $fail++;
        }
    } else {
        printf("  R%-2d   = %s\n", $r, $hex);
    }
}

# ============================================================
# Step 6: DMEM check
# STORE writes r1=000a000a_000a000a to word address 1
# ============================================================
print "\n=== DMEM CHECK ===\n";
# r9=5 -> ALU result = 0x0005000500050005
# data_Rmemory uses addr[7:0] directly -> mem[5]
# (NOT addr[9:2] which would give mem[1])
my ($dmem_u, $dmem_l) = read_dmem(5);
my $dmem_hex = sprintf("0x%08x%08x", $dmem_u, $dmem_l);
printf("  DMEM[5] = %s", $dmem_hex);
if ($dmem_u == 0x000a000a && $dmem_l == 0x000a000a) {
    print "   PASS (= r1 = 10 per lane)\n";
} else {
    printf("   FAIL (expected 0x000a000a000a000a)\n");
    $fail++;
}

# ============================================================
# Summary
# ============================================================
print "\n=== SUMMARY ===\n";
my $total = $pass + $fail;
printf("  PASS: %d / %d\n", $pass, $total);
printf("  FAIL: %d / %d\n", $fail, $total);
if ($fail == 0) {
    print "  *** ALL TESTS PASSED ***\n";
} else {
    print "  *** SOME TESTS FAILED -- all regs=0 means CPU did not run ***\n";
    print "  Check: 1) cpu_enable wired correctly in wrapper\n";
    print "         2) regfile_shadow updated on MEM_WB_RegWrite\n";
    print "         3) regfile_re_ext / regfile_addr_ext connected to correct regs\n";
}