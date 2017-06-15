#include <assert.h>

int A=0;
int B=1;
int C=2;
int D=3;
int E=4;
int F=5;
int G=6;

struct state_elements_main {
  _Bool U;
  unsigned char stato;
};
struct state_elements_main smain; 

void initial() {
  smain.U = 0;
  smain.stato = A;
}

void b02(
    _Bool clock,
    _Bool  LINEA, _Bool *U)
{
  // clocked block
  switch(smain.stato) {
    case 0: 
              smain.stato = B;
              smain.U=0;
              break;
            
    case 1: 
              if (LINEA==0)
                smain.stato = C;
              else
                smain.stato = F;
              smain.U = 0;
              break;
            
    case 2: 
              if (LINEA==0)
                smain.stato = D;
              else 
                smain.stato = G;
              smain.U = 0;
              break;
            
    case 3: 
              smain.stato = E;
              smain.U=0;
              break;
            
    case 4: 
              smain.stato = B;
              smain.U=1;
              break;
            
    case 5: 
              smain.stato = G;
              smain.U=0;
              break;
            
    case 6: 
              if (LINEA==0)
                smain.stato = E;
              else 
                smain.stato = A;
              smain.U = 0;
              break;
            
  }
  *U=smain.U;
}

int main()
{
  _Bool LINEA;
  _Bool U; 
  _Bool  clock=0;
  _Bool   nb;
  __ASTREE_volatile_input((nb));
  initial();

  while(1) {
    LINEA=nb;
    b02(clock,LINEA,&U);
    if(smain.stato==D) {
      b02(clock,LINEA,&U);
      b02(clock,LINEA,&U);
      assert(smain.stato!=B);
    }
  }
  return 1;
}
