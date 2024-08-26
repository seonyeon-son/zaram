`ifndef		NOINC
`include		"../common/riscv_configs.v"
`endif


module	riscv_writeback
(
	output			 [`XLEN-1:0]	o_result_w			,
	input			 [`XLEN-1:0]	i_alu_result_w		,
	input			 [`XLEN-1:0]	i_read_data_w		,
	input			 [`XLEN-1:0]	i_pc_plus_4w		,
	input			 [		1:0]	i_result_src_w	,
	input			[`XLEN-1:0]				i_ext_imm_w
);


	riscv_mux
	#(
		.N_MUX_IN					(4					)
	)
	u_mux_writeback(
		.o_mux_data					(o_result_w			),
		.i_mux_concat_data			({i_ext_imm_w,i_pc_plus_4w,i_read_data_w,i_alu_result_w}),
		.i_mux_sel					(i_result_src_w		)

	);

	endmodule

