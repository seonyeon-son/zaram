`ifndef		NOINC
`include	"../common/riscv_configs.v"
`endif
module riscv_hazard
(	
	output reg					o_stall_f,
	output reg					o_stall_d,
	output reg					o_flush_d,
	output reg					o_flush_e,
	output reg	[	   1:0]		o_forward_ae,
	output reg	[	   1:0]		o_forward_be,
	input		[      4:0]		i_rs_1d,
	input		[      4:0]		i_rs_2d,
	input		[      4:0]		i_rd_e,
	input		[      4:0]		i_rs_1e,
	input		[      4:0]		i_rs_2e,
	input		[      1:0]		i_pc_src_e,
	input						i_result_src_e,
	input		[      4:0]		i_rd_m,
	input						i_reg_write_m,
	input		[      4:0]		i_rd_w,
	input						i_reg_write_w
);


// ForwardAE
	always @ (*) begin
		if(i_reg_write_m && (i_rd_m != 0) && (i_rs_1e == i_rd_m))
			o_forward_ae = 2'b10;
		else if(i_reg_write_w && (i_rd_w != 0) && (i_rs_1e == i_rd_w))
			o_forward_ae = 2'b01;
		else
			o_forward_ae = 2'b00;
	end

	// ForwardBE
	always @ (*) begin
		if(i_reg_write_m && (i_rd_m != 0) && (i_rs_2e == i_rd_m))
			o_forward_be = 2'b10;
		else if(i_reg_write_w && (i_rd_w != 0) && (i_rs_2e == i_rd_w))
			o_forward_be = 2'b01;
		else
			o_forward_be = 2'b00;
	end

	// lw stall
	always @ (*) begin
		if(((i_rs_1d == i_rd_e) || (i_rs_2d == i_rd_e)) && (i_result_src_e == 1'b0)) begin
			o_stall_f = 1'b1;
			o_stall_d = 1'b1;
			o_flush_e = 1'b1;
		end
		else begin
			o_stall_f = 1'b0;
			o_stall_d = 1'b0;
			o_flush_e = 1'b0;
		end
	end

	// branch flush
	always @ (*) begin
		if((i_pc_src_e == 2'b01) || (i_pc_src_e == 2'b10)) begin
			o_flush_d = 1'b1;
			o_flush_e = 1'b1;
		end
		else begin
			o_flush_d = 1'b0;
			o_flush_e = 1'b0;
		end
	end

	endmodule
   /*
module riscv_hazard
(
	output 						o_stall_f,
	output 						o_stall_d,
	output 						o_flush_d,
	output 						o_flush_e,
	output 		[1:0]			o_forward_ae,
	output 		[1:0]			o_forward_be,
	input		[4:0]			i_rs_1d,
	input		[4:0]			i_rs_2d,
	input		[4:0]			i_rd_e,
	input		[4:0]			i_rs_2e,
	input		[4:0]			i_rs_1e,
	input						i_pc_src_e,
	input						i_result_src_e,
	input		[4:0]			i_rd_m,
	input		[4:0]			i_rd_w,
	input						i_reg_write_m,
	input						i_reg_write_w
);

wire	lwstall;

assign o_forward_ae		= (((i_rs_1e == i_rd_m) && i_reg_write_m) && (i_rs_1e != 0)) ? 2'b10 :
						  (((i_rs_1e == i_rd_w) && i_reg_write_w) && (i_rs_1e != 0)) ? 2'b01 : 2'b00;

assign o_forward_be		= (((i_rs_2e == i_rd_m) && i_reg_write_m) && (i_rs_2e != 0)) ? 2'b10 :
						  (((i_rs_2e == i_rd_w) && i_reg_write_w) && (i_rs_2e != 0)) ? 2'b01 : 2'b00;

assign lwstall	= (((i_rs_1d == i_rd_e) || (i_rs_2d == i_rd_e)) && i_result_src_e);

assign o_stall_f	= lwstall;
assign o_stall_d	= lwstall;
assign o_flush_d	= i_pc_src_e;
assign o_flush_e	= (lwstall || i_pc_src_e);

endmodule
*/
