#include <assert.h>

struct state_elements_main{
 unsigned char valid;
 unsigned char qAge;
};
struct state_elements_main  smain;

void ibuf(_Bool clock, unsigned char iqLoads, unsigned char exeReady, unsigned char opsReady, unsigned char flush, unsigned char *load0, unsigned char *load1, unsigned char *load2, unsigned char *issue0, unsigned char *issue1, unsigned char *valid)
{
  _Bool nv0;
  _Bool nv1;
  _Bool nv2;
  

  *load0 = (*load0 & 0x2) | ((!(smain.valid&1) && (iqLoads&1))&1);
  *load0 = (*load0 & 0x1) | (((!(smain.valid&1) && !(iqLoads&1) && ((iqLoads>>1)&1)) << 1)&2);
  *load1 = (*load1 & 0x2) | ((!((smain.valid>>1)&1) && (smain.valid&1) && (iqLoads&1))&1);
  *load1 = (*load1 & 0x1) | (((!((smain.valid>>1)&1) && ((iqLoads>>1)&1) && !(((*load0>>1)&1) || (*load1&1))) << 1)&2);

  *load2 = (*load2 & 0x2) | ((!((smain.valid>>2)&1) && ((smain.valid>>1)&1) && (smain.valid&1) && (iqLoads&1))&1);
  *load2 = (*load2 & 0x1) | (((!((smain.valid>>2)&1) && ((iqLoads>>1)&1) && !((*load2&1) || ((*load0>>1)&1) || ((*load1>>1)&1))) << 1)&2);
 
 
  *issue0 = (*issue0 & 0x6) | (((exeReady&1) && (opsReady&1) && (smain.valid&1) && ((smain.qAge&1) || !((opsReady>>1)&1)) && (((smain.qAge>>1)&1) || !((opsReady>>2)&1)))&1);
  
  *issue0 = (*issue0 & 0x5) | (((((exeReady&1) && ((opsReady>>1)&1) && ((smain.valid>>1)&1) && (!(smain.qAge&1) || !(opsReady&1)) && (((smain.qAge>>2)&1) || !((opsReady>>2)&1))) << 1)<<2)&2);
  
  *issue0 = (*issue0 & 0x3) | ((((exeReady&1) && ((opsReady>>2)&1) && ((smain.valid>>2)&1) && (!((smain.qAge>>1)&1) || !(opsReady&1)) && (((smain.qAge>>2)&1) || !((opsReady>>1)&1))) << 2)&4);
  
  *issue1 = (*issue1 & 0x6) | ((((exeReady>>1)&1) && (opsReady&1) && (smain.valid&1) && ((smain.qAge&1) || !((opsReady>>1)&1) || ((*issue0>>1)&1)) && (((smain.qAge>>1)&1) || !((opsReady>>2)&1) || ((*issue0>>2)&1)) && !(*issue0&1))&1);
  
  *issue1 = (*issue1 & 0x5) | (((((exeReady>>1)&1) && ((opsReady>>1)&1) && ((smain.valid>>1)&1) && (!(smain.qAge&1) || !(opsReady&1) || (*issue0&1)) && (((smain.qAge>>2)&1) || !((opsReady>>2)&1) || ((*issue0>>2)&1)) && !((*issue0>>1)&1)) << 1)&2);
  
  *issue1 = (*issue1 & 0x3) | (((((exeReady>>1)&1) && ((opsReady>>2)&1) && ((smain.valid>>2)&1) && (!((smain.qAge>>1)&1) || !(opsReady&1) || (*issue0&1)) && (((smain.qAge>>2)&1) || !((opsReady>>1)&1) || ((*issue0>>1)&1)) && !((*issue0>>2)&1)) << 2)&4);


  nv0 = !(flush&1) && (((smain.valid&1) && !((*issue0&1) || (*issue1&1))) || (*load0&1));

  nv1 = !((flush>>1)&1) && ((((smain.valid>>1)&1) && !(((*issue0>>1)&1) || ((*issue1>>1)&1))) || (*load1&1));

  nv2 = !((flush>>2)&1) && ((((smain.valid>>2)&1) && !(((*issue0>>2)&1) || ((*issue1>>2)&1))) || (*load2&1));

  smain.valid = (smain.valid & 0x6) | ((nv0 & 1)&1);
  smain.valid = (smain.valid & 0x5) | ((nv1 << 1)&2);
  smain.valid = (smain.valid & 0x3) | ((nv2 << 2)&4);
  smain.qAge = (smain.qAge & 0x6) | ((nv0 && (!nv1 || (smain.qAge & 1) || !((smain.valid >> 1) & 1))) & 1);
  smain.qAge = (smain.qAge & 0x5) | (((nv0 && (!nv2 || ((smain.qAge >> 1)&1) || !((smain.valid>>2)&1))) << 1)&2);
  smain.qAge = (smain.qAge & 0x3) | (((nv1 && (!nv2 || ((smain.qAge >> 2)&1) || !((smain.valid>>2)&1))) << 2)&4);
}

void initial_main() {
  smain.qAge = 0;
  smain.valid = 0;
}

int main() {
  _Bool clock=0;
  unsigned char iqLoads;
  unsigned char exeReady;
  unsigned char opsReady;
  unsigned char flush;
  unsigned char load0;
  unsigned char load1;
  unsigned char load2;
  unsigned char issue0;
  unsigned char issue1;
  unsigned char valid;
  unsigned char nondet_uchar;
  __ASTREE_volatile_input((nondet_uchar));


  initial_main();

  /*assert(((smain.qAge&1)==0 || ((smain.qAge>>1)&1)==1 || ((smain.qAge>>2)&1)==0) &&
  ((smain.qAge&1)==1 || ((smain.qAge>>1)&1)==0 || ((smain.qAge>>2)&1)==1) &&
  (!((smain.qAge&1)==1) ||  (smain.valid&1)==1) &&
  (!(((smain.qAge>>1)&1)==1) || (smain.valid&1)==1) &&
  (!(((smain.qAge>>2)&1)==1) || ((smain.valid>>1)&1)==1) &&
  (!((smain.valid&1)==1 && ((smain.valid>>1)&1)==0) || (smain.qAge&1)==1) &&
  (!((smain.valid&1)==1 && ((smain.valid>>2)&1)==0) || ((smain.qAge>>1)&1)==1) &&
  (!(((smain.valid>>1)&1)==1 && ((smain.valid>>2)&1)==0) || ((smain.qAge>>2)&1)==1));
  */

  while(1) {
    iqLoads = nondet_uchar;
    exeReady = nondet_uchar;
    opsReady = nondet_uchar;
    flush = nondet_uchar;

  ibuf(clock, iqLoads, exeReady, opsReady, flush, &load0, &load1, &load2, &issue0, &issue1, &valid);
  
    assert(!(((smain.qAge&1)==0 || ((smain.qAge>>1)&1)==1 || ((smain.qAge>>2)&1)==0) &&
  ((smain.qAge&1)==1 || ((smain.qAge>>1)&1)==0 || ((smain.qAge>>2)&1)==1) &&
  (!((smain.qAge&1)==1) ||  (smain.valid&1)==1) &&
  (!(((smain.qAge>>1)&1)==1) || (smain.valid&1)==1) &&
  (!(((smain.qAge>>2)&1)==1) || ((smain.valid>>1)&1)==1) &&
  (!((smain.valid&1)==1 && ((smain.valid>>1)&1)==0) || (smain.qAge&1)==1) &&
  (!((smain.valid&1)==1 && ((smain.valid>>2)&1)==0) || ((smain.qAge>>1)&1)==1) &&
  (!(((smain.valid>>1)&1)==1 && ((smain.valid>>2)&1)==0) || ((smain.qAge>>2)&1)==1)));
  }
  return 1;
}
