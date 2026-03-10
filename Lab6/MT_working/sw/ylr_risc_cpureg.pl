#!/usr/bin/perl -w
use lib "/usr/local/netfpga/lib/Perl5";
use strict;

my $YLR_RISC_CPU_COMMAND_REG              = 0x2000400;
my $YLR_RISC_CPU_ADDRESS_REG              = 0x2000404;
my $YLR_RISC_CPU_IMEM_REG                 = 0x2000408;
my $YLR_RISC_CPU_DMEM_WRITE_LOWER32       = 0x200040C;
my $YLR_RISC_CPU_DMEM_WRITE_UPPER32       = 0x2000410;
my $YLR_RISC_CPU_DMEM_READ_LOWER32        = 0x2000414;
my $YLR_RISC_CPU_DMEM_READ_UPPER32        = 0x2000418;
my $YLR_RISC_CPU_REGFILE_READ_LOWER32     = 0x200041C;
my $YLR_RISC_CPU_REGFILE_READ_UPPER32     = 0x2000420;

# Register access helpers

sub regwrite {
   my( $addr, $value ) = @_;
   my $cmd = sprintf("regwrite 0x%08x 0x%08x", $addr, $value);
   system($cmd) == 0 or die "Failed: $cmd\n";
}

sub regread {
   my( $addr ) = @_;
   my $cmd = sprintf("regread 0x%08x", $addr);
   my @out = `$cmd`;
   my $result = $out[0];
   if ($result =~ m/Reg (0x[0-9a-f]+).*:\s+(0x[0-9a-f]+)/) {
      return $2;
   }
   die "Unexpected regread output\n";
}

# Operations

# command bits
# bit[0] = Start CPU
# bit[1] = Stop CPU
# bit[2] = Write DMEM
# bit[3] = Write IMEM
# bit[4] = Read DMEM
# bit[5] = Read RegFile

sub write_imem {
   my ($addr, $instr) = @_;
   regwrite($YLR_RISC_CPU_ADDRESS_REG, $addr);
   regwrite($YLR_RISC_CPU_IMEM_REG, $instr);
   regwrite($YLR_RISC_CPU_COMMAND_REG, 0x8);  # bit[3]
   regwrite($YLR_RISC_CPU_COMMAND_REG, 0x0);
}

sub write_dmem {
   my ($addr, $data64) = @_;

   my $lower = $data64 & 0xFFFFFFFF;
   my $upper = ($data64 >> 32) & 0xFFFFFFFF;

   regwrite($YLR_RISC_CPU_ADDRESS_REG, $addr);
   regwrite($YLR_RISC_CPU_DMEM_WRITE_LOWER32, $lower);
   regwrite($YLR_RISC_CPU_DMEM_WRITE_UPPER32, $upper);

   regwrite($YLR_RISC_CPU_COMMAND_REG, 0x4);  # bit[2]
   regwrite($YLR_RISC_CPU_COMMAND_REG, 0x0);
}

sub read_dmem {
   my ($addr) = @_;

   regwrite($YLR_RISC_CPU_ADDRESS_REG, $addr);
   regwrite($YLR_RISC_CPU_COMMAND_REG, 0x10);  # bit[4]

   my $lower = hex(regread($YLR_RISC_CPU_DMEM_READ_LOWER32));
   my $upper = hex(regread($YLR_RISC_CPU_DMEM_READ_UPPER32));

   my $data = sprintf("0x%016x", ($upper << 32) | $lower);
   print "DMEM[$addr] = $data\n";

   regwrite($YLR_RISC_CPU_COMMAND_REG, 0x0);
}

sub read_regfile {
   my ($regnum) = @_;

   regwrite($YLR_RISC_CPU_ADDRESS_REG, $regnum);
   regwrite($YLR_RISC_CPU_COMMAND_REG, 0x20);  # bit[5]

   my $lower = hex(regread($YLR_RISC_CPU_REGFILE_READ_LOWER32));
   my $upper = hex(regread($YLR_RISC_CPU_REGFILE_READ_UPPER32));

   my $data = sprintf("0x%016x", ($upper << 32) | $lower);
   print "R$regnum = $data\n";

   regwrite($YLR_RISC_CPU_COMMAND_REG, 0x0);
}

sub start_cpu {
   regwrite($YLR_RISC_CPU_COMMAND_REG, 0x1);  # bit[0]
   regwrite($YLR_RISC_CPU_COMMAND_REG, 0x0);
}

sub stop_cpu {
   regwrite($YLR_RISC_CPU_COMMAND_REG, 0x2);  # bit[1]
   regwrite($YLR_RISC_CPU_COMMAND_REG, 0x0);
}

# Usage

sub usage {
   print "Usage:\n";
   print "  ylr_risc_cpureg imem <addr> <hex_instr>\n";
   print "  ylr_risc_cpureg dmemw <addr> <hex_64bit_data>\n";
   print "  ylr_risc_cpureg dmemr <addr>\n";
   print "  ylr_risc_cpureg regr  <regnum>\n";
   print "  ylr_risc_cpureg start\n";
   print "  ylr_risc_cpureg stop\n";
}

# Main

my $numargs = $#ARGV + 1;
if ($numargs < 1) {
   usage();
   exit(1);
}

my $cmd = $ARGV[0];

if ($cmd eq "imem") {
   die "Need addr and instr\n" if ($numargs < 3);
   write_imem($ARGV[1], hex($ARGV[2]));
}
elsif ($cmd eq "dmemr") {
   die "Need addr\n" if ($numargs < 2);
   read_dmem($ARGV[1]);
}
elsif ($cmd eq "dmemw") {
   die "Need addr data\n" if ($numargs < 3);
   write_dmem($ARGV[1], hex($ARGV[2]));
}
elsif ($cmd eq "regr") {
   die "Need regnum\n" if ($numargs < 2);
   read_regfile($ARGV[1]);
}
elsif ($cmd eq "start") {
   start_cpu();
}
elsif ($cmd eq "stop") {
   stop_cpu();
}
else {
   usage();
}