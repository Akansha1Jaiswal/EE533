///////////////////////////////////////////////////////////////////////////////
// vim:set shiftwidth=3 softtabstop=3 expandtab:
// $Id: module_template 2008-03-13 gac1 $
//
// Module: ylrcpu.v
// Project: NF2.1
// Description: This is the verilog file that connects generic registers and the 
// user data path with the pipeline_top.v module to generate the register.v file.
//
///////////////////////////////////////////////////////////////////////////////
`timescale 1ns/1ps

module ylr_risc_cpu 
   #(
      parameter UDP_REG_SRC_WIDTH = 2
   )
   (

      // --- Register interface
      input                               reg_req_in,
      input                               reg_ack_in,
      input                               reg_rd_wr_L_in,
      input  [`UDP_REG_ADDR_WIDTH-1:0]    reg_addr_in,
      input  [`CPCI_NF2_DATA_WIDTH-1:0]   reg_data_in,
      input  [UDP_REG_SRC_WIDTH-1:0]      reg_src_in,

      output                              reg_req_out,
      output                              reg_ack_out,
      output                              reg_rd_wr_L_out,
      output  [`UDP_REG_ADDR_WIDTH-1:0]   reg_addr_out,
      output  [`CPCI_NF2_DATA_WIDTH-1:0]  reg_data_out,
      output  [UDP_REG_SRC_WIDTH-1:0]     reg_src_out,

      // misc
      input                                reset,
      input                                clk
   );

   // Define the log2 function
   // `LOG2_FUNC

   //------------------------- Signals-------------------------------

   // No Ethernet Port Signals needed for this design

   // software registers 
   wire [31:0]                   command;
   wire [31:0]                   address;
   wire [31:0]                   imem_data;
   wire [31:0]                   dmem_upper;
   wire [31:0]                   dmem_lower;
   // hardware registers
   reg [31:0]                    dmem_upper_read;
   reg [31:0]                    dmem_lower_read;
   reg [31:0]                    regfile_lower_read;
   reg [31:0]                    regfile_upper_read;
   
   reg cpu_enable;
   
   wire        imem_we_ext;
   wire [8:0]  imem_addr_ext;
   wire [31:0] imem_data_ext;

   wire        dmem_we_ext;
   wire [7:0]  dmem_addr_ext;
   wire [63:0] dmem_data_ext;

   wire        dmem_re_ext;
   wire [63:0] dmem_rdata_ext;
   
	wire        regfile_re_ext;
	wire [3:0]  regfile_addr_ext;
	wire [63:0] regfile_rdata_ext;

   //------------------------- Local assignments -------------------------------

   //------------------------- Modules-------------------------------

   generic_regs
   #( 
      .UDP_REG_SRC_WIDTH   (UDP_REG_SRC_WIDTH),
      .TAG                 (`YLR_RISC_CPU_BLOCK_ADDR),          // Tag -- eg. MODULE_TAG
      .REG_ADDR_WIDTH      (`YLR_RISC_CPU_REG_ADDR_WIDTH),     // Width of block addresses -- eg. MODULE_REG_ADDR_WIDTH
      .NUM_COUNTERS        (0),                 // Number of counters
      .NUM_SOFTWARE_REGS   (5),                 // Number of sw regs
      .NUM_HARDWARE_REGS   (4)                  // Number of hw regs
   ) module_regs (
      .reg_req_in       (reg_req_in),
      .reg_ack_in       (reg_ack_in),
      .reg_rd_wr_L_in   (reg_rd_wr_L_in),
      .reg_addr_in      (reg_addr_in),
      .reg_data_in      (reg_data_in),
      .reg_src_in       (reg_src_in),

      .reg_req_out      (reg_req_out),
      .reg_ack_out      (reg_ack_out),
      .reg_rd_wr_L_out  (reg_rd_wr_L_out),
      .reg_addr_out     (reg_addr_out),
      .reg_data_out     (reg_data_out),
      .reg_src_out      (reg_src_out),

      // --- counters interface
      .counter_updates  (),
      .counter_decrement(),

      // --- SW regs interface
      .software_regs    ({dmem_upper, dmem_lower, imem_data, address, command}),

      // --- HW regs interface
      .hardware_regs    ({regfile_upper_read, regfile_lower_read, dmem_upper_read, dmem_lower_read}),

      .clk              (clk),
      .reset            (reset)
    );
	
	pipeline_top my_cpu (
	    .clk   (clk),
		.reset (reset),
		.cpu_enable (cpu_enable),
		
	// IMEM programming
        .imem_we_ext   (imem_we_ext),
        .imem_addr_ext (imem_addr_ext),
        .imem_data_ext (imem_data_ext),

    // DMEM programming
        .dmem_we_ext   (dmem_we_ext),
        .dmem_addr_ext (dmem_addr_ext),
        .dmem_data_ext (dmem_data_ext),

    // DMEM read
        .dmem_re_ext   (dmem_re_ext),
        .dmem_rdata_ext(dmem_rdata_ext),
		
	//REGFILE read
		.regfile_re_ext    (regfile_re_ext),
		.regfile_addr_ext  (regfile_addr_ext),
		.regfile_rdata_ext (regfile_rdata_ext)
	);

   //------------------------- Logic-------------------------------
   
    // command bits
/* 	command [0] - Start CPU 
    command [1] - Stop CPU  
    command [2] - Write DMem
	command [3] - Write IMem
	command [4] - Read DMem
	command [5] - Read RegFile*/
    
	wire write_imem   = command [3];
	wire write_dmem   = command [2];
	wire read_dmem    = command [4];
	wire start_cpu    = command [0];
	wire stop_cpu     = command [1];
	wire read_regfile = command [5];
	
	// Combine 64-bit DMem
	
	wire [63:0] dmem_write_data = {dmem_upper, dmem_lower};

    // Connecting BRAMs to Software/Hardware regs
	
	
	assign imem_we_ext   = write_imem;
    assign imem_addr_ext = address[8:0];
    assign imem_data_ext = imem_data;

    assign dmem_we_ext   = write_dmem;
    assign dmem_addr_ext = address[7:0];
    assign dmem_data_ext = {dmem_upper, dmem_lower};

    assign dmem_re_ext   = read_dmem;
	
	assign regfile_re_ext   = read_regfile;
	assign regfile_addr_ext = address[3:0];
	
	always @(posedge clk) begin
	    if (reset) begin
           dmem_upper_read <= 32'h0;
           dmem_lower_read <= 32'h0;
		end
        else if (dmem_re_ext) begin
           dmem_upper_read <= dmem_rdata_ext[63:32];
           dmem_lower_read <= dmem_rdata_ext[31:0];
        end
    end
	always @(posedge clk) begin
	   if (reset)
		  cpu_enable <= 1'b0;
	   else begin
		  if (start_cpu)
			 cpu_enable <= 1'b1;
		  else if (stop_cpu)
			 cpu_enable <= 1'b0;
	   end
	end
	always @(posedge clk) begin
	   if (reset) begin
		  regfile_upper_read <= 32'h0;
		  regfile_lower_read <= 32'h0;
	   end
	   else if (regfile_re_ext) begin
		  regfile_upper_read <= regfile_rdata_ext[63:32];
		  regfile_lower_read <= regfile_rdata_ext[31:0];
	   end
	end
	
endmodule 
