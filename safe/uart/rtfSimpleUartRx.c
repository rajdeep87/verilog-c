#include <stdio.h>
#include <assert.h>

int SamplerStyle = 0;

struct state_elements_rtfSimpleUartRx{
 unsigned char rxdd;
 unsigned char cnt;
 _Bool rxdsmp;
 _Bool rdxstart;
 unsigned short int rx_data;
 _Bool state;
 unsigned char rxdsum;
 _Bool wf;
 unsigned char dat;
 _Bool modeX8;
 _Bool data_present;
 _Bool overrun;
 _Bool frame_err;
};
struct state_elements_rtfSimpleUartRx  srtfSimpleUartRx;


void rtfSimpleUartRx(_Bool rst_i, _Bool clk_i, _Bool cyc_i, _Bool stb_i, _Bool *ack_o, _Bool we_i, unsigned char *dat_o, _Bool cs_i, _Bool baud16x_ce, _Bool baud8x, _Bool clear, _Bool rxd, _Bool *data_present, _Bool *frame_err, _Bool *overrun)
{
  unsigned char cnt_old;
  unsigned short int rx_data_old;
  _Bool state_old;
  _Bool wf_old;
  _Bool isX8;
  _Bool modeX8_old;
  unsigned char rxdd_old;
  _Bool rxdsmp_old;
  unsigned char rxdsum_old;

  // update shadow variables
  rxdd_old = srtfSimpleUartRx.rxdd;
  rxdsmp_old = srtfSimpleUartRx.rxdsmp;
  rxdsum_old = srtfSimpleUartRx.rxdsum;
  state_old = srtfSimpleUartRx.state;
  wf_old = srtfSimpleUartRx.wf;
  rx_data_old = srtfSimpleUartRx.rx_data;
  cnt_old = srtfSimpleUartRx.cnt;
  modeX8_old = srtfSimpleUartRx.modeX8;
  
  
  isX8 = baud8x;
  *ack_o = cyc_i && stb_i && cs_i;
  
  if(wf_old)
    srtfSimpleUartRx.dat = ((rx_data_old >> 1) & 0xff);

  if(rst_i)
    *data_present = 0;

  else
    if(wf_old)
      *data_present = 1;

    else
      if(*ack_o && !we_i)
        *data_present = 0;

  // clocked block
  srtfSimpleUartRx.rxdd = (rxd | ((rxdd_old & 31) << 1));
  
  if(SamplerStyle == 0)
  {
    srtfSimpleUartRx.rxdsmp = ((rxdd_old >> 3) & 1);
    srtfSimpleUartRx.rdxstart = ((rxdd_old >> 4) & 1) & !((rxdd_old>>3)&1);
  }
  else
  {
    srtfSimpleUartRx.rxdsum = (srtfSimpleUartRx.rxdsum & 2) | ((rxdsum_old & 1) << 1);
    srtfSimpleUartRx.rxdsum = (srtfSimpleUartRx.rxdsum & 1) | ((0<<1 | ((rxdd_old>>3)&1)) + (0<<1 | ((rxdd_old>>4)&1)) + (0 << 1 | ((rxdd_old>>5)&1)));
    srtfSimpleUartRx.rxdsmp = ((rxdsum_old >> 1) & 1);
    srtfSimpleUartRx.rdxstart = ((((rxdsum_old >> 1)&1) == 0) & (((rxdsum_old >> 1)&1) == 3));
  }
  
  // clocked block
  if(rst_i)
  {
    srtfSimpleUartRx.state = 0;
    srtfSimpleUartRx.wf = 0;
    *overrun = 0;
    srtfSimpleUartRx.overrun = 0;
    *frame_err = 0;
    srtfSimpleUartRx.frame_err = 0;
  }

  else
  {
    srtfSimpleUartRx.wf = 0;
    if(clear)
    {
      srtfSimpleUartRx.wf = 0;
      srtfSimpleUartRx.state = 0;
      *overrun = 0;
      srtfSimpleUartRx.overrun = 0;
      *frame_err = 0;
      srtfSimpleUartRx.frame_err = 0;
    }

    else
      if(baud16x_ce)
      {
          if(srtfSimpleUartRx.state == 0) {
            if(srtfSimpleUartRx.rdxstart) {
              srtfSimpleUartRx.state = 1;
            }
          }
          else
            if((unsigned int)state_old == 1)
            {
              if(cnt_old == 151)
              {
                *frame_err = !rxdsmp_old;
                srtfSimpleUartRx.frame_err = !rxdsmp_old;
                *overrun = *data_present;
                srtfSimpleUartRx.overrun = *data_present;
                if(!(*data_present))
                  srtfSimpleUartRx.wf = 1;

                srtfSimpleUartRx.state = 0;
              }

              if(cnt_old == 0x7 && rxdsmp_old)
                srtfSimpleUartRx.state = 0;

              if((cnt_old & 0xf) == 0x7)
                srtfSimpleUartRx.rx_data = ((rx_data_old >> 1) & 511) | (rxdsmp_old << 9);
            }
      }
  }
  
  // clocked block
  if(baud16x_ce)
  {
    if(state_old == 0)
    {
      srtfSimpleUartRx.cnt = modeX8_old;
      srtfSimpleUartRx.modeX8 = isX8;
    }
    else
    {
        srtfSimpleUartRx.cnt = (srtfSimpleUartRx.cnt&0x01) | (((((cnt_old >> 1) & 0x7f) + (cnt_old&1))&0x7f) << 1);
        srtfSimpleUartRx.cnt = ((!(cnt_old&1)) | modeX8_old) | (srtfSimpleUartRx.cnt & 0xfe); 
    }
  }

  *dat_o = *ack_o ? srtfSimpleUartRx.dat : 0;

}

