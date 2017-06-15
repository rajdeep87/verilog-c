#include <stdio.h>
#include <assert.h>
#define TRUE 1
#define FALSE 0

struct state_elements_rtfSimpleUartTx{
unsigned char cnt;
_Bool rd;
_Bool modeX8;
_Bool empty;
_Bool txc;
unsigned short int tx_data;
unsigned char fdo;
};
struct state_elements_rtfSimpleUartTx  srtfSimpleUartTx;

struct diagnose {
  _Bool ctsd;
  _Bool baud16x_ced;
  _Bool txcd;
  _Bool baud8xd;
  _Bool txdd;
  unsigned short int datum;
};
struct diagnose d;


void rtfSimpleUartTx(_Bool rst_i, _Bool clk_i, _Bool cyc_i, _Bool stb_i, _Bool *ack_o, _Bool we_i, 
                     unsigned char dat_i, _Bool cs_i, _Bool baud16x_ce, _Bool baud8x, _Bool cts, _Bool *txd, _Bool *empty, _Bool *txc)
{
  _Bool empty_old;
  unsigned short int tx_data_old=0;
  unsigned char cnt_old;
  _Bool rd_old;
  _Bool isX8;
  _Bool modeX8_old;
 
  // update diagnose variables
  d.ctsd = cts;
  d.baud16x_ced = baud16x_ce;
  d.baud8xd = baud8x;
 
  
  // shadow variables 
  empty_old = srtfSimpleUartTx.empty;
  cnt_old = srtfSimpleUartTx.cnt;
  rd_old = srtfSimpleUartTx.rd;
  tx_data_old = (srtfSimpleUartTx.tx_data & 0x3FF);
  modeX8_old = srtfSimpleUartTx.modeX8;
  
  isX8 = baud8x;
  *ack_o = cyc_i && stb_i && cs_i;
  
  if(*ack_o && we_i)
    srtfSimpleUartTx.fdo = dat_i;

  if(rst_i) {
    srtfSimpleUartTx.empty = TRUE;
    *empty = TRUE;
  }

  else
  {
    if(*ack_o && we_i) {
      srtfSimpleUartTx.empty = FALSE;
      *empty = 0;
    }

    else
      if(rd_old) {
        srtfSimpleUartTx.empty = TRUE;
        *empty = TRUE;
      }

  }
  
  if(rst_i)
  {
    srtfSimpleUartTx.cnt = 159;
    srtfSimpleUartTx.rd = FALSE;
    srtfSimpleUartTx.tx_data = 1023;
    srtfSimpleUartTx.txc = TRUE;
    srtfSimpleUartTx.modeX8 = FALSE;
  }

  else
  {
    srtfSimpleUartTx.rd = FALSE;
    if(baud16x_ce)
    {
      if(cnt_old == 159)
      {
        srtfSimpleUartTx.modeX8 = isX8;
        if(!empty_old && cts)
        {
          //tx_data_old = (0 | ((srtfSimpleUartTx.fdo & 0xFF) << 1) | (1 << 9));
          srtfSimpleUartTx.tx_data = (0 | ((srtfSimpleUartTx.fdo & 0xFF) << 1) | (1 << 9));
          d.datum = srtfSimpleUartTx.tx_data & 0x3FF;
          srtfSimpleUartTx.rd = TRUE;
          srtfSimpleUartTx.cnt = modeX8_old;
          srtfSimpleUartTx.txc = FALSE;
        }

        else
          srtfSimpleUartTx.txc = TRUE;
      }

      else
      {
        srtfSimpleUartTx.cnt = (srtfSimpleUartTx.cnt&0x01) | (((((cnt_old >> 1) & 0x7f) + (cnt_old&1))&0x7f) << 1);
        srtfSimpleUartTx.cnt = ((!(cnt_old&1)) | modeX8_old) | (srtfSimpleUartTx.cnt & 0xfe); 
        if((cnt_old&0xf) == 15) {
          srtfSimpleUartTx.tx_data = ((tx_data_old >> 1) & 511) | (1 << 9);
          d.datum = srtfSimpleUartTx.tx_data & 0x3FF;
        }
      }
    }
  }

  *txd = (srtfSimpleUartTx.tx_data & 1);
  d.txdd = (srtfSimpleUartTx.tx_data & 1);

  // diagnose variable update
  d.txcd = *txc;
}

