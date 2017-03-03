#include <stdio.h>

#include "afifo.c"
#include "Clk_ctrl.c"
#include "Phy_int.c"
#include "reg_int.c"
#include "MAC_tx.c"
#include "MAC_rx.c"
#include "RMON.c"
#include "eth_miim.c"

#define TRUE 1
#define FALSE 0

struct state_elements_MAC_top{
_Bool rx_pkg_lgth_fifo_wr_tmp;
_Bool rx_pkg_lgth_fifo_wr_tmp_pl1;
_Bool rx_pkg_lgth_fifo_wr;
};
struct state_elements_MAC_top  sMAC_top;

void MAC_top(_Bool Reset, _Bool Clk_125M, _Bool Clk_user, _Bool Clk_reg, unsigned char *Speed, _Bool *Rx_mac_ra, _Bool Rx_mac_rd, unsigned int *Rx_mac_data, unsigned char *Rx_mac_BE, _Bool *Rx_mac_pa, _Bool *Rx_mac_sop, _Bool *Rx_mac_eop, _Bool *Tx_mac_wa, _Bool Tx_mac_wr, unsigned int Tx_mac_data, unsigned char Tx_mac_BE, _Bool Tx_mac_sop, _Bool Tx_mac_eop, _Bool Pkg_lgth_fifo_rd, _Bool *Pkg_lgth_fifo_ra, unsigned short int *Pkg_lgth_fifo_data, _Bool *Gtx_clk, _Bool Rx_clk, _Bool Tx_clk, _Bool *Tx_er, _Bool *Tx_en, unsigned char *Txd, _Bool Rx_er, _Bool Rx_dv, unsigned char Rxd, _Bool Crs, _Bool Col, _Bool CSB, _Bool WRB, unsigned short int CD_in, unsigned short int *CD_out, unsigned char CA, _Bool *Mdo, _Bool *MdoEn, _Bool Mdi, _Bool *Mdc)
{
  _Bool tmp7;
  _Bool tmp6;
  _Bool tmp5;
  _Bool tmp4;
  _Bool tmp3;
  _Bool tmp2;
  _Bool tmp1;
  _Bool tmp0;
  unsigned short int Rx_pkt_length_rmon;
  _Bool Rx_apply_rmon;
  unsigned char Rx_pkt_err_type_rmon;
  unsigned char Rx_pkt_type_rmon;
  unsigned char Tx_pkt_type_rmon;
  unsigned short int Tx_pkt_length_rmon;
  _Bool Tx_apply_rmon;
  unsigned char Tx_pkt_err_type_rmon;
  _Bool MCrs_dv;
  unsigned char MRxD;
  _Bool MRxErr;
  unsigned short int pause_quanta;
  _Bool pause_quanta_val;
  unsigned char MTxD;
  _Bool MTxEn;
  _Bool MCRS;
  _Bool MAC_tx_clk;
  _Bool MAC_rx_clk;
  _Bool MAC_tx_clk_div;
  _Bool MAC_rx_clk_div;
  unsigned char Tx_Hwmark;
  unsigned char Tx_Lwmark;
  _Bool pause_frame_send_en;
  unsigned short int pause_quanta_set;
  _Bool MAC_tx_add_en;
  _Bool FullDuplex;
  unsigned char MaxRetry;
  unsigned char IFGset;
  unsigned char MAC_tx_add_prom_data;
  unsigned char MAC_tx_add_prom_add;
  _Bool MAC_tx_add_prom_wr;
  _Bool tx_pause_en;
  _Bool xoff_cpu;
  _Bool xon_cpu;
  _Bool MAC_rx_add_chk_en;
  unsigned char MAC_rx_add_prom_data;
  unsigned char MAC_rx_add_prom_add;
  _Bool MAC_rx_add_prom_wr;
  _Bool broadcast_filter_en;
  unsigned short int broadcast_MAX;
  _Bool RX_APPEND_CRC;
  unsigned char Rx_Hwmark;
  unsigned char Rx_Lwmark;
  _Bool CRC_chk_en;
  unsigned char RX_IFG_SET;
  unsigned short int RX_MAX_LENGTH;
  unsigned char RX_MIN_LENGTH;
  unsigned char CPU_rd_addr;
  _Bool CPU_rd_apply;
  _Bool CPU_rd_grant;
  unsigned int CPU_rd_dout;
  _Bool Line_loop_en;
  unsigned char Divider;
  unsigned short int CtrlData;
  unsigned char Rgad;
  unsigned char Fiad;
  _Bool NoPre;
  _Bool WCtrlData;
  _Bool RStat;
  _Bool ScanStat;
  _Bool Busy;
  _Bool LinkFail;
  _Bool Nvalid;
  unsigned short int Prsd;
  _Bool WCtrlDataStart;
  _Bool RStatStart;
  _Bool UpdateMIIRX_DATAReg;
  unsigned short int broadcast_bucket_depth;
  unsigned short int broadcast_bucket_interval;
  _Bool Pkg_lgth_fifo_empty;
 
  // interfaces for afifo
  unsigned int tmp;
 _Bool full;
 _Bool almost_full;
 unsigned char wr_count;
 unsigned char rd_count;
 _Bool rd_ack;
 _Bool wr_ack;

 if(RX_APPEND_CRC)
   tmp = Rx_pkt_length_rmon;
 else
   tmp = Rx_pkt_length_rmon-4;
    
 
  
  MAC_tx(Reset, MAC_tx_clk_div, Clk_user, &MTxD, &MTxEn, MCRS, &Tx_pkt_type_rmon, &Tx_pkt_length_rmon, &Tx_apply_rmon, &Tx_pkt_err_type_rmon, &Tx_mac_wa, Tx_mac_wr, Tx_mac_data, Tx_mac_BE, Tx_mac_sop, Tx_mac_eop, Tx_Hwmark, Tx_Lwmark, pause_frame_send_en, pause_quanta_set, MAC_tx_add_en, FullDuplex, MaxRetry, IFGset, MAC_tx_add_prom_data, MAC_tx_add_prom_add, MAC_tx_add_prom_wr, tx_pause_en, xoff_cpu, xon_cpu, pause_quanta, pause_quanta_val);

 MAC_rx(Reset, Clk_user, MAC_rx_clk_div, MCrs_dv, MRxD, MRxErr, &pause_quanta, &pause_quanta_val, &Rx_mac_ra, Rx_mac_rd, &Rx_mac_data, &Rx_mac_BE, &Rx_mac_pa, &Rx_mac_sop, &Rx_mac_eop, MAC_rx_add_chk_en, MAC_rx_add_prom_data, MAC_rx_add_prom_add, MAC_rx_add_prom_wr, broadcast_filter_en, broadcast_bucket_depth, broadcast_bucket_interval, RX_APPEND_CRC, Rx_Hwmark, Rx_Lwmark, CRC_chk_en, RX_IFG_SET, RX_MAX_LENGTH, RX_MIN_LENGTH, &Rx_pkt_length_rmon, &Rx_apply_rmon, &Rx_pkt_err_type_rmon, &Rx_pkt_type_rmon);
  
  Pkg_lgth_fifo_ra = !Pkg_lgth_fifo_empty;
  if(Reset)
    tmp0 = FALSE;

  else
    if(Rx_apply_rmon && Rx_pkt_err_type_rmon == 4)
      tmp1 = TRUE;

    else
      tmp2 = FALSE;
  if(Reset)
    tmp3 = FALSE;

  else
    tmp4 = sMAC_top.rx_pkg_lgth_fifo_wr_tmp;
  if(Reset)
    tmp5 = FALSE;

  else
    if(sMAC_top.rx_pkg_lgth_fifo_wr_tmp && !sMAC_top.rx_pkg_lgth_fifo_wr_tmp_pl1)
      tmp6 = TRUE;

    else
      tmp7 = FALSE;
  if(Reset)
    sMAC_top.rx_pkg_lgth_fifo_wr_tmp = tmp0;

  else
    if(Rx_apply_rmon && Rx_pkt_err_type_rmon == 4)
      sMAC_top.rx_pkg_lgth_fifo_wr_tmp = tmp1;

    else
      sMAC_top.rx_pkg_lgth_fifo_wr_tmp = tmp2;

    // Property must hold here
    //assert(!(Rx_apply_rmon && Rx_pkt_err_type_rmon == 4) || (sMAC_top.rx_pkg_lgth_fifo_wr_tmp == 1));

    //assert(!(Rx_apply_rmon && Rx_pkt_err_type_rmon == 4) || (sMAC_top.rx_pkg_lgth_fifo_wr_tmp == 0));

  if(Reset)
    sMAC_top.rx_pkg_lgth_fifo_wr_tmp_pl1 = tmp3;

  else
    sMAC_top.rx_pkg_lgth_fifo_wr_tmp_pl1 = tmp4;
  if(Reset)
    sMAC_top.rx_pkg_lgth_fifo_wr = tmp5;

  else
    if(sMAC_top.rx_pkg_lgth_fifo_wr_tmp && !sMAC_top.rx_pkg_lgth_fifo_wr_tmp_pl1)
      sMAC_top.rx_pkg_lgth_fifo_wr = tmp6;

    else
      sMAC_top.rx_pkg_lgth_fifo_wr = tmp7;


    // Property must hold here
    // The package length fifo write must be HIGH here
    assert(!(sMAC_top.rx_pkg_lgth_fifo_wr_tmp && !sMAC_top.rx_pkg_lgth_fifo_wr_tmp_pl1) || (sMAC_top.rx_pkg_lgth_fifo_wr == 1));

afifo(tmp, sMAC_top.rx_pkg_lgth_fifo_wr, MAC_rx_clk_div, Pkg_lgth_fifo_rd, Clk_user, Reset, &Pkg_lgth_fifo_data, &full, &almost_full, &Pkg_lgth_fifo_empty, &wr_count, &rd_count, &rd_ack, &wr_ack);

RMON(Clk_reg, Reset, Tx_pkt_type_rmon, Tx_pkt_length_rmon, Tx_apply_rmon, Tx_pkt_err_type_rmon, Rx_pkt_type_rmon, Rx_pkt_length_rmon, Rx_apply_rmon, Rx_pkt_err_type_rmon, CPU_rd_addr, CPU_rd_apply, &CPU_rd_grant, &CPU_rd_dout);

Phy_int(Reset, MAC_rx_clk, MAC_tx_clk, &MCrs_dv, &MRxD, &MRxErr, MTxD, MTxEn, &MCRS, &Tx_er, &Tx_en, &Txd, Rx_er, Rx_dv, Rxd, Crs, Col, Line_loop_en, Speed);

Clk_ctrl(Reset, Clk_125M, Speed, &Gtx_clk, Rx_clk, Tx_clk, &MAC_tx_clk, &MAC_rx_clk, &MAC_tx_clk_div, &MAC_rx_clk_div);

eth_miim(Clk_reg, Reset, Divider, CtrlData, Rgad, Fiad, NoPre, WCtrlData, RStat, ScanStat, &Mdo, &MdoEn, Mdi, &Mdc, &Busy, &LinkFail, &Nvalid, &Prsd, &WCtrlDataStart, &RStatStart, &UpdateMIIRX_DATAReg);

Reg_int(Reset, Clk_reg, CSB, WRB, CD_in, &CD_out, CA, &Tx_Hwmark, &Tx_Lwmark, &pause_frame_send_en, &pause_quanta_set, &MAC_tx_add_en, &FullDuplex, &MaxRetry, &IFGset, &MAC_tx_add_prom_data, &MAC_tx_add_prom_add, &MAC_tx_add_prom_wr, &tx_pause_en, &xoff_cpu, &xon_cpu, &MAC_rx_add_chk_en, &MAC_rx_add_prom_data, &MAC_rx_add_prom_add, &MAC_rx_add_prom_wr, &broadcast_filter_en, &broadcast_bucket_depth, &broadcast_bucket_interval, &RX_APPEND_CRC, &Rx_Hwmark, &Rx_Lwmark, &CRC_chk_en, &RX_IFG_SET, &RX_MAX_LENGTH, &RX_MIN_LENGTH, &CPU_rd_addr, &CPU_rd_apply, CPU_rd_grant, CPU_rd_dout, &Line_loop_en, &Speed, &Divider, &CtrlData, &Rgad, &Fiad, &NoPre, &WCtrlData, &RStat, &ScanStat, Busy, LinkFail, Nvalid, Prsd, WCtrlDataStart, RStatStart, UpdateMIIRX_DATAReg);

}

void main() {
_Bool Reset;
_Bool Clk_125M;
_Bool Clk_user;
_Bool Clk_reg;
unsigned char Speed;
_Bool Rx_mac_ra;
_Bool Rx_mac_rd;
unsigned int Rx_mac_data;
unsigned char Rx_mac_BE;
_Bool Rx_mac_pa;
_Bool Rx_mac_sop;
_Bool Rx_mac_eop;
_Bool Tx_mac_wa;
_Bool Tx_mac_wr;
unsigned int Tx_mac_data;
unsigned char Tx_mac_BE;
_Bool Tx_mac_sop;
_Bool Tx_mac_eop;
_Bool Pkg_lgth_fifo_rd;
_Bool Pkg_lgth_fifo_ra;
unsigned short int Pkg_lgth_fifo_data;
_Bool Gtx_clk;
_Bool Rx_clk;
_Bool Tx_clk;
_Bool Tx_er;
_Bool Tx_en;
unsigned char Txd;
_Bool Rx_er;
_Bool Rx_dv;
unsigned char Rxd;
_Bool Crs;
_Bool Col;
_Bool CSB;
_Bool WRB;
unsigned short int CD_in;
unsigned short int CD_out;
unsigned char CA;
_Bool Mdo;
_Bool MdoEn;
_Bool Mdi;
_Bool Mdc;

 MAC_top(Reset, Clk_125M, Clk_user, Clk_reg, &Speed, &Rx_mac_ra, Rx_mac_rd, &Rx_mac_data, &Rx_mac_BE, &Rx_mac_pa, &Rx_mac_sop, &Rx_mac_eop, &Tx_mac_wa, Tx_mac_wr, Tx_mac_data, Tx_mac_BE, Tx_mac_sop, Tx_mac_eop, Pkg_lgth_fifo_rd, &Pkg_lgth_fifo_ra, &Pkg_lgth_fifo_data, &Gtx_clk, Rx_clk, Tx_clk, &Tx_er, &Tx_en, &Txd, Rx_er, Rx_dv, Rxd, Crs, Col, CSB, WRB, CD_in, &CD_out, CA, &Mdo, &MdoEn, Mdi, &Mdc);

}
