//#include <stdio.h>
#define TRUE 1
#define FALSE 0

struct state_elements_CRC_gen{
unsigned char CRC_out;
_Bool CRC_end;
unsigned int CRC_reg;
unsigned char Counter;
unsigned int NewCRC;
unsigned int NextCRC;
};
struct state_elements_CRC_gen  sCRC_gen;

void CRC_gen(_Bool Reset, _Bool Clk, _Bool Init, unsigned char Frame_data, _Bool Data_en, _Bool CRC_rd, unsigned char *CRC_out, _Bool *CRC_end)
{
  unsigned int tmp100, tmp101;
  unsigned char tmp6;
  unsigned char tmp5;
  unsigned char tmp4;
  unsigned char tmp3;
  unsigned char tmp2;
  unsigned int tmp1;
  unsigned int tmp0;
  if(Reset)
    tmp0 = 4294967295;

  else
    if(Init)
      tmp1 = 4294967295;

 else 
   if(Data_en) {
     
  sCRC_gen.NewCRC = sCRC_gen.NewCRC | ((sCRC_gen.CRC_reg >> 24 & 1) ^ (sCRC_gen.CRC_reg >> 30 & 1) ^ (Frame_data >> 1 & 1) ^ (Frame_data >> 7 & 1)) << 0;
        sCRC_gen.NewCRC = sCRC_gen.NewCRC | ((sCRC_gen.CRC_reg >> 25 & 1) ^ (sCRC_gen.CRC_reg >> 31 & 1) ^ (Frame_data >> 0 & 1) ^ (Frame_data >> 6 & 1) ^ (sCRC_gen.CRC_reg >> 24 & 1) ^ (sCRC_gen.CRC_reg >> 30 & 1) ^ (Frame_data >> 1 & 1) ^ (Frame_data >> 7 & 1)) << 1;
        sCRC_gen.NewCRC = sCRC_gen.NewCRC | ((sCRC_gen.CRC_reg >> 26 & 1) ^ (Frame_data >> 5 & 1) ^ (sCRC_gen.CRC_reg >> 25 & 1) ^ (sCRC_gen.CRC_reg >> 31 & 1) ^ (Frame_data >> 0 & 1) ^ (Frame_data >> 6 & 1) ^ (sCRC_gen.CRC_reg >> 24 & 1) ^ (sCRC_gen.CRC_reg >> 30 & 1) ^ (Frame_data >> 1 & 1) ^ (Frame_data >> 7 & 1)) << 2;
        sCRC_gen.NewCRC = sCRC_gen.NewCRC | ((sCRC_gen.CRC_reg >> 27 & 1) ^ (Frame_data >> 4 & 1) ^ (sCRC_gen.CRC_reg >> 26 & 1) ^ (Frame_data >> 5 & 1) ^ (sCRC_gen.CRC_reg >> 25 & 1) ^ (sCRC_gen.CRC_reg >> 31 & 1) ^ (Frame_data >> 0 & 1) ^ (Frame_data >> 6 & 1)) << 3;
        sCRC_gen.NewCRC = sCRC_gen.NewCRC | ((sCRC_gen.CRC_reg >> 28 & 1) ^ (Frame_data >> 3 & 1) ^ (sCRC_gen.CRC_reg >> 27 & 1) ^ (Frame_data >> 4 & 1) ^ (sCRC_gen.CRC_reg >> 26 & 1) ^ (Frame_data >> 5 & 1) ^ (sCRC_gen.CRC_reg >> 24 & 1) ^ (sCRC_gen.CRC_reg >> 30 & 1) ^ (Frame_data >> 1 & 1) ^ (Frame_data >> 7 & 1)) << 4;
        sCRC_gen.NewCRC = sCRC_gen.NewCRC | ((sCRC_gen.CRC_reg >> 29 & 1) ^ (Frame_data >> 2 & 1) ^ (sCRC_gen.CRC_reg >> 28 & 1) ^ (Frame_data >> 3 & 1) ^ (sCRC_gen.CRC_reg >> 27 & 1) ^ (Frame_data >> 4 & 1) ^ (sCRC_gen.CRC_reg >> 25 & 1) ^ (sCRC_gen.CRC_reg >> 31 & 1) ^ (Frame_data >> 0 & 1) ^ (Frame_data >> 6 & 1) ^ (sCRC_gen.CRC_reg >> 24 & 1) ^ (sCRC_gen.CRC_reg >> 30 & 1) ^ (Frame_data >> 1 & 1) ^ (Frame_data >> 7 & 1)) << 5;
        sCRC_gen.NewCRC = sCRC_gen.NewCRC | ((sCRC_gen.CRC_reg >> 30 & 1) ^ (Frame_data >> 1 & 1) ^ (sCRC_gen.CRC_reg >> 29 & 1) ^ (Frame_data >> 2 & 1) ^ (sCRC_gen.CRC_reg >> 28 & 1) ^ (Frame_data >> 3 & 1) ^ (sCRC_gen.CRC_reg >> 26 & 1) ^ (Frame_data >> 5 & 1) ^ (sCRC_gen.CRC_reg >> 25 & 1) ^ (sCRC_gen.CRC_reg >> 31 & 1) ^ (Frame_data >> 0 & 1) ^ (Frame_data >> 6 & 1)) << 6;
        sCRC_gen.NewCRC = sCRC_gen.NewCRC | ((sCRC_gen.CRC_reg >> 31 & 1) ^ (Frame_data >> 0 & 1) ^ (sCRC_gen.CRC_reg >> 29 & 1) ^ (Frame_data >> 2 & 1) ^ (sCRC_gen.CRC_reg >> 27 & 1) ^ (Frame_data >> 4 & 1) ^ (sCRC_gen.CRC_reg >> 26 & 1) ^ (Frame_data >> 5 & 1) ^ (sCRC_gen.CRC_reg >> 24 & 1) ^ (Frame_data >> 7 & 1)) << 7;
        sCRC_gen.NewCRC = sCRC_gen.NewCRC | ((sCRC_gen.CRC_reg >> 0 & 1) ^ (sCRC_gen.CRC_reg >> 28 & 1) ^ (Frame_data >> 3 & 1) ^ (sCRC_gen.CRC_reg >> 27 & 1) ^ (Frame_data >> 4 & 1) ^ (sCRC_gen.CRC_reg >> 25 & 1) ^ (Frame_data >> 6 & 1) ^ (sCRC_gen.CRC_reg >> 24 & 1) ^ (Frame_data >> 7 & 1)) << 8;
        sCRC_gen.NewCRC = sCRC_gen.NewCRC | ((sCRC_gen.CRC_reg >> 1 & 1) ^ (sCRC_gen.CRC_reg >> 29 & 1) ^ (Frame_data >> 2 & 1) ^ (sCRC_gen.CRC_reg >> 28 & 1) ^ (Frame_data >> 3 & 1) ^ (sCRC_gen.CRC_reg >> 26 & 1) ^ (Frame_data >> 5 & 1) ^ (sCRC_gen.CRC_reg >> 25 & 1) ^ (Frame_data >> 6 & 1)) << 9;
        sCRC_gen.NewCRC = sCRC_gen.NewCRC | ((sCRC_gen.CRC_reg >> 2 & 1) ^ (sCRC_gen.CRC_reg >> 29 & 1) ^ (Frame_data >> 2 & 1) ^ (sCRC_gen.CRC_reg >> 27 & 1) ^ (Frame_data >> 4 & 1) ^ (sCRC_gen.CRC_reg >> 26 & 1) ^ (Frame_data >> 5 & 1) ^ (sCRC_gen.CRC_reg >> 24 & 1) ^ (Frame_data >> 7 & 1)) << 10;
        sCRC_gen.NewCRC = sCRC_gen.NewCRC | ((sCRC_gen.CRC_reg >> 3 & 1) ^ (sCRC_gen.CRC_reg >> 28 & 1) ^ (Frame_data >> 3 & 1) ^ (sCRC_gen.CRC_reg >> 27 & 1) ^ (Frame_data >> 4 & 1) ^ (sCRC_gen.CRC_reg >> 25 & 1) ^ (Frame_data >> 6 & 1) ^ (sCRC_gen.CRC_reg >> 24 & 1) ^ (Frame_data >> 7 & 1)) << 11;
        sCRC_gen.NewCRC = sCRC_gen.NewCRC | ((sCRC_gen.CRC_reg >> 4 & 1) ^ (sCRC_gen.CRC_reg >> 29 & 1) ^ (Frame_data >> 2 & 1) ^ (sCRC_gen.CRC_reg >> 28 & 1) ^ (Frame_data >> 3 & 1) ^ (sCRC_gen.CRC_reg >> 26 & 1) ^ (Frame_data >> 5 & 1) ^ (sCRC_gen.CRC_reg >> 25 & 1) ^ (Frame_data >> 6 & 1) ^ (sCRC_gen.CRC_reg >> 24 & 1) ^ (sCRC_gen.CRC_reg >> 30 & 1) ^ (Frame_data >> 1 & 1) ^ (Frame_data >> 7 & 1)) << 12;
        sCRC_gen.NewCRC = sCRC_gen.NewCRC | ((sCRC_gen.CRC_reg >> 5 & 1) ^ (sCRC_gen.CRC_reg >> 30 & 1) ^ (Frame_data >> 1 & 1) ^ (sCRC_gen.CRC_reg >> 29 & 1) ^ (Frame_data >> 2 & 1) ^ (sCRC_gen.CRC_reg >> 27 & 1) ^ (Frame_data >> 4 & 1) ^ (sCRC_gen.CRC_reg >> 26 & 1) ^ (Frame_data >> 5 & 1) ^ (sCRC_gen.CRC_reg >> 25 & 1) ^ (sCRC_gen.CRC_reg >> 31 & 1) ^ (Frame_data >> 0 & 1) ^ (Frame_data >> 6 & 1)) << 13;
        sCRC_gen.NewCRC = sCRC_gen.NewCRC | ((sCRC_gen.CRC_reg >> 6 & 1) ^ (sCRC_gen.CRC_reg >> 31 & 1) ^ (Frame_data >> 0 & 1) ^ (sCRC_gen.CRC_reg >> 30 & 1) ^ (Frame_data >> 1 & 1) ^ (sCRC_gen.CRC_reg >> 28 & 1) ^ (Frame_data >> 3 & 1) ^ (sCRC_gen.CRC_reg >> 27 & 1) ^ (Frame_data >> 4 & 1) ^ (sCRC_gen.CRC_reg >> 26 & 1) ^ (Frame_data >> 5 & 1)) << 14;
        sCRC_gen.NewCRC = sCRC_gen.NewCRC | ((sCRC_gen.CRC_reg >> 7 & 1) ^ (sCRC_gen.CRC_reg >> 31 & 1) ^ (Frame_data >> 0 & 1) ^ (sCRC_gen.CRC_reg >> 29 & 1) ^ (Frame_data >> 2 & 1) ^ (sCRC_gen.CRC_reg >> 28 & 1) ^ (Frame_data >> 3 & 1) ^ (sCRC_gen.CRC_reg >> 27 & 1) ^ (Frame_data >> 4 & 1)) << 15;
        sCRC_gen.NewCRC = sCRC_gen.NewCRC | ((sCRC_gen.CRC_reg >> 8 & 1) ^ (sCRC_gen.CRC_reg >> 29 & 1) ^ (Frame_data >> 2 & 1) ^ (sCRC_gen.CRC_reg >> 28 & 1) ^ (Frame_data >> 3 & 1) ^ (sCRC_gen.CRC_reg >> 24 & 1) ^ (Frame_data >> 7 & 1)) << 16;
        sCRC_gen.NewCRC = sCRC_gen.NewCRC | ((sCRC_gen.CRC_reg >> 9 & 1) ^ (sCRC_gen.CRC_reg >> 30 & 1) ^ (Frame_data >> 1 & 1) ^ (sCRC_gen.CRC_reg >> 29 & 1) ^ (Frame_data >> 2 & 1) ^ (sCRC_gen.CRC_reg >> 25 & 1) ^ (Frame_data >> 6 & 1)) << 17;
        sCRC_gen.NewCRC = sCRC_gen.NewCRC | ((sCRC_gen.CRC_reg >> 10 & 1) ^ (sCRC_gen.CRC_reg >> 31 & 1) ^ (Frame_data >> 0 & 1) ^ (sCRC_gen.CRC_reg >> 30 & 1) ^ (Frame_data >> 1 & 1) ^ (sCRC_gen.CRC_reg >> 26 & 1) ^ (Frame_data >> 5 & 1)) << 18;
        sCRC_gen.NewCRC = sCRC_gen.NewCRC | ((sCRC_gen.CRC_reg >> 11 & 1) ^ (sCRC_gen.CRC_reg >> 31 & 1) ^ (Frame_data >> 0 & 1) ^ (sCRC_gen.CRC_reg >> 27 & 1) ^ (Frame_data >> 4 & 1)) << 19;
        sCRC_gen.NewCRC = sCRC_gen.NewCRC | ((sCRC_gen.CRC_reg >> 12 & 1) ^ (sCRC_gen.CRC_reg >> 28 & 1) ^ (Frame_data >> 3 & 1)) << 20;
        sCRC_gen.NewCRC = sCRC_gen.NewCRC | ((sCRC_gen.CRC_reg >> 13 & 1) ^ (sCRC_gen.CRC_reg >> 29 & 1) ^ (Frame_data >> 2 & 1)) << 21;
        sCRC_gen.NewCRC = sCRC_gen.NewCRC | ((sCRC_gen.CRC_reg >> 14 & 1) ^ (sCRC_gen.CRC_reg >> 24 & 1) ^ (Frame_data >> 7 & 1)) << 22;
        sCRC_gen.NewCRC = sCRC_gen.NewCRC | ((sCRC_gen.CRC_reg >> 15 & 1) ^ (sCRC_gen.CRC_reg >> 25 & 1) ^ (Frame_data >> 6 & 1) ^ (sCRC_gen.CRC_reg >> 24 & 1) ^ (sCRC_gen.CRC_reg >> 30 & 1) ^ (Frame_data >> 1 & 1) ^ (Frame_data >> 7 & 1)) << 23;
        sCRC_gen.NewCRC = sCRC_gen.NewCRC | ((sCRC_gen.CRC_reg >> 16 & 1) ^ (sCRC_gen.CRC_reg >> 26 & 1) ^ (Frame_data >> 5 & 1) ^ (sCRC_gen.CRC_reg >> 25 & 1) ^ (sCRC_gen.CRC_reg >> 31 & 1) ^ (Frame_data >> 0 & 1) ^ (Frame_data >> 6 & 1)) << 24;
        sCRC_gen.NewCRC = sCRC_gen.NewCRC | ((sCRC_gen.CRC_reg >> 17 & 1) ^ (sCRC_gen.CRC_reg >> 27 & 1) ^ (Frame_data >> 4 & 1) ^ (sCRC_gen.CRC_reg >> 26 & 1) ^ (Frame_data >> 5 & 1)) << 25;
        sCRC_gen.NewCRC = sCRC_gen.NewCRC | ((sCRC_gen.CRC_reg >> 18 & 1) ^ (sCRC_gen.CRC_reg >> 28 & 1) ^ (Frame_data >> 3 & 1) ^ (sCRC_gen.CRC_reg >> 27 & 1) ^ (Frame_data >> 4 & 1) ^ (sCRC_gen.CRC_reg >> 24 & 1) ^ (sCRC_gen.CRC_reg >> 30 & 1) ^ (Frame_data >> 1 & 1) ^ (Frame_data >> 7 & 1)) << 26;
        sCRC_gen.NewCRC = sCRC_gen.NewCRC | ((sCRC_gen.CRC_reg >> 19 & 1) ^ (sCRC_gen.CRC_reg >> 29 & 1) ^ (Frame_data >> 2 & 1) ^ (sCRC_gen.CRC_reg >> 28 & 1) ^ (Frame_data >> 3 & 1) ^ (sCRC_gen.CRC_reg >> 25 & 1) ^ (sCRC_gen.CRC_reg >> 31 & 1) ^ (Frame_data >> 0 & 1) ^ (Frame_data >> 6 & 1)) << 27;
        sCRC_gen.NewCRC = sCRC_gen.NewCRC | ((sCRC_gen.CRC_reg >> 20 & 1) ^ (sCRC_gen.CRC_reg >> 30 & 1) ^ (Frame_data >> 1 & 1) ^ (sCRC_gen.CRC_reg >> 29 & 1) ^ (Frame_data >> 2 & 1) ^ (sCRC_gen.CRC_reg >> 26 & 1) ^ (Frame_data >> 5 & 1)) << 28;
        sCRC_gen.NewCRC = sCRC_gen.NewCRC | ((sCRC_gen.CRC_reg >> 21 & 1) ^ (sCRC_gen.CRC_reg >> 31 & 1) ^ (Frame_data >> 0 & 1) ^ (sCRC_gen.CRC_reg >> 30 & 1) ^ (Frame_data >> 1 & 1) ^ (sCRC_gen.CRC_reg >> 27 & 1) ^ (Frame_data >> 4 & 1)) << 29;
        sCRC_gen.NewCRC = sCRC_gen.NewCRC | ((sCRC_gen.CRC_reg >> 22 & 1) ^ (sCRC_gen.CRC_reg >> 31 & 1) ^ (Frame_data >> 0 & 1) ^ (sCRC_gen.CRC_reg >> 28 & 1) ^ (Frame_data >> 3 & 1)) << 30;
        sCRC_gen.NewCRC = sCRC_gen.NewCRC | ((sCRC_gen.CRC_reg >> 23 & 1) ^ (sCRC_gen.CRC_reg >> 29 & 1) ^ (Frame_data >> 2 & 1)) << 31;
  sCRC_gen.NextCRC = sCRC_gen.NewCRC;
  tmp100 = sCRC_gen.NextCRC;
 }
 else if(CRC_rd) 
   tmp101 = (sCRC_gen.CRC_reg & 0xFFFFFF << 23) | 0xFF;

  if(CRC_rd)
    tmp2 = (sCRC_gen.CRC_reg >> 24 & 1) << 7 | (sCRC_gen.CRC_reg >> 25 & 1) << 6 | (sCRC_gen.CRC_reg >> 26 & 1) << 5 | (sCRC_gen.CRC_reg >>27 & 1) << 4 | (sCRC_gen.CRC_reg >> 28 & 1) << 3 | (sCRC_gen.CRC_reg >> 29 & 1) << 2 | (sCRC_gen.CRC_reg >> 30 & 1) << 1 | (sCRC_gen.CRC_reg >> 31 & 1);

  else
    tmp3 = 0;
  if(Reset)
    tmp4 = 0;

  else
    if(!CRC_rd)
      tmp5 = 0;
  else
      tmp6 = (unsigned char)(unsigned int)sCRC_gen.Counter + 1;
  if((unsigned int)sCRC_gen.Counter == 3)
  {
    sCRC_gen.CRC_end = TRUE;
    *CRC_end = TRUE;
  }

  else
  {
    sCRC_gen.CRC_end = FALSE;
    *CRC_end = FALSE;
  }
  if(Reset)
    sCRC_gen.CRC_reg = tmp0;

  else
    if(Init)
      sCRC_gen.CRC_reg = tmp1;

  else if(Data_en)
    sCRC_gen.CRC_reg = tmp100;
  else if(CRC_rd)
    sCRC_gen.CRC_reg = tmp101;
    
  
  if(CRC_rd)
  {
    sCRC_gen.CRC_out = tmp2;
    *CRC_out = tmp2;
  }
  else
  {
    sCRC_gen.CRC_out = tmp3;
    *CRC_out = tmp3;
  }
  if(Reset)
    sCRC_gen.Counter = tmp4;

  else
    if(!CRC_rd)
      sCRC_gen.Counter = tmp5;

    else
      sCRC_gen.Counter = tmp6;
}

/*
void main() {
_Bool Reset;
_Bool Clk;
_Bool Init;
unsigned char Frame_data;
_Bool Data_en;
_Bool CRC_rd;
unsigned char CRC_out;
_Bool CRC_end;

CRC_gen(Reset, Clk, Init, Frame_data, Data_en, CRC_rd, &CRC_out, &CRC_end);
}*/
