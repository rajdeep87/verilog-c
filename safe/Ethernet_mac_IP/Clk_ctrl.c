//#include <stdio.h>

#define TRUE 1
#define FALSE 0

void Clk_ctrl(_Bool Reset, _Bool Clk_125M, unsigned char Speed, _Bool *Gtx_clk, _Bool Rx_clk, _Bool Tx_clk, _Bool *MAC_tx_clk, _Bool *MAC_rx_clk, _Bool *MAC_tx_clk_div, _Bool *MAC_rx_clk_div)
{
  _Bool Rx_clk_div2;
  _Bool Tx_clk_div2;
  *Gtx_clk = Clk_125M;
  *Gtx_clk = Clk_125M;
  *MAC_rx_clk = Rx_clk;
  *MAC_rx_clk = Rx_clk;
}

/*
void main() {
_Bool Reset;
_Bool Clk_125M;
unsigned char Speed;
_Bool Gtx_clk;
_Bool Rx_clk;
_Bool Tx_clk;
_Bool MAC_tx_clk;
_Bool MAC_rx_clk;
_Bool MAC_tx_clk_div;
_Bool MAC_rx_clk_div;
Clk_ctrl(Reset, Clk_125M, Speed, &Gtx_clk, Rx_clk, Tx_clk, &MAC_tx_clk, &MAC_rx_clk, &MAC_tx_clk_div, &MAC_rx_clk_div);
}
*/
