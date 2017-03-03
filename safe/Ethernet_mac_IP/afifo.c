//#include <stdio.h>
#define TRUE 1
#define FALSE 0

struct state_elements_afifo{
 _Bool rd_ack;
 unsigned char Add_wr;
 unsigned char Add_wr_ungray;
 unsigned char Add_wr_gray;
 unsigned char Add_wr_gray_dl1;
 unsigned char Add_rd;
 unsigned char Add_rd_gray;
 unsigned char Add_rd_gray_dl1;
 unsigned char Add_rd_ungray;
 _Bool rd_ack_tmp;
 _Bool full;
 _Bool almost_full;
 _Bool empty;
};

void afifo(unsigned short int din, _Bool wr_en, _Bool wr_clk, _Bool rd_en, _Bool rd_clk, _Bool ainit, unsigned short int *dout, _Bool *full, _Bool *almost_full, _Bool *empty, unsigned char *wr_count, unsigned char *rd_count, _Bool *rd_ack, _Bool *wr_ack)
{
  struct state_elements_afifo  safifo;
  _Bool tmp25;
  _Bool tmp24;
  _Bool tmp23;
  unsigned char tmp22;
  unsigned char tmp21;
  _Bool tmp20;
  _Bool tmp19;
  unsigned char tmp18;
  unsigned char tmp17;
  unsigned char tmp16;
  _Bool tmp15;
  _Bool tmp14;
  _Bool tmp13;
  unsigned char tmp12;
  unsigned char tmp11;
  _Bool tmp10;
  _Bool tmp9;
  _Bool tmp8;
  _Bool tmp7;
  _Bool tmp6;
  _Bool tmp5;
  unsigned char tmp4;
  unsigned char tmp3;
  _Bool tmp2;
  _Bool tmp1;
  unsigned char tmp0;
 
  // parameter declaration
  int DATA_WIDTH;
  DATA_WIDTH = 16;
  int ADDR_WIDTH;
  ADDR_WIDTH = 8;
  int COUNT_DATA_WIDTH;
  COUNT_DATA_WIDTH = 8;
  int ALMOST_FULL_DEPTH;
  ALMOST_FULL_DEPTH = 8;

  unsigned char Add_rd_pluse;
  unsigned char Add_wr_pluse;
  int i;
  unsigned char ff_used_wr;
  unsigned char ff_used_rd;
  unsigned short int dout_tmp;
  *wr_ack = FALSE;
  *wr_ack = FALSE;
  ff_used_wr = safifo.Add_wr - safifo.Add_rd_ungray;
  *wr_count = ff_used_wr >> 0 & 255;
  *wr_count = ff_used_wr >> 0 & 255;
  if(ainit)
    tmp0 = 0;

  else
  {
    tmp1 = safifo.Add_wr >> 7 & 1;
    for(i = 0; i <= ADDR_WIDTH - 2; i = (unsigned int)i + 1 & 4294967295)
      tmp2 = ((safifo.Add_wr >> (i + 1)) & 1) ^ ((safifo.Add_wr >> i) & 1) ;
  }
  if(ainit)
    tmp3 = 0;

  else
    tmp4 = safifo.Add_rd_gray;
  if(ainit)
    safifo.Add_rd_ungray = 0;

  else
  {
    safifo.Add_rd_ungray = safifo.Add_rd_ungray | (safifo.Add_rd_gray_dl1 >> 7 & 1) << 7;
    for(i = 0; (unsigned int)i <= ADDR_WIDTH - 2; i = (unsigned int)i + 1 & 4294967295)
      safifo.Add_rd_ungray = safifo.Add_rd_ungray | (((safifo.Add_rd_ungray >> (i + 1)) && 1) ^ ((safifo.Add_rd_gray_dl1 >> i) & 1)) << i;
  }
  Add_wr_pluse = (unsigned char)(unsigned int)safifo.Add_wr + 1;
  if(ainit)
    tmp5 = FALSE;

  else
    if(Add_wr_pluse == safifo.Add_rd_ungray && wr_en)
      tmp6 = TRUE;

    else
      if(safifo.Add_wr != safifo.Add_rd_ungray)
        tmp7 = FALSE;

  if(ainit)
    tmp8 = FALSE;

  else
    if((unsigned int)wr_count >= ALMOST_FULL_DEPTH)
      tmp9 = TRUE;

    else
      tmp10 = FALSE;
  if(ainit)
    tmp11 = 0;

  else
    if(wr_en && !safifo.full)
      tmp12 = (unsigned char)(unsigned int)safifo.Add_wr + 1;

  if(ainit)
    tmp13 = FALSE;

  else
    if(rd_en && !safifo.empty)
      tmp14 = TRUE;

    else
      tmp15 = FALSE;
  ff_used_rd = safifo.Add_wr_ungray - safifo.Add_rd;
  *rd_count = ff_used_rd >> 0 & 255;
  *rd_count = ff_used_rd >> 0 & 255;
  Add_rd_pluse = (unsigned char)(unsigned int)safifo.Add_rd + 1;
  if(ainit)
    tmp16 = 0;

  else
    if(rd_en && !safifo.empty)
      tmp17 = (unsigned char)(unsigned int)safifo.Add_rd + 1;

  if(ainit)
    tmp18 = 0;

  else
  {
    tmp19 = safifo.Add_rd >> 7 & 1;
    for(i = 0; (unsigned int)i <= ADDR_WIDTH - 2; i = (unsigned int)i + 1 & 4294967295)
      tmp20 = ((safifo.Add_rd >> (i + 1)) & 1) ^ ((safifo.Add_wr >> i) & 1) ;
  }
  if(ainit)
    tmp21 = 0;

  else
    tmp22 = safifo.Add_wr_gray;
  if(ainit)
    safifo.Add_wr_ungray = 0;

  else
  {
    safifo.Add_wr_ungray = safifo.Add_wr_ungray | (safifo.Add_wr_gray_dl1 >> 7 & 1) << 7;
    for(i = 0; (unsigned int)i <= ADDR_WIDTH - 2; i = (unsigned int)i + 1 & 4294967295)

      safifo.Add_rd_ungray = safifo.Add_rd_ungray | (((safifo.Add_rd_ungray >> (i + 1)) && 1) ^ ((safifo.Add_rd_gray_dl1 >> i) & 1)) << i;

  }
  if(ainit)
    tmp23 = TRUE;

  else
    if(Add_rd_pluse == safifo.Add_wr_ungray && rd_en)
      tmp24 = TRUE;

    else
      if(safifo.Add_rd != safifo.Add_wr_ungray)
        tmp25 = FALSE;

  if(ainit)
    safifo.Add_wr_gray = tmp0;

  else
  {
    safifo.Add_wr_gray = safifo.Add_wr_gray | (tmp1 << 7);
    for(i = 0; (unsigned int)i <= ADDR_WIDTH - 2; i = (unsigned int)i + 1 & 4294967295)
      safifo.Add_wr_gray = safifo.Add_wr_gray | (tmp2 << i);
  }
  if(ainit)
    safifo.Add_rd_gray_dl1 = tmp3;

  else
    safifo.Add_rd_gray_dl1 = tmp4;
  if(ainit)
  {
    safifo.full = tmp5;
    *full = tmp5;
  }

  else
    if(Add_wr_pluse == safifo.Add_rd_ungray && wr_en)
    {
      safifo.full = tmp6;
      *full = tmp6;
    }

    else
      if(safifo.Add_wr != safifo.Add_rd_ungray)
      {
        safifo.full = tmp7;
        *full = tmp7;
      }

  if(ainit)
  {
    safifo.almost_full = tmp8;
    *almost_full = tmp8;
  }

  else
    if((unsigned int)wr_count >= ALMOST_FULL_DEPTH)
    {
      safifo.almost_full = tmp9;
      *almost_full = tmp9;
    }

    else
    {
      safifo.almost_full = tmp10;
      *almost_full = tmp10;
    }
  if(ainit)
    safifo.Add_wr = tmp11;

  else
    if(wr_en && !safifo.full)
      safifo.Add_wr = tmp12;

  if(ainit)
  {
    safifo.rd_ack = tmp13;
    *rd_ack = tmp13;
  }

  else
    if(rd_en && !safifo.empty)
    {
      safifo.rd_ack = tmp14;
      *rd_ack = tmp14;
    }

    else
    {
      safifo.rd_ack = tmp15;
      *rd_ack = tmp15;
    }
  if(ainit)
    safifo.Add_rd = tmp16;

  else
    if(rd_en && !safifo.empty)
      safifo.Add_rd = tmp17;

  if(ainit)
    safifo.Add_rd_gray = tmp18;

  else
  {
    safifo.Add_rd_gray  = safifo.Add_rd_gray | (tmp19 << 7);
    for(i = 0; (unsigned int)i <= ADDR_WIDTH - 2; i = (unsigned int)i + 1 & 4294967295)
      safifo.Add_rd_gray = safifo.Add_rd_gray | (tmp20 << i);
  }
  if(ainit)
    safifo.Add_wr_gray_dl1 = tmp21;

  else
    safifo.Add_wr_gray_dl1 = tmp22;
  if(ainit)
  {
    safifo.empty = tmp23;
    *empty = tmp23;
  }

  else
    if(Add_rd_pluse == safifo.Add_wr_ungray && rd_en)
    {
      safifo.empty = tmp24;
      *empty = tmp24;
    }

    else
      if(safifo.Add_rd != safifo.Add_wr_ungray)
      {
        safifo.empty = tmp25;
        *empty = tmp25;
      }
}
