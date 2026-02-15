VERSION 6
BEGIN SCHEMATIC
    BEGIN ATTR DeviceFamilyName "virtex2p"
        DELETE all:0
        EDITNAME all:0
        EDITTRAIT all:0
    END ATTR
    BEGIN NETLIST
        SIGNAL clk
        SIGNAL A(63:0)
        SIGNAL B(63:0)
        SIGNAL opcode(3:0)
        SIGNAL Result(63:0)
        SIGNAL SLT
        SIGNAL Overflow_flag
        SIGNAL Cout
        SIGNAL Zero_flag
        SIGNAL XLXN_10
        SIGNAL XLXN_11
        SIGNAL XLXN_12
        SIGNAL XLXN_13
        SIGNAL XLXN_14
        SIGNAL XLXN_15(63:0)
        SIGNAL XLXN_16(63:0)
        SIGNAL XLXN_17(3:0)
        SIGNAL XLXN_18
        SIGNAL XLXN_19
        SIGNAL XLXN_20
        SIGNAL XLXN_21
        SIGNAL XLXN_22(63:0)
        PORT Input clk
        PORT Input A(63:0)
        PORT Input B(63:0)
        PORT Input opcode(3:0)
        PORT Output Result(63:0)
        PORT Output SLT
        PORT Output Overflow_flag
        PORT Output Cout
        PORT Output Zero_flag
        BEGIN BLOCKDEF alu64
            TIMESTAMP 2026 2 12 7 32 42
            RECTANGLE N 64 -320 320 0 
            RECTANGLE N 0 -300 64 -276 
            LINE N 64 -288 0 -288 
            RECTANGLE N 0 -172 64 -148 
            LINE N 64 -160 0 -160 
            RECTANGLE N 0 -44 64 -20 
            LINE N 64 -32 0 -32 
            LINE N 320 -288 384 -288 
            LINE N 320 -224 384 -224 
            LINE N 320 -160 384 -160 
            LINE N 320 -96 384 -96 
            RECTANGLE N 320 -44 384 -20 
            LINE N 320 -32 384 -32 
        END BLOCKDEF
        BEGIN BLOCKDEF reg64_
            TIMESTAMP 2026 2 12 7 33 6
            RECTANGLE N 64 -128 320 0 
            LINE N 64 -96 0 -96 
            RECTANGLE N 0 -44 64 -20 
            LINE N 64 -32 0 -32 
            RECTANGLE N 320 -108 384 -84 
            LINE N 320 -96 384 -96 
        END BLOCKDEF
        BEGIN BLOCKDEF reg4
            TIMESTAMP 2026 2 12 7 35 38
            RECTANGLE N 64 -128 320 0 
            LINE N 64 -96 0 -96 
            RECTANGLE N 0 -44 64 -20 
            LINE N 64 -32 0 -32 
            RECTANGLE N 320 -108 384 -84 
            LINE N 320 -96 384 -96 
        END BLOCKDEF
        BEGIN BLOCKDEF fd
            TIMESTAMP 2000 1 1 10 10 10
            RECTANGLE N 64 -320 320 -64 
            LINE N 0 -128 64 -128 
            LINE N 0 -256 64 -256 
            LINE N 384 -256 320 -256 
            LINE N 80 -128 64 -144 
            LINE N 64 -112 80 -128 
        END BLOCKDEF
        BEGIN BLOCK XLXI_1 alu64
            PIN A(63:0) XLXN_15(63:0)
            PIN B(63:0) XLXN_16(63:0)
            PIN opcode(3:0) XLXN_17(3:0)
            PIN zero_flag XLXN_18
            PIN Cout XLXN_19
            PIN overflow_flag XLXN_20
            PIN SLT XLXN_21
            PIN result(63:0) XLXN_22(63:0)
        END BLOCK
        BEGIN BLOCK XLXI_2 reg64_
            PIN clk clk
            PIN D(63:0) A(63:0)
            PIN Q(63:0) XLXN_15(63:0)
        END BLOCK
        BEGIN BLOCK XLXI_3 reg64_
            PIN clk clk
            PIN D(63:0) B(63:0)
            PIN Q(63:0) XLXN_16(63:0)
        END BLOCK
        BEGIN BLOCK XLXI_4 reg64_
            PIN clk clk
            PIN D(63:0) XLXN_22(63:0)
            PIN Q(63:0) Result(63:0)
        END BLOCK
        BEGIN BLOCK XLXI_5 reg4
            PIN clk clk
            PIN D(3:0) opcode(3:0)
            PIN Q(3:0) XLXN_17(3:0)
        END BLOCK
        BEGIN BLOCK XLXI_6 fd
            PIN C clk
            PIN D XLXN_18
            PIN Q Zero_flag
        END BLOCK
        BEGIN BLOCK XLXI_7 fd
            PIN C clk
            PIN D XLXN_19
            PIN Q Cout
        END BLOCK
        BEGIN BLOCK XLXI_8 fd
            PIN C clk
            PIN D XLXN_20
            PIN Q Overflow_flag
        END BLOCK
        BEGIN BLOCK XLXI_9 fd
            PIN C clk
            PIN D XLXN_21
            PIN Q SLT
        END BLOCK
    END NETLIST
    BEGIN SHEET 1 3520 2720
        BEGIN INSTANCE XLXI_1 1488 1280 R0
        END INSTANCE
        BEGIN INSTANCE XLXI_2 736 832 R0
        END INSTANCE
        BEGIN INSTANCE XLXI_3 736 1120 R0
        END INSTANCE
        BEGIN INSTANCE XLXI_5 736 1376 R0
        END INSTANCE
        INSTANCE XLXI_6 2160 384 R0
        INSTANCE XLXI_7 2160 704 R0
        INSTANCE XLXI_8 2160 1040 R0
        INSTANCE XLXI_9 2160 1376 R0
        BEGIN INSTANCE XLXI_4 2160 1536 R0
        END INSTANCE
        BEGIN BRANCH clk
            WIRE 432 736 592 736
            WIRE 592 736 720 736
            WIRE 720 736 736 736
            WIRE 496 720 592 720
            WIRE 592 720 592 736
            WIRE 496 720 496 848
            WIRE 496 848 496 1024
            WIRE 496 1024 736 1024
            WIRE 496 1024 496 1280
            WIRE 496 1280 736 1280
            WIRE 496 848 1328 848
            WIRE 1328 256 1328 848
            WIRE 1328 256 2048 256
            WIRE 2048 256 2160 256
            WIRE 2048 256 2048 576
            WIRE 2048 576 2160 576
            WIRE 2048 576 2048 912
            WIRE 2048 912 2160 912
            WIRE 2048 912 2048 1248
            WIRE 2048 1248 2160 1248
            WIRE 2048 1248 2048 1440
            WIRE 2048 1440 2160 1440
        END BRANCH
        BEGIN BRANCH A(63:0)
            WIRE 704 800 736 800
        END BRANCH
        IOMARKER 704 800 A(63:0) R180 28
        BEGIN BRANCH B(63:0)
            WIRE 704 1088 736 1088
        END BRANCH
        IOMARKER 704 1088 B(63:0) R180 28
        BEGIN BRANCH opcode(3:0)
            WIRE 704 1344 736 1344
        END BRANCH
        IOMARKER 704 1344 opcode(3:0) R180 28
        BEGIN BRANCH Result(63:0)
            WIRE 2544 1440 2576 1440
        END BRANCH
        IOMARKER 2576 1440 Result(63:0) R0 28
        BEGIN BRANCH SLT
            WIRE 2544 1120 2576 1120
        END BRANCH
        IOMARKER 2576 1120 SLT R0 28
        BEGIN BRANCH Overflow_flag
            WIRE 2544 784 2576 784
        END BRANCH
        IOMARKER 2576 784 Overflow_flag R0 28
        BEGIN BRANCH Cout
            WIRE 2544 448 2576 448
        END BRANCH
        IOMARKER 2576 448 Cout R0 28
        BEGIN BRANCH Zero_flag
            WIRE 2544 128 2576 128
        END BRANCH
        IOMARKER 2576 128 Zero_flag R0 28
        IOMARKER 432 736 clk R180 28
        BEGIN BRANCH XLXN_15(63:0)
            WIRE 1120 736 1344 736
            WIRE 1344 736 1344 992
            WIRE 1344 992 1488 992
        END BRANCH
        BEGIN BRANCH XLXN_16(63:0)
            WIRE 1120 1024 1296 1024
            WIRE 1296 1024 1296 1120
            WIRE 1296 1120 1488 1120
        END BRANCH
        BEGIN BRANCH XLXN_17(3:0)
            WIRE 1120 1280 1296 1280
            WIRE 1296 1248 1296 1280
            WIRE 1296 1248 1488 1248
        END BRANCH
        BEGIN BRANCH XLXN_18
            WIRE 1872 992 2016 992
            WIRE 2016 128 2016 992
            WIRE 2016 128 2160 128
        END BRANCH
        BEGIN BRANCH XLXN_19
            WIRE 1872 1056 2032 1056
            WIRE 2032 448 2032 1056
            WIRE 2032 448 2160 448
        END BRANCH
        BEGIN BRANCH XLXN_20
            WIRE 1872 1120 2000 1120
            WIRE 2000 784 2000 1120
            WIRE 2000 784 2160 784
        END BRANCH
        BEGIN BRANCH XLXN_21
            WIRE 1872 1184 2016 1184
            WIRE 2016 1120 2016 1184
            WIRE 2016 1120 2160 1120
        END BRANCH
        BEGIN BRANCH XLXN_22(63:0)
            WIRE 1872 1248 2016 1248
            WIRE 2016 1248 2016 1504
            WIRE 2016 1504 2160 1504
        END BRANCH
    END SHEET
END SCHEMATIC
