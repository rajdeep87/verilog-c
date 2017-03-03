//#include <stdio.h>
#define TRUE 1
#define FALSE 0

struct state_elements_eth_shiftreg{
unsigned short int Prsd;
_Bool LinkFail;
unsigned char ShiftReg;
};
void eth_shiftreg(_Bool Clk, _Bool Reset, _Bool MdcEn_n, _Bool Mdi, unsigned char Fiad, unsigned char Rgad, unsigned short int CtrlData, _Bool WriteOp, unsigned char ByteSelect, unsigned char LatchByte, _Bool *ShiftedBit, unsigned short int *Prsd, _Bool *LinkFail)
{
  struct state_elements_eth_shiftreg  seth_shiftreg;
  unsigned char tmp6, tmp7, tmp8, tmp9, tmp10, tmp11;
  _Bool tmp5;
  unsigned char tmp4;
  unsigned char tmp3;
  _Bool tmp2;
  unsigned short int tmp1;
  unsigned char tmp0;
  int Tp;
  Tp = 1;
  if(Reset)
  {
    tmp0 = 0;
    tmp1 = 0;
    tmp2 = FALSE;
  }

  else
  {
    if(MdcEn_n)
    {
      if((ByteSelect & 8) | (ByteSelect & 4) | (ByteSelect & 2) | (ByteSelect & 1))
      {
        switch (ByteSelect & 0xF) {
          case 1: tmp7 = 0x1 << 6 | !WriteOp | WriteOp | Fiad & 0x1E;
          case 2: tmp8 = Fiad & 1 << 7 | Rgad & 0x1F << 2 | 0x2;
          case 4: tmp9 = CtrlData >> 8 & 0xFF;
          case 8: tmp10 = CtrlData & 0xFF;
          default: tmp11 = 0x00;
        }
      }
      else
      {
        tmp3 = (seth_shiftreg.ShiftReg >> 0 & 127) << 1 | Mdi;
        if(LatchByte & 1)
        {
          tmp4 = (seth_shiftreg.ShiftReg >> 0 & 127) << 1 | Mdi;
          if(Rgad == 1)
            tmp5 = !seth_shiftreg.ShiftReg >> 1 & 1;
        }
        else
        {
          if(LatchByte >> 1 & 1)
            tmp6 = (seth_shiftreg.ShiftReg >> 0 & 127) << 1 | Mdi;
        }
      }
    }
  }
  if(Reset)
  {
    seth_shiftreg.ShiftReg = tmp0 & 0xFF;
    {
      seth_shiftreg.Prsd = tmp1 & 0xFFFF;
      *Prsd = tmp1 & 0xFF;
    }
    {
      seth_shiftreg.LinkFail = tmp2;
      *LinkFail = tmp2;
    }
  }

  else
  {
    if(MdcEn_n)
    {
      if((ByteSelect & 8) | (ByteSelect & 4) | (ByteSelect & 2) | (ByteSelect & 1))
      {
        switch (ByteSelect & 0xF) {
          case 1: seth_shiftreg.ShiftReg = tmp7; 
          case 2: seth_shiftreg.ShiftReg = tmp8; 
          case 4: seth_shiftreg.ShiftReg = tmp9; 
          case 8: seth_shiftreg.ShiftReg = tmp10; 
          default: seth_shiftreg.ShiftReg = tmp11;
        }
      }
      else
      {
        seth_shiftreg.ShiftReg = tmp3;
        if(LatchByte & 1)
        {
          *Prsd = *Prsd | tmp4 & 0xFF;
          seth_shiftreg.Prsd = seth_shiftreg.Prsd | tmp4 & 0xFF;
          if(Rgad == 1)
            *LinkFail = tmp5; 
        }
        else
        {
          if(LatchByte >> 1 & 1)
            *Prsd = *Prsd | tmp6 << 8;
            seth_shiftreg.Prsd = seth_shiftreg.Prsd | tmp6 & 0xFF;
        }
      }
    }
  }
  *ShiftedBit = seth_shiftreg.ShiftReg >> 7 & 1;
}

/*
void main() {
_Bool Clk;
_Bool Reset;
_Bool MdcEn_n;
_Bool Mdi;
unsigned char Fiad;
unsigned char Rgad;
unsigned short int CtrlData;
_Bool WriteOp;
unsigned char ByteSelect;
unsigned char LatchByte;
_Bool ShiftedBit;
unsigned short int Prsd;
_Bool LinkFail;
while(1) {
eth_shiftreg(Clk, Reset, MdcEn_n, Mdi, Fiad, Rgad, CtrlData, WriteOp, ByteSelect, LatchByte, &ShiftedBit, &Prsd, &LinkFail);
}
}*/
