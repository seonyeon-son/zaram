// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vriscv_top__Syms.h"


void Vriscv_top::traceChgTop0(void* userp, VerilatedVcd* tracep) {
    Vriscv_top__Syms* __restrict vlSymsp = static_cast<Vriscv_top__Syms*>(userp);
    Vriscv_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    {
        vlTOPp->traceChgSub0(userp, tracep);
    }
}

void Vriscv_top::traceChgSub0(void* userp, VerilatedVcd* tracep) {
    Vriscv_top__Syms* __restrict vlSymsp = static_cast<Vriscv_top__Syms*>(userp);
    Vriscv_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[0U])) {
            tracep->chgWData(oldp+0,(vlTOPp->riscv_top__DOT__u_riscv_fetch__DOT__u_riscv_imem__DOT__FILE_TEXT_MIF),1024);
            tracep->chgWData(oldp+32,(vlTOPp->riscv_top__DOT__u_riscv_memory__DOT__u_riscv_dmem__DOT__FILE_DATA_MIF),1024);
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[1U])) {
            tracep->chgIData(oldp+64,(vlTOPp->riscv_top__DOT__o_pc_plus_4d),32);
            tracep->chgIData(oldp+65,((vlTOPp->riscv_top__DOT__o_pc_e 
                                       + vlTOPp->riscv_top__DOT__o_ext_imm_e)),32);
            tracep->chgCData(oldp+66,(vlTOPp->riscv_top__DOT__o_result_src_e),2);
            tracep->chgBit(oldp+67,(vlTOPp->riscv_top__DOT__o_jump_e));
            tracep->chgBit(oldp+68,(vlTOPp->riscv_top__DOT__o_branch_e));
            tracep->chgCData(oldp+69,(vlTOPp->riscv_top__DOT__o_alu_ctrl_e),4);
            tracep->chgBit(oldp+70,(vlTOPp->riscv_top__DOT__o_alu_src_e_a));
            tracep->chgBit(oldp+71,(vlTOPp->riscv_top__DOT__o_alu_src_e_b));
            tracep->chgIData(oldp+72,(vlTOPp->riscv_top__DOT__o_rd_1e),32);
            tracep->chgIData(oldp+73,(vlTOPp->riscv_top__DOT__o_rd_2e),32);
            tracep->chgIData(oldp+74,(vlTOPp->riscv_top__DOT__o_pc_e),32);
            tracep->chgCData(oldp+75,(vlTOPp->riscv_top__DOT__o_rs_1e),5);
            tracep->chgCData(oldp+76,(vlTOPp->riscv_top__DOT__o_rs_2e),5);
            tracep->chgIData(oldp+77,(vlTOPp->riscv_top__DOT__o_ext_imm_e),32);
            tracep->chgIData(oldp+78,(vlTOPp->riscv_top__DOT__o_pc_plus_4e),32);
            tracep->chgBit(oldp+79,(vlTOPp->riscv_top__DOT__o_zero_condition_e));
            tracep->chgCData(oldp+80,(vlTOPp->riscv_top__DOT__o_funct3_e),3);
            tracep->chgCData(oldp+81,(vlTOPp->riscv_top__DOT__o_ctrl_mem_byte_sel_e),4);
            tracep->chgBit(oldp+82,(vlTOPp->riscv_top__DOT__o_alu_jalr_e));
            tracep->chgCData(oldp+83,(vlTOPp->riscv_top__DOT__o_result_src_m),2);
            tracep->chgIData(oldp+84,(vlTOPp->riscv_top__DOT__o_pc_plus_4m),32);
            tracep->chgIData(oldp+85,(vlTOPp->riscv_top__DOT__o_ext_imm_m),32);
            tracep->chgCData(oldp+86,(vlTOPp->riscv_top__DOT__o_funct3_m),3);
            tracep->chgCData(oldp+87,(vlTOPp->riscv_top__DOT__o_result_src_w),2);
            tracep->chgIData(oldp+88,(vlTOPp->riscv_top__DOT__o_pc_plus_4w),32);
            tracep->chgIData(oldp+89,(vlTOPp->riscv_top__DOT__o_ext_imm_w),32);
            tracep->chgIData(oldp+90,(vlTOPp->riscv_top__DOT__o_read_data_w),32);
            tracep->chgIData(oldp+91,(vlTOPp->riscv_top__DOT__o_alu_result_w),32);
            tracep->chgIData(oldp+92,(vlTOPp->riscv_top__DOT__u_riscv_fetch__DOT__i_pcf),32);
            tracep->chgIData(oldp+93,(((IData)(4U) 
                                       + vlTOPp->riscv_top__DOT__u_riscv_fetch__DOT__i_pcf)),32);
            tracep->chgIData(oldp+94,(vlTOPp->riscv_top__DOT__u_riscv_fetch__DOT__u_riscv_imem__DOT__imem_arr
                                      [(0x3fffU & (vlTOPp->riscv_top__DOT__u_riscv_fetch__DOT__i_pcf 
                                                   >> 2U))]),32);
            tracep->chgSData(oldp+95,((0x3fffU & (vlTOPp->riscv_top__DOT__u_riscv_fetch__DOT__i_pcf 
                                                  >> 2U))),14);
            tracep->chgQData(oldp+96,(vlTOPp->riscv_top__DOT__u_riscv_execute__DOT__u_riscv_alu__DOT__DEBUG_ALU_OP),64);
            tracep->chgWData(oldp+98,(vlTOPp->riscv_top__DOT__u_riscv_writeback__DOT____Vcellinp__u_mux_writeback__i_mux_concat_data),128);
            tracep->chgIData(oldp+102,(vlTOPp->riscv_top__DOT__u_riscv_writeback__DOT__u_mux_writeback__DOT__mux_input_arr[0]),32);
            tracep->chgIData(oldp+103,(vlTOPp->riscv_top__DOT__u_riscv_writeback__DOT__u_mux_writeback__DOT__mux_input_arr[1]),32);
            tracep->chgIData(oldp+104,(vlTOPp->riscv_top__DOT__u_riscv_writeback__DOT__u_mux_writeback__DOT__mux_input_arr[2]),32);
            tracep->chgIData(oldp+105,(vlTOPp->riscv_top__DOT__u_riscv_writeback__DOT__u_mux_writeback__DOT__mux_input_arr[3]),32);
            tracep->chgBit(oldp+106,((1U & (IData)(vlTOPp->riscv_top__DOT__o_result_src_e))));
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[2U])) {
            tracep->chgIData(oldp+107,(vlTOPp->riscv_top__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[0]),32);
            tracep->chgIData(oldp+108,(vlTOPp->riscv_top__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[1]),32);
            tracep->chgIData(oldp+109,(vlTOPp->riscv_top__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[2]),32);
            tracep->chgIData(oldp+110,(vlTOPp->riscv_top__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[3]),32);
            tracep->chgIData(oldp+111,(vlTOPp->riscv_top__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[4]),32);
            tracep->chgIData(oldp+112,(vlTOPp->riscv_top__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[5]),32);
            tracep->chgIData(oldp+113,(vlTOPp->riscv_top__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[6]),32);
            tracep->chgIData(oldp+114,(vlTOPp->riscv_top__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[7]),32);
            tracep->chgIData(oldp+115,(vlTOPp->riscv_top__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[8]),32);
            tracep->chgIData(oldp+116,(vlTOPp->riscv_top__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[9]),32);
            tracep->chgIData(oldp+117,(vlTOPp->riscv_top__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[10]),32);
            tracep->chgIData(oldp+118,(vlTOPp->riscv_top__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[11]),32);
            tracep->chgIData(oldp+119,(vlTOPp->riscv_top__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[12]),32);
            tracep->chgIData(oldp+120,(vlTOPp->riscv_top__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[13]),32);
            tracep->chgIData(oldp+121,(vlTOPp->riscv_top__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[14]),32);
            tracep->chgIData(oldp+122,(vlTOPp->riscv_top__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[15]),32);
            tracep->chgIData(oldp+123,(vlTOPp->riscv_top__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[16]),32);
            tracep->chgIData(oldp+124,(vlTOPp->riscv_top__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[17]),32);
            tracep->chgIData(oldp+125,(vlTOPp->riscv_top__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[18]),32);
            tracep->chgIData(oldp+126,(vlTOPp->riscv_top__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[19]),32);
            tracep->chgIData(oldp+127,(vlTOPp->riscv_top__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[20]),32);
            tracep->chgIData(oldp+128,(vlTOPp->riscv_top__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[21]),32);
            tracep->chgIData(oldp+129,(vlTOPp->riscv_top__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[22]),32);
            tracep->chgIData(oldp+130,(vlTOPp->riscv_top__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[23]),32);
            tracep->chgIData(oldp+131,(vlTOPp->riscv_top__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[24]),32);
            tracep->chgIData(oldp+132,(vlTOPp->riscv_top__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[25]),32);
            tracep->chgIData(oldp+133,(vlTOPp->riscv_top__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[26]),32);
            tracep->chgIData(oldp+134,(vlTOPp->riscv_top__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[27]),32);
            tracep->chgIData(oldp+135,(vlTOPp->riscv_top__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[28]),32);
            tracep->chgIData(oldp+136,(vlTOPp->riscv_top__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[29]),32);
            tracep->chgIData(oldp+137,(vlTOPp->riscv_top__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[30]),32);
            tracep->chgIData(oldp+138,(vlTOPp->riscv_top__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[31]),32);
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[3U])) {
            tracep->chgCData(oldp+139,(vlTOPp->riscv_top__DOT__o_pc_src_e),2);
            tracep->chgBit(oldp+140,(vlTOPp->riscv_top__DOT__u_riscv_hazard__DOT__lw_stall));
            tracep->chgBit(oldp+141,((1U & (IData)(vlTOPp->riscv_top__DOT__o_pc_src_e))));
            tracep->chgIData(oldp+142,(vlTOPp->riscv_top__DOT__o_alu_data),32);
            tracep->chgBit(oldp+143,(vlTOPp->riscv_top__DOT__o_reg_write_e));
            tracep->chgBit(oldp+144,(vlTOPp->riscv_top__DOT__o_mem_write_e));
            tracep->chgCData(oldp+145,(vlTOPp->riscv_top__DOT__o_rd_e),5);
            tracep->chgIData(oldp+146,(vlTOPp->riscv_top__DOT__o_result_w),32);
            tracep->chgCData(oldp+147,(vlTOPp->riscv_top__DOT__o_rd_w),5);
            tracep->chgBit(oldp+148,(vlTOPp->riscv_top__DOT__o_reg_write_w));
            tracep->chgBit(oldp+149,(vlTOPp->riscv_top__DOT__o_flush_e));
            tracep->chgBit(oldp+150,(vlTOPp->riscv_top__DOT__o_reg_write_m));
            tracep->chgCData(oldp+151,(vlTOPp->riscv_top__DOT__o_rd_m),5);
            tracep->chgCData(oldp+152,(vlTOPp->riscv_top__DOT__o_forward_ae),2);
            tracep->chgCData(oldp+153,(vlTOPp->riscv_top__DOT__o_forward_be),2);
            tracep->chgIData(oldp+154,(vlTOPp->riscv_top__DOT__u_riscv_fetch__DOT__u_riscv_mux__DOT__mux_input_arr
                                       [vlTOPp->riscv_top__DOT__o_pc_src_e]),32);
            tracep->chgWData(oldp+155,(vlTOPp->riscv_top__DOT__u_riscv_fetch__DOT____Vcellinp__u_riscv_mux__i_mux_concat_data),128);
            tracep->chgIData(oldp+159,(vlTOPp->riscv_top__DOT__u_riscv_fetch__DOT__u_riscv_mux__DOT__mux_input_arr[0]),32);
            tracep->chgIData(oldp+160,(vlTOPp->riscv_top__DOT__u_riscv_fetch__DOT__u_riscv_mux__DOT__mux_input_arr[1]),32);
            tracep->chgIData(oldp+161,(vlTOPp->riscv_top__DOT__u_riscv_fetch__DOT__u_riscv_mux__DOT__mux_input_arr[2]),32);
            tracep->chgIData(oldp+162,(vlTOPp->riscv_top__DOT__u_riscv_fetch__DOT__u_riscv_mux__DOT__mux_input_arr[3]),32);
            tracep->chgCData(oldp+163,(vlTOPp->riscv_top__DOT__u_riscv_decode__DOT__o_imm_src_d),3);
            tracep->chgCData(oldp+164,(vlTOPp->riscv_top__DOT__u_riscv_decode__DOT__o_result_src_d),2);
            tracep->chgBit(oldp+165,(vlTOPp->riscv_top__DOT__u_riscv_decode__DOT__o_alu_src_d_b));
            tracep->chgCData(oldp+166,(vlTOPp->riscv_top__DOT__u_riscv_decode__DOT__o_alu_ctrl_d),4);
            tracep->chgIData(oldp+167,(vlTOPp->riscv_top__DOT__u_riscv_decode__DOT__o_ext_imm_d),32);
            tracep->chgWData(oldp+168,(vlTOPp->riscv_top__DOT__u_riscv_decode__DOT__u_riscv_ctrl_i__DOT__DEBUG_INSTR),256);
            tracep->chgIData(oldp+176,(vlTOPp->riscv_top__DOT__u_riscv_execute__DOT__o_src_ae),32);
            tracep->chgIData(oldp+177,(vlTOPp->riscv_top__DOT__u_riscv_execute__DOT__o_write_data_e),32);
            tracep->chgIData(oldp+178,(vlTOPp->riscv_top__DOT__u_riscv_execute__DOT__o_src_be),32);
            tracep->chgIData(oldp+179,(((2U >= (IData)(vlTOPp->riscv_top__DOT__o_forward_ae))
                                         ? vlTOPp->riscv_top__DOT__u_riscv_execute__DOT__u_mux_execute_0__DOT__mux_input_arr
                                        [vlTOPp->riscv_top__DOT__o_forward_ae]
                                         : 0U)),32);
            tracep->chgWData(oldp+180,(vlTOPp->riscv_top__DOT__u_riscv_execute__DOT____Vcellinp__u_mux_execute_0__i_mux_concat_data),96);
            tracep->chgIData(oldp+183,(vlTOPp->riscv_top__DOT__u_riscv_execute__DOT__u_mux_execute_0__DOT__mux_input_arr[0]),32);
            tracep->chgIData(oldp+184,(vlTOPp->riscv_top__DOT__u_riscv_execute__DOT__u_mux_execute_0__DOT__mux_input_arr[1]),32);
            tracep->chgIData(oldp+185,(vlTOPp->riscv_top__DOT__u_riscv_execute__DOT__u_mux_execute_0__DOT__mux_input_arr[2]),32);
            tracep->chgQData(oldp+186,(vlTOPp->riscv_top__DOT__u_riscv_execute__DOT____Vcellinp__u_riscv_mux_1__i_mux_concat_data),64);
            tracep->chgIData(oldp+188,(vlTOPp->riscv_top__DOT__u_riscv_execute__DOT__u_riscv_mux_1__DOT__mux_input_arr[0]),32);
            tracep->chgIData(oldp+189,(vlTOPp->riscv_top__DOT__u_riscv_execute__DOT__u_riscv_mux_1__DOT__mux_input_arr[1]),32);
            tracep->chgWData(oldp+190,(vlTOPp->riscv_top__DOT__u_riscv_execute__DOT____Vcellinp__u_mux_execute_2__i_mux_concat_data),96);
            tracep->chgIData(oldp+193,(vlTOPp->riscv_top__DOT__u_riscv_execute__DOT__u_mux_execute_2__DOT__mux_input_arr[0]),32);
            tracep->chgIData(oldp+194,(vlTOPp->riscv_top__DOT__u_riscv_execute__DOT__u_mux_execute_2__DOT__mux_input_arr[1]),32);
            tracep->chgIData(oldp+195,(vlTOPp->riscv_top__DOT__u_riscv_execute__DOT__u_mux_execute_2__DOT__mux_input_arr[2]),32);
            tracep->chgQData(oldp+196,(vlTOPp->riscv_top__DOT__u_riscv_execute__DOT____Vcellinp__u_riscv_mux_3__i_mux_concat_data),64);
            tracep->chgIData(oldp+198,(vlTOPp->riscv_top__DOT__u_riscv_execute__DOT__u_riscv_mux_3__DOT__mux_input_arr[0]),32);
            tracep->chgIData(oldp+199,(vlTOPp->riscv_top__DOT__u_riscv_execute__DOT__u_riscv_mux_3__DOT__mux_input_arr[1]),32);
            tracep->chgBit(oldp+200,((0U == vlTOPp->riscv_top__DOT__o_alu_data)));
            tracep->chgIData(oldp+201,(vlTOPp->riscv_top__DOT__u_riscv_memory__DOT__o_dmem_intf_wr_data),32);
            tracep->chgCData(oldp+202,(vlTOPp->riscv_top__DOT__u_riscv_memory__DOT__o_dmem_intf_byte_sel),4);
            tracep->chgIData(oldp+203,(vlTOPp->riscv_top__DOT__u_riscv_memory__DOT__u_riscv_dmem_interface__DOT__byte_aligned_dmem_rd_data),32);
        }
        tracep->chgIData(oldp+204,(vlTOPp->o_instr_d),32);
        tracep->chgIData(oldp+205,(vlTOPp->o_pc_d),32);
        tracep->chgIData(oldp+206,(vlTOPp->o_alu_result_m),32);
        tracep->chgBit(oldp+207,(vlTOPp->o_mem_write_m));
        tracep->chgCData(oldp+208,(vlTOPp->o_ctrl_mem_byte_sel_m),4);
        tracep->chgIData(oldp+209,(vlTOPp->o_write_data_m),32);
        tracep->chgIData(oldp+210,(vlTOPp->o_mem_read_data),32);
        tracep->chgBit(oldp+211,(vlTOPp->i_clk));
        tracep->chgBit(oldp+212,(vlTOPp->i_rstn));
        tracep->chgBit(oldp+213,(((IData)(vlTOPp->riscv_top__DOT__o_zero_condition_e)
                                   ? (0U != vlTOPp->riscv_top__DOT__o_alu_data)
                                   : (0U == vlTOPp->riscv_top__DOT__o_alu_data))));
        tracep->chgBit(oldp+214,((0x17U == (0x7fU & vlTOPp->o_instr_d))));
        tracep->chgBit(oldp+215,((1U & (~ ((0x23U == 
                                            (0x7fU 
                                             & vlTOPp->o_instr_d)) 
                                           | (0x63U 
                                              == (0x7fU 
                                                  & vlTOPp->o_instr_d)))))));
        tracep->chgBit(oldp+216,((0x23U == (0x7fU & vlTOPp->o_instr_d))));
        tracep->chgIData(oldp+217,(vlTOPp->riscv_top__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers
                                   [(0x1fU & (vlTOPp->o_instr_d 
                                              >> 0xfU))]),32);
        tracep->chgIData(oldp+218,(vlTOPp->riscv_top__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers
                                   [(0x1fU & (vlTOPp->o_instr_d 
                                              >> 0x14U))]),32);
        tracep->chgCData(oldp+219,((((3U == (0x7fU 
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
        tracep->chgBit(oldp+220,((0x67U == (0x7fU & vlTOPp->o_instr_d))));
        tracep->chgBit(oldp+221,(((0x63U == (0x7fU 
                                             & vlTOPp->o_instr_d)) 
                                  & ((0x4000U & vlTOPp->o_instr_d)
                                      ? ((0x2000U & vlTOPp->o_instr_d)
                                          ? (~ (vlTOPp->o_instr_d 
                                                >> 0xcU))
                                          : (~ (vlTOPp->o_instr_d 
                                                >> 0xcU)))
                                      : ((~ (vlTOPp->o_instr_d 
                                             >> 0xdU)) 
                                         & (vlTOPp->o_instr_d 
                                            >> 0xcU))))));
        tracep->chgBit(oldp+222,((0x6fU == (0x7fU & vlTOPp->o_instr_d))));
        tracep->chgBit(oldp+223,((0x63U == (0x7fU & vlTOPp->o_instr_d))));
        tracep->chgCData(oldp+224,((0x7fU & vlTOPp->o_instr_d)),7);
        tracep->chgCData(oldp+225,((7U & (vlTOPp->o_instr_d 
                                          >> 0xcU))),3);
        tracep->chgBit(oldp+226,((1U & (vlTOPp->o_instr_d 
                                        >> 0x1eU))));
        tracep->chgCData(oldp+227,((0x1fU & (vlTOPp->o_instr_d 
                                             >> 0xfU))),5);
        tracep->chgCData(oldp+228,((0x1fU & (vlTOPp->o_instr_d 
                                             >> 0x14U))),5);
        tracep->chgCData(oldp+229,((0x1fU & (vlTOPp->o_instr_d 
                                             >> 7U))),5);
        tracep->chgIData(oldp+230,(((4U & (IData)(vlTOPp->riscv_top__DOT__o_funct3_m))
                                     ? ((2U & (IData)(vlTOPp->riscv_top__DOT__o_funct3_m))
                                         ? 0U : ((1U 
                                                  & (IData)(vlTOPp->riscv_top__DOT__o_funct3_m))
                                                  ? 
                                                 (0xffffU 
                                                  & vlTOPp->riscv_top__DOT__u_riscv_memory__DOT__u_riscv_dmem_interface__DOT__byte_aligned_dmem_rd_data)
                                                  : 
                                                 (0xffU 
                                                  & vlTOPp->riscv_top__DOT__u_riscv_memory__DOT__u_riscv_dmem_interface__DOT__byte_aligned_dmem_rd_data)))
                                     : ((2U & (IData)(vlTOPp->riscv_top__DOT__o_funct3_m))
                                         ? ((1U & (IData)(vlTOPp->riscv_top__DOT__o_funct3_m))
                                             ? 0U : vlTOPp->riscv_top__DOT__u_riscv_memory__DOT__u_riscv_dmem_interface__DOT__byte_aligned_dmem_rd_data)
                                         : ((1U & (IData)(vlTOPp->riscv_top__DOT__o_funct3_m))
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
        tracep->chgIData(oldp+231,(vlTOPp->riscv_top__DOT__u_riscv_memory__DOT__u_riscv_dmem__DOT__dmem_arr
                                   [(0x3fffU & (vlTOPp->o_alu_result_m 
                                                >> 2U))]),32);
        tracep->chgSData(oldp+232,((0x3fffU & (vlTOPp->o_alu_result_m 
                                               >> 2U))),14);
        tracep->chgIData(oldp+233,(vlTOPp->riscv_top__DOT__u_riscv_memory__DOT__u_riscv_dmem__DOT__i),32);
    }
}

void Vriscv_top::traceCleanup(void* userp, VerilatedVcd* /*unused*/) {
    Vriscv_top__Syms* __restrict vlSymsp = static_cast<Vriscv_top__Syms*>(userp);
    Vriscv_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        vlTOPp->__Vm_traceActivity[0U] = 0U;
        vlTOPp->__Vm_traceActivity[1U] = 0U;
        vlTOPp->__Vm_traceActivity[2U] = 0U;
        vlTOPp->__Vm_traceActivity[3U] = 0U;
    }
}
