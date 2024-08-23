`ifndef		NOINC
`include	"riscv_configs.v"
`endif

module riscv_register_decode
#(
	parameter	REGISTER_INIT_0	= 0
)
(	
	output reg	[`XLEN-1:0]		o_register_q_0,
	output reg	[`XLEN-1:0]		o_register_q_1,
	output reg	[`XLEN-1:0]		o_register_q_2,
	output reg	[`XLEN-1:0]		o_register_q_3,
	output reg	[`XLEN-1:0]		o_register_q_4,
	output reg	[`XLEN-1:0]		o_register_q_5,
	output reg	[`XLEN-1:0]		o_register_q_6,
	output reg	[`XLEN-1:0]		o_register_q_7,
	output reg	[`XLEN-1:0]		o_register_q_8,
	output reg	[`XLEN-1:0]		o_register_q_9,
	output reg	[`XLEN-1:0]		o_register_q_10,
	output reg	[`XLEN-1:0]		o_register_q_11,
	output reg	[`XLEN-1:0]		o_register_q_12,
	output reg	[`XLEN-1:0]		o_register_q_13,
	output reg	[`XLEN-1:0]		o_register_q_14,
	input		[`XLEN-1:0]		i_register_d_0,
	input		[`XLEN-1:0]		i_register_d_1,
	input		[`XLEN-1:0]		i_register_d_2,
	input		[`XLEN-1:0]		i_register_d_3,
	input		[`XLEN-1:0]		i_register_d_4,
	input		[`XLEN-1:0]		i_register_d_5,
	input		[`XLEN-1:0]		i_register_d_6,
	input		[`XLEN-1:0]		i_register_d_7,
	input		[`XLEN-1:0]		i_register_d_8,
	input		[`XLEN-1:0]		i_register_d_9,
	input		[`XLEN-1:0]		i_register_d_10,
	input		[`XLEN-1:0]		i_register_d_11,
	input		[`XLEN-1:0]		i_register_d_12,
	input		[`XLEN-1:0]		i_register_d_13,
	input		[`XLEN-1:0]		i_register_d_14,
	input						i_clk,
	input						i_rstn,
	input						i_clr
);

	always @(posedge i_clk or negedge i_rstn) begin
		if(!i_rstn) begin
			o_register_q_0	<= REGISTER_INIT;
			o_register_q_1	<= REGISTER_INIT;
			o_register_q_2	<= REGISTER_INIT;
		end else begin
				o_register_q_0	<= i_register_d_0;
				o_register_q_1	<= i_register_d_1;
				o_register_q_2	<= i_register_d_2;
				o_register_q_3	<= i_register_d_3;
				o_register_q_4	<= i_register_d_4;
				o_register_q_5	<= i_register_d_5;
				o_register_q_6	<= i_register_d_6;
				o_register_q_7	<= i_register_d_7;
				o_register_q_8	<= i_register_d_8;
				o_register_q_9	<= i_register_d_9;
				o_register_q_10	<= i_register_d_10;
				o_register_q_11	<= i_register_d_11;
				o_register_q_12	<= i_register_d_12;
				o_register_q_13	<= i_register_d_13;
				o_register_q_14	<= i_register_d_14;
		end
	end

endmodule
