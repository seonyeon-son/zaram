`ifndef		NOINC
`include	"../common/riscv_configs.v"
`include	"../common/riscv_alu.v"
`endif

module	riscv_execute
(
	output			[`XLEN-1:0]	o_pc_target_e		,
	output						o_zero_e			,
	output						o_reg_write_m		,
	output			[	   1:0]	o_result_src_m		,
	output						o_mem_write_m		,
	output			[`XLEN-1:0]	o_alu_result_m		,
	output			[`XLEN-1:0]	o_write_data_m		,
	output			[	   4:0]	o_rd_m				,
	output			[`XLEN-1:0]	o_pc_plus_4m		,
	output			[`XLEN-1:0]	o_ext_imm_m			,
	output			[`XLEN-1:0]	o_alu_data			,
	output			[2:0]		o_funct3_m			,
	output			[3:0]		o_ctrl_mem_byte_sel_m,

	input			[`XLEN-1:0] i_rd_1e               ,
	input			[`XLEN-1:0] i_result_w            ,
	input			[	   1:0] i_forward_ae          ,
	input			[`XLEN-1:0] i_rd_2e               ,
	input			[	   1:0] i_forward_be          ,
	input			[`XLEN-1:0] i_pc_e                ,
	input			[`XLEN-1:0] i_ext_imm_e           ,
	input			[	   3:0] i_alu_ctrl_e          ,
	input                       i_alu_src_e_a         ,
	input                       i_alu_src_e_b         ,
	input                       i_reg_write_e         ,
	input			[1:0]       i_result_src_e        ,
	input                       i_zero_condition      ,
	input			[2:0]       i_funct3_e            ,
	input			[3:0]       i_ctrl_mem_byte_sel_e ,
	input                       i_mem_write_e         ,
	input			[4:0]       i_rd_e                ,
	input			[`XLEN-1:0] i_pc_plus_4e          ,
	input                       i_clk                 ,
	input                       i_rstn

);
	
	wire		[`XLEN-1:0]		o_src_ae			;
	wire		[`XLEN-1:0]		o_write_data_e		;
	wire		[`XLEN-1:0]		o_src_be			;
	wire		[`XLEN-1:0]		o_mux_src_a			;


	riscv_mux
	#(
		.N_MUX_IN				(3					)
	)
	u_mux_execute_0(
		.o_mux_data				(o_mux_src_a		),
		.i_mux_concat_data		({o_alu_result_m,i_result_w,i_rd_1e}),
		.i_mux_sel				(i_forward_ae		)
	);

	riscv_mux
	#(
		.N_MUX_IN				(2					)
	)
	u_riscv_mux_1(
		.o_mux_data				(o_src_ae			),
		.i_mux_concat_data		({i_pc_e,o_mux_src_a}),
		.i_mux_sel				(i_alu_src_e_a		)
	);

	riscv_mux
	#(
		.N_MUX_IN				(3					)
	)
	u_mux_execute_2(
		.o_mux_data				(o_write_data_e		),
		.i_mux_concat_data		({o_alu_result_m,i_result_w,i_rd_2e}),
		.i_mux_sel				(i_forward_be		)
	);

	riscv_mux
	#(
		.N_MUX_IN				(2					)
	)
	u_riscv_mux_3(
		.o_mux_data				(o_src_be			),
		.i_mux_concat_data		({i_ext_imm_e,o_write_data_e}),
		.i_mux_sel				(i_alu_src_e_b		)
	);

	riscv_adder
	u_adder_execute(
		.o_adder_sum			(o_pc_target_e		),
		.i_adder_a				(i_pc_e				),
		.i_adder_b				(i_ext_imm_e		)
	);

	riscv_alu
	u_riscv_alu(
		.o_alu_result			(o_alu_data			),
		.o_alu_zero				(o_zero_e			),
		.i_alu_a				(o_src_ae			),
		.i_alu_b				(o_src_be			),
		.i_alu_ctrl				(i_alu_ctrl_e		),
		.i_zero_condition		(i_zero_condition	)
	);

	riscv_register_execute
	u_riscv_register_execute(
		.o_register_q_0			(o_reg_write_m		),
		.o_register_q_1			(o_result_src_m		),
		.o_register_q_2			(o_mem_write_m		),
		.o_register_q_3			(o_alu_result_m		),
		.o_register_q_4			(o_write_data_m		),
		.o_register_q_5			(o_rd_m				),
		.o_register_q_6			(o_pc_plus_4m		),
		.o_register_q_7			(o_ext_imm_m		),
		.o_register_q_8			(o_ctrl_mem_byte_sel_m	),
		.o_register_q_9			(o_funct3_m			),
		.i_register_d_0			(i_reg_write_e		),
		.i_register_d_1			(i_result_src_e		),
		.i_register_d_2			(i_mem_write_e		),
		.i_register_d_3			(o_alu_data			),
		.i_register_d_4			(o_write_data_e		),
		.i_register_d_5			(i_rd_e				),
		.i_register_d_6			(i_pc_plus_4e		),
		.i_register_d_7			(i_ext_imm_e		),
		.i_register_d_8			(i_ctrl_mem_byte_sel_e	),
		.i_register_d_9			(i_funct3_e),
		.i_clk					(i_clk				),
		.i_rstn					(i_rstn				)
	);

	endmodule



