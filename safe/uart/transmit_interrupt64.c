#include<assert.h>
#include "rtfSimpleUart.c"

// type declarations
typedef unsigned int _u32;
typedef unsigned char _u8;
unsigned char nondet_uchar();

// ----------------------------------------------------
// Global data declared for the top level module in RTL
// ----------------------------------------------------
  _Bool rst_i;_Bool clk_i;_Bool cyc_i;_Bool stb_i; _Bool we_i;
  unsigned int adr_i; unsigned char dat_i;
  unsigned char dat_o; 
  _Bool ack_o; _Bool vol_o; _Bool irq_o; _Bool cts_ni; 
  _Bool rts_no; _Bool dsr_ni; _Bool dcd_ni; _Bool dtr_no; 
  _Bool rxd_i; _Bool txd_o; _Bool data_present_o;
 
// ---------------------------------------------------------------------
// Transactions on the wishbone interface
// ---------------------------------------------------------------------

void wb_reset(void) {
  
  rtfSimpleUart(1, clk_i, cyc_i, stb_i, we_i, adr_i, dat_i, &dat_o, &ack_o, &vol_o, &irq_o, cts_ni, 
                &rts_no, dsr_ni, dcd_ni, &dtr_no, rxd_i, &txd_o, &data_present_o);
 
  rst_i = 0;
  // Rule 3.20
  stb_i = 0;
  cyc_i = 0;
}

void wb_idle() {

  assert(rst_i == 0 && stb_i == 0 && cyc_i == 0);
  
  rtfSimpleUart(rst_i, clk_i, cyc_i, stb_i, we_i, adr_i, dat_i, &dat_o, &ack_o, &vol_o, &irq_o, 
                      cts_ni, &rts_no, dsr_ni, dcd_ni, &dtr_no, rxd_i, &txd_o, &data_present_o);
}

void wb_write(_u32 addr, _u8 b) {
  
  // Master presents address, data, asserts WE, CYC and STB
  // this invocation is for cs as cs is set combinatorially 
  // in hw-cbmc, this is attained through set_inputs();
  rtfSimpleUart(0, clk_i, 1, 1, 1, addr, b, &dat_o, &ack_o, &vol_o, &irq_o, cts_ni, 
                   &rts_no, dsr_ni, dcd_ni, &dtr_no, rxd_i, &txd_o, &data_present_o);
  
  if((addr & 0xF) == 4)
  {
    assert(srtfSimpleUart.rx_present_ie == (b & 1));
    assert(srtfSimpleUart.tx_empty_ie == ((b >> 1) & 1));
    assert(srtfSimpleUart.dcd_ie == ((b >> 3) & 1));
  }

  // this holds for UART_CR 
  if((addr & 0xF) == 7)
  {
    assert(srtfSimpleUart.hwfc == (b & 1));
  }

  we_i = 0;
  cyc_i = 0;
  stb_i = 0;
  
}

_u8 wb_read(_u32 addr) {
  
  // Master presents address, data, asserts CYC and STB, deasserts WE
  rtfSimpleUart(0, clk_i, 1, 1, 0, addr, dat_i, &dat_o, &ack_o, &vol_o, &irq_o, cts_ni, &rts_no, dsr_ni, dcd_ni, &dtr_no, rxd_i, &txd_o, &data_present_o);
  
  _u8 b = dat_o;
  // The following assertion must hold when doing the first inb()
  //assert(b == 0x60); 
  we_i = 0;
  cyc_i = 0;
  stb_i = 0;

  return b;
}

// ---------------------------------------------------------------------
// Linux-style inb, outb
//
// Right now, these call wb_read and wb_write directly.
//
// If/when we decide to run HW and FW in separate threads,
// inb/outb would execute in the FW thread, wb_read/wb_write would
// execute in the hardware thread, and communication between them
// would be via synchronization or fifo channel.
// ---------------------------------------------------------------------

typedef unsigned char u8;

unsigned char inb (unsigned long port) {
  return wb_read(port);
}

void outb (u8 value, unsigned long port) {
  wb_write(port, value);
}

int power(int base, int exp)
{
  int result = 1;
  while(exp) { result *= base; exp--; }
  return result;
}

// ---------------------------------------------------------------------
// UART Firmware
// ---------------------------------------------------------------------

// UART addresses
// Some of these are not implemented yet in the opencores UART.
#define UART_TR 0xffdc0a00         // tx/rx data (RW)
#define UART_LS (UART_TR + 1)      // line status (RO)
#define UART_MS (UART_TR + 2)      // modem status (RO)
#define UART_IS (UART_TR + 3)      // interrupt status (RO)
#define UART_IE (UART_TR + 4)      // interrupt enable (RW)
#define UART_FF (UART_TR + 5)      // frame format (RW)
#define UART_MC (UART_TR + 6)      // modem control (RW)
#define UART_CR (UART_TR + 7)      // uart control (RW)
#define UART_CM0 (UART_TR + 8)     // clock multiplier byte 0 - least significant (RW)
#define UART_CM1 (UART_TR + 9)     //                  byte 1
#define UART_CM2 (UART_TR + 10)    //                  byte 2
#define UART_CM3 (UART_TR + 11)    //                  byte 3 - most significant (RW)
#define UART_FC (UART_TR + 12)     // fifo control (RW)
#define UART_SPR (UART_TR + 15)    // scratchpad (RW)

// ---------------------------------------------------------------------
// Main test routine
// ---------------------------------------------------------------------

int main(void) {

  _u8 b;
  unsigned int i=0,iter=0;
 
  wb_reset();
  assert(srtfSimpleUartTx.cnt == 0x9f);
  
  wb_idle();
  
  // turn off the interrupts
  outb(0x3, UART_IE);
  // check the cs signal, it must be HIGH here
  
  wb_idle();
  
  // turn off hardware flow control
  outb(0x0, UART_CR);
  assert(srtfSimpleUart.hwfc == 0);
 
  wb_idle();

  // Use a really large clk multiplier! (UART_CM0 is ignored)
  assert(srtfSimpleUart.ck_mul != 0);
  // Print some statistics
  outb(0x80, UART_CM3);
  assert(srtfSimpleUart.ck_mul == 0x80ef36);
   
  outb (0x00, UART_CM2);
  assert(srtfSimpleUart.ck_mul == 0x800036);
  
  outb (0x00, UART_CM1);
  assert(srtfSimpleUart.ck_mul == 0x800000);
  assert(srtfSimpleUartTx.cnt == 0x9f);


  // *****************************************
  // ship out a byte through the serial port
  // *****************************************
  // check the Line Status register
    unsigned int data_out=0;
    _Bool data_array[8] = {0,0,0,0,0,0,0,0};
    _u8 data = nondet_uchar();
    __CPROVER_assume(data <= 127);

    b = inb(UART_LS);
    assert(b == 0x60);

    // check all status signals
    assert(srtfSimpleUartTx.empty == 1);
    assert(srtfSimpleUartRx.overrun == 0);
    assert(srtfSimpleUartTx.cnt == 0x9f);
    assert(b & 0x40); // tx empty
    assert(!dtr_no); // data terminal ready
   
    // ********** Transaction 1 **************
    // ship out a byte through the serial port
    // ***************************************

    assert(srtfSimpleUartTx.empty == 1);  
    b = inb(UART_LS);
    assert(b && 0x20); // tx empty
    
    int k=0;
    _Bool flip=1;
    _Bool is_txinterrupt = 0;
    _u8 istatus = 0;
    
    
    if(irq_o) {
      istatus = inb(UART_IS) & 0x0c;
      if (istatus == 0x0c) {
         outb(data, UART_TR);
         is_txinterrupt = 1;
      for (i = 0; i < 20; i++) {
        wb_idle();
      }
      assert(srtfSimpleUartTx.empty == 1);
      b = inb(UART_LS);
      assert(b && 0x20); // tx empty
    
      for(i = 0; i < 317; i++) { 
        if(((srtfSimpleUartTx.cnt & 0xF) == 0xF) && (srtfSimpleUartTx.fdo == data) && flip==1) {
          data_array[k] = d.txdd;
          k++;
        }
        if(flip==1) flip=0;
        else flip = 1;
        wb_idle();
      }
     }
     // rx interrupt is here, but we don't take any action
     else {}
    }
    // there is no interrupt
    else { 
      wb_idle(); 
    }

    //check the data out in the serial port
    _Bool dat;
    if(is_txinterrupt) {
     for(i=1;i<=7;i++) {
        dat = data_array[i]; 
        data_out = data_out + (dat * power(2,(i-1))); 
     }
     assert(data_out == data);
    } 
   return 1;
}
