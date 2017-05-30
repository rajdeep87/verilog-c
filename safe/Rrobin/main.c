#include <assert.h>

struct state_elements_main {
  _Bool ack0;
  _Bool ack1;
  _Bool req0;
  _Bool req1;
  _Bool robin;
};
struct state_elements_main  smain;

void rrobin(_Bool clock, _Bool ir0, _Bool ir1, _Bool *ack0, _Bool *ack1)
{
  if(!smain.req0)
    smain.ack0 = 0;
  else if(!smain.req1)
    smain.ack0 = 1;
  else if(!smain.ack0 && !smain.ack1)
    smain.ack0 = !smain.robin;
  else
    smain.ack0 = !smain.ack0;
  
  if(!smain.req1)
    smain.ack1 = 0;
  else if(!smain.req0)
    smain.ack1 = 1;
  else if(!smain.ack0 && !smain.ack1)
    smain.ack1 = smain.robin;
  else
    smain.ack1 = !smain.ack1;

  if(smain.req0 && smain.req1 && !smain.ack0 && !smain.ack1)
    smain.robin = !smain.robin;

  smain.req0 = ir0;
  smain.req1 = ir1;

  // update the acknowledgement
  *ack0 = smain.ack0;
  *ack1 = smain.ack1;
}

void initial_main(_Bool ir0, _Bool ir1) {
  smain.ack0 = 0;
  smain.ack1 = 0;
  smain.robin = 0;
  smain.req0 = ir0;
  smain.req1 = ir1;
}

int main() {
  _Bool clock=0;
  _Bool ir0;
  _Bool ir1;
  _Bool ack0;
  _Bool ack1;
  _Bool nd_b;
  __ASTREE_volatile_input((nd_b));
  
  initial_main(ir0, ir1);
  while(1) {
    ir0 = nd_b;
    ir1 = nd_b;
    if(smain.req1==1 && smain.ack0==1) {
      rrobin(clock, ir0, ir1, &ack0, &ack1);
      assert(ack1==1);
    }
  }
  return 0;
}
