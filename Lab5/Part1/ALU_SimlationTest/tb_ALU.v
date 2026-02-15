`timescale 1ns/1ps

module tb_ALU64;

reg clk;
reg rst;
reg [63:0] A, B;
reg [2:0] sel;
wire [63:0] Result;

integer i;
reg [63:0] expected;

// DUT instantiation
ALU64 dut (
    .clk(clk),
    .rst(rst),
    .A(A),
    .B(B),
    .sel(sel),
    .Result(Result)
);

//////////////////////////
// Clock Generation
//////////////////////////
always #5 clk = ~clk;   // 10ns clock period

//////////////////////////
// Test Procedure
//////////////////////////
initial begin
    clk = 0;
    rst = 1;
    A = 0;
    B = 0;
    sel = 0;

    #20;
    rst = 0;

    //////////////////////////////////////////
    // Directed Tests
    //////////////////////////////////////////

    A = 64'hA5A5A5A5A5A5A5A5;
    B = 64'h5A5A5A5A5A5A5A5A;

    // AND
    sel = 3'b000;
    #10;
    expected = A & B;
    check_result("AND");

    // OR
    sel = 3'b001;
    #10;
    expected = A | B;
    check_result("OR");

    // XNOR
    sel = 3'b010;
    #10;
    expected = ~(A ^ B);
    check_result("XNOR");

    // ADD
    sel = 3'b011;
    #10;
    expected = A + B;
    check_result("ADD");

    // SUB
    sel = 3'b100;
    #10;
    expected = A - B;
    check_result("SUB");

    // EQUAL
    sel = 3'b110;
    #10;
    expected = (A == B) ? 64'd1 : 64'd0;
    check_result("EQUAL");

    //////////////////////////////////////////
    // Random Tests
    //////////////////////////////////////////
    for(i = 0; i < 20; i = i + 1) begin
        A = $random;
        B = $random;

        sel = 3'b000; #10; expected = A & B; check_result("RAND AND");
        sel = 3'b001; #10; expected = A | B; check_result("RAND OR");
        sel = 3'b010; #10; expected = ~(A ^ B); check_result("RAND XNOR");
        sel = 3'b011; #10; expected = A + B; check_result("RAND ADD");
        sel = 3'b100; #10; expected = A - B; check_result("RAND SUB");
        sel = 3'b110; #10; expected = (A == B) ? 64'd1 : 64'd0; check_result("RAND EQ");
    end

    //////////////////////////////////////////
    // Reset Check
    //////////////////////////////////////////
    rst = 1;
    #10;
    if(Result !== 64'd0)
        $display("RESET FAILED");
    else
        $display("RESET PASSED");

    $display("All tests completed.");
    $stop;
end


//////////////////////////
// Result Checker Task
//////////////////////////
task check_result;
    input [100*8:0] op_name;
    begin
        if(Result !== expected)
            $display("ERROR in %s: A=%h B=%h Sel=%b Expected=%h Got=%h",
                     op_name, A, B, sel, expected, Result);
        else
            $display("PASS  in %s: Result=%h", op_name, Result);
    end
endtask

endmodule
