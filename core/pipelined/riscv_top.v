`ifndef		NOINC
`include	"../common/riscv_configs.v"
`include	"../pipelined/riscv_fetch.v"
`include	"../pipelined/riscv_decode.v"
`include	"../pipelined/riscv_execute.v"
`include	"../pipelined/riscv_memory.v"
`include	"../pipelined/riscv_hazard.v"
`include	"../common/riscv_register.v"
`endif

module	riscv_top
#(
	parameter	REGISTER_INIT	=	0
)
(
	output	[`XLEN-1:0]		o_instr_d,
	output	[`XLEN-1:0]		o_pc_d,
	output	[`XLEN-1:0]		o_alu_result_m ,
	output					o_mem_write_m,
	output	[3:0]			o_ctrl_mem_byte_sel_m,
	output	[`XLEN-1:0]		o_write_data_m,
	output	[`XLEN-1:0]		o_mem_read_data,

	input					i_clk,
	input					i_rstn
);

	wire	[`XLEN-1:0]		o_pc_plus_4d;
	wire	[`XLEN-1:0]		o_pc_target_e;
	wire	[1:0]				o_pc_src_e;
	wire					o_stall_f;
	wire					o_stall_d;
	wire					o_flush_d;
	wire	[`XLEN-1:0]		o_alu_data;
	riscv_fetch
	u_riscv_fetch(
		.o_instr_d     (o_instr_d		),
		.o_pc_d        (o_pc_d			),
		.o_pc_plus_4d  (o_pc_plus_4d	),
		.i_pc_target_e (o_pc_target_e	),
		.i_pc_src_e    (o_pc_src_e		),
		.i_stall_f     (o_stall_f		),
		.i_stall_d     (o_stall_d		),
		.i_flush_d     (o_flush_d		),
		.i_alu_result  (o_alu_data		),
		.i_clk			(i_clk			),
		.i_rstn			(i_rstn			)
	);



wire                o_reg_write_e         ;
wire	[1:0]       o_result_src_e        ;
wire                o_mem_write_e         ;
wire                o_jump_e              ;
wire                o_branch_e            ;
wire	[3:0]       o_alu_ctrl_e          ;
wire                o_alu_src_e_a         ;
wire                o_alu_src_e_b         ;
wire	[`XLEN-1:0] o_rd_1e               ;
wire	[`XLEN-1:0] o_rd_2e               ;
wire	[`XLEN-1:0] o_pc_e                ;
wire	[	   4:0] o_rs_1e               ;
wire	[	   4:0] o_rs_2e               ;
wire	[	   4:0] o_rd_e                ;
wire	[`XLEN-1:0] o_ext_imm_e           ;
wire	[`XLEN-1:0] o_pc_plus_4e          ;
wire	[`XLEN-1:0] o_result_w            ;
wire	[	   4:0] o_rd_w                ;
wire				o_reg_write_w         ;
wire                o_flush_e             ;
wire                o_zero_condition_e    ;
wire		[2:0]   o_funct3_e            ;
wire		[3:0]   o_ctrl_mem_byte_sel_e ;
wire                o_alu_jalr_e          ;
		

	riscv_decode
	u_riscv_decode(
		.o_reg_write_e         ( o_reg_write_e         ) ,
        .o_result_src_e        ( o_result_src_e        ) ,
        .o_mem_write_e         ( o_mem_write_e         ) ,
        .o_jump_e              ( o_jump_e              ) ,
        .o_branch_e            ( o_branch_e            ) ,
        .o_alu_ctrl_e          ( o_alu_ctrl_e          ) ,
        .o_alu_src_e_a         ( o_alu_src_e_a         ) ,
        .o_alu_src_e_b         ( o_alu_src_e_b         ) ,
        .o_rd_1e               ( o_rd_1e               ) ,
        .o_rd_2e               ( o_rd_2e               ) ,
        .o_pc_e                ( o_pc_e                ) ,
        .o_rs_1e               ( o_rs_1e               ) ,
        .o_rs_2e               ( o_rs_2e               ) ,
        .o_rd_e                ( o_rd_e                ) ,
        .o_ext_imm_e           ( o_ext_imm_e           ) ,
        .o_pc_plus_4e          ( o_pc_plus_4e          ) ,
        .i_instr_d             ( o_instr_d             ) ,
        .i_pc_d                ( o_pc_d                ) ,
        .i_pc_plus_4d          ( o_pc_plus_4d          ) ,
        .i_result_w            ( o_result_w            ) ,
        .i_rd_w                ( o_rd_w                ) ,
        .i_reg_write_w         ( o_reg_write_w         ) ,
		.i_clk                 ( i_clk                 ) ,
		.i_rstn                ( i_rstn                ) ,
		.o_flush_e             ( o_flush_e             ) ,
		.o_zero_condition_e    ( o_zero_condition_e    ) ,
		.o_funct3_e            ( o_funct3_e            ) ,
		.o_ctrl_mem_byte_sel_e ( o_ctrl_mem_byte_sel_e ) ,
		.o_alu_jalr_e          ( o_alu_jalr_e          )
		);

	assign		o_pc_src_e = (o_alu_jalr_e) ? 2'd3	 :
							 (o_jump_e | ( o_branch_e & o_zero_e)) ? 2'd1 : 2'd0;

wire					o_zero_e       ;
wire					o_reg_write_m  ;
wire	[1:0]			o_result_src_m ;
wire	[	   4:0]		o_rd_m         ;
wire	[`XLEN-1:0]		o_pc_plus_4m   ;
wire	[`XLEN-1:0]		o_ext_imm_m	   ;
wire	[	   1:0]		o_forward_ae   ;	
wire	[	   1:0]		o_forward_be   ;
wire	[2:0]			o_funct3_m;




		riscv_execute
		u_riscv_execute    (
	.o_pc_target_e         ( o_pc_target_e         ) ,
	.o_zero_e              ( o_zero_e              ) ,
	.o_reg_write_m         ( o_reg_write_m         ) ,
	.o_result_src_m        ( o_result_src_m        ) ,
	.o_mem_write_m         ( o_mem_write_m         ) ,
	.o_alu_result_m        ( o_alu_result_m        ) ,
	.o_write_data_m        ( o_write_data_m        ) ,
	.o_rd_m                ( o_rd_m                ) ,
	.o_pc_plus_4m          ( o_pc_plus_4m          ) ,
	.o_ext_imm_m           ( o_ext_imm_m           ) ,
	.o_alu_data            ( o_alu_data            ) ,
	.o_funct3_m            ( o_funct3_m            ) ,
	.o_ctrl_mem_byte_sel_m ( o_ctrl_mem_byte_sel_m ) ,

	.i_reg_write_e         ( o_reg_write_e         ) ,
	.i_rd_1e               ( o_rd_1e               ) ,
	.i_result_w            ( o_result_w            ) ,
	.i_forward_ae          ( o_forward_ae          ) ,
	.i_rd_2e               ( o_rd_2e               ) ,
	.i_forward_be          ( o_forward_be          ) ,
	.i_pc_e                ( o_pc_e                ) ,
	.i_ext_imm_e           ( o_ext_imm_e           ) ,
	.i_alu_ctrl_e          ( o_alu_ctrl_e          ) ,
	.i_alu_src_e_a         ( o_alu_src_e_a         ) ,
	.i_alu_src_e_b         ( o_alu_src_e_b         ) ,
	.i_result_src_e        ( o_result_src_e        ) ,
	.i_zero_condition      ( o_zero_condition_e    ) ,
	.i_funct3_e            ( o_funct3_e            ) ,
	.i_ctrl_mem_byte_sel_e ( o_ctrl_mem_byte_sel_e ) ,
	.i_mem_write_e         ( o_mem_write_e         ) ,
	.i_rd_e                ( o_rd_e                ) ,
	.i_pc_plus_4e          ( o_pc_plus_4e          ) ,
	.i_clk                 ( i_clk                 ) ,
	.i_rstn                ( i_rstn                )

);


	wire	[	   1:0]			o_result_src_w;
	wire	[`XLEN-1:0]			o_pc_plus_4w;
	wire	[`XLEN-1:0]			o_ext_imm_w;
	wire	[`XLEN-1:0]			o_read_data_w;
	wire	[`XLEN-1:0]			o_alu_result_w;



	riscv_memory
	u_riscv_memory(
	.o_reg_write_w			(o_reg_write_w         ) ,
	.o_result_src_w			(o_result_src_w        ) ,
	.o_alu_result_w			(o_alu_result_w        ) ,
	.o_read_data_w			(o_read_data_w         ) ,
	.o_rd_w					(o_rd_w                ) ,
	.o_pc_plus_4w			(o_pc_plus_4w          ) ,
	.o_ext_imm_w			(o_ext_imm_w           ) ,
	.o_mem_read_data		(o_mem_read_data       ) ,


	.i_reg_write_m			(o_reg_write_m         ) ,
	.i_result_src_m			(o_result_src_m        ) ,
	.i_mem_write_m			(o_mem_write_m         ) ,
	.i_alu_result_m			(o_alu_result_m        ) ,
	.i_write_data_m			(o_write_data_m        ) ,
	.i_rd_m					(o_rd_m                ) ,
	.i_pc_plus_4m			(o_pc_plus_4m          ) ,
	.i_clk					(i_clk                 ) ,
	.i_rstn					(i_rstn                ) ,
	.i_mem_funct3			(o_funct3_m            ) ,
	.i_ext_imm_m			(o_ext_imm_m           ) ,
	.i_ctrl_mem_byte_sel_m	(o_ctrl_mem_byte_sel_m )
);

	riscv_writeback
	u_riscv_writeback(
		.o_result_w			(o_result_w			),
		.i_alu_result_w		(o_alu_result_w		),
		.i_read_data_w		(o_read_data_w		),
		.i_pc_plus_4w		(o_pc_plus_4w		),
		.i_result_src_w		(o_result_src_w		),
		.i_ext_imm_w		(o_ext_imm_w		)
		);


	riscv_hazard
	u_riscv_hazard(
	.o_stall_f      (o_stall_f         ) ,
	.o_stall_d      (o_stall_d         ) ,
	.o_flush_d      (o_flush_d         ) ,
	.o_flush_e      (o_flush_e         ) ,
	.o_forward_ae   (o_forward_ae      ) ,
	.o_forward_be   (o_forward_be      ) ,
	.i_rs_1d        (o_instr_d[19:15]  ) ,
	.i_rs_2d        (o_instr_d[24:20]  ) ,
	.i_rd_e         (o_instr_d[11:7]   ) ,
	.i_rs_1e        (o_rs_1e           ) ,
	.i_rs_2e        (o_rs_2e           ) ,
	.i_pc_src_e     (o_pc_src_e[0]     ) ,
	.i_result_src_e (o_result_src_e[0] ) ,
	.i_rd_m         (o_rd_m            ) ,
	.i_reg_write_m  (o_reg_write_m     ) ,
	.i_rd_w         (o_rd_w            ) ,
	.i_reg_write_w	(o_reg_write_w     )
);

endmodule
		
		
			
