//#include <stdio.h>
#define TRUE 1
#define FALSE 0
struct state_elements_RMON_dpram{
};
void RMON_dpram(_Bool Reset, _Bool Clk, unsigned char Addra, unsigned int Dina, unsigned int *Douta, _Bool Wea, unsigned char Addrb, unsigned int *Doutb)
{
  struct state_elements_RMON_dpram  sRMON_dpram;
  _Bool Clka;
  _Bool Clkb;
  Clka = Clk;
  Clkb = Clk;
}

/*
void main() {
_Bool Reset;
_Bool Clk;
unsigned char Addra;
unsigned int Dina;
unsigned int Douta;
_Bool Wea;
unsigned char Addrb;
unsigned int Doutb;
RMON_dpram(Reset, Clk, Addra, Dina, &Douta, Wea, Addrb, &Doutb);
}
*/
