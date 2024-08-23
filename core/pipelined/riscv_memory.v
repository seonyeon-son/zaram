`ifndef			NOINC
`include		"../common/riscv_configs.v"
`include		"../common/riscv_dmem.v"
`include		"../common/riscv_register_memory.v"


module	riscv_memory
(
	output							(o_reg_write_w			),
	output							(o_result_src_w			),
	output							(o_alu_result_m			),
	output							(o_read_data_w			),
	output							(o_rd_w					),
	output							(o_pc_plus_4w			),

	input							(i_reg_write_m			),
	input				[1:0]		(i_result_src_m			),
	input							(i_mem_write_m			),
	input							(i_alu_result_m			),
	input							(i_write_data_m			),
	input							(i_rd_m					),
	input							(i_pc_plus_4m			),
	input							(i_clk					),
	input							(i_rstn					)
);

	wire				[`XLEN-1:0]	(o_dmem_rd_data			);


	riscv_dmem
	u_riscv_dmem(
		.o_dmem_data				(o_dmem_rd_data			),
		.i_dmem_data				(i_alu_result_m			),
		.i_dmem_addr				(i_write_data_m			),
		.i_dmem_byte_sel			(
		.i_dmem_wr_en				(i_mem_write_m			),
		.i_clk						(i_clk					)
	);

	riscv_register_memory
	u_riscv_register_memory(
		.o_register_q_0				(o_reg_write_w			),		
        .o_register_q_1				(o_result_src_w			),
        .o_register_q_2				(o_alu_result_m
        .o_register_q_3				(o_read_data_w			),		
        .o_register_q_4				(o_rd_w					),
        .o_register_q_5				(o_pc_plus_4w			),
        .i_register_q_0				(i_reg_write_m			),	
        .i_register_q_1				(i_result_src_m			),
        .i_register_q_2				(i_alu_result_m			),
        .i_register_q_3				(o_dmem_rd_data			),
        .i_register_q_4				(i_pc_plus_4m			),
        .i_register_q_5				(i_rd_m					),
        .i_clk						(i_clk					),
        .i_rstn						(i_rstn					)
	);

	endmodule
