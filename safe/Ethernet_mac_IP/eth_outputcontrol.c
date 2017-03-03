//#include <stdio.h>
#define TRUE 1
#define FALSE 0

struct state_elements_eth_outputcontrol{
_Bool MdoEn_2d;
_Bool MdoEn_d;
_Bool Mdo_2d;
_Bool Mdo_d;
_Bool Mdo;
_Bool MdoEn;
};
void eth_outputcontrol(_Bool Clk, _Bool Reset, _Bool WriteOp, _Bool NoPre, _Bool InProgress, _Bool ShiftedBit, unsigned char BitCounter, _Bool MdcEn_n, _Bool *Mdo, _Bool *MdoEn)
{
  struct state_elements_eth_outputcontrol  seth_outputcontrol;
  _Bool tmp11;
  _Bool tmp10;
  _Bool tmp9;
  _Bool tmp8;
  _Bool tmp7;
  _Bool tmp6;
  _Bool tmp5;
  _Bool tmp4;
  _Bool tmp3;
  _Bool tmp2;
  _Bool tmp1;
  _Bool tmp0;
  int Tp;
  Tp = 1;
  _Bool SerialEn;
  SerialEn = WriteOp && InProgress && ((unsigned int)BitCounter > 31 || (unsigned int)BitCounter == 0 && NoPre) || !WriteOp && InProgress && ((unsigned int)BitCounter > 31 && (unsigned int)BitCounter < 46 || (unsigned int)BitCounter == 0 && NoPre);
  if(Reset)
  {
    tmp0 = FALSE;
    tmp1 = FALSE;
    tmp2 = FALSE;
  }

  else
  {
    if(MdcEn_n)
    {
      tmp3 = SerialEn || InProgress && (unsigned int)BitCounter < 32;
      tmp4 = seth_outputcontrol.MdoEn_2d;
      tmp5 = seth_outputcontrol.MdoEn_d;
    }

  }
  if(Reset)
  {
    tmp6 = FALSE;
    tmp7 = FALSE;
    tmp8 = FALSE;
  }

  else
  {
    if(MdcEn_n)
    {
      tmp9 = !SerialEn && (unsigned int)BitCounter < 32;
      tmp10 = ShiftedBit || seth_outputcontrol.Mdo_2d;
      tmp11 = seth_outputcontrol.Mdo_d;
    }

  }
  if(Reset)
  {
    seth_outputcontrol.MdoEn_2d = tmp0;
    seth_outputcontrol.MdoEn_d = tmp1;
    {
      seth_outputcontrol.MdoEn = tmp2;
      *MdoEn = tmp2;
    }
  }

  else
  {
    if(MdcEn_n)
    {
      seth_outputcontrol.MdoEn_2d = tmp3;
      seth_outputcontrol.MdoEn_d = tmp4;
      {
        seth_outputcontrol.MdoEn = tmp5;
        *MdoEn = tmp5;
      }
    }

  }
  if(Reset)
  {
    seth_outputcontrol.Mdo_2d = tmp6;
    seth_outputcontrol.Mdo_d = tmp7;
    {
      seth_outputcontrol.Mdo = tmp8;
      *Mdo = tmp8;
    }
  }

  else
  {
    if(MdcEn_n)
    {
      seth_outputcontrol.Mdo_2d = tmp9;
      seth_outputcontrol.Mdo_d = tmp10;
      {
        seth_outputcontrol.Mdo = tmp11;
        *Mdo = tmp11;
      }
    }

  }
}
/*
void main() {
_Bool Clk;
_Bool Reset;
_Bool WriteOp;
_Bool NoPre;
_Bool InProgress;
_Bool ShiftedBit;
unsigned char BitCounter;
_Bool MdcEn_n;
_Bool Mdo;
_Bool MdoEn;
while(1) {
eth_outputcontrol(Clk, Reset, WriteOp, NoPre, InProgress, ShiftedBit, BitCounter, MdcEn_n, &Mdo, &MdoEn);
}
}*/
