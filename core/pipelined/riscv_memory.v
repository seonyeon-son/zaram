`ifndef			NOINC
`include		"../common/riscv_configs.v"
`include		"../common/riscv_dmem.v"
`include		"../common/riscv_register_memory.v"
`endif

module	riscv_memory
(
	output                          o_reg_write_w   ,
	output				[1:0]       o_result_src_w  ,
	output				[`XLEN-1:0] o_alu_result_w  ,
	output				[`XLEN-1:0] o_read_data_w   ,
	output				[4:0]       o_rd_w          ,
	output				[`XLEN-1:0] o_pc_plus_4w    ,
	output				[`XLEN-1:0] o_ext_imm_w     ,
	output				[`XLEN-1:0] o_mem_read_data ,

	input                           i_reg_write_m         ,
	input				[1:0]       i_result_src_m        ,
	input                           i_mem_write_m         ,
	input				[`XLEN-1:0] i_alu_result_m        ,
	input				[`XLEN-1:0] i_write_data_m        ,
	input				[4:0]       i_rd_m                ,
	input				[`XLEN-1:0] i_pc_plus_4m          ,

	input                           i_clk                 ,
	input                           i_rstn                ,
	input				[2:0]       i_mem_funct3          ,
	input				[`XLEN-1:0] i_ext_imm_m           ,
	input				[3:0]       i_ctrl_mem_byte_sel_m
);

	wire				[`XLEN-1:0] o_dmem_intf_addr     ;
	wire			                o_dmem_intf_wen      ;
	wire				[`XLEN-1:0] o_dmem_intf_wr_data  ;
	wire				[3:0]       o_dmem_intf_byte_sel ;
	wire				[`XLEN-1:0] o_dmem_intf_rd_data  ;
	wire				[`XLEN-1:0] o_dmem_rd_data       ;


	riscv_dmem_interface
	u_riscv_dmem_interface(
		.o_dmem_intf_addr			(o_dmem_intf_addr      ) ,
		.o_dmem_intf_wen			(o_dmem_intf_wen       ) ,
		.o_dmem_intf_wr_data		(o_dmem_intf_wr_data   ) ,
		.o_dmem_intf_byte_sel		(o_dmem_intf_byte_sel  ) ,
		.o_dmem_intf_rd_data		(o_dmem_intf_rd_data   ) ,
		.i_dmem_intf_addr			(i_alu_result_m        ) ,
		.i_dmem_intf_wen			(i_mem_write_m         ) ,
		.i_dmem_intf_wr_data		(i_write_data_m        ) ,
		.i_dmem_intf_byte_sel		(i_ctrl_mem_byte_sel_m ) ,
		.i_dmem_intf_rd_data		(o_dmem_rd_data        ) ,
		.i_dmem_intf_func3			(i_mem_funct3          ) ,
		.i_clk						(i_clk                 )
	);

	riscv_dmem
	u_riscv_dmem(
		.o_dmem_data				(o_dmem_rd_data                       ) ,
		.i_dmem_data				(o_dmem_intf_wr_data                  ) ,
		.i_dmem_addr				(o_dmem_intf_addr[`DMEM_ADDR_BIT-1:2] ) ,
		.i_dmem_byte_sel			(o_dmem_intf_byte_sel                 ) ,
		.i_dmem_wr_en				(o_dmem_intf_wen                      ) ,
		.i_clk						(i_clk                                )
	);

	riscv_register_memory
	u_riscv_register_memory(
		.o_register_q_0				(o_reg_write_w			),		
        .o_register_q_1				(o_result_src_w			),
        .o_register_q_2				(o_alu_result_w			),
        .o_register_q_3				(o_read_data_w			),		
        .o_register_q_4				(o_rd_w					),
        .o_register_q_5				(o_pc_plus_4w			),
        .o_register_q_6				(o_ext_imm_w			),
        .i_register_d_0				(i_reg_write_m			),	
        .i_register_d_1				(i_result_src_m			),
        .i_register_d_2				(i_alu_result_m			),
        .i_register_d_3				(o_dmem_intf_rd_data	),
        .i_register_d_4				(i_rd_m					),
        .i_register_d_5				(i_pc_plus_4m			),
        .i_register_d_6				(i_ext_imm_m			),				
        .i_clk						(i_clk					),
        .i_rstn						(i_rstn					)
	);

	endmodule
