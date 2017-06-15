#include <stdio.h>
#include <assert.h>
#include "rtfSimpleUartTx.c"
#include "rtfSimpleUartRx.c"
#include "edge_det.c"

#define TRUE 1
#define FALSE 0


struct state_elements_rtfSimpleUart{
 _Bool hwfc;
 _Bool loopback;
 unsigned char ctsx;
 unsigned char dcdx;
 unsigned char dsrx;
 unsigned char dat_o;
 unsigned int c;
 unsigned int ck_mul;
 unsigned char spr;
 _Bool rts_no;
 _Bool rx_present_ie;
 _Bool tx_empty_ie;
 _Bool dtr_no;
 _Bool dcd_ie;
};
struct state_elements_rtfSimpleUart  srtfSimpleUart;

void rtfSimpleUart(_Bool rst_i, _Bool clk_i, _Bool cyc_i, _Bool stb_i, _Bool we_i, unsigned int adr_i, unsigned char dat_i, unsigned char *dat_o, _Bool *ack_o, _Bool *vol_o, _Bool *irq_o, _Bool cts_ni, _Bool *rts_no, _Bool dsr_ni, _Bool dcd_ni, _Bool *dtr_no, _Bool rxd_i, _Bool *txd_o, _Bool *data_present_o)
{
  _Bool cs;
  unsigned int c_old;
  unsigned int ck_mul_old;
  unsigned char spr_old;
  _Bool tx_empty;
  _Bool baud16;
  _Bool rx_present_ie_old;
  _Bool tx_empty_ie_old;
  _Bool dcd_ie_old;
  _Bool hwfc_old;
  _Bool loopback_old;
  _Bool clear;
  _Bool frame_err;
  _Bool over_run;
  unsigned char ctsx_old;
  unsigned char dcdx_old;
  unsigned char dsrx_old;
  _Bool dcd_chg;
  _Bool rxIRQ;
  _Bool txIRQ;
  _Bool msIRQ;
  unsigned char irqenc;
  unsigned char rx_do;
  _Bool txrx;
  _Bool txd_int;
  _Bool rxd_int;
  _Bool cts_nint;
  _Bool ne;
  _Bool ee;
  _Bool nb;
  __ASTREE_volatile_input((nb));
  
  // parameters declared:
  int pClkFreq = 20000000;
  int pBaud = 19200;
  int pClkMul =  (4096 * pBaud) / (pClkFreq / 65536);
  int pRts = 1;
  int pDtr = 1;
  
  // update shadow variables
  c_old = srtfSimpleUart.c;
  rx_present_ie_old = srtfSimpleUart.rx_present_ie;
  tx_empty_ie_old = srtfSimpleUart.tx_empty_ie;
  dcd_ie_old = srtfSimpleUart.dcd_ie;
  hwfc_old = srtfSimpleUart.hwfc;
  loopback_old = srtfSimpleUart.loopback;
  ck_mul_old = srtfSimpleUart.ck_mul;
  spr_old = srtfSimpleUart.spr;
  ctsx_old = srtfSimpleUart.ctsx;
  dcdx_old = srtfSimpleUart.dcdx;
  dsrx_old = srtfSimpleUart.dsrx;
  
  // assign nondet to cs
  cs = nb;

  *ack_o = cs;
  *vol_o = cs && (((adr_i >> 2) & 3) == 0);

  cs = cyc_i && stb_i && (((adr_i >> 4) & 0xFFFFFFF) == 0xFFDC0A0);
  clear = cyc_i && stb_i && we_i && ((adr_i & 0xF) == 13);
  dcd_chg = ((srtfSimpleUart.dcdx >> 1) & 0x1) ^ (srtfSimpleUart.dcdx & 0x1);
  
  rxIRQ = srtfSimpleUartRx.data_present && srtfSimpleUart.rx_present_ie;
  txIRQ = srtfSimpleUartTx.empty && srtfSimpleUart.tx_empty_ie;
  msIRQ = dcd_chg && srtfSimpleUart.dcd_ie;
  irqenc = rxIRQ ? 1 : (txIRQ ? 3 : (msIRQ ? 4 : 0));
  txrx = cs && ((adr_i & 0xf) == 0);
  *irq_o = (rxIRQ | txIRQ | msIRQ);
 
  
  // clocked block
  if(rst_i)
    srtfSimpleUart.c = 0;
  else
    srtfSimpleUart.c = c_old + ck_mul_old;
  
  if(rst_i)
  {
    srtfSimpleUart.rts_no = !((pRts >> 0) & 1);
    *rts_no = !((pRts >> 0) & 1);
    srtfSimpleUart.rx_present_ie = FALSE;
    srtfSimpleUart.tx_empty_ie = FALSE;
    srtfSimpleUart.dcd_ie = FALSE;
    srtfSimpleUart.hwfc = TRUE;
    srtfSimpleUart.dtr_no = !((pDtr >> 0) & 1);
    *dtr_no = !((pDtr >> 0) & 1);
    srtfSimpleUart.loopback = FALSE;
    srtfSimpleUart.ck_mul = (unsigned int)pClkMul;
    srtfSimpleUart.spr = 0;
  }

  else
    if(cs && we_i)
    {
        if((adr_i&0xf) == 4)
        {
          srtfSimpleUart.rx_present_ie = ((dat_i >> 0) & 1);
          srtfSimpleUart.tx_empty_ie = ((dat_i >> 1) & 1);
          srtfSimpleUart.dcd_ie = ((dat_i >> 3) & 1);
        }

        else
          if((adr_i&0xf) == 6)
          {
            srtfSimpleUart.dtr_no = !((dat_i >> 0) & 1);
            *dtr_no = !((dat_i >> 0) & 1);
            srtfSimpleUart.rts_no = !((dat_i >> 1) & 1);
            *rts_no = !((dat_i >> 1) & 1);
            srtfSimpleUart.loopback = ((dat_i >> 4) & 1);
          }

        else
          if((adr_i&0xf) == 7)
             srtfSimpleUart.hwfc = ((dat_i >> 0) & 1);

        else
          if((adr_i&0xf) == 9)
            srtfSimpleUart.ck_mul = (ck_mul_old & 0xffff00) | (dat_i & 255);

         else
           if((adr_i&0xf) == 10)
             srtfSimpleUart.ck_mul = (ck_mul_old & 0xff00ff) | ((dat_i << 8) & 0x00ff00);

          else
            if((adr_i&0xf) == 11)
              srtfSimpleUart.ck_mul = (ck_mul_old & 0x00ffff) | ((dat_i << 16) & 0xff0000);

          else if((adr_i&0xf) == 15)
              srtfSimpleUart.spr = dat_i;

          else {}
    }

  // nondet boolean assignment
  cts_nint = nb;
  // synchronize external signals
  srtfSimpleUart.ctsx = ((ctsx_old & 0x1) << 1) | (!cts_nint);
  srtfSimpleUart.dcdx = ((dcdx_old & 0x1) << 1) | (!dcd_ni);
  srtfSimpleUart.dsrx = ((dsrx_old & 0x1) << 1) | (!dsr_ni);


  // call to edge detector
  _Bool i = ((srtfSimpleUart.c >> 23) & 1);
  _Bool val=1;
  edge_det(rst_i, clk_i, val, i, &baud16, &ne, &ee);
  
  
  
  // call to transmitter
  _Bool txc;
  _Bool temp1 = ((srtfSimpleUart.ctsx >> 1) & 1) | ~srtfSimpleUart.hwfc;
  rtfSimpleUartTx(rst_i, clk_i, cyc_i, stb_i, ack_o, we_i, dat_i, txrx, baud16, 0, temp1, &txd_int, &tx_empty, &txc);
 
  
  // logic for loopback mode
  rxd_int = loopback_old ? d.txdd : rxd_i;
  // call to receiver
  unsigned char temp0 = 0;
  rtfSimpleUartRx(rst_i, clk_i, cyc_i, stb_i, ack_o, we_i, &rx_do, txrx, baud16, temp0, clear, rxd_int, data_present_o, &frame_err, &over_run);
  
  *txd_o = loopback_old ? 1 : d.txdd;
  cts_nint = loopback_old ? srtfSimpleUartRx.data_present : cts_ni;

  
  // continuous assignments  
  if(cs)
  {
    if((adr_i&0xf) == 1) {
     srtfSimpleUart.dat_o = (*data_present_o) | (srtfSimpleUartRx.overrun << 1)  | (0 << 2) | (srtfSimpleUartRx.frame_err << 3) | (0 << 4) | (srtfSimpleUartTx.empty << 5) | (srtfSimpleUartTx.empty << 6) | (0 << 7);
     *dat_o = srtfSimpleUart.dat_o;
    }

    else if((adr_i&0xF) == 2) {
     srtfSimpleUart.dat_o = (0 & 0x7) | (dcd_chg << 3) | (((ctsx_old >> 1) & 1) << 4) | (((dsrx_old >> 1) & 1) << 5) | (0 << 6) || (((dcdx_old >> 1) & 1) << 7);
     *dat_o = srtfSimpleUart.dat_o;
    }
 
    else if((adr_i&0xf) == 3) {
      srtfSimpleUart.dat_o = (0 & 0x3) | ((irqenc & 0x7) << 2) | ((0 & 0x3) << 5) | (*irq_o << 7);
     *dat_o = srtfSimpleUart.dat_o;
    }

    else if((adr_i&0xf) == 4) {
      srtfSimpleUart.dat_o = (rx_present_ie_old) | (tx_empty_ie_old << 1) | (0 << 2) | (dcd_ie_old << 3) | ((0 & 0xf) << 4);
     *dat_o = srtfSimpleUart.dat_o;
    }

    else if((adr_i&0xf) == 6) {
      srtfSimpleUart.dat_o = ((0 & 0x7) << 4) | (loopback_old << 3) | ((0 & 0x3) << 2) | !(srtfSimpleUart.rts_no << 1) | !(srtfSimpleUart.dtr_no);
     *dat_o = srtfSimpleUart.dat_o;
    }

    else if((adr_i&0xf) == 7) {
      srtfSimpleUart.dat_o = (hwfc_old) | ((0 & 0x7f) << 1);
     *dat_o = srtfSimpleUart.dat_o;
    }

    else if((adr_i&0xf) == 8) {
      srtfSimpleUart.dat_o = 0 & 0xff;
     *dat_o = srtfSimpleUart.dat_o;
    }

    else if((adr_i&0xf) == 9) {
      srtfSimpleUart.dat_o = ck_mul_old&0xf;
      *dat_o = srtfSimpleUart.dat_o;
    }

    else if((adr_i&0xf) == 10) {
      srtfSimpleUart.dat_o = ((ck_mul_old >> 8)&0xff);
      *dat_o = srtfSimpleUart.dat_o;
    }

    else if((adr_i&0xf) == 11) {
      srtfSimpleUart.dat_o = (ck_mul_old >> 16)&0xff;
      *dat_o = srtfSimpleUart.dat_o;
    }

    else if((adr_i&0xf) == 15) {
      srtfSimpleUart.dat_o = spr_old;
      *dat_o = srtfSimpleUart.dat_o;
    }
                        
    else {
      srtfSimpleUart.dat_o = rx_do;
      *dat_o = srtfSimpleUart.dat_o;
    }
  }

  else {
      srtfSimpleUart.dat_o = 0;
      *dat_o = srtfSimpleUart.dat_o;
  }
  
}

