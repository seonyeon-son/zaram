`ifndef		NOINC
`include	"../common/riscv_adder.v"
`include	"../common/riscv_mux.v"
`include	"../common/riscv_configs.v"
`include	"../common/riscv_register_fetch.v"


module	riscv_fetch
(
	output			[`XLEN-1:0]		o_instr_d,
	output			[`XLEN-1:0]		o_pc_d,
	output reg		[`XLEN-1:0]		o_pc_plus_4d,
	input			[`XLEN-1:0]		i_pc_target_e,
	input							i_pc_src_e,
	input							i_stall_f,
	input							i_stall_d,
	input							i_flush_d
);

	wire			[`XLEN-1:0]		o_pcf_;
	wire			[`XLEN-1:0]		i_pcf;
	wire			[`XLEN-1:0]		o_pc_plus_4f;
	wire			[`XLEN-1:0]		o_imem_rd_data;

	
	assign	o_pcf = i_pcf;

	riscv_mux
	#(
		.N_MUX_IN				(2					)
	)
	u_riscv_mux(
		.o_mux_data				(o_pcf_				),
		.i_mux_concat_data		({i_pc_target_e, o_pc_plus_4f}),
		.i_mux_sel				(i_pc_src_e			)
	);

	riscv_register
	u_riscv_register(
		.o_register_q			(i_pcf				),
		.i_register_d			(o_pcf_				),
		.i_register_en			(i_stall_f			),
		.i_clk					(i_clk				),
		.i_rstn					(i_rstn				)
	);

	riscv_imem
	u_riscv_imem(
		.o_imem_data			(o_imem_rd_data		),
		.i_imem_addr			(i_pcf				)
	);

	riscv_adder
	u_riscv_adder(
		.o_adder_sum			(o_pc_plus_4f		),
		.i_adder_a				(i_pcf				),
		.i_adder_b				(32'd4				)
	);

	riscv_register_fetch
	u_risv_register_fetch(
		.o_register_q_0			(o_instr_d			),
		.o_register_q_1			(o_pc_d				),
		.o_register_q_2			(o_pc_plus_4d		),
		.i_register_q_0			(o_imem_rd_data		),
		.i_register_q_1			(i_pcf				),
		.i_register_q_2			(o_pc_plus_4f		),
		.i_register_en			(i_stall_d			),	
		.i_clk					(i_clk				),
		.i_rstn					(i_rstn				),
		.i_clr					(i_flush_d			)
	);

	endmodule
