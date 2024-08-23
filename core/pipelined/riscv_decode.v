`ifndef		NOINC
`include	"../common/riscv_regfile.v"
`include	"../common/riscv_ctrl.v"
`include	"../common/riscv_regfile.v"
`include	"../common/riscv_immext.v"
`include	"../common/riscv_register_decode.v"


module	riscv_decode
(
	output			[`XLEN-1:0]		o_reg_write_e,
	output			[`XLEN-1:0]		o_result_src_e,
	output			[`XLEN-1:0]		o_mem_write_e,
	output			[`XLEN-1:0]		o_jump_e,
	output							o_branch_e,
	output							o_alu_ctrl_e,
	output							o_alu_src_e,
	output			[`XLEN-1:0]		o_rd_1e,
	output			[`XLEN-1:0]		o_rd_2e,
	output			[`XLEN-1:0]		o_pc_e,
	output			[`XLEN-1:0]		o_rs_1e,
	output			[`XLEN-1:0]		o_rs_2e,
	output			[`XLEN-1:0]		o_rd_e,
	output			[`XLEN-1:0]		o_ext_imm_e,
	output			[`XLEN-1:0]		o_pc_plus_4e,

	input			[`XLEN-1:0]		i_instr_d,
	input			[`XLEN-1:0]		i_pc_d,
	input			[`XLEN-1:0]		i_pc_plus_4d,
	input			[`XLEN-1:0]		i_result_w,
	input			[`XLEN-1:0]		i_rd_w,
	input			[`XLEN-1:0]		i_result_w,
	input			[`XLEN-1:0]		i_reg_wirte_w,
	input							i_clk,
);

	wire			[`XLEN-1:0]		o_imm_src_d;
	wire			[`XLEN-1:0]		o_result_src_d;
	wire			[`XLEN-1:0]		o_alu_src_d;
	wire			[`XLEN-1:0]		o_reg_write_d;
	wire			[`XLEN-1:0]		o_mem_write_d;

	wire			[`XLEN-1:0]		o_ctrl_mem_byte_sel_d;
	wire			[`XLEN-1:0]		o_alu_ctrl_d;
	
	wire			[`XLEN-1:0]		o_aui_d;
	wire			[`XLEN-1:0]		o_lui_d;
	wire			[`XLEN-1:0]		o_zero_condition_d;


	wire			[`XLEN-1:0]		o_jump_d;
	wire			[`XLEN-1:0]		o_branch_d;



	riscv_ctrl
	u_riscv_ctrl(
		.o_ctrl_src_imm			(o_imm_src_d		),
		.o_ctrl_src_rd			(o_result_src_d		),
		.o_ctrl_src_alu_b		(o_alu_src_d		),
		.o_ctrl_reg_wr_en		(o_reg_write_d		),
		.o_ctrl_mem_wr_en		(o_mem_write_d		),
		.o_ctrl_mem_byte_sel	(o_ctrl_mem_byte_sel_d),
		.o_ctrl_alu_ctrl		(o_alu_ctrl_d		),
		.o_ctrl_jump_d			(o_jump_d			),
		.o_ctrl_branch_d		(o_branch_d			),
		.o_aui					(o_aui_d			),
		.o_lui					(o_lui_d			),
		.o_zero_condition		(o_zero_condition_d	),
		.i_ctrl_opcode			(i_instr_d[6:0]		),
		.i_ctrl_funct3			(i_instr_d[14:12]	),
		.i_ctrl_funct7_5b		(i_instr_d[30]		)
	);


	riscv_regfile
	u_riscv_regfile(
		.o_regfile_rs1_data		(o_rd_1_data		),
		.o_regfile_rs2_data		(o_rd_2_data		),
		.i_regfile_rs1_addr		(i_instr_d[19:15]	),
		.i_regfile_rs2_addr		(i_instr_d[24:20]	),
		.i_regfile_rd_addr		(i_rd_w				),
		.i_regfile_rd_data		(i_result_w			),
		.i_regfile_rd_wen		(i_reg_write_w		),
		.i_clk					(i_clk				)
	);

	riscv_immext
	u_riscv_immext(
		.o_imm_ext				(o_ext_imm_d		),
		.i_imm_instr			(i_instr_d[31:7]	),
		.i_imm_src				(o_imm_src_d		)
	);

	riscv_register_decode
	u_riscv_register_decode(
		.o_register_q_0			(o_reg_write_e		),
        .o_register_q_1			(o_result_src_e		),
        .o_register_q_2			(o_mem_write_e		),
        .o_register_q_3			(o_jump_e			),
        .o_register_q_4			(o_branch_e			),
        .o_register_q_5			(o_alu_ctrl_e		),
        .o_register_q_6			(o_alu_src_e		),
        .o_register_q_7			(o_rd_1e			),
        .o_register_q_8			(o_rd_2e			),
        .o_register_q_9			(o_pc_e				),
        .o_register_q_10		(o_rs_1e			),	
        .o_register_q_11		(o_rs_2e			),	
        .o_register_q_12		(o_rd_e				),
        .o_register_q_13		(o_ext_imm_e		),
        .o_register_q_14		(o_pc_plus_4e		),
        .i_register_d_0			(o_reg_write_d		),
        .i_register_d_1			(o_result_src_d		),
        .i_register_d_2			(o_mem_write_d		),
        .i_register_d_3			(i_jump_d			),
        .i_register_d_4			(i_branch_d			),
        .i_register_d_5			(i_alu_ctrl_d		),
        .i_register_d_6			(i_alu_src_d		),
        .i_register_d_7			(o_rd_1_data		),
        .i_register_d_8			(o_rd_2_data		),
        .i_register_d_9			(i_pc_d				),
        .i_register_d_10		(i_rs_1_d			),
        .i_register_d_11		(i_rs_2_d			),
        .i_register_d_12		(i_rd_d				),
        .i_register_d_13		(i_ext_imm_d		),
        .i_register_d_14		(i_pc_plus_4d		)
	);

	endmodule
