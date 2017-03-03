//#include <stdio.h>
#define TRUE 1
#define FALSE 0

struct state_elements_CRC_chk{
 unsigned int CRC_reg;
 unsigned int Next_CRC;
 unsigned int NewCRC;
};
void CRC_chk(_Bool Reset, _Bool Clk, unsigned char CRC_data, _Bool CRC_init, _Bool CRC_en, _Bool CRC_chk_en, _Bool *CRC_err)
{
  struct state_elements_CRC_chk  sCRC_chk;
  unsigned int tmp2;
  unsigned int tmp1;
  unsigned int tmp0;
  if(Reset)
    tmp0 = 4294967295;
  else
    if(CRC_init)
      tmp1 = 4294967295;
  else
    if(CRC_en)
    {
        sCRC_chk.NewCRC = sCRC_chk.NewCRC | ((sCRC_chk.CRC_reg >> 24 & 1) ^ (sCRC_chk.CRC_reg >> 30 & 1) ^ (CRC_data >> 1 & 1) ^ (CRC_data >> 7 & 1)) << 0;
        sCRC_chk.NewCRC = sCRC_chk.NewCRC | ((sCRC_chk.CRC_reg >> 25 & 1) ^ (sCRC_chk.CRC_reg >> 31 & 1) ^ (CRC_data >> 0 & 1) ^ (CRC_data >> 6 & 1) ^ (sCRC_chk.CRC_reg >> 24 & 1) ^ (sCRC_chk.CRC_reg >> 30 & 1) ^ (CRC_data >> 1 & 1) ^ (CRC_data >> 7 & 1)) << 1;
        sCRC_chk.NewCRC = sCRC_chk.NewCRC | ((sCRC_chk.CRC_reg >> 26 & 1) ^ (CRC_data >> 5 & 1) ^ (sCRC_chk.CRC_reg >> 25 & 1) ^ (sCRC_chk.CRC_reg >> 31 & 1) ^ (CRC_data >> 0 & 1) ^ (CRC_data >> 6 & 1) ^ (sCRC_chk.CRC_reg >> 24 & 1) ^ (sCRC_chk.CRC_reg >> 30 & 1) ^ (CRC_data >> 1 & 1) ^ (CRC_data >> 7 & 1)) << 2;
        sCRC_chk.NewCRC = sCRC_chk.NewCRC | ((sCRC_chk.CRC_reg >> 27 & 1) ^ (CRC_data >> 4 & 1) ^ (sCRC_chk.CRC_reg >> 26 & 1) ^ (CRC_data >> 5 & 1) ^ (sCRC_chk.CRC_reg >> 25 & 1) ^ (sCRC_chk.CRC_reg >> 31 & 1) ^ (CRC_data >> 0 & 1) ^ (CRC_data >> 6 & 1)) << 3;
        sCRC_chk.NewCRC = sCRC_chk.NewCRC | ((sCRC_chk.CRC_reg >> 28 & 1) ^ (CRC_data >> 3 & 1) ^ (sCRC_chk.CRC_reg >> 27 & 1) ^ (CRC_data >> 4 & 1) ^ (sCRC_chk.CRC_reg >> 26 & 1) ^ (CRC_data >> 5 & 1) ^ (sCRC_chk.CRC_reg >> 24 & 1) ^ (sCRC_chk.CRC_reg >> 30 & 1) ^ (CRC_data >> 1 & 1) ^ (CRC_data >> 7 & 1)) << 4;
        sCRC_chk.NewCRC = sCRC_chk.NewCRC | ((sCRC_chk.CRC_reg >> 29 & 1) ^ (CRC_data >> 2 & 1) ^ (sCRC_chk.CRC_reg >> 28 & 1) ^ (CRC_data >> 3 & 1) ^ (sCRC_chk.CRC_reg >> 27 & 1) ^ (CRC_data >> 4 & 1) ^ (sCRC_chk.CRC_reg >> 25 & 1) ^ (sCRC_chk.CRC_reg >> 31 & 1) ^ (CRC_data >> 0 & 1) ^ (CRC_data >> 6 & 1) ^ (sCRC_chk.CRC_reg >> 24 & 1) ^ (sCRC_chk.CRC_reg >> 30 & 1) ^ (CRC_data >> 1 & 1) ^ (CRC_data >> 7 & 1)) << 5;
        sCRC_chk.NewCRC = sCRC_chk.NewCRC | ((sCRC_chk.CRC_reg >> 30 & 1) ^ (CRC_data >> 1 & 1) ^ (sCRC_chk.CRC_reg >> 29 & 1) ^ (CRC_data >> 2 & 1) ^ (sCRC_chk.CRC_reg >> 28 & 1) ^ (CRC_data >> 3 & 1) ^ (sCRC_chk.CRC_reg >> 26 & 1) ^ (CRC_data >> 5 & 1) ^ (sCRC_chk.CRC_reg >> 25 & 1) ^ (sCRC_chk.CRC_reg >> 31 & 1) ^ (CRC_data >> 0 & 1) ^ (CRC_data >> 6 & 1)) << 6;
        sCRC_chk.NewCRC = sCRC_chk.NewCRC | ((sCRC_chk.CRC_reg >> 31 & 1) ^ (CRC_data >> 0 & 1) ^ (sCRC_chk.CRC_reg >> 29 & 1) ^ (CRC_data >> 2 & 1) ^ (sCRC_chk.CRC_reg >> 27 & 1) ^ (CRC_data >> 4 & 1) ^ (sCRC_chk.CRC_reg >> 26 & 1) ^ (CRC_data >> 5 & 1) ^ (sCRC_chk.CRC_reg >> 24 & 1) ^ (CRC_data >> 7 & 1)) << 7;
        sCRC_chk.NewCRC = sCRC_chk.NewCRC | ((sCRC_chk.CRC_reg >> 0 & 1) ^ (sCRC_chk.CRC_reg >> 28 & 1) ^ (CRC_data >> 3 & 1) ^ (sCRC_chk.CRC_reg >> 27 & 1) ^ (CRC_data >> 4 & 1) ^ (sCRC_chk.CRC_reg >> 25 & 1) ^ (CRC_data >> 6 & 1) ^ (sCRC_chk.CRC_reg >> 24 & 1) ^ (CRC_data >> 7 & 1)) << 8;
        sCRC_chk.NewCRC = sCRC_chk.NewCRC | ((sCRC_chk.CRC_reg >> 1 & 1) ^ (sCRC_chk.CRC_reg >> 29 & 1) ^ (CRC_data >> 2 & 1) ^ (sCRC_chk.CRC_reg >> 28 & 1) ^ (CRC_data >> 3 & 1) ^ (sCRC_chk.CRC_reg >> 26 & 1) ^ (CRC_data >> 5 & 1) ^ (sCRC_chk.CRC_reg >> 25 & 1) ^ (CRC_data >> 6 & 1)) << 9;
        sCRC_chk.NewCRC = sCRC_chk.NewCRC | ((sCRC_chk.CRC_reg >> 2 & 1) ^ (sCRC_chk.CRC_reg >> 29 & 1) ^ (CRC_data >> 2 & 1) ^ (sCRC_chk.CRC_reg >> 27 & 1) ^ (CRC_data >> 4 & 1) ^ (sCRC_chk.CRC_reg >> 26 & 1) ^ (CRC_data >> 5 & 1) ^ (sCRC_chk.CRC_reg >> 24 & 1) ^ (CRC_data >> 7 & 1)) << 10;
        sCRC_chk.NewCRC = sCRC_chk.NewCRC | ((sCRC_chk.CRC_reg >> 3 & 1) ^ (sCRC_chk.CRC_reg >> 28 & 1) ^ (CRC_data >> 3 & 1) ^ (sCRC_chk.CRC_reg >> 27 & 1) ^ (CRC_data >> 4 & 1) ^ (sCRC_chk.CRC_reg >> 25 & 1) ^ (CRC_data >> 6 & 1) ^ (sCRC_chk.CRC_reg >> 24 & 1) ^ (CRC_data >> 7 & 1)) << 11;
        sCRC_chk.NewCRC = sCRC_chk.NewCRC | ((sCRC_chk.CRC_reg >> 4 & 1) ^ (sCRC_chk.CRC_reg >> 29 & 1) ^ (CRC_data >> 2 & 1) ^ (sCRC_chk.CRC_reg >> 28 & 1) ^ (CRC_data >> 3 & 1) ^ (sCRC_chk.CRC_reg >> 26 & 1) ^ (CRC_data >> 5 & 1) ^ (sCRC_chk.CRC_reg >> 25 & 1) ^ (CRC_data >> 6 & 1) ^ (sCRC_chk.CRC_reg >> 24 & 1) ^ (sCRC_chk.CRC_reg >> 30 & 1) ^ (CRC_data >> 1 & 1) ^ (CRC_data >> 7 & 1)) << 12;
        sCRC_chk.NewCRC = sCRC_chk.NewCRC | ((sCRC_chk.CRC_reg >> 5 & 1) ^ (sCRC_chk.CRC_reg >> 30 & 1) ^ (CRC_data >> 1 & 1) ^ (sCRC_chk.CRC_reg >> 29 & 1) ^ (CRC_data >> 2 & 1) ^ (sCRC_chk.CRC_reg >> 27 & 1) ^ (CRC_data >> 4 & 1) ^ (sCRC_chk.CRC_reg >> 26 & 1) ^ (CRC_data >> 5 & 1) ^ (sCRC_chk.CRC_reg >> 25 & 1) ^ (sCRC_chk.CRC_reg >> 31 & 1) ^ (CRC_data >> 0 & 1) ^ (CRC_data >> 6 & 1)) << 13;
        sCRC_chk.NewCRC = sCRC_chk.NewCRC | ((sCRC_chk.CRC_reg >> 6 & 1) ^ (sCRC_chk.CRC_reg >> 31 & 1) ^ (CRC_data >> 0 & 1) ^ (sCRC_chk.CRC_reg >> 30 & 1) ^ (CRC_data >> 1 & 1) ^ (sCRC_chk.CRC_reg >> 28 & 1) ^ (CRC_data >> 3 & 1) ^ (sCRC_chk.CRC_reg >> 27 & 1) ^ (CRC_data >> 4 & 1) ^ (sCRC_chk.CRC_reg >> 26 & 1) ^ (CRC_data >> 5 & 1)) << 14;
        sCRC_chk.NewCRC = sCRC_chk.NewCRC | ((sCRC_chk.CRC_reg >> 7 & 1) ^ (sCRC_chk.CRC_reg >> 31 & 1) ^ (CRC_data >> 0 & 1) ^ (sCRC_chk.CRC_reg >> 29 & 1) ^ (CRC_data >> 2 & 1) ^ (sCRC_chk.CRC_reg >> 28 & 1) ^ (CRC_data >> 3 & 1) ^ (sCRC_chk.CRC_reg >> 27 & 1) ^ (CRC_data >> 4 & 1)) << 15;
        sCRC_chk.NewCRC = sCRC_chk.NewCRC | ((sCRC_chk.CRC_reg >> 8 & 1) ^ (sCRC_chk.CRC_reg >> 29 & 1) ^ (CRC_data >> 2 & 1) ^ (sCRC_chk.CRC_reg >> 28 & 1) ^ (CRC_data >> 3 & 1) ^ (sCRC_chk.CRC_reg >> 24 & 1) ^ (CRC_data >> 7 & 1)) << 16;
        sCRC_chk.NewCRC = sCRC_chk.NewCRC | ((sCRC_chk.CRC_reg >> 9 & 1) ^ (sCRC_chk.CRC_reg >> 30 & 1) ^ (CRC_data >> 1 & 1) ^ (sCRC_chk.CRC_reg >> 29 & 1) ^ (CRC_data >> 2 & 1) ^ (sCRC_chk.CRC_reg >> 25 & 1) ^ (CRC_data >> 6 & 1)) << 17;
        sCRC_chk.NewCRC = sCRC_chk.NewCRC | ((sCRC_chk.CRC_reg >> 10 & 1) ^ (sCRC_chk.CRC_reg >> 31 & 1) ^ (CRC_data >> 0 & 1) ^ (sCRC_chk.CRC_reg >> 30 & 1) ^ (CRC_data >> 1 & 1) ^ (sCRC_chk.CRC_reg >> 26 & 1) ^ (CRC_data >> 5 & 1)) << 18;
        sCRC_chk.NewCRC = sCRC_chk.NewCRC | ((sCRC_chk.CRC_reg >> 11 & 1) ^ (sCRC_chk.CRC_reg >> 31 & 1) ^ (CRC_data >> 0 & 1) ^ (sCRC_chk.CRC_reg >> 27 & 1) ^ (CRC_data >> 4 & 1)) << 19;
        sCRC_chk.NewCRC = sCRC_chk.NewCRC | ((sCRC_chk.CRC_reg >> 12 & 1) ^ (sCRC_chk.CRC_reg >> 28 & 1) ^ (CRC_data >> 3 & 1)) << 20;
        sCRC_chk.NewCRC = sCRC_chk.NewCRC | ((sCRC_chk.CRC_reg >> 13 & 1) ^ (sCRC_chk.CRC_reg >> 29 & 1) ^ (CRC_data >> 2 & 1)) << 21;
        sCRC_chk.NewCRC = sCRC_chk.NewCRC | ((sCRC_chk.CRC_reg >> 14 & 1) ^ (sCRC_chk.CRC_reg >> 24 & 1) ^ (CRC_data >> 7 & 1)) << 22;
        sCRC_chk.NewCRC = sCRC_chk.NewCRC | ((sCRC_chk.CRC_reg >> 15 & 1) ^ (sCRC_chk.CRC_reg >> 25 & 1) ^ (CRC_data >> 6 & 1) ^ (sCRC_chk.CRC_reg >> 24 & 1) ^ (sCRC_chk.CRC_reg >> 30 & 1) ^ (CRC_data >> 1 & 1) ^ (CRC_data >> 7 & 1)) << 23;
        sCRC_chk.NewCRC = sCRC_chk.NewCRC | ((sCRC_chk.CRC_reg >> 16 & 1) ^ (sCRC_chk.CRC_reg >> 26 & 1) ^ (CRC_data >> 5 & 1) ^ (sCRC_chk.CRC_reg >> 25 & 1) ^ (sCRC_chk.CRC_reg >> 31 & 1) ^ (CRC_data >> 0 & 1) ^ (CRC_data >> 6 & 1)) << 24;
        sCRC_chk.NewCRC = sCRC_chk.NewCRC | ((sCRC_chk.CRC_reg >> 17 & 1) ^ (sCRC_chk.CRC_reg >> 27 & 1) ^ (CRC_data >> 4 & 1) ^ (sCRC_chk.CRC_reg >> 26 & 1) ^ (CRC_data >> 5 & 1)) << 25;
        sCRC_chk.NewCRC = sCRC_chk.NewCRC | ((sCRC_chk.CRC_reg >> 18 & 1) ^ (sCRC_chk.CRC_reg >> 28 & 1) ^ (CRC_data >> 3 & 1) ^ (sCRC_chk.CRC_reg >> 27 & 1) ^ (CRC_data >> 4 & 1) ^ (sCRC_chk.CRC_reg >> 24 & 1) ^ (sCRC_chk.CRC_reg >> 30 & 1) ^ (CRC_data >> 1 & 1) ^ (CRC_data >> 7 & 1)) << 26;
        sCRC_chk.NewCRC = sCRC_chk.NewCRC | ((sCRC_chk.CRC_reg >> 19 & 1) ^ (sCRC_chk.CRC_reg >> 29 & 1) ^ (CRC_data >> 2 & 1) ^ (sCRC_chk.CRC_reg >> 28 & 1) ^ (CRC_data >> 3 & 1) ^ (sCRC_chk.CRC_reg >> 25 & 1) ^ (sCRC_chk.CRC_reg >> 31 & 1) ^ (CRC_data >> 0 & 1) ^ (CRC_data >> 6 & 1)) << 27;
        sCRC_chk.NewCRC = sCRC_chk.NewCRC | ((sCRC_chk.CRC_reg >> 20 & 1) ^ (sCRC_chk.CRC_reg >> 30 & 1) ^ (CRC_data >> 1 & 1) ^ (sCRC_chk.CRC_reg >> 29 & 1) ^ (CRC_data >> 2 & 1) ^ (sCRC_chk.CRC_reg >> 26 & 1) ^ (CRC_data >> 5 & 1)) << 28;
        sCRC_chk.NewCRC = sCRC_chk.NewCRC | ((sCRC_chk.CRC_reg >> 21 & 1) ^ (sCRC_chk.CRC_reg >> 31 & 1) ^ (CRC_data >> 0 & 1) ^ (sCRC_chk.CRC_reg >> 30 & 1) ^ (CRC_data >> 1 & 1) ^ (sCRC_chk.CRC_reg >> 27 & 1) ^ (CRC_data >> 4 & 1)) << 29;
        sCRC_chk.NewCRC = sCRC_chk.NewCRC | ((sCRC_chk.CRC_reg >> 22 & 1) ^ (sCRC_chk.CRC_reg >> 31 & 1) ^ (CRC_data >> 0 & 1) ^ (sCRC_chk.CRC_reg >> 28 & 1) ^ (CRC_data >> 3 & 1)) << 30;
        sCRC_chk.NewCRC = sCRC_chk.NewCRC | ((sCRC_chk.CRC_reg >> 23 & 1) ^ (sCRC_chk.CRC_reg >> 29 & 1) ^ (CRC_data >> 2 & 1)) << 31;
        sCRC_chk.Next_CRC = sCRC_chk.NewCRC;
        tmp2 = sCRC_chk.Next_CRC;
      }

  if(Reset)
    sCRC_chk.CRC_reg = tmp0;
  else
    if(CRC_init)
      sCRC_chk.CRC_reg = tmp1;
  else
    if(CRC_en)
    {
      sCRC_chk.CRC_reg = tmp2;
    }
  *CRC_err = CRC_chk_en && sCRC_chk.CRC_reg != 3338984827;
  *CRC_err = CRC_chk_en && sCRC_chk.CRC_reg != 3338984827;
}

/*
void main() {
 _Bool Reset;
 _Bool Clk;
 unsigned char CRC_data;
 _Bool CRC_init;
 _Bool CRC_en;
 _Bool CRC_chk_en;
 _Bool CRC_err;
 while(1) {
  CRC_chk(Reset, Clk, CRC_data, CRC_init, CRC_en, CRC_chk_en, &CRC_err);
 }
}*/
