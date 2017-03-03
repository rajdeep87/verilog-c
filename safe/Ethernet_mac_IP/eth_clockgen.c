//#include <stdio.h>
#define TRUE 1
#define FALSE 0

struct state_elements_eth_clockgen{
unsigned char Counter;
_Bool Mdc;
};
void eth_clockgen(_Bool Clk, _Bool Reset, unsigned char Divider, _Bool *Mdc, _Bool *MdcEn, _Bool *MdcEn_n)
{
  struct state_elements_eth_clockgen  seth_clockgen;
  _Bool tmp4;
  _Bool tmp3;
  unsigned char tmp2;
  unsigned char tmp1;
  unsigned char tmp0;
  int Tp;
  Tp = 1;
  _Bool CountEq0;
  unsigned char CounterPreset;
  unsigned char TempDivider;
  TempDivider = TempDivider | ((unsigned int)Divider & 0xFF < 2 ? 2 : Divider & 0xFF) << 0;
  CounterPreset = CounterPreset | (unsigned int)(TempDivider & 0xFF >> 1) - 1 << 0;
  if(Reset)
    tmp0 = 1;

  else
  {
    if(CountEq0)
    {
      tmp1 = CounterPreset & 0xFF;
    }

    else
      tmp2 = seth_clockgen.Counter - 1;
  }
  if(Reset)
    tmp3 = FALSE;

  else
  {
    if(CountEq0)
      tmp4 = !seth_clockgen.Mdc;

  }
  CountEq0 = seth_clockgen.Counter == 0;
  *MdcEn = CountEq0 && !seth_clockgen.Mdc;
  *MdcEn = CountEq0 && !seth_clockgen.Mdc;
  *MdcEn_n = CountEq0 && seth_clockgen.Mdc;
  *MdcEn_n = CountEq0 && seth_clockgen.Mdc;
  if(Reset)
    seth_clockgen.Counter = tmp0 & 0xFF;

  else
  {
    if(CountEq0)
    {
      seth_clockgen.Counter = tmp1 & 0xFF;
    }

    else
      seth_clockgen.Counter = tmp2 & 0xFF;
  }
  if(Reset)
  {
    seth_clockgen.Mdc = tmp3;
    *Mdc = tmp3;
  }

  else
  {
    if(CountEq0)
    {
      seth_clockgen.Mdc = tmp4;
      *Mdc = tmp4;
    }

  }
}

/*
void main() {
_Bool Clk;
_Bool Reset;
unsigned char Divider;
_Bool Mdc;
_Bool MdcEn;
_Bool MdcEn_n;
while(1) {
eth_clockgen(Clk, Reset, Divider, &Mdc, &MdcEn, &MdcEn_n);
}
}*/
