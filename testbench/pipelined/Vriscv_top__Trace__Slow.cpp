// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vriscv_top__Syms.h"


//======================

void Vriscv_top::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, __VlSymsp);
    traceRegister(tfp->spTrace());
}

void Vriscv_top::traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vriscv_top__Syms* __restrict vlSymsp = static_cast<Vriscv_top__Syms*>(userp);
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    Vriscv_top::traceInitTop(vlSymsp, tracep);
    tracep->scopeEscape('.');
}

//======================


void Vriscv_top::traceInitTop(void* userp, VerilatedVcd* tracep) {
    Vriscv_top__Syms* __restrict vlSymsp = static_cast<Vriscv_top__Syms*>(userp);
    Vriscv_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceInitSub0(userp, tracep);
    }
}

void Vriscv_top::traceInitSub0(void* userp, VerilatedVcd* tracep) {
    Vriscv_top__Syms* __restrict vlSymsp = static_cast<Vriscv_top__Syms*>(userp);
    Vriscv_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBus(c+242,"o_instr_d", false,-1, 31,0);
        tracep->declBus(c+243,"o_pc_d", false,-1, 31,0);
        tracep->declBus(c+244,"o_alu_result_m", false,-1, 31,0);
        tracep->declBit(c+245,"o_mem_write_m", false,-1);
        tracep->declBus(c+246,"o_ctrl_mem_byte_sel_m", false,-1, 3,0);
        tracep->declBus(c+247,"o_write_data_m", false,-1, 31,0);
        tracep->declBus(c+248,"o_mem_read_data", false,-1, 31,0);
        tracep->declBit(c+249,"i_clk", false,-1);
        tracep->declBit(c+250,"i_rstn", false,-1);
        tracep->declBus(c+285,"riscv_top REGISTER_INIT", false,-1, 31,0);
        tracep->declBus(c+242,"riscv_top o_instr_d", false,-1, 31,0);
        tracep->declBus(c+243,"riscv_top o_pc_d", false,-1, 31,0);
        tracep->declBus(c+244,"riscv_top o_alu_result_m", false,-1, 31,0);
        tracep->declBit(c+245,"riscv_top o_mem_write_m", false,-1);
        tracep->declBus(c+246,"riscv_top o_ctrl_mem_byte_sel_m", false,-1, 3,0);
        tracep->declBus(c+247,"riscv_top o_write_data_m", false,-1, 31,0);
        tracep->declBus(c+248,"riscv_top o_mem_read_data", false,-1, 31,0);
        tracep->declBit(c+249,"riscv_top i_clk", false,-1);
        tracep->declBit(c+250,"riscv_top i_rstn", false,-1);
        tracep->declBus(c+167,"riscv_top o_pc_plus_4d", false,-1, 31,0);
        tracep->declBus(c+65,"riscv_top o_pc_target_e", false,-1, 31,0);
        tracep->declBus(c+168,"riscv_top o_pc_src_e", false,-1, 1,0);
        tracep->declBit(c+251,"riscv_top o_stall_f", false,-1);
        tracep->declBit(c+169,"riscv_top o_stall_d", false,-1);
        tracep->declBit(c+170,"riscv_top o_flush_d", false,-1);
        tracep->declBus(c+171,"riscv_top o_alu_data", false,-1, 31,0);
        tracep->declBit(c+172,"riscv_top o_reg_write_e", false,-1);
        tracep->declBus(c+66,"riscv_top o_result_src_e", false,-1, 1,0);
        tracep->declBit(c+67,"riscv_top o_mem_write_e", false,-1);
        tracep->declBit(c+68,"riscv_top o_jump_e", false,-1);
        tracep->declBit(c+69,"riscv_top o_branch_e", false,-1);
        tracep->declBus(c+70,"riscv_top o_alu_ctrl_e", false,-1, 3,0);
        tracep->declBit(c+71,"riscv_top o_alu_src_e_a", false,-1);
        tracep->declBit(c+72,"riscv_top o_alu_src_e_b", false,-1);
        tracep->declBus(c+73,"riscv_top o_rd_1e", false,-1, 31,0);
        tracep->declBus(c+74,"riscv_top o_rd_2e", false,-1, 31,0);
        tracep->declBus(c+75,"riscv_top o_pc_e", false,-1, 31,0);
        tracep->declBus(c+76,"riscv_top o_rs_1e", false,-1, 4,0);
        tracep->declBus(c+77,"riscv_top o_rs_2e", false,-1, 4,0);
        tracep->declBus(c+78,"riscv_top o_rd_e", false,-1, 4,0);
        tracep->declBus(c+79,"riscv_top o_ext_imm_e", false,-1, 31,0);
        tracep->declBus(c+173,"riscv_top o_pc_plus_4e", false,-1, 31,0);
        tracep->declBus(c+174,"riscv_top o_result_w", false,-1, 31,0);
        tracep->declBus(c+175,"riscv_top o_rd_w", false,-1, 4,0);
        tracep->declBit(c+176,"riscv_top o_reg_write_w", false,-1);
        tracep->declBit(c+177,"riscv_top o_flush_e", false,-1);
        tracep->declBit(c+80,"riscv_top o_zero_condition_e", false,-1);
        tracep->declBus(c+81,"riscv_top o_funct3_e", false,-1, 2,0);
        tracep->declBus(c+82,"riscv_top o_ctrl_mem_byte_sel_e", false,-1, 3,0);
        tracep->declBit(c+83,"riscv_top o_alu_jalr_e", false,-1);
        tracep->declBit(c+252,"riscv_top o_zero_e", false,-1);
        tracep->declBit(c+178,"riscv_top o_reg_write_m", false,-1);
        tracep->declBus(c+84,"riscv_top o_result_src_m", false,-1, 1,0);
        tracep->declBus(c+85,"riscv_top o_rd_m", false,-1, 4,0);
        tracep->declBus(c+179,"riscv_top o_pc_plus_4m", false,-1, 31,0);
        tracep->declBus(c+86,"riscv_top o_ext_imm_m", false,-1, 31,0);
        tracep->declBus(c+180,"riscv_top o_forward_ae", false,-1, 1,0);
        tracep->declBus(c+181,"riscv_top o_forward_be", false,-1, 1,0);
        tracep->declBus(c+87,"riscv_top o_funct3_m", false,-1, 2,0);
        tracep->declBus(c+88,"riscv_top o_result_src_w", false,-1, 1,0);
        tracep->declBus(c+89,"riscv_top o_pc_plus_4w", false,-1, 31,0);
        tracep->declBus(c+90,"riscv_top o_ext_imm_w", false,-1, 31,0);
        tracep->declBus(c+91,"riscv_top o_read_data_w", false,-1, 31,0);
        tracep->declBus(c+92,"riscv_top o_alu_result_w", false,-1, 31,0);
        tracep->declBus(c+242,"riscv_top u_riscv_fetch o_instr_d", false,-1, 31,0);
        tracep->declBus(c+243,"riscv_top u_riscv_fetch o_pc_d", false,-1, 31,0);
        tracep->declBus(c+167,"riscv_top u_riscv_fetch o_pc_plus_4d", false,-1, 31,0);
        tracep->declBus(c+65,"riscv_top u_riscv_fetch i_pc_target_e", false,-1, 31,0);
        tracep->declBus(c+168,"riscv_top u_riscv_fetch i_pc_src_e", false,-1, 1,0);
        tracep->declBit(c+251,"riscv_top u_riscv_fetch i_stall_f", false,-1);
        tracep->declBit(c+169,"riscv_top u_riscv_fetch i_stall_d", false,-1);
        tracep->declBit(c+170,"riscv_top u_riscv_fetch i_flush_d", false,-1);
        tracep->declBus(c+171,"riscv_top u_riscv_fetch i_alu_result", false,-1, 31,0);
        tracep->declBit(c+249,"riscv_top u_riscv_fetch i_clk", false,-1);
        tracep->declBit(c+250,"riscv_top u_riscv_fetch i_rstn", false,-1);
        tracep->declBus(c+93,"riscv_top u_riscv_fetch i_pcf", false,-1, 31,0);
        tracep->declBus(c+94,"riscv_top u_riscv_fetch o_pc_plus_4f", false,-1, 31,0);
        tracep->declBus(c+95,"riscv_top u_riscv_fetch o_imem_rd_data", false,-1, 31,0);
        tracep->declBus(c+182,"riscv_top u_riscv_fetch o_pcf_", false,-1, 31,0);
        tracep->declBus(c+286,"riscv_top u_riscv_fetch u_riscv_mux N_MUX_IN", false,-1, 31,0);
        tracep->declBus(c+182,"riscv_top u_riscv_fetch u_riscv_mux o_mux_data", false,-1, 31,0);
        tracep->declArray(c+183,"riscv_top u_riscv_fetch u_riscv_mux i_mux_concat_data", false,-1, 127,0);
        tracep->declBus(c+168,"riscv_top u_riscv_fetch u_riscv_mux i_mux_sel", false,-1, 1,0);
        {int i; for (i=0; i<4; i++) {
                tracep->declBus(c+187+i*1,"riscv_top u_riscv_fetch u_riscv_mux mux_input_arr", true,(i+0), 31,0);}}
        tracep->declBus(c+285,"riscv_top u_riscv_fetch u_riscv_register REGISTER_INIT", false,-1, 31,0);
        tracep->declBus(c+93,"riscv_top u_riscv_fetch u_riscv_register o_register_q", false,-1, 31,0);
        tracep->declBus(c+182,"riscv_top u_riscv_fetch u_riscv_register i_register_d", false,-1, 31,0);
        tracep->declBit(c+251,"riscv_top u_riscv_fetch u_riscv_register i_register_en", false,-1);
        tracep->declBit(c+249,"riscv_top u_riscv_fetch u_riscv_register i_clk", false,-1);
        tracep->declBit(c+250,"riscv_top u_riscv_fetch u_riscv_register i_rstn", false,-1);
        tracep->declBus(c+95,"riscv_top u_riscv_fetch u_riscv_imem o_imem_data", false,-1, 31,0);
        tracep->declBus(c+96,"riscv_top u_riscv_fetch u_riscv_imem i_imem_addr", false,-1, 13,0);
        tracep->declArray(c+1,"riscv_top u_riscv_fetch u_riscv_imem FILE_TEXT_MIF", false,-1, 1023,0);
        tracep->declBus(c+94,"riscv_top u_riscv_fetch u_riscv_adder o_adder_sum", false,-1, 31,0);
        tracep->declBus(c+93,"riscv_top u_riscv_fetch u_riscv_adder i_adder_a", false,-1, 31,0);
        tracep->declBus(c+287,"riscv_top u_riscv_fetch u_riscv_adder i_adder_b", false,-1, 31,0);
        tracep->declBus(c+285,"riscv_top u_riscv_fetch u_risv_register_fetch REGISTER_INIT", false,-1, 31,0);
        tracep->declBus(c+242,"riscv_top u_riscv_fetch u_risv_register_fetch o_register_q_0", false,-1, 31,0);
        tracep->declBus(c+243,"riscv_top u_riscv_fetch u_risv_register_fetch o_register_q_1", false,-1, 31,0);
        tracep->declBus(c+167,"riscv_top u_riscv_fetch u_risv_register_fetch o_register_q_2", false,-1, 31,0);
        tracep->declBus(c+95,"riscv_top u_riscv_fetch u_risv_register_fetch i_register_d_0", false,-1, 31,0);
        tracep->declBus(c+93,"riscv_top u_riscv_fetch u_risv_register_fetch i_register_d_1", false,-1, 31,0);
        tracep->declBus(c+94,"riscv_top u_riscv_fetch u_risv_register_fetch i_register_d_2", false,-1, 31,0);
        tracep->declBit(c+169,"riscv_top u_riscv_fetch u_risv_register_fetch i_register_en", false,-1);
        tracep->declBit(c+249,"riscv_top u_riscv_fetch u_risv_register_fetch i_clk", false,-1);
        tracep->declBit(c+250,"riscv_top u_riscv_fetch u_risv_register_fetch i_rstn", false,-1);
        tracep->declBit(c+170,"riscv_top u_riscv_fetch u_risv_register_fetch i_clr", false,-1);
        tracep->declBit(c+172,"riscv_top u_riscv_decode o_reg_write_e", false,-1);
        tracep->declBus(c+66,"riscv_top u_riscv_decode o_result_src_e", false,-1, 1,0);
        tracep->declBit(c+67,"riscv_top u_riscv_decode o_mem_write_e", false,-1);
        tracep->declBit(c+68,"riscv_top u_riscv_decode o_jump_e", false,-1);
        tracep->declBit(c+69,"riscv_top u_riscv_decode o_branch_e", false,-1);
        tracep->declBus(c+70,"riscv_top u_riscv_decode o_alu_ctrl_e", false,-1, 3,0);
        tracep->declBit(c+71,"riscv_top u_riscv_decode o_alu_src_e_a", false,-1);
        tracep->declBit(c+72,"riscv_top u_riscv_decode o_alu_src_e_b", false,-1);
        tracep->declBus(c+73,"riscv_top u_riscv_decode o_rd_1e", false,-1, 31,0);
        tracep->declBus(c+74,"riscv_top u_riscv_decode o_rd_2e", false,-1, 31,0);
        tracep->declBus(c+75,"riscv_top u_riscv_decode o_pc_e", false,-1, 31,0);
        tracep->declBus(c+76,"riscv_top u_riscv_decode o_rs_1e", false,-1, 4,0);
        tracep->declBus(c+77,"riscv_top u_riscv_decode o_rs_2e", false,-1, 4,0);
        tracep->declBus(c+78,"riscv_top u_riscv_decode o_rd_e", false,-1, 4,0);
        tracep->declBus(c+79,"riscv_top u_riscv_decode o_ext_imm_e", false,-1, 31,0);
        tracep->declBus(c+173,"riscv_top u_riscv_decode o_pc_plus_4e", false,-1, 31,0);
        tracep->declBit(c+83,"riscv_top u_riscv_decode o_alu_jalr_e", false,-1);
        tracep->declBit(c+80,"riscv_top u_riscv_decode o_zero_condition_e", false,-1);
        tracep->declBus(c+81,"riscv_top u_riscv_decode o_funct3_e", false,-1, 2,0);
        tracep->declBus(c+82,"riscv_top u_riscv_decode o_ctrl_mem_byte_sel_e", false,-1, 3,0);
        tracep->declBus(c+242,"riscv_top u_riscv_decode i_instr_d", false,-1, 31,0);
        tracep->declBus(c+243,"riscv_top u_riscv_decode i_pc_d", false,-1, 31,0);
        tracep->declBus(c+167,"riscv_top u_riscv_decode i_pc_plus_4d", false,-1, 31,0);
        tracep->declBus(c+174,"riscv_top u_riscv_decode i_result_w", false,-1, 31,0);
        tracep->declBus(c+175,"riscv_top u_riscv_decode i_rd_w", false,-1, 4,0);
        tracep->declBit(c+176,"riscv_top u_riscv_decode i_reg_write_w", false,-1);
        tracep->declBit(c+249,"riscv_top u_riscv_decode i_clk", false,-1);
        tracep->declBit(c+177,"riscv_top u_riscv_decode o_flush_e", false,-1);
        tracep->declBit(c+250,"riscv_top u_riscv_decode i_rstn", false,-1);
        tracep->declBus(c+191,"riscv_top u_riscv_decode o_imm_src_d", false,-1, 2,0);
        tracep->declBus(c+192,"riscv_top u_riscv_decode o_result_src_d", false,-1, 1,0);
        tracep->declBit(c+253,"riscv_top u_riscv_decode o_alu_src_d_a", false,-1);
        tracep->declBit(c+193,"riscv_top u_riscv_decode o_alu_src_d_b", false,-1);
        tracep->declBit(c+254,"riscv_top u_riscv_decode o_reg_write_d", false,-1);
        tracep->declBit(c+255,"riscv_top u_riscv_decode o_mem_write_d", false,-1);
        tracep->declBus(c+256,"riscv_top u_riscv_decode o_rd_1_data", false,-1, 31,0);
        tracep->declBus(c+257,"riscv_top u_riscv_decode o_rd_2_data", false,-1, 31,0);
        tracep->declBus(c+258,"riscv_top u_riscv_decode o_ctrl_mem_byte_sel_d", false,-1, 3,0);
        tracep->declBus(c+194,"riscv_top u_riscv_decode o_alu_ctrl_d", false,-1, 3,0);
        tracep->declBit(c+259,"riscv_top u_riscv_decode o_alu_jalr_d", false,-1);
        tracep->declBit(c+260,"riscv_top u_riscv_decode o_zero_condition_d", false,-1);
        tracep->declBit(c+261,"riscv_top u_riscv_decode o_jump_d", false,-1);
        tracep->declBit(c+262,"riscv_top u_riscv_decode o_branch_d", false,-1);
        tracep->declBus(c+195,"riscv_top u_riscv_decode o_ext_imm_d", false,-1, 31,0);
        tracep->declBus(c+191,"riscv_top u_riscv_decode u_riscv_ctrl_i o_ctrl_src_imm", false,-1, 2,0);
        tracep->declBus(c+192,"riscv_top u_riscv_decode u_riscv_ctrl_i o_ctrl_src_rd", false,-1, 1,0);
        tracep->declBit(c+253,"riscv_top u_riscv_decode u_riscv_ctrl_i o_ctrl_src_alu_a", false,-1);
        tracep->declBit(c+193,"riscv_top u_riscv_decode u_riscv_ctrl_i o_ctrl_src_alu_b", false,-1);
        tracep->declBit(c+254,"riscv_top u_riscv_decode u_riscv_ctrl_i o_ctrl_reg_wr_en", false,-1);
        tracep->declBit(c+255,"riscv_top u_riscv_decode u_riscv_ctrl_i o_ctrl_mem_wr_en", false,-1);
        tracep->declBus(c+258,"riscv_top u_riscv_decode u_riscv_ctrl_i o_ctrl_mem_byte_sel", false,-1, 3,0);
        tracep->declBus(c+194,"riscv_top u_riscv_decode u_riscv_ctrl_i o_ctrl_alu_ctrl", false,-1, 3,0);
        tracep->declBit(c+259,"riscv_top u_riscv_decode u_riscv_ctrl_i o_jalr_d", false,-1);
        tracep->declBit(c+261,"riscv_top u_riscv_decode u_riscv_ctrl_i o_jump_d", false,-1);
        tracep->declBit(c+262,"riscv_top u_riscv_decode u_riscv_ctrl_i o_branch_d", false,-1);
        tracep->declBit(c+260,"riscv_top u_riscv_decode u_riscv_ctrl_i o_zero_condition", false,-1);
        tracep->declBus(c+263,"riscv_top u_riscv_decode u_riscv_ctrl_i i_ctrl_opcode", false,-1, 6,0);
        tracep->declBus(c+264,"riscv_top u_riscv_decode u_riscv_ctrl_i i_ctrl_funct3", false,-1, 2,0);
        tracep->declBit(c+265,"riscv_top u_riscv_decode u_riscv_ctrl_i i_ctrl_funct7_5b", false,-1);
        tracep->declArray(c+196,"riscv_top u_riscv_decode u_riscv_ctrl_i DEBUG_INSTR", false,-1, 255,0);
        tracep->declBus(c+256,"riscv_top u_riscv_decode u_riscv_regfile o_regfile_rs1_data", false,-1, 31,0);
        tracep->declBus(c+257,"riscv_top u_riscv_decode u_riscv_regfile o_regfile_rs2_data", false,-1, 31,0);
        tracep->declBus(c+266,"riscv_top u_riscv_decode u_riscv_regfile i_regfile_rs1_addr", false,-1, 4,0);
        tracep->declBus(c+267,"riscv_top u_riscv_decode u_riscv_regfile i_regfile_rs2_addr", false,-1, 4,0);
        tracep->declBus(c+174,"riscv_top u_riscv_decode u_riscv_regfile i_regfile_rd_data", false,-1, 31,0);
        tracep->declBus(c+175,"riscv_top u_riscv_decode u_riscv_regfile i_regfile_rd_addr", false,-1, 4,0);
        tracep->declBit(c+176,"riscv_top u_riscv_decode u_riscv_regfile i_regfile_rd_wen", false,-1);
        tracep->declBit(c+249,"riscv_top u_riscv_decode u_riscv_regfile i_clk", false,-1);
        {int i; for (i=0; i<32; i++) {
                tracep->declBus(c+135+i*1,"riscv_top u_riscv_decode u_riscv_regfile registers", true,(i+0), 31,0);}}
        tracep->declBus(c+195,"riscv_top u_riscv_decode u_riscv_immext o_imm_ext", false,-1, 31,0);
        tracep->declBus(c+242,"riscv_top u_riscv_decode u_riscv_immext i_imm_instr", false,-1, 31,0);
        tracep->declBus(c+191,"riscv_top u_riscv_decode u_riscv_immext i_imm_src", false,-1, 2,0);
        tracep->declBus(c+285,"riscv_top u_riscv_decode u_riscv_register_decode REGISTER_INIT", false,-1, 31,0);
        tracep->declBus(c+204,"riscv_top u_riscv_decode u_riscv_register_decode o_register_q_0", false,-1, 31,0);
        tracep->declBus(c+97,"riscv_top u_riscv_decode u_riscv_register_decode o_register_q_1", false,-1, 31,0);
        tracep->declBus(c+98,"riscv_top u_riscv_decode u_riscv_register_decode o_register_q_2", false,-1, 31,0);
        tracep->declBus(c+99,"riscv_top u_riscv_decode u_riscv_register_decode o_register_q_3", false,-1, 31,0);
        tracep->declBus(c+100,"riscv_top u_riscv_decode u_riscv_register_decode o_register_q_4", false,-1, 31,0);
        tracep->declBus(c+101,"riscv_top u_riscv_decode u_riscv_register_decode o_register_q_5", false,-1, 31,0);
        tracep->declBus(c+102,"riscv_top u_riscv_decode u_riscv_register_decode o_register_q_6", false,-1, 31,0);
        tracep->declBus(c+73,"riscv_top u_riscv_decode u_riscv_register_decode o_register_q_7", false,-1, 31,0);
        tracep->declBus(c+74,"riscv_top u_riscv_decode u_riscv_register_decode o_register_q_8", false,-1, 31,0);
        tracep->declBus(c+75,"riscv_top u_riscv_decode u_riscv_register_decode o_register_q_9", false,-1, 31,0);
        tracep->declBus(c+103,"riscv_top u_riscv_decode u_riscv_register_decode o_register_q_10", false,-1, 31,0);
        tracep->declBus(c+104,"riscv_top u_riscv_decode u_riscv_register_decode o_register_q_11", false,-1, 31,0);
        tracep->declBus(c+105,"riscv_top u_riscv_decode u_riscv_register_decode o_register_q_12", false,-1, 31,0);
        tracep->declBus(c+79,"riscv_top u_riscv_decode u_riscv_register_decode o_register_q_13", false,-1, 31,0);
        tracep->declBus(c+173,"riscv_top u_riscv_decode u_riscv_register_decode o_register_q_14", false,-1, 31,0);
        tracep->declBus(c+106,"riscv_top u_riscv_decode u_riscv_register_decode o_register_q_15", false,-1, 31,0);
        tracep->declBus(c+107,"riscv_top u_riscv_decode u_riscv_register_decode o_register_q_16", false,-1, 31,0);
        tracep->declBus(c+108,"riscv_top u_riscv_decode u_riscv_register_decode o_register_q_17", false,-1, 31,0);
        tracep->declBus(c+109,"riscv_top u_riscv_decode u_riscv_register_decode o_register_q_18", false,-1, 31,0);
        tracep->declBus(c+110,"riscv_top u_riscv_decode u_riscv_register_decode o_register_q_19", false,-1, 31,0);
        tracep->declBus(c+268,"riscv_top u_riscv_decode u_riscv_register_decode i_register_d_0", false,-1, 31,0);
        tracep->declBus(c+205,"riscv_top u_riscv_decode u_riscv_register_decode i_register_d_1", false,-1, 31,0);
        tracep->declBus(c+269,"riscv_top u_riscv_decode u_riscv_register_decode i_register_d_2", false,-1, 31,0);
        tracep->declBus(c+270,"riscv_top u_riscv_decode u_riscv_register_decode i_register_d_3", false,-1, 31,0);
        tracep->declBus(c+271,"riscv_top u_riscv_decode u_riscv_register_decode i_register_d_4", false,-1, 31,0);
        tracep->declBus(c+206,"riscv_top u_riscv_decode u_riscv_register_decode i_register_d_5", false,-1, 31,0);
        tracep->declBus(c+272,"riscv_top u_riscv_decode u_riscv_register_decode i_register_d_6", false,-1, 31,0);
        tracep->declBus(c+256,"riscv_top u_riscv_decode u_riscv_register_decode i_register_d_7", false,-1, 31,0);
        tracep->declBus(c+257,"riscv_top u_riscv_decode u_riscv_register_decode i_register_d_8", false,-1, 31,0);
        tracep->declBus(c+243,"riscv_top u_riscv_decode u_riscv_register_decode i_register_d_9", false,-1, 31,0);
        tracep->declBus(c+273,"riscv_top u_riscv_decode u_riscv_register_decode i_register_d_10", false,-1, 31,0);
        tracep->declBus(c+274,"riscv_top u_riscv_decode u_riscv_register_decode i_register_d_11", false,-1, 31,0);
        tracep->declBus(c+275,"riscv_top u_riscv_decode u_riscv_register_decode i_register_d_12", false,-1, 31,0);
        tracep->declBus(c+195,"riscv_top u_riscv_decode u_riscv_register_decode i_register_d_13", false,-1, 31,0);
        tracep->declBus(c+167,"riscv_top u_riscv_decode u_riscv_register_decode i_register_d_14", false,-1, 31,0);
        tracep->declBus(c+207,"riscv_top u_riscv_decode u_riscv_register_decode i_register_d_15", false,-1, 31,0);
        tracep->declBus(c+276,"riscv_top u_riscv_decode u_riscv_register_decode i_register_d_16", false,-1, 31,0);
        tracep->declBus(c+277,"riscv_top u_riscv_decode u_riscv_register_decode i_register_d_17", false,-1, 31,0);
        tracep->declBus(c+278,"riscv_top u_riscv_decode u_riscv_register_decode i_register_d_18", false,-1, 31,0);
        tracep->declBus(c+279,"riscv_top u_riscv_decode u_riscv_register_decode i_register_d_19", false,-1, 31,0);
        tracep->declBit(c+249,"riscv_top u_riscv_decode u_riscv_register_decode i_clk", false,-1);
        tracep->declBit(c+250,"riscv_top u_riscv_decode u_riscv_register_decode i_rstn", false,-1);
        tracep->declBit(c+177,"riscv_top u_riscv_decode u_riscv_register_decode i_clr", false,-1);
        tracep->declBus(c+65,"riscv_top u_riscv_execute o_pc_target_e", false,-1, 31,0);
        tracep->declBit(c+252,"riscv_top u_riscv_execute o_zero_e", false,-1);
        tracep->declBit(c+178,"riscv_top u_riscv_execute o_reg_write_m", false,-1);
        tracep->declBus(c+84,"riscv_top u_riscv_execute o_result_src_m", false,-1, 1,0);
        tracep->declBit(c+245,"riscv_top u_riscv_execute o_mem_write_m", false,-1);
        tracep->declBus(c+244,"riscv_top u_riscv_execute o_alu_result_m", false,-1, 31,0);
        tracep->declBus(c+247,"riscv_top u_riscv_execute o_write_data_m", false,-1, 31,0);
        tracep->declBus(c+85,"riscv_top u_riscv_execute o_rd_m", false,-1, 4,0);
        tracep->declBus(c+179,"riscv_top u_riscv_execute o_pc_plus_4m", false,-1, 31,0);
        tracep->declBus(c+86,"riscv_top u_riscv_execute o_ext_imm_m", false,-1, 31,0);
        tracep->declBus(c+171,"riscv_top u_riscv_execute o_alu_data", false,-1, 31,0);
        tracep->declBus(c+87,"riscv_top u_riscv_execute o_funct3_m", false,-1, 2,0);
        tracep->declBus(c+246,"riscv_top u_riscv_execute o_ctrl_mem_byte_sel_m", false,-1, 3,0);
        tracep->declBus(c+73,"riscv_top u_riscv_execute i_rd_1e", false,-1, 31,0);
        tracep->declBus(c+174,"riscv_top u_riscv_execute i_result_w", false,-1, 31,0);
        tracep->declBus(c+180,"riscv_top u_riscv_execute i_forward_ae", false,-1, 1,0);
        tracep->declBus(c+74,"riscv_top u_riscv_execute i_rd_2e", false,-1, 31,0);
        tracep->declBus(c+181,"riscv_top u_riscv_execute i_forward_be", false,-1, 1,0);
        tracep->declBus(c+75,"riscv_top u_riscv_execute i_pc_e", false,-1, 31,0);
        tracep->declBus(c+79,"riscv_top u_riscv_execute i_ext_imm_e", false,-1, 31,0);
        tracep->declBus(c+70,"riscv_top u_riscv_execute i_alu_ctrl_e", false,-1, 3,0);
        tracep->declBit(c+71,"riscv_top u_riscv_execute i_alu_src_e_a", false,-1);
        tracep->declBit(c+72,"riscv_top u_riscv_execute i_alu_src_e_b", false,-1);
        tracep->declBit(c+172,"riscv_top u_riscv_execute i_reg_write_e", false,-1);
        tracep->declBus(c+66,"riscv_top u_riscv_execute i_result_src_e", false,-1, 1,0);
        tracep->declBit(c+80,"riscv_top u_riscv_execute i_zero_condition", false,-1);
        tracep->declBus(c+81,"riscv_top u_riscv_execute i_funct3_e", false,-1, 2,0);
        tracep->declBus(c+82,"riscv_top u_riscv_execute i_ctrl_mem_byte_sel_e", false,-1, 3,0);
        tracep->declBit(c+67,"riscv_top u_riscv_execute i_mem_write_e", false,-1);
        tracep->declBus(c+78,"riscv_top u_riscv_execute i_rd_e", false,-1, 4,0);
        tracep->declBus(c+173,"riscv_top u_riscv_execute i_pc_plus_4e", false,-1, 31,0);
        tracep->declBit(c+249,"riscv_top u_riscv_execute i_clk", false,-1);
        tracep->declBit(c+250,"riscv_top u_riscv_execute i_rstn", false,-1);
        tracep->declBus(c+208,"riscv_top u_riscv_execute o_src_ae", false,-1, 31,0);
        tracep->declBus(c+209,"riscv_top u_riscv_execute o_write_data_e", false,-1, 31,0);
        tracep->declBus(c+210,"riscv_top u_riscv_execute o_src_be", false,-1, 31,0);
        tracep->declBus(c+211,"riscv_top u_riscv_execute o_mux_src_a", false,-1, 31,0);
        tracep->declBus(c+288,"riscv_top u_riscv_execute u_mux_execute_0 N_MUX_IN", false,-1, 31,0);
        tracep->declBus(c+211,"riscv_top u_riscv_execute u_mux_execute_0 o_mux_data", false,-1, 31,0);
        tracep->declArray(c+212,"riscv_top u_riscv_execute u_mux_execute_0 i_mux_concat_data", false,-1, 95,0);
        tracep->declBus(c+180,"riscv_top u_riscv_execute u_mux_execute_0 i_mux_sel", false,-1, 1,0);
        {int i; for (i=0; i<3; i++) {
                tracep->declBus(c+215+i*1,"riscv_top u_riscv_execute u_mux_execute_0 mux_input_arr", true,(i+0), 31,0);}}
        tracep->declBus(c+289,"riscv_top u_riscv_execute u_riscv_mux_1 N_MUX_IN", false,-1, 31,0);
        tracep->declBus(c+208,"riscv_top u_riscv_execute u_riscv_mux_1 o_mux_data", false,-1, 31,0);
        tracep->declQuad(c+218,"riscv_top u_riscv_execute u_riscv_mux_1 i_mux_concat_data", false,-1, 63,0);
        tracep->declBus(c+71,"riscv_top u_riscv_execute u_riscv_mux_1 i_mux_sel", false,-1, 0,0);
        {int i; for (i=0; i<2; i++) {
                tracep->declBus(c+220+i*1,"riscv_top u_riscv_execute u_riscv_mux_1 mux_input_arr", true,(i+0), 31,0);}}
        tracep->declBus(c+288,"riscv_top u_riscv_execute u_mux_execute_2 N_MUX_IN", false,-1, 31,0);
        tracep->declBus(c+209,"riscv_top u_riscv_execute u_mux_execute_2 o_mux_data", false,-1, 31,0);
        tracep->declArray(c+222,"riscv_top u_riscv_execute u_mux_execute_2 i_mux_concat_data", false,-1, 95,0);
        tracep->declBus(c+181,"riscv_top u_riscv_execute u_mux_execute_2 i_mux_sel", false,-1, 1,0);
        {int i; for (i=0; i<3; i++) {
                tracep->declBus(c+225+i*1,"riscv_top u_riscv_execute u_mux_execute_2 mux_input_arr", true,(i+0), 31,0);}}
        tracep->declBus(c+289,"riscv_top u_riscv_execute u_riscv_mux_3 N_MUX_IN", false,-1, 31,0);
        tracep->declBus(c+210,"riscv_top u_riscv_execute u_riscv_mux_3 o_mux_data", false,-1, 31,0);
        tracep->declQuad(c+228,"riscv_top u_riscv_execute u_riscv_mux_3 i_mux_concat_data", false,-1, 63,0);
        tracep->declBus(c+72,"riscv_top u_riscv_execute u_riscv_mux_3 i_mux_sel", false,-1, 0,0);
        {int i; for (i=0; i<2; i++) {
                tracep->declBus(c+230+i*1,"riscv_top u_riscv_execute u_riscv_mux_3 mux_input_arr", true,(i+0), 31,0);}}
        tracep->declBus(c+65,"riscv_top u_riscv_execute u_adder_execute o_adder_sum", false,-1, 31,0);
        tracep->declBus(c+75,"riscv_top u_riscv_execute u_adder_execute i_adder_a", false,-1, 31,0);
        tracep->declBus(c+79,"riscv_top u_riscv_execute u_adder_execute i_adder_b", false,-1, 31,0);
        tracep->declBus(c+171,"riscv_top u_riscv_execute u_riscv_alu o_alu_result", false,-1, 31,0);
        tracep->declBit(c+252,"riscv_top u_riscv_execute u_riscv_alu o_alu_zero", false,-1);
        tracep->declBus(c+208,"riscv_top u_riscv_execute u_riscv_alu i_alu_a", false,-1, 31,0);
        tracep->declBus(c+210,"riscv_top u_riscv_execute u_riscv_alu i_alu_b", false,-1, 31,0);
        tracep->declBus(c+70,"riscv_top u_riscv_execute u_riscv_alu i_alu_ctrl", false,-1, 3,0);
        tracep->declBit(c+80,"riscv_top u_riscv_execute u_riscv_alu i_zero_condition", false,-1);
        tracep->declBit(c+232,"riscv_top u_riscv_execute u_riscv_alu alu_zero", false,-1);
        tracep->declQuad(c+111,"riscv_top u_riscv_execute u_riscv_alu DEBUG_ALU_OP", false,-1, 63,0);
        tracep->declBus(c+285,"riscv_top u_riscv_execute u_riscv_register_execute REGISTER_INIT", false,-1, 31,0);
        tracep->declBus(c+233,"riscv_top u_riscv_execute u_riscv_register_execute o_register_q_0", false,-1, 31,0);
        tracep->declBus(c+113,"riscv_top u_riscv_execute u_riscv_register_execute o_register_q_1", false,-1, 31,0);
        tracep->declBus(c+114,"riscv_top u_riscv_execute u_riscv_register_execute o_register_q_2", false,-1, 31,0);
        tracep->declBus(c+244,"riscv_top u_riscv_execute u_riscv_register_execute o_register_q_3", false,-1, 31,0);
        tracep->declBus(c+247,"riscv_top u_riscv_execute u_riscv_register_execute o_register_q_4", false,-1, 31,0);
        tracep->declBus(c+115,"riscv_top u_riscv_execute u_riscv_register_execute o_register_q_5", false,-1, 31,0);
        tracep->declBus(c+179,"riscv_top u_riscv_execute u_riscv_register_execute o_register_q_6", false,-1, 31,0);
        tracep->declBus(c+86,"riscv_top u_riscv_execute u_riscv_register_execute o_register_q_7", false,-1, 31,0);
        tracep->declBus(c+116,"riscv_top u_riscv_execute u_riscv_register_execute o_register_q_8", false,-1, 31,0);
        tracep->declBus(c+117,"riscv_top u_riscv_execute u_riscv_register_execute o_register_q_9", false,-1, 31,0);
        tracep->declBus(c+234,"riscv_top u_riscv_execute u_riscv_register_execute i_register_d_0", false,-1, 31,0);
        tracep->declBus(c+118,"riscv_top u_riscv_execute u_riscv_register_execute i_register_d_1", false,-1, 31,0);
        tracep->declBus(c+119,"riscv_top u_riscv_execute u_riscv_register_execute i_register_d_2", false,-1, 31,0);
        tracep->declBus(c+171,"riscv_top u_riscv_execute u_riscv_register_execute i_register_d_3", false,-1, 31,0);
        tracep->declBus(c+209,"riscv_top u_riscv_execute u_riscv_register_execute i_register_d_4", false,-1, 31,0);
        tracep->declBus(c+120,"riscv_top u_riscv_execute u_riscv_register_execute i_register_d_5", false,-1, 31,0);
        tracep->declBus(c+173,"riscv_top u_riscv_execute u_riscv_register_execute i_register_d_6", false,-1, 31,0);
        tracep->declBus(c+79,"riscv_top u_riscv_execute u_riscv_register_execute i_register_d_7", false,-1, 31,0);
        tracep->declBus(c+121,"riscv_top u_riscv_execute u_riscv_register_execute i_register_d_8", false,-1, 31,0);
        tracep->declBus(c+122,"riscv_top u_riscv_execute u_riscv_register_execute i_register_d_9", false,-1, 31,0);
        tracep->declBit(c+249,"riscv_top u_riscv_execute u_riscv_register_execute i_clk", false,-1);
        tracep->declBit(c+250,"riscv_top u_riscv_execute u_riscv_register_execute i_rstn", false,-1);
        tracep->declBit(c+176,"riscv_top u_riscv_memory o_reg_write_w", false,-1);
        tracep->declBus(c+88,"riscv_top u_riscv_memory o_result_src_w", false,-1, 1,0);
        tracep->declBus(c+92,"riscv_top u_riscv_memory o_alu_result_w", false,-1, 31,0);
        tracep->declBus(c+91,"riscv_top u_riscv_memory o_read_data_w", false,-1, 31,0);
        tracep->declBus(c+175,"riscv_top u_riscv_memory o_rd_w", false,-1, 4,0);
        tracep->declBus(c+89,"riscv_top u_riscv_memory o_pc_plus_4w", false,-1, 31,0);
        tracep->declBus(c+90,"riscv_top u_riscv_memory o_ext_imm_w", false,-1, 31,0);
        tracep->declBus(c+248,"riscv_top u_riscv_memory o_mem_read_data", false,-1, 31,0);
        tracep->declBit(c+178,"riscv_top u_riscv_memory i_reg_write_m", false,-1);
        tracep->declBus(c+84,"riscv_top u_riscv_memory i_result_src_m", false,-1, 1,0);
        tracep->declBit(c+245,"riscv_top u_riscv_memory i_mem_write_m", false,-1);
        tracep->declBus(c+244,"riscv_top u_riscv_memory i_alu_result_m", false,-1, 31,0);
        tracep->declBus(c+247,"riscv_top u_riscv_memory i_write_data_m", false,-1, 31,0);
        tracep->declBus(c+85,"riscv_top u_riscv_memory i_rd_m", false,-1, 4,0);
        tracep->declBus(c+179,"riscv_top u_riscv_memory i_pc_plus_4m", false,-1, 31,0);
        tracep->declBit(c+249,"riscv_top u_riscv_memory i_clk", false,-1);
        tracep->declBit(c+250,"riscv_top u_riscv_memory i_rstn", false,-1);
        tracep->declBus(c+87,"riscv_top u_riscv_memory i_mem_funct3", false,-1, 2,0);
        tracep->declBus(c+86,"riscv_top u_riscv_memory i_ext_imm_m", false,-1, 31,0);
        tracep->declBus(c+246,"riscv_top u_riscv_memory i_ctrl_mem_byte_sel_m", false,-1, 3,0);
        tracep->declBus(c+244,"riscv_top u_riscv_memory o_dmem_intf_addr", false,-1, 31,0);
        tracep->declBit(c+245,"riscv_top u_riscv_memory o_dmem_intf_wen", false,-1);
        tracep->declBus(c+235,"riscv_top u_riscv_memory o_dmem_intf_wr_data", false,-1, 31,0);
        tracep->declBus(c+236,"riscv_top u_riscv_memory o_dmem_intf_byte_sel", false,-1, 3,0);
        tracep->declBus(c+280,"riscv_top u_riscv_memory o_dmem_intf_rd_data", false,-1, 31,0);
        tracep->declBus(c+281,"riscv_top u_riscv_memory o_dmem_rd_data", false,-1, 31,0);
        tracep->declBus(c+281,"riscv_top u_riscv_memory u_riscv_dmem o_dmem_data", false,-1, 31,0);
        tracep->declBus(c+235,"riscv_top u_riscv_memory u_riscv_dmem i_dmem_data", false,-1, 31,0);
        tracep->declBus(c+282,"riscv_top u_riscv_memory u_riscv_dmem i_dmem_addr", false,-1, 13,0);
        tracep->declBus(c+236,"riscv_top u_riscv_memory u_riscv_dmem i_dmem_byte_sel", false,-1, 3,0);
        tracep->declBit(c+245,"riscv_top u_riscv_memory u_riscv_dmem i_dmem_wr_en", false,-1);
        tracep->declBit(c+249,"riscv_top u_riscv_memory u_riscv_dmem i_clk", false,-1);
        tracep->declArray(c+33,"riscv_top u_riscv_memory u_riscv_dmem FILE_DATA_MIF", false,-1, 1023,0);
        tracep->declBus(c+283,"riscv_top u_riscv_memory u_riscv_dmem i", false,-1, 31,0);
        tracep->declBus(c+244,"riscv_top u_riscv_memory u_riscv_dmem_interface o_dmem_intf_addr", false,-1, 31,0);
        tracep->declBit(c+245,"riscv_top u_riscv_memory u_riscv_dmem_interface o_dmem_intf_wen", false,-1);
        tracep->declBus(c+244,"riscv_top u_riscv_memory u_riscv_dmem_interface i_dmem_intf_addr", false,-1, 31,0);
        tracep->declBit(c+245,"riscv_top u_riscv_memory u_riscv_dmem_interface i_dmem_intf_wen", false,-1);
        tracep->declBus(c+235,"riscv_top u_riscv_memory u_riscv_dmem_interface o_dmem_intf_wr_data", false,-1, 31,0);
        tracep->declBus(c+236,"riscv_top u_riscv_memory u_riscv_dmem_interface o_dmem_intf_byte_sel", false,-1, 3,0);
        tracep->declBus(c+280,"riscv_top u_riscv_memory u_riscv_dmem_interface o_dmem_intf_rd_data", false,-1, 31,0);
        tracep->declBus(c+247,"riscv_top u_riscv_memory u_riscv_dmem_interface i_dmem_intf_wr_data", false,-1, 31,0);
        tracep->declBus(c+246,"riscv_top u_riscv_memory u_riscv_dmem_interface i_dmem_intf_byte_sel", false,-1, 3,0);
        tracep->declBus(c+281,"riscv_top u_riscv_memory u_riscv_dmem_interface i_dmem_intf_rd_data", false,-1, 31,0);
        tracep->declBus(c+87,"riscv_top u_riscv_memory u_riscv_dmem_interface i_dmem_intf_func3", false,-1, 2,0);
        tracep->declBit(c+249,"riscv_top u_riscv_memory u_riscv_dmem_interface i_clk", false,-1);
        tracep->declBus(c+237,"riscv_top u_riscv_memory u_riscv_dmem_interface byte_aligned_dmem_rd_data", false,-1, 31,0);
        tracep->declBus(c+285,"riscv_top u_riscv_memory u_riscv_register_memory REGISTER_INIT", false,-1, 31,0);
        tracep->declBus(c+238,"riscv_top u_riscv_memory u_riscv_register_memory o_register_q_0", false,-1, 31,0);
        tracep->declBus(c+123,"riscv_top u_riscv_memory u_riscv_register_memory o_register_q_1", false,-1, 31,0);
        tracep->declBus(c+92,"riscv_top u_riscv_memory u_riscv_register_memory o_register_q_2", false,-1, 31,0);
        tracep->declBus(c+91,"riscv_top u_riscv_memory u_riscv_register_memory o_register_q_3", false,-1, 31,0);
        tracep->declBus(c+239,"riscv_top u_riscv_memory u_riscv_register_memory o_register_q_4", false,-1, 31,0);
        tracep->declBus(c+89,"riscv_top u_riscv_memory u_riscv_register_memory o_register_q_5", false,-1, 31,0);
        tracep->declBus(c+90,"riscv_top u_riscv_memory u_riscv_register_memory o_register_q_6", false,-1, 31,0);
        tracep->declBus(c+240,"riscv_top u_riscv_memory u_riscv_register_memory i_register_d_0", false,-1, 31,0);
        tracep->declBus(c+124,"riscv_top u_riscv_memory u_riscv_register_memory i_register_d_1", false,-1, 31,0);
        tracep->declBus(c+244,"riscv_top u_riscv_memory u_riscv_register_memory i_register_d_2", false,-1, 31,0);
        tracep->declBus(c+280,"riscv_top u_riscv_memory u_riscv_register_memory i_register_d_3", false,-1, 31,0);
        tracep->declBus(c+179,"riscv_top u_riscv_memory u_riscv_register_memory i_register_d_4", false,-1, 31,0);
        tracep->declBus(c+125,"riscv_top u_riscv_memory u_riscv_register_memory i_register_d_5", false,-1, 31,0);
        tracep->declBus(c+86,"riscv_top u_riscv_memory u_riscv_register_memory i_register_d_6", false,-1, 31,0);
        tracep->declBit(c+249,"riscv_top u_riscv_memory u_riscv_register_memory i_clk", false,-1);
        tracep->declBit(c+250,"riscv_top u_riscv_memory u_riscv_register_memory i_rstn", false,-1);
        tracep->declBus(c+174,"riscv_top u_riscv_writeback o_result_w", false,-1, 31,0);
        tracep->declBus(c+92,"riscv_top u_riscv_writeback i_alu_result_w", false,-1, 31,0);
        tracep->declBus(c+91,"riscv_top u_riscv_writeback i_read_data_w", false,-1, 31,0);
        tracep->declBus(c+89,"riscv_top u_riscv_writeback i_pc_plus_4w", false,-1, 31,0);
        tracep->declBus(c+88,"riscv_top u_riscv_writeback i_result_src_w", false,-1, 1,0);
        tracep->declBus(c+90,"riscv_top u_riscv_writeback i_ext_imm_w", false,-1, 31,0);
        tracep->declBus(c+286,"riscv_top u_riscv_writeback u_mux_writeback N_MUX_IN", false,-1, 31,0);
        tracep->declBus(c+174,"riscv_top u_riscv_writeback u_mux_writeback o_mux_data", false,-1, 31,0);
        tracep->declArray(c+126,"riscv_top u_riscv_writeback u_mux_writeback i_mux_concat_data", false,-1, 127,0);
        tracep->declBus(c+88,"riscv_top u_riscv_writeback u_mux_writeback i_mux_sel", false,-1, 1,0);
        {int i; for (i=0; i<4; i++) {
                tracep->declBus(c+130+i*1,"riscv_top u_riscv_writeback u_mux_writeback mux_input_arr", true,(i+0), 31,0);}}
        tracep->declBit(c+251,"riscv_top u_riscv_hazard o_stall_f", false,-1);
        tracep->declBit(c+169,"riscv_top u_riscv_hazard o_stall_d", false,-1);
        tracep->declBit(c+170,"riscv_top u_riscv_hazard o_flush_d", false,-1);
        tracep->declBit(c+177,"riscv_top u_riscv_hazard o_flush_e", false,-1);
        tracep->declBus(c+180,"riscv_top u_riscv_hazard o_forward_ae", false,-1, 1,0);
        tracep->declBus(c+181,"riscv_top u_riscv_hazard o_forward_be", false,-1, 1,0);
        tracep->declBus(c+266,"riscv_top u_riscv_hazard i_rs_1d", false,-1, 4,0);
        tracep->declBus(c+267,"riscv_top u_riscv_hazard i_rs_2d", false,-1, 4,0);
        tracep->declBus(c+284,"riscv_top u_riscv_hazard i_rd_e", false,-1, 4,0);
        tracep->declBus(c+76,"riscv_top u_riscv_hazard i_rs_1e", false,-1, 4,0);
        tracep->declBus(c+77,"riscv_top u_riscv_hazard i_rs_2e", false,-1, 4,0);
        tracep->declBus(c+241,"riscv_top u_riscv_hazard i_pc_src_e", false,-1, 1,0);
        tracep->declBit(c+134,"riscv_top u_riscv_hazard i_result_src_e", false,-1);
        tracep->declBus(c+85,"riscv_top u_riscv_hazard i_rd_m", false,-1, 4,0);
        tracep->declBit(c+178,"riscv_top u_riscv_hazard i_reg_write_m", false,-1);
        tracep->declBus(c+175,"riscv_top u_riscv_hazard i_rd_w", false,-1, 4,0);
        tracep->declBit(c+176,"riscv_top u_riscv_hazard i_reg_write_w", false,-1);
    }
}

void Vriscv_top::traceRegister(VerilatedVcd* tracep) {
    // Body
    {
        tracep->addFullCb(&traceFullTop0, __VlSymsp);
        tracep->addChgCb(&traceChgTop0, __VlSymsp);
        tracep->addCleanupCb(&traceCleanup, __VlSymsp);
    }
}

void Vriscv_top::traceFullTop0(void* userp, VerilatedVcd* tracep) {
    Vriscv_top__Syms* __restrict vlSymsp = static_cast<Vriscv_top__Syms*>(userp);
    Vriscv_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceFullSub0(userp, tracep);
    }
}

void Vriscv_top::traceFullSub0(void* userp, VerilatedVcd* tracep) {
    Vriscv_top__Syms* __restrict vlSymsp = static_cast<Vriscv_top__Syms*>(userp);
    Vriscv_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullWData(oldp+1,(vlTOPp->riscv_top__DOT__u_riscv_fetch__DOT__u_riscv_imem__DOT__FILE_TEXT_MIF),1024);
        tracep->fullWData(oldp+33,(vlTOPp->riscv_top__DOT__u_riscv_memory__DOT__u_riscv_dmem__DOT__FILE_DATA_MIF),1024);
        tracep->fullIData(oldp+65,((vlTOPp->riscv_top__DOT__o_pc_e 
                                    + vlTOPp->riscv_top__DOT__o_ext_imm_e)),32);
        tracep->fullCData(oldp+66,((3U & vlTOPp->riscv_top__DOT__u_riscv_decode__DOT____Vcellout__u_riscv_register_decode__o_register_q_1)),2);
        tracep->fullBit(oldp+67,((1U & vlTOPp->riscv_top__DOT__u_riscv_decode__DOT____Vcellout__u_riscv_register_decode__o_register_q_2)));
        tracep->fullBit(oldp+68,((1U & vlTOPp->riscv_top__DOT__u_riscv_decode__DOT____Vcellout__u_riscv_register_decode__o_register_q_3)));
        tracep->fullBit(oldp+69,((1U & vlTOPp->riscv_top__DOT__u_riscv_decode__DOT____Vcellout__u_riscv_register_decode__o_register_q_4)));
        tracep->fullCData(oldp+70,((0xfU & vlTOPp->riscv_top__DOT__u_riscv_decode__DOT____Vcellout__u_riscv_register_decode__o_register_q_5)),4);
        tracep->fullBit(oldp+71,((1U & vlTOPp->riscv_top__DOT__u_riscv_decode__DOT____Vcellout__u_riscv_register_decode__o_register_q_6)));
        tracep->fullBit(oldp+72,((1U & vlTOPp->riscv_top__DOT__u_riscv_decode__DOT____Vcellout__u_riscv_register_decode__o_register_q_15)));
        tracep->fullIData(oldp+73,(vlTOPp->riscv_top__DOT__o_rd_1e),32);
        tracep->fullIData(oldp+74,(vlTOPp->riscv_top__DOT__o_rd_2e),32);
        tracep->fullIData(oldp+75,(vlTOPp->riscv_top__DOT__o_pc_e),32);
        tracep->fullCData(oldp+76,((0x1fU & vlTOPp->riscv_top__DOT__u_riscv_decode__DOT____Vcellout__u_riscv_register_decode__o_register_q_10)),5);
        tracep->fullCData(oldp+77,((0x1fU & vlTOPp->riscv_top__DOT__u_riscv_decode__DOT____Vcellout__u_riscv_register_decode__o_register_q_11)),5);
        tracep->fullCData(oldp+78,((0x1fU & vlTOPp->riscv_top__DOT__u_riscv_decode__DOT____Vcellout__u_riscv_register_decode__o_register_q_12)),5);
        tracep->fullIData(oldp+79,(vlTOPp->riscv_top__DOT__o_ext_imm_e),32);
        tracep->fullBit(oldp+80,((1U & vlTOPp->riscv_top__DOT__u_riscv_decode__DOT____Vcellout__u_riscv_register_decode__o_register_q_16)));
        tracep->fullCData(oldp+81,((7U & vlTOPp->riscv_top__DOT__u_riscv_decode__DOT____Vcellout__u_riscv_register_decode__o_register_q_19)),3);
        tracep->fullCData(oldp+82,((0xfU & vlTOPp->riscv_top__DOT__u_riscv_decode__DOT____Vcellout__u_riscv_register_decode__o_register_q_18)),4);
        tracep->fullBit(oldp+83,((1U & vlTOPp->riscv_top__DOT__u_riscv_decode__DOT____Vcellout__u_riscv_register_decode__o_register_q_17)));
        tracep->fullCData(oldp+84,((3U & vlTOPp->riscv_top__DOT__u_riscv_execute__DOT____Vcellout__u_riscv_register_execute__o_register_q_1)),2);
        tracep->fullCData(oldp+85,((0x1fU & vlTOPp->riscv_top__DOT__u_riscv_execute__DOT____Vcellout__u_riscv_register_execute__o_register_q_5)),5);
        tracep->fullIData(oldp+86,(vlTOPp->riscv_top__DOT__o_ext_imm_m),32);
        tracep->fullCData(oldp+87,((7U & vlTOPp->riscv_top__DOT__u_riscv_execute__DOT____Vcellout__u_riscv_register_execute__o_register_q_9)),3);
        tracep->fullCData(oldp+88,((3U & vlTOPp->riscv_top__DOT__u_riscv_memory__DOT____Vcellout__u_riscv_register_memory__o_register_q_1)),2);
        tracep->fullIData(oldp+89,(vlTOPp->riscv_top__DOT__o_pc_plus_4w),32);
        tracep->fullIData(oldp+90,(vlTOPp->riscv_top__DOT__o_ext_imm_w),32);
        tracep->fullIData(oldp+91,(vlTOPp->riscv_top__DOT__o_read_data_w),32);
        tracep->fullIData(oldp+92,(vlTOPp->riscv_top__DOT__o_alu_result_w),32);
        tracep->fullIData(oldp+93,(vlTOPp->riscv_top__DOT__u_riscv_fetch__DOT__i_pcf),32);
        tracep->fullIData(oldp+94,(((IData)(4U) + vlTOPp->riscv_top__DOT__u_riscv_fetch__DOT__i_pcf)),32);
        tracep->fullIData(oldp+95,(vlTOPp->riscv_top__DOT__u_riscv_fetch__DOT__u_riscv_imem__DOT__imem_arr
                                   [(0x3fffU & (vlTOPp->riscv_top__DOT__u_riscv_fetch__DOT__i_pcf 
                                                >> 2U))]),32);
        tracep->fullSData(oldp+96,((0x3fffU & (vlTOPp->riscv_top__DOT__u_riscv_fetch__DOT__i_pcf 
                                               >> 2U))),14);
        tracep->fullIData(oldp+97,(vlTOPp->riscv_top__DOT__u_riscv_decode__DOT____Vcellout__u_riscv_register_decode__o_register_q_1),32);
        tracep->fullIData(oldp+98,(vlTOPp->riscv_top__DOT__u_riscv_decode__DOT____Vcellout__u_riscv_register_decode__o_register_q_2),32);
        tracep->fullIData(oldp+99,(vlTOPp->riscv_top__DOT__u_riscv_decode__DOT____Vcellout__u_riscv_register_decode__o_register_q_3),32);
        tracep->fullIData(oldp+100,(vlTOPp->riscv_top__DOT__u_riscv_decode__DOT____Vcellout__u_riscv_register_decode__o_register_q_4),32);
        tracep->fullIData(oldp+101,(vlTOPp->riscv_top__DOT__u_riscv_decode__DOT____Vcellout__u_riscv_register_decode__o_register_q_5),32);
        tracep->fullIData(oldp+102,(vlTOPp->riscv_top__DOT__u_riscv_decode__DOT____Vcellout__u_riscv_register_decode__o_register_q_6),32);
        tracep->fullIData(oldp+103,(vlTOPp->riscv_top__DOT__u_riscv_decode__DOT____Vcellout__u_riscv_register_decode__o_register_q_10),32);
        tracep->fullIData(oldp+104,(vlTOPp->riscv_top__DOT__u_riscv_decode__DOT____Vcellout__u_riscv_register_decode__o_register_q_11),32);
        tracep->fullIData(oldp+105,(vlTOPp->riscv_top__DOT__u_riscv_decode__DOT____Vcellout__u_riscv_register_decode__o_register_q_12),32);
        tracep->fullIData(oldp+106,(vlTOPp->riscv_top__DOT__u_riscv_decode__DOT____Vcellout__u_riscv_register_decode__o_register_q_15),32);
        tracep->fullIData(oldp+107,(vlTOPp->riscv_top__DOT__u_riscv_decode__DOT____Vcellout__u_riscv_register_decode__o_register_q_16),32);
        tracep->fullIData(oldp+108,(vlTOPp->riscv_top__DOT__u_riscv_decode__DOT____Vcellout__u_riscv_register_decode__o_register_q_17),32);
        tracep->fullIData(oldp+109,(vlTOPp->riscv_top__DOT__u_riscv_decode__DOT____Vcellout__u_riscv_register_decode__o_register_q_18),32);
        tracep->fullIData(oldp+110,(vlTOPp->riscv_top__DOT__u_riscv_decode__DOT____Vcellout__u_riscv_register_decode__o_register_q_19),32);
        tracep->fullQData(oldp+111,(vlTOPp->riscv_top__DOT__u_riscv_execute__DOT__u_riscv_alu__DOT__DEBUG_ALU_OP),64);
        tracep->fullIData(oldp+113,(vlTOPp->riscv_top__DOT__u_riscv_execute__DOT____Vcellout__u_riscv_register_execute__o_register_q_1),32);
        tracep->fullIData(oldp+114,(vlTOPp->riscv_top__DOT__u_riscv_execute__DOT____Vcellout__u_riscv_register_execute__o_register_q_2),32);
        tracep->fullIData(oldp+115,(vlTOPp->riscv_top__DOT__u_riscv_execute__DOT____Vcellout__u_riscv_register_execute__o_register_q_5),32);
        tracep->fullIData(oldp+116,(vlTOPp->riscv_top__DOT__u_riscv_execute__DOT____Vcellout__u_riscv_register_execute__o_register_q_8),32);
        tracep->fullIData(oldp+117,(vlTOPp->riscv_top__DOT__u_riscv_execute__DOT____Vcellout__u_riscv_register_execute__o_register_q_9),32);
        tracep->fullIData(oldp+118,((3U & vlTOPp->riscv_top__DOT__u_riscv_decode__DOT____Vcellout__u_riscv_register_decode__o_register_q_1)),32);
        tracep->fullIData(oldp+119,((1U & vlTOPp->riscv_top__DOT__u_riscv_decode__DOT____Vcellout__u_riscv_register_decode__o_register_q_2)),32);
        tracep->fullIData(oldp+120,((0x1fU & vlTOPp->riscv_top__DOT__u_riscv_decode__DOT____Vcellout__u_riscv_register_decode__o_register_q_12)),32);
        tracep->fullIData(oldp+121,((0xfU & vlTOPp->riscv_top__DOT__u_riscv_decode__DOT____Vcellout__u_riscv_register_decode__o_register_q_18)),32);
        tracep->fullIData(oldp+122,((7U & vlTOPp->riscv_top__DOT__u_riscv_decode__DOT____Vcellout__u_riscv_register_decode__o_register_q_19)),32);
        tracep->fullIData(oldp+123,(vlTOPp->riscv_top__DOT__u_riscv_memory__DOT____Vcellout__u_riscv_register_memory__o_register_q_1),32);
        tracep->fullIData(oldp+124,((3U & vlTOPp->riscv_top__DOT__u_riscv_execute__DOT____Vcellout__u_riscv_register_execute__o_register_q_1)),32);
        tracep->fullIData(oldp+125,((0x1fU & vlTOPp->riscv_top__DOT__u_riscv_execute__DOT____Vcellout__u_riscv_register_execute__o_register_q_5)),32);
        tracep->fullWData(oldp+126,(vlTOPp->riscv_top__DOT__u_riscv_writeback__DOT____Vcellinp__u_mux_writeback__i_mux_concat_data),128);
        tracep->fullIData(oldp+130,(vlTOPp->riscv_top__DOT__u_riscv_writeback__DOT__u_mux_writeback__DOT__mux_input_arr[0]),32);
        tracep->fullIData(oldp+131,(vlTOPp->riscv_top__DOT__u_riscv_writeback__DOT__u_mux_writeback__DOT__mux_input_arr[1]),32);
        tracep->fullIData(oldp+132,(vlTOPp->riscv_top__DOT__u_riscv_writeback__DOT__u_mux_writeback__DOT__mux_input_arr[2]),32);
        tracep->fullIData(oldp+133,(vlTOPp->riscv_top__DOT__u_riscv_writeback__DOT__u_mux_writeback__DOT__mux_input_arr[3]),32);
        tracep->fullBit(oldp+134,((1U & vlTOPp->riscv_top__DOT__u_riscv_decode__DOT____Vcellout__u_riscv_register_decode__o_register_q_1)));
        tracep->fullIData(oldp+135,(vlTOPp->riscv_top__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[0]),32);
        tracep->fullIData(oldp+136,(vlTOPp->riscv_top__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[1]),32);
        tracep->fullIData(oldp+137,(vlTOPp->riscv_top__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[2]),32);
        tracep->fullIData(oldp+138,(vlTOPp->riscv_top__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[3]),32);
        tracep->fullIData(oldp+139,(vlTOPp->riscv_top__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[4]),32);
        tracep->fullIData(oldp+140,(vlTOPp->riscv_top__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[5]),32);
        tracep->fullIData(oldp+141,(vlTOPp->riscv_top__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[6]),32);
        tracep->fullIData(oldp+142,(vlTOPp->riscv_top__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[7]),32);
        tracep->fullIData(oldp+143,(vlTOPp->riscv_top__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[8]),32);
        tracep->fullIData(oldp+144,(vlTOPp->riscv_top__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[9]),32);
        tracep->fullIData(oldp+145,(vlTOPp->riscv_top__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[10]),32);
        tracep->fullIData(oldp+146,(vlTOPp->riscv_top__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[11]),32);
        tracep->fullIData(oldp+147,(vlTOPp->riscv_top__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[12]),32);
        tracep->fullIData(oldp+148,(vlTOPp->riscv_top__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[13]),32);
        tracep->fullIData(oldp+149,(vlTOPp->riscv_top__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[14]),32);
        tracep->fullIData(oldp+150,(vlTOPp->riscv_top__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[15]),32);
        tracep->fullIData(oldp+151,(vlTOPp->riscv_top__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[16]),32);
        tracep->fullIData(oldp+152,(vlTOPp->riscv_top__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[17]),32);
        tracep->fullIData(oldp+153,(vlTOPp->riscv_top__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[18]),32);
        tracep->fullIData(oldp+154,(vlTOPp->riscv_top__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[19]),32);
        tracep->fullIData(oldp+155,(vlTOPp->riscv_top__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[20]),32);
        tracep->fullIData(oldp+156,(vlTOPp->riscv_top__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[21]),32);
        tracep->fullIData(oldp+157,(vlTOPp->riscv_top__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[22]),32);
        tracep->fullIData(oldp+158,(vlTOPp->riscv_top__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[23]),32);
        tracep->fullIData(oldp+159,(vlTOPp->riscv_top__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[24]),32);
        tracep->fullIData(oldp+160,(vlTOPp->riscv_top__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[25]),32);
        tracep->fullIData(oldp+161,(vlTOPp->riscv_top__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[26]),32);
        tracep->fullIData(oldp+162,(vlTOPp->riscv_top__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[27]),32);
        tracep->fullIData(oldp+163,(vlTOPp->riscv_top__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[28]),32);
        tracep->fullIData(oldp+164,(vlTOPp->riscv_top__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[29]),32);
        tracep->fullIData(oldp+165,(vlTOPp->riscv_top__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[30]),32);
        tracep->fullIData(oldp+166,(vlTOPp->riscv_top__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[31]),32);
        tracep->fullIData(oldp+167,(vlTOPp->riscv_top__DOT__o_pc_plus_4d),32);
        tracep->fullCData(oldp+168,(vlTOPp->riscv_top__DOT__o_pc_src_e),2);
        tracep->fullBit(oldp+169,(vlTOPp->riscv_top__DOT__o_stall_d));
        tracep->fullBit(oldp+170,((1U & (IData)(vlTOPp->riscv_top__DOT__o_pc_src_e))));
        tracep->fullIData(oldp+171,(vlTOPp->riscv_top__DOT__o_alu_data),32);
        tracep->fullBit(oldp+172,((1U & vlTOPp->riscv_top__DOT__u_riscv_decode__DOT____Vcellout__u_riscv_register_decode__o_register_q_0)));
        tracep->fullIData(oldp+173,(vlTOPp->riscv_top__DOT__o_pc_plus_4e),32);
        tracep->fullIData(oldp+174,(vlTOPp->riscv_top__DOT__o_result_w),32);
        tracep->fullCData(oldp+175,((0x1fU & vlTOPp->riscv_top__DOT__u_riscv_memory__DOT____Vcellout__u_riscv_register_memory__o_register_q_4)),5);
        tracep->fullBit(oldp+176,((1U & vlTOPp->riscv_top__DOT__u_riscv_memory__DOT____Vcellout__u_riscv_register_memory__o_register_q_0)));
        tracep->fullBit(oldp+177,(vlTOPp->riscv_top__DOT__o_flush_e));
        tracep->fullBit(oldp+178,((1U & vlTOPp->riscv_top__DOT__u_riscv_execute__DOT____Vcellout__u_riscv_register_execute__o_register_q_0)));
        tracep->fullIData(oldp+179,(vlTOPp->riscv_top__DOT__o_pc_plus_4m),32);
        tracep->fullCData(oldp+180,(vlTOPp->riscv_top__DOT__o_forward_ae),2);
        tracep->fullCData(oldp+181,(vlTOPp->riscv_top__DOT__o_forward_be),2);
        tracep->fullIData(oldp+182,(vlTOPp->riscv_top__DOT__u_riscv_fetch__DOT__u_riscv_mux__DOT__mux_input_arr
                                    [vlTOPp->riscv_top__DOT__o_pc_src_e]),32);
        tracep->fullWData(oldp+183,(vlTOPp->riscv_top__DOT__u_riscv_fetch__DOT____Vcellinp__u_riscv_mux__i_mux_concat_data),128);
        tracep->fullIData(oldp+187,(vlTOPp->riscv_top__DOT__u_riscv_fetch__DOT__u_riscv_mux__DOT__mux_input_arr[0]),32);
        tracep->fullIData(oldp+188,(vlTOPp->riscv_top__DOT__u_riscv_fetch__DOT__u_riscv_mux__DOT__mux_input_arr[1]),32);
        tracep->fullIData(oldp+189,(vlTOPp->riscv_top__DOT__u_riscv_fetch__DOT__u_riscv_mux__DOT__mux_input_arr[2]),32);
        tracep->fullIData(oldp+190,(vlTOPp->riscv_top__DOT__u_riscv_fetch__DOT__u_riscv_mux__DOT__mux_input_arr[3]),32);
        tracep->fullCData(oldp+191,(vlTOPp->riscv_top__DOT__u_riscv_decode__DOT__o_imm_src_d),3);
        tracep->fullCData(oldp+192,(vlTOPp->riscv_top__DOT__u_riscv_decode__DOT__o_result_src_d),2);
        tracep->fullBit(oldp+193,(vlTOPp->riscv_top__DOT__u_riscv_decode__DOT__o_alu_src_d_b));
        tracep->fullCData(oldp+194,(vlTOPp->riscv_top__DOT__u_riscv_decode__DOT__o_alu_ctrl_d),4);
        tracep->fullIData(oldp+195,(vlTOPp->riscv_top__DOT__u_riscv_decode__DOT__o_ext_imm_d),32);
        tracep->fullWData(oldp+196,(vlTOPp->riscv_top__DOT__u_riscv_decode__DOT__u_riscv_ctrl_i__DOT__DEBUG_INSTR),256);
        tracep->fullIData(oldp+204,(vlTOPp->riscv_top__DOT__u_riscv_decode__DOT____Vcellout__u_riscv_register_decode__o_register_q_0),32);
        tracep->fullIData(oldp+205,(vlTOPp->riscv_top__DOT__u_riscv_decode__DOT__o_result_src_d),32);
        tracep->fullIData(oldp+206,(vlTOPp->riscv_top__DOT__u_riscv_decode__DOT__o_alu_ctrl_d),32);
        tracep->fullIData(oldp+207,(vlTOPp->riscv_top__DOT__u_riscv_decode__DOT__o_alu_src_d_b),32);
        tracep->fullIData(oldp+208,(vlTOPp->riscv_top__DOT__u_riscv_execute__DOT__o_src_ae),32);
        tracep->fullIData(oldp+209,(vlTOPp->riscv_top__DOT__u_riscv_execute__DOT__o_write_data_e),32);
        tracep->fullIData(oldp+210,(vlTOPp->riscv_top__DOT__u_riscv_execute__DOT__o_src_be),32);
        tracep->fullIData(oldp+211,(((2U >= (IData)(vlTOPp->riscv_top__DOT__o_forward_ae))
                                      ? vlTOPp->riscv_top__DOT__u_riscv_execute__DOT__u_mux_execute_0__DOT__mux_input_arr
                                     [vlTOPp->riscv_top__DOT__o_forward_ae]
                                      : 0U)),32);
        tracep->fullWData(oldp+212,(vlTOPp->riscv_top__DOT__u_riscv_execute__DOT____Vcellinp__u_mux_execute_0__i_mux_concat_data),96);
        tracep->fullIData(oldp+215,(vlTOPp->riscv_top__DOT__u_riscv_execute__DOT__u_mux_execute_0__DOT__mux_input_arr[0]),32);
        tracep->fullIData(oldp+216,(vlTOPp->riscv_top__DOT__u_riscv_execute__DOT__u_mux_execute_0__DOT__mux_input_arr[1]),32);
        tracep->fullIData(oldp+217,(vlTOPp->riscv_top__DOT__u_riscv_execute__DOT__u_mux_execute_0__DOT__mux_input_arr[2]),32);
        tracep->fullQData(oldp+218,(vlTOPp->riscv_top__DOT__u_riscv_execute__DOT____Vcellinp__u_riscv_mux_1__i_mux_concat_data),64);
        tracep->fullIData(oldp+220,(vlTOPp->riscv_top__DOT__u_riscv_execute__DOT__u_riscv_mux_1__DOT__mux_input_arr[0]),32);
        tracep->fullIData(oldp+221,(vlTOPp->riscv_top__DOT__u_riscv_execute__DOT__u_riscv_mux_1__DOT__mux_input_arr[1]),32);
        tracep->fullWData(oldp+222,(vlTOPp->riscv_top__DOT__u_riscv_execute__DOT____Vcellinp__u_mux_execute_2__i_mux_concat_data),96);
        tracep->fullIData(oldp+225,(vlTOPp->riscv_top__DOT__u_riscv_execute__DOT__u_mux_execute_2__DOT__mux_input_arr[0]),32);
        tracep->fullIData(oldp+226,(vlTOPp->riscv_top__DOT__u_riscv_execute__DOT__u_mux_execute_2__DOT__mux_input_arr[1]),32);
        tracep->fullIData(oldp+227,(vlTOPp->riscv_top__DOT__u_riscv_execute__DOT__u_mux_execute_2__DOT__mux_input_arr[2]),32);
        tracep->fullQData(oldp+228,(vlTOPp->riscv_top__DOT__u_riscv_execute__DOT____Vcellinp__u_riscv_mux_3__i_mux_concat_data),64);
        tracep->fullIData(oldp+230,(vlTOPp->riscv_top__DOT__u_riscv_execute__DOT__u_riscv_mux_3__DOT__mux_input_arr[0]),32);
        tracep->fullIData(oldp+231,(vlTOPp->riscv_top__DOT__u_riscv_execute__DOT__u_riscv_mux_3__DOT__mux_input_arr[1]),32);
        tracep->fullBit(oldp+232,((0U == vlTOPp->riscv_top__DOT__o_alu_data)));
        tracep->fullIData(oldp+233,(vlTOPp->riscv_top__DOT__u_riscv_execute__DOT____Vcellout__u_riscv_register_execute__o_register_q_0),32);
        tracep->fullIData(oldp+234,((1U & vlTOPp->riscv_top__DOT__u_riscv_decode__DOT____Vcellout__u_riscv_register_decode__o_register_q_0)),32);
        tracep->fullIData(oldp+235,(vlTOPp->riscv_top__DOT__u_riscv_memory__DOT__o_dmem_intf_wr_data),32);
        tracep->fullCData(oldp+236,(vlTOPp->riscv_top__DOT__u_riscv_memory__DOT__o_dmem_intf_byte_sel),4);
        tracep->fullIData(oldp+237,(vlTOPp->riscv_top__DOT__u_riscv_memory__DOT__u_riscv_dmem_interface__DOT__byte_aligned_dmem_rd_data),32);
        tracep->fullIData(oldp+238,(vlTOPp->riscv_top__DOT__u_riscv_memory__DOT____Vcellout__u_riscv_register_memory__o_register_q_0),32);
        tracep->fullIData(oldp+239,(vlTOPp->riscv_top__DOT__u_riscv_memory__DOT____Vcellout__u_riscv_register_memory__o_register_q_4),32);
        tracep->fullIData(oldp+240,((1U & vlTOPp->riscv_top__DOT__u_riscv_execute__DOT____Vcellout__u_riscv_register_execute__o_register_q_0)),32);
        tracep->fullCData(oldp+241,((1U & (IData)(vlTOPp->riscv_top__DOT__o_pc_src_e))),2);
        tracep->fullIData(oldp+242,(vlTOPp->o_instr_d),32);
        tracep->fullIData(oldp+243,(vlTOPp->o_pc_d),32);
        tracep->fullIData(oldp+244,(vlTOPp->o_alu_result_m),32);
        tracep->fullBit(oldp+245,(vlTOPp->o_mem_write_m));
        tracep->fullCData(oldp+246,(vlTOPp->o_ctrl_mem_byte_sel_m),4);
        tracep->fullIData(oldp+247,(vlTOPp->o_write_data_m),32);
        tracep->fullIData(oldp+248,(vlTOPp->o_mem_read_data),32);
        tracep->fullBit(oldp+249,(vlTOPp->i_clk));
        tracep->fullBit(oldp+250,(vlTOPp->i_rstn));
        tracep->fullBit(oldp+251,(((((0x1fU & (vlTOPp->o_instr_d 
                                               >> 0xfU)) 
                                     == (0x1fU & (vlTOPp->o_instr_d 
                                                  >> 7U))) 
                                    | ((0x1fU & (vlTOPp->o_instr_d 
                                                 >> 0x14U)) 
                                       == (0x1fU & 
                                           (vlTOPp->o_instr_d 
                                            >> 7U)))) 
                                   & (~ vlTOPp->riscv_top__DOT__u_riscv_decode__DOT____Vcellout__u_riscv_register_decode__o_register_q_1))));
        tracep->fullBit(oldp+252,(((1U & vlTOPp->riscv_top__DOT__u_riscv_decode__DOT____Vcellout__u_riscv_register_decode__o_register_q_16)
                                    ? (0U != vlTOPp->riscv_top__DOT__o_alu_data)
                                    : (0U == vlTOPp->riscv_top__DOT__o_alu_data))));
        tracep->fullBit(oldp+253,((0x17U == (0x7fU 
                                             & vlTOPp->o_instr_d))));
        tracep->fullBit(oldp+254,((1U & (~ ((0x23U 
                                             == (0x7fU 
                                                 & vlTOPp->o_instr_d)) 
                                            | (0x63U 
                                               == (0x7fU 
                                                   & vlTOPp->o_instr_d)))))));
        tracep->fullBit(oldp+255,((0x23U == (0x7fU 
                                             & vlTOPp->o_instr_d))));
        tracep->fullIData(oldp+256,(vlTOPp->riscv_top__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers
                                    [(0x1fU & (vlTOPp->o_instr_d 
                                               >> 0xfU))]),32);
        tracep->fullIData(oldp+257,(vlTOPp->riscv_top__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers
                                    [(0x1fU & (vlTOPp->o_instr_d 
                                               >> 0x14U))]),32);
        tracep->fullCData(oldp+258,((((3U == (0x7fU 
                                              & vlTOPp->o_instr_d)) 
                                      | (0x23U == (0x7fU 
                                                   & vlTOPp->o_instr_d)))
                                      ? ((0x4000U & vlTOPp->o_instr_d)
                                          ? ((0x2000U 
                                              & vlTOPp->o_instr_d)
                                              ? 0xfU
                                              : ((0x1000U 
                                                  & vlTOPp->o_instr_d)
                                                  ? 3U
                                                  : 1U))
                                          : ((0x2000U 
                                              & vlTOPp->o_instr_d)
                                              ? 0xfU
                                              : ((0x1000U 
                                                  & vlTOPp->o_instr_d)
                                                  ? 3U
                                                  : 1U)))
                                      : 0xfU)),4);
        tracep->fullBit(oldp+259,((0x67U == (0x7fU 
                                             & vlTOPp->o_instr_d))));
        tracep->fullBit(oldp+260,(((0x63U == (0x7fU 
                                              & vlTOPp->o_instr_d)) 
                                   & ((0x4000U & vlTOPp->o_instr_d)
                                       ? ((0x2000U 
                                           & vlTOPp->o_instr_d)
                                           ? (~ (vlTOPp->o_instr_d 
                                                 >> 0xcU))
                                           : (~ (vlTOPp->o_instr_d 
                                                 >> 0xcU)))
                                       : ((~ (vlTOPp->o_instr_d 
                                              >> 0xdU)) 
                                          & (vlTOPp->o_instr_d 
                                             >> 0xcU))))));
        tracep->fullBit(oldp+261,((0x6fU == (0x7fU 
                                             & vlTOPp->o_instr_d))));
        tracep->fullBit(oldp+262,((0x63U == (0x7fU 
                                             & vlTOPp->o_instr_d))));
        tracep->fullCData(oldp+263,((0x7fU & vlTOPp->o_instr_d)),7);
        tracep->fullCData(oldp+264,((7U & (vlTOPp->o_instr_d 
                                           >> 0xcU))),3);
        tracep->fullBit(oldp+265,((1U & (vlTOPp->o_instr_d 
                                         >> 0x1eU))));
        tracep->fullCData(oldp+266,((0x1fU & (vlTOPp->o_instr_d 
                                              >> 0xfU))),5);
        tracep->fullCData(oldp+267,((0x1fU & (vlTOPp->o_instr_d 
                                              >> 0x14U))),5);
        tracep->fullIData(oldp+268,((1U & (~ ((0x23U 
                                               == (0x7fU 
                                                   & vlTOPp->o_instr_d)) 
                                              | (0x63U 
                                                 == 
                                                 (0x7fU 
                                                  & vlTOPp->o_instr_d)))))),32);
        tracep->fullIData(oldp+269,((0x23U == (0x7fU 
                                               & vlTOPp->o_instr_d))),32);
        tracep->fullIData(oldp+270,((0x6fU == (0x7fU 
                                               & vlTOPp->o_instr_d))),32);
        tracep->fullIData(oldp+271,((0x63U == (0x7fU 
                                               & vlTOPp->o_instr_d))),32);
        tracep->fullIData(oldp+272,((0x17U == (0x7fU 
                                               & vlTOPp->o_instr_d))),32);
        tracep->fullIData(oldp+273,((0x1fU & (vlTOPp->o_instr_d 
                                              >> 0xfU))),32);
        tracep->fullIData(oldp+274,((0x1fU & (vlTOPp->o_instr_d 
                                              >> 0x14U))),32);
        tracep->fullIData(oldp+275,((0x1fU & (vlTOPp->o_instr_d 
                                              >> 7U))),32);
        tracep->fullIData(oldp+276,(((0x63U == (0x7fU 
                                                & vlTOPp->o_instr_d)) 
                                     & ((0x4000U & vlTOPp->o_instr_d)
                                         ? ((0x2000U 
                                             & vlTOPp->o_instr_d)
                                             ? (~ (vlTOPp->o_instr_d 
                                                   >> 0xcU))
                                             : (~ (vlTOPp->o_instr_d 
                                                   >> 0xcU)))
                                         : ((~ (vlTOPp->o_instr_d 
                                                >> 0xdU)) 
                                            & (vlTOPp->o_instr_d 
                                               >> 0xcU))))),32);
        tracep->fullIData(oldp+277,((0x67U == (0x7fU 
                                               & vlTOPp->o_instr_d))),32);
        tracep->fullIData(oldp+278,((((3U == (0x7fU 
                                              & vlTOPp->o_instr_d)) 
                                      | (0x23U == (0x7fU 
                                                   & vlTOPp->o_instr_d)))
                                      ? ((0x4000U & vlTOPp->o_instr_d)
                                          ? ((0x2000U 
                                              & vlTOPp->o_instr_d)
                                              ? 0xfU
                                              : ((0x1000U 
                                                  & vlTOPp->o_instr_d)
                                                  ? 3U
                                                  : 1U))
                                          : ((0x2000U 
                                              & vlTOPp->o_instr_d)
                                              ? 0xfU
                                              : ((0x1000U 
                                                  & vlTOPp->o_instr_d)
                                                  ? 3U
                                                  : 1U)))
                                      : 0xfU)),32);
        tracep->fullIData(oldp+279,((7U & (vlTOPp->o_instr_d 
                                           >> 0xcU))),32);
        tracep->fullIData(oldp+280,(((4U & vlTOPp->riscv_top__DOT__u_riscv_execute__DOT____Vcellout__u_riscv_register_execute__o_register_q_9)
                                      ? ((2U & vlTOPp->riscv_top__DOT__u_riscv_execute__DOT____Vcellout__u_riscv_register_execute__o_register_q_9)
                                          ? 0U : ((1U 
                                                   & vlTOPp->riscv_top__DOT__u_riscv_execute__DOT____Vcellout__u_riscv_register_execute__o_register_q_9)
                                                   ? 
                                                  (0xffffU 
                                                   & vlTOPp->riscv_top__DOT__u_riscv_memory__DOT__u_riscv_dmem_interface__DOT__byte_aligned_dmem_rd_data)
                                                   : 
                                                  (0xffU 
                                                   & vlTOPp->riscv_top__DOT__u_riscv_memory__DOT__u_riscv_dmem_interface__DOT__byte_aligned_dmem_rd_data)))
                                      : ((2U & vlTOPp->riscv_top__DOT__u_riscv_execute__DOT____Vcellout__u_riscv_register_execute__o_register_q_9)
                                          ? ((1U & vlTOPp->riscv_top__DOT__u_riscv_execute__DOT____Vcellout__u_riscv_register_execute__o_register_q_9)
                                              ? 0U : vlTOPp->riscv_top__DOT__u_riscv_memory__DOT__u_riscv_dmem_interface__DOT__byte_aligned_dmem_rd_data)
                                          : ((1U & vlTOPp->riscv_top__DOT__u_riscv_execute__DOT____Vcellout__u_riscv_register_execute__o_register_q_9)
                                              ? ((0xffff0000U 
                                                  & ((- (IData)(
                                                                (1U 
                                                                 & (vlTOPp->riscv_top__DOT__u_riscv_memory__DOT__u_riscv_dmem_interface__DOT__byte_aligned_dmem_rd_data 
                                                                    >> 0xfU)))) 
                                                     << 0x10U)) 
                                                 | (0xffffU 
                                                    & vlTOPp->riscv_top__DOT__u_riscv_memory__DOT__u_riscv_dmem_interface__DOT__byte_aligned_dmem_rd_data))
                                              : ((0xffffff00U 
                                                  & ((- (IData)(
                                                                (1U 
                                                                 & (vlTOPp->riscv_top__DOT__u_riscv_memory__DOT__u_riscv_dmem_interface__DOT__byte_aligned_dmem_rd_data 
                                                                    >> 7U)))) 
                                                     << 8U)) 
                                                 | (0xffU 
                                                    & vlTOPp->riscv_top__DOT__u_riscv_memory__DOT__u_riscv_dmem_interface__DOT__byte_aligned_dmem_rd_data)))))),32);
        tracep->fullIData(oldp+281,(vlTOPp->riscv_top__DOT__u_riscv_memory__DOT__u_riscv_dmem__DOT__dmem_arr
                                    [(0x3fffU & (vlTOPp->o_alu_result_m 
                                                 >> 2U))]),32);
        tracep->fullSData(oldp+282,((0x3fffU & (vlTOPp->o_alu_result_m 
                                                >> 2U))),14);
        tracep->fullIData(oldp+283,(vlTOPp->riscv_top__DOT__u_riscv_memory__DOT__u_riscv_dmem__DOT__i),32);
        tracep->fullCData(oldp+284,((0x1fU & (vlTOPp->o_instr_d 
                                              >> 7U))),5);
        tracep->fullIData(oldp+285,(0U),32);
        tracep->fullIData(oldp+286,(4U),32);
        tracep->fullIData(oldp+287,(4U),32);
        tracep->fullIData(oldp+288,(3U),32);
        tracep->fullIData(oldp+289,(2U),32);
    }
}
