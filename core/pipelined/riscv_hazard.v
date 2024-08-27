`ifndef		NOINC
`include	"../common/riscv_configs.v"
`endif
module riscv_hazard
(	
	output 						o_stall_f,
	output 						o_stall_d,
	output 						o_flush_d,
	output 						o_flush_e,
	output reg	[	   1:0]		o_forward_ae,
	output reg	[	   1:0]		o_forward_be,
	input		[      4:0]		i_rs_1d,
	input		[      4:0]		i_rs_2d,
	input		[      4:0]		i_rd_e,
	input		[      4:0]		i_rs_1e,
	input		[      4:0]		i_rs_2e,
	input						i_pc_src_e,
	input						i_result_src_e,
	input		[      4:0]		i_rd_m,
	input						i_reg_write_m,
	input		[      4:0]		i_rd_w,
	input						i_reg_write_w
);


// ForwardAE
	always @ (*) begin
		if(i_reg_write_m && (i_rs_1e != 0) && (i_rs_1e == i_rd_m))
			o_forward_ae = 2'b10;
		else if(i_reg_write_w && (i_rs_1e != 0) && (i_rs_1e == i_rd_w))
			o_forward_ae = 2'b01;
		else
			o_forward_ae = 2'b00;
	end

	// ForwardBE
	always @ (*) begin
		if(i_reg_write_m && (i_rs_2e != 0) && (i_rs_2e == i_rd_m))
			o_forward_be = 2'b10;
		else if(i_reg_write_w && (i_rs_2e != 0) && (i_rs_2e == i_rd_w))
			o_forward_be = 2'b01;
		else
			o_forward_be = 2'b00;
	end

	reg	lw_stall;

	// lw stall
	always @ (*) begin
		if(((i_rs_1d == i_rd_e) || (i_rs_2d == i_rd_e)) && (i_result_src_e == 1)) begin
			lw_stall	= 1;
		end
		else begin
			lw_stall	= 0;
		end
	end

	assign	o_stall_f	= lw_stall;
	assign	o_stall_d	= lw_stall;
	assign	o_flush_d	= i_pc_src_e;
	assign	o_flush_e	= (lw_stall || i_pc_src_e);


	endmodule

