//#include <stdio.h>
#define TRUE 1
#define FALSE 0

struct state_elements_RegCPUData{
  unsigned short int RegOut;
};

void RegCPUData(unsigned short int *RegOut, unsigned char CA_reg_set, unsigned short int RegInit, _Bool Reset, _Bool Clk, _Bool CWR_pulse, _Bool CCSB, unsigned char CA_reg, unsigned short int CD_in_reg)
{
  struct state_elements_RegCPUData  sRegCPUData;
  unsigned short int tmp1;
  unsigned short int tmp0;
  if(Reset)
    tmp0 = RegInit;

  else
    if(CWR_pulse && !CCSB && (CA_reg >> 1 & 0x7F)  == (CA_reg_set & 0x7F))
      tmp1 = CD_in_reg;

  if(Reset)
  {
    sRegCPUData.RegOut = tmp0;
    *RegOut = tmp0;
  }

  else
    if(CWR_pulse && !CCSB && (CA_reg >> 1 & 0x7F) == (CA_reg_set & 0x7F))
    {
      sRegCPUData.RegOut = tmp1;
      *RegOut = tmp1;
    }
}

struct state_elements_Reg_int{
  struct state_elements_RegCPUData U_0_000;
   struct state_elements_RegCPUData U_0_001;
   struct state_elements_RegCPUData U_0_002;
   struct state_elements_RegCPUData U_0_003;
   struct state_elements_RegCPUData U_0_004;
   struct state_elements_RegCPUData U_0_005;
   struct state_elements_RegCPUData U_0_006;
   struct state_elements_RegCPUData U_0_007;
   struct state_elements_RegCPUData U_0_008;
   struct state_elements_RegCPUData U_0_009;
   struct state_elements_RegCPUData U_0_010;
   struct state_elements_RegCPUData U_0_011;
   struct state_elements_RegCPUData U_0_012;
   struct state_elements_RegCPUData U_0_013;
   struct state_elements_RegCPUData U_0_014;
   struct state_elements_RegCPUData U_0_015;
   struct state_elements_RegCPUData U_0_016;
   struct state_elements_RegCPUData U_0_017;
   struct state_elements_RegCPUData U_0_018;
   struct state_elements_RegCPUData U_0_019;
   struct state_elements_RegCPUData U_0_020;
   struct state_elements_RegCPUData U_0_021;
   struct state_elements_RegCPUData U_0_022;
   struct state_elements_RegCPUData U_0_023;
   struct state_elements_RegCPUData U_0_024;
   struct state_elements_RegCPUData U_0_025;
   struct state_elements_RegCPUData U_0_026;
   struct state_elements_RegCPUData U_0_027;
   struct state_elements_RegCPUData U_0_028;
   struct state_elements_RegCPUData U_0_029;
   struct state_elements_RegCPUData U_0_033;
   struct state_elements_RegCPUData U_0_034;
   unsigned short int CD_out;
};

void Reg_int(_Bool Reset, _Bool Clk_reg, _Bool CSB, _Bool WRB, unsigned short int CD_in, unsigned short int *CD_out, unsigned char CA, unsigned char *Tx_Hwmark, unsigned char *Tx_Lwmark, _Bool *pause_frame_send_en, unsigned short int *pause_quanta_set, _Bool *MAC_tx_add_en, _Bool *FullDuplex, unsigned char *MaxRetry, unsigned char *IFGset, unsigned char *MAC_tx_add_prom_data, unsigned char *MAC_tx_add_prom_add, _Bool *MAC_tx_add_prom_wr, _Bool *tx_pause_en, _Bool *xoff_cpu, _Bool *xon_cpu, _Bool *MAC_rx_add_chk_en, unsigned char *MAC_rx_add_prom_data, unsigned char *MAC_rx_add_prom_add, _Bool *MAC_rx_add_prom_wr, _Bool *broadcast_filter_en, unsigned short int *broadcast_bucket_depth, unsigned short int *broadcast_bucket_interval, _Bool *RX_APPEND_CRC, unsigned char *Rx_Hwmark, unsigned char *Rx_Lwmark, _Bool *CRC_chk_en, unsigned char *RX_IFG_SET, unsigned short int *RX_MAX_LENGTH, unsigned char *RX_MIN_LENGTH, unsigned char *CPU_rd_addr, _Bool *CPU_rd_apply, _Bool CPU_rd_grant, unsigned int CPU_rd_dout, _Bool *Line_loop_en, unsigned char *Speed, unsigned char *Divider, unsigned short int *CtrlData, unsigned char *Rgad, unsigned char *Fiad, _Bool *NoPre, _Bool *WCtrlData, _Bool *RStat, _Bool *ScanStat, _Bool Busy, _Bool LinkFail, _Bool Nvalid, unsigned short int Prsd, _Bool WCtrlDataStart, _Bool RStatStart, _Bool UpdateMIIRX_DATAReg)

{ 
  unsigned short int tmp0, tmp1, tmp2, tmp3, tmp4, tmp5, tmp6, tmp7, tmp8, tmp9, tmp10,
  tmp11, tmp12, tmp13, tmp14, tmp15, tmp16, tmp17, tmp18, tmp19, tmp20, tmp21, tmp22,
  tmp23, tmp24, tmp25, tmp26, tmp27, tmp28, tmp29, tmp30, tmp31, tmp32, tmp33, tmp34;

  struct state_elements_Reg_int  sReg_int;

    RegCPUData(Tx_Hwmark, 0, 9, Reset, Clk_reg, !WRB, CSB, CA, CD_in);
    RegCPUData(Tx_Lwmark, 1, 8, Reset, Clk_reg, !WRB, CSB, CA, CD_in);
    RegCPUData(pause_frame_send_en, 2, 0, Reset, Clk_reg, !WRB, CSB, CA, CD_in);
    RegCPUData(pause_quanta_set, 3, 0, Reset, Clk_reg, !WRB, CSB, CA, CD_in);
    RegCPUData(IFGset, 4, 12, Reset, Clk_reg, !WRB, CSB, CA, CD_in);
    RegCPUData(FullDuplex, 5, 1, Reset, Clk_reg, !WRB, CSB, CA, CD_in);
    RegCPUData(MaxRetry, 6, 2, Reset, Clk_reg, !WRB, CSB, CA, CD_in);
    RegCPUData(MAC_tx_add_en, 7, 0, Reset, Clk_reg, !WRB, CSB, CA, CD_in);
    RegCPUData(MAC_tx_add_prom_data, 8, 0, Reset, Clk_reg, !WRB, CSB, CA, CD_in);
    RegCPUData(MAC_tx_add_prom_add, 9, 0, Reset, Clk_reg, !WRB, CSB, CA, CD_in);
    RegCPUData(MAC_tx_add_prom_wr, 10, 0, Reset, Clk_reg, !WRB, CSB, CA, CD_in);
    RegCPUData(tx_pause_en, 11, 0, Reset, Clk_reg, !WRB, CSB, CA, CD_in);
    RegCPUData(xoff_cpu, 12, 0, Reset, Clk_reg, !WRB, CSB, CA, CD_in);
    RegCPUData(xon_cpu, 13, 0, Reset, Clk_reg, !WRB, CSB, CA, CD_in);
    RegCPUData(MAC_rx_add_chk_en, 14, 0, Reset, Clk_reg, !WRB, CSB, CA, CD_in);
    RegCPUData(MAC_rx_add_prom_data, 15, 0, Reset, Clk_reg, !WRB, CSB, CA, CD_in);
    RegCPUData(MAC_rx_add_prom_add, 16, 0, Reset, Clk_reg, !WRB, CSB, CA, CD_in);
    RegCPUData(MAC_rx_add_prom_wr, 17, 0, Reset, Clk_reg, !WRB, CSB, CA, CD_in);
    RegCPUData(broadcast_filter_en, 18, 0, Reset, Clk_reg, !WRB, CSB, CA, CD_in);
    RegCPUData(broadcast_bucket_depth, 19, 0, Reset, Clk_reg, !WRB, CSB, CA, CD_in);
    RegCPUData(broadcast_bucket_interval, 20, 0, Reset, Clk_reg, !WRB, CSB, CA, CD_in);
    RegCPUData(RX_APPEND_CRC, 21, 0, Reset, Clk_reg, !WRB, CSB, CA, CD_in);
    RegCPUData(Rx_Hwmark, 22, 26, Reset, Clk_reg, !WRB, CSB, CA, CD_in);
    RegCPUData(Rx_Lwmark, 23, 16, Reset, Clk_reg, !WRB, CSB, CA, CD_in);
    RegCPUData(CRC_chk_en, 24, 0, Reset, Clk_reg, !WRB, CSB, CA, CD_in);
    RegCPUData(RX_IFG_SET, 25, 12, Reset, Clk_reg, !WRB, CSB, CA, CD_in);
    RegCPUData(RX_MAX_LENGTH, 26, 10000, Reset, Clk_reg, !WRB, CSB, CA, CD_in);
    RegCPUData(RX_MIN_LENGTH, 27, 64, Reset, Clk_reg, !WRB, CSB, CA, CD_in);
    RegCPUData(CPU_rd_addr, 28, 0, Reset, Clk_reg, !WRB, CSB, CA, CD_in);
    RegCPUData(CPU_rd_apply, 29, 0, Reset, Clk_reg, !WRB, CSB, CA, CD_in);
    RegCPUData(Line_loop_en, 33, 0, Reset, Clk_reg, !WRB, CSB, CA, CD_in);
    RegCPUData(Speed, 34, 4, Reset, Clk_reg, !WRB, CSB, CA, CD_in);
  
  if(Reset)
    tmp0 = 0;
   
  else if (!CSB && WRB)
         switch(CA >> 1 & 0x7F) {
                case 0:     tmp0 = (unsigned int)*Tx_Hwmark;
                case 1:     tmp1 = (unsigned int)*Tx_Lwmark; 
                case 2:     tmp2 = *pause_frame_send_en; 
                case 3:     tmp3 = *pause_quanta_set;
                case 4:     tmp4 = (unsigned short int)*IFGset; 
                case 5:     tmp5 = *FullDuplex; 
                case 6:     tmp6  = (unsigned short int)*MaxRetry;
                case 7:     tmp7 = *MAC_tx_add_en; 
                case 8:     tmp8 = (unsigned short int)*MAC_tx_add_prom_data;
                case 9:     tmp9 = (unsigned short int)*MAC_tx_add_prom_add; 
                case 10:    tmp10 = (unsigned short int)*MAC_tx_add_prom_wr; 
                case 11:    tmp11 = *tx_pause_en; 
                case 12:    tmp12 = *xoff_cpu;
                case 13:    tmp13 = *xon_cpu; 
                case 14:    tmp14 = *MAC_rx_add_chk_en; 
                case 15:    tmp15 = (unsigned short int)*MAC_rx_add_prom_data;
                case 16:    tmp16 = (unsigned short int)*MAC_rx_add_prom_add; 
                case 17:    tmp17 = *MAC_rx_add_prom_wr; 
                case 18:    tmp18 = *broadcast_filter_en; 
                case 19:    tmp19 = (unsigned short int)*broadcast_bucket_depth;    
                case 20:    tmp20 = (unsigned short int)*broadcast_bucket_interval;   
                case 21:    tmp21 = *RX_APPEND_CRC; 
                case 22:    tmp22 = (unsigned short int)*Rx_Hwmark; 
                case 23:    tmp23 = (unsigned short int)*Rx_Lwmark; 
                case 24:    tmp24 = *CRC_chk_en; 
                case 25:    tmp25 = (unsigned short int)*RX_IFG_SET; 
                case 26:    tmp26 = *RX_MAX_LENGTH; 
                case 27:    tmp27 = *RX_MIN_LENGTH; 
                case 28:    tmp28 = *CPU_rd_addr; 
                case 29:    tmp29 = *CPU_rd_apply;
                case 30:    tmp30 = CPU_rd_grant;
                case 31:    tmp31 = CPU_rd_dout & 0xFFFF; 
                case 32:    tmp32 = CPU_rd_dout >> 16 & 0xFFFF;                 
                case 33:    tmp33 = *Line_loop_en;               
                case 34:    tmp34 = (unsigned int)*Speed;                       
                default:  *CD_out = 0;                          
             }

  if(Reset)
    *CD_out = tmp0;
  else if (!CSB && WRB)
        switch (CA >> 1 & 0x7F) {
                case 0:    *CD_out= tmp0;
                case 1:    *CD_out= tmp1; 
                case 2:    *CD_out= tmp2; 
                case 3:    *CD_out= tmp3;
                case 4:    *CD_out= tmp4; 
                case 5:    *CD_out= tmp5;                  
                case 6:    *CD_out= tmp6;                  
                case 7:    *CD_out= tmp7;              
                case 8:    *CD_out= tmp8;       
                case 9:    *CD_out= tmp9;        
                case 10:    *CD_out= tmp10;          
                case 11:    *CD_out= tmp11;                 
                case 12:    *CD_out= tmp12;                   
                case 13:    *CD_out= tmp13;                     
                case 14:    *CD_out= tmp14;           
                case 15:    *CD_out= tmp15;       
                case 16:    *CD_out= tmp16;         
                case 17:    *CD_out= tmp17;          
                case 18:    *CD_out= tmp18;         
                case 19:    *CD_out= tmp19;         
                case 20:    *CD_out= tmp20;     
                case 21:    *CD_out= tmp21;               
                case 22:    *CD_out= tmp22;                   
                case 23:    *CD_out= tmp23;                   
                case 24:    *CD_out= tmp24;                  
                case 25:    *CD_out= tmp25;                  
                case 26:    *CD_out= tmp26;               
                case 27:    *CD_out= tmp27;               
                case 28:    *CD_out= tmp28;                 
                case 29:    *CD_out= tmp29;               
                case 30:    *CD_out= tmp29;              
                case 31:    *CD_out= tmp30;           
                case 32:    *CD_out= tmp31;                          
                case 33:    *CD_out= tmp32;               
                case 34:    *CD_out= tmp33;                      
                default:  *CD_out= 0;                          
        }
}

