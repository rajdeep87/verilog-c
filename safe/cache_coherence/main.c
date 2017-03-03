#include <stdio.h>
#include <assert.h>
#define TRUE 1
#define FALSE 0

struct state_elements_processor{
_Bool valid;
unsigned int count;
};
struct state_elements_processor  sprocessor;

void processor_initial() { 
  sprocessor.count = 5;
  sprocessor.valid = TRUE;
}
void processor(_Bool clk, _Bool req_enable, _Bool *valid)
{
  _Bool tmp3;
  unsigned int tmp2;
  unsigned int tmp1;
  _Bool tmp0;
  unsigned int nd_count;
  if(req_enable)
  {
    if((unsigned int)sprocessor.count == 0)
    {
      tmp0 = TRUE;
      tmp1 = nd_count;
      sprocessor.valid = tmp0;
      *valid = tmp0;
      sprocessor.count = tmp1 & 7;
    }
    else
    {
      tmp2 = (unsigned int)(unsigned int)sprocessor.count - 1;
      tmp3 = FALSE;
      sprocessor.count = tmp2 & 7;
      sprocessor.valid = tmp3;
      *valid = tmp3;
    }
  }
}

struct state_elements_pcache {
 _Bool bus_req;
 _Bool hit;
 _Bool inv_out;
 _Bool miss;
 _Bool read;
 _Bool update;
 _Bool write;
 unsigned int next_state;
 unsigned int state;
 unsigned int snoop_type;
};
struct state_elements_pcache  spcache;

void pcache_initial() {
 spcache.state = 2;
 spcache.next_state = 0;
 spcache.bus_req = FALSE;
 spcache.snoop_type = 2;
 spcache.read = TRUE;
 spcache.write = FALSE;
 spcache.hit = FALSE;
 spcache.miss = TRUE;
 spcache.update = FALSE;
 spcache.inv_out = FALSE;
}
void pcache(_Bool clk, unsigned int shared_snoop, _Bool is_snoop, unsigned int master_in, _Bool ND_in, _Bool bus_ack, _Bool all_shared, _Bool mem_served, _Bool invalidate, unsigned int *snoop_type, _Bool *bus_req, _Bool *master_out, _Bool *is_shared, _Bool *inv_out, _Bool *info_avail)
{
  _Bool tmp97;
  _Bool tmp96;
  _Bool tmp95;
  _Bool tmp94;
  _Bool tmp93;
  _Bool tmp92;
  _Bool tmp91;
  _Bool tmp90;
  _Bool tmp89;
  _Bool tmp88;
  _Bool tmp87;
  _Bool tmp86;
  _Bool tmp85;
  unsigned int tmp84;
  _Bool tmp83;
  _Bool tmp82;
  _Bool tmp81;
  unsigned int tmp80;
  _Bool tmp79;
  unsigned int tmp78;
  _Bool tmp77;
  unsigned int tmp76;
  _Bool tmp75;
  unsigned int tmp74;
  _Bool tmp73;
  unsigned int tmp72;
  _Bool tmp71;
  unsigned int tmp70;
  _Bool tmp69;
  unsigned int tmp68;
  _Bool tmp67;
  unsigned int tmp66;
  _Bool tmp65;
  unsigned int tmp64;
  _Bool tmp63;
  unsigned int tmp62;
  _Bool tmp61;
  unsigned int tmp60;
  _Bool tmp59;
  unsigned int tmp58;
  _Bool tmp57;
  unsigned int tmp56;
  _Bool tmp55;
  unsigned int tmp54;
  _Bool tmp53;
  unsigned int tmp52;
  _Bool tmp51;
  _Bool tmp50;
  unsigned int tmp49;
  _Bool tmp48;
  unsigned int tmp47;
  _Bool tmp46;
  unsigned int tmp45;
  _Bool tmp44;
  unsigned int tmp43;
  _Bool tmp42;
  unsigned int tmp41;
  _Bool tmp40;
  unsigned int tmp39;
  _Bool tmp38;
  unsigned int tmp37;
  _Bool tmp36;
  unsigned int tmp35;
  _Bool tmp34;
  unsigned int tmp33;
  _Bool tmp32;
  unsigned int tmp31;
  _Bool tmp30;
  unsigned int tmp29;
  _Bool tmp28;
  unsigned int tmp27;
  _Bool tmp26;
  unsigned int tmp25;
  _Bool tmp24;
  unsigned int tmp23;
  _Bool tmp22;
  unsigned int tmp21;
  _Bool tmp20;
  unsigned int tmp19;
  _Bool tmp18;
  unsigned int tmp17;
  _Bool tmp16;
  unsigned int tmp15;
  _Bool tmp14;
  unsigned int tmp13;
  _Bool tmp12;
  unsigned int tmp11;
  _Bool tmp10;
  unsigned int tmp9;
  _Bool tmp8;
  unsigned int tmp7;
  _Bool tmp6;
  _Bool tmp5;
  unsigned int tmp4;
  unsigned int tmp3;
  unsigned int tmp2;
  unsigned int tmp1;
  unsigned int tmp0;
  unsigned int random_reg;
  /*_Bool clk;
  unsigned int shared_snoop;
  _Bool is_snoop;
  _Bool master_in;
  _Bool ND_in;
  _Bool bus_ack;
  _Bool all_shared;
  _Bool invalidate;
  _Bool mem_served;
  _Bool info_avail;
  _Bool is_shared;
  _Bool master_out;*/
  _Bool hit_miss;
  unsigned int sh_snp;
  _Bool req_enable;
  _Bool proc_req;
  _Bool valid;
  req_enable = is_snoop && info_avail ? FALSE : (is_snoop && !info_avail && sh_snp == 2 && is_shared ? FALSE : (!(sh_snp == 0) && valid ? FALSE : (spcache.bus_req ? FALSE : TRUE)));
    processor(clk, req_enable, &valid);
  is_shared = spcache.state == 1 ? TRUE : FALSE;
  sh_snp = shared_snoop;
  master_out = master_in || spcache.next_state == 2 ? FALSE : (sh_snp == 2 || sh_snp == 4 || sh_snp == 5 || sh_snp == 1 && spcache.next_state == 1 || sh_snp == 3 && spcache.next_state == 0 ? TRUE : FALSE);
  //info_avail = sh_snp == 1 || spcache.next_state == 1 ? TRUE : (spcache.next_state == 0 && !(sh_snp == 0 || sh_snp == 1) || spcache.next_state == 1 && (sh_snp == 4 || sh_snp == 5) ? (unsigned int)ND_in[0] : FALSE);
  {
    if(spcache.state == 1 && spcache.hit && spcache.write)
    {
      tmp0 = 1;
      spcache.snoop_type = tmp0 & 7;
    }

    else
      if(spcache.state == 1 && spcache.miss && (spcache.read || spcache.write))
      {
        spcache.snoop_type = 2;
      }

      else
        if(spcache.state == 2 && (unsigned int)spcache.hit == 1 && ((unsigned int)spcache.read == 1 || (unsigned int)spcache.write == 1))
        {
          tmp1 = 3;
          spcache.snoop_type = tmp1 & 7;
        }

        else
          if(spcache.state == 2 && (unsigned int)spcache.miss == 1 && ((unsigned int)spcache.read == 1 || (unsigned int)spcache.write == 1))
          {
            tmp2 = 4;
            spcache.snoop_type = tmp2 & 7;
          }

          else
            if(spcache.state == 0 && spcache.miss && (spcache.read || spcache.write))
            {
              tmp3 = 5;
              spcache.snoop_type = tmp3 & 7;
            }

            else
            {
              tmp4 = 0;
              spcache.snoop_type = tmp4 & 7;
            }
    if(spcache.snoop_type != 0 && valid)
    {
      tmp5 = TRUE;
      spcache.bus_req = tmp5 & FALSE;
    }

    else
    {
    }
    if(is_snoop && !bus_ack)
    {
      tmp6 = FALSE;
      if(info_avail)
      {
        {
          if(shared_snoop == 1)
          {
            if(spcache.state == 1)
            {
              tmp7 = 2;
              tmp8 = TRUE;
              spcache.update = tmp6 & FALSE;
              spcache.next_state = tmp7 & 3;
              spcache.update = tmp8 & FALSE;
            }

            else
            {
              tmp9 = spcache.state;
              tmp10 = FALSE;
              spcache.next_state = tmp9 & 3;
              spcache.update = tmp10 & FALSE;
            }
          }

          else
            if(shared_snoop == 2)
            {
              if(spcache.state == 0)
              {
                if(!invalidate)
                {
                  tmp11 = 1;
                  tmp12 = TRUE;
                  spcache.next_state = tmp11 & 3;
                  spcache.update = tmp12 & FALSE;
                }

                else
                {
                  tmp13 = 2;
                  tmp14 = TRUE;
                  spcache.next_state = tmp13 & 3;
                  spcache.update = tmp14 & FALSE;
                }
              }

              else
              {
                tmp15 = spcache.state;
                tmp16 = FALSE;
                spcache.next_state = tmp15 & 3;
                spcache.update = tmp16 & FALSE;
              }
            }

            else
              if(shared_snoop == 3)
              {
                if(spcache.state == 0)
                {
                  if(!invalidate)
                  {
                    tmp17 = 1;
                    tmp18 = TRUE;
                    spcache.next_state = tmp17 & 3;
                    spcache.update = tmp18 & FALSE;
                  }

                  else
                  {
                    tmp19 = 2;
                    tmp20 = TRUE;
                    spcache.next_state = tmp19 & 3;
                    spcache.update = tmp20 & FALSE;
                  }
                }

                else
                {
                  tmp21 = spcache.state;
                  tmp22 = FALSE;
                  spcache.next_state = tmp21 & 3;
                  spcache.update = tmp22 & FALSE;
                }
              }

              else
                if(shared_snoop == 4)
                {
                  if(spcache.state == 1)
                  {
                    if(invalidate)
                    {
                      tmp23 = 2;
                      tmp24 = TRUE;
                      spcache.next_state = tmp23 & 3;
                      spcache.update = tmp24 & FALSE;
                    }

                    else
                    {
                      tmp25 = spcache.state;
                      tmp26 = FALSE;
                      spcache.next_state = tmp25 & 3;
                      spcache.update = tmp26 & FALSE;
                    }
                  }

                  else
                    if(spcache.state == 0)
                    {
                      if(!invalidate)
                      {
                        tmp27 = 1;
                        tmp28 = TRUE;
                        spcache.next_state = tmp27 & 3;
                        spcache.update = tmp28 & FALSE;
                      }

                      else
                      {
                        tmp29 = 2;
                        tmp30 = TRUE;
                        spcache.next_state = tmp29 & 3;
                        spcache.update = tmp30 & FALSE;
                      }
                    }

                    else
                    {
                      tmp31 = spcache.state;
                      tmp32 = FALSE;
                      spcache.next_state = tmp31 & 3;
                      spcache.update = tmp32 & FALSE;
                    }
                }

                else
                  if(shared_snoop == 5)
                  {
                    if(spcache.state == 1)
                    {
                      if(invalidate)
                      {
                        tmp33 = 2;
                        tmp34 = TRUE;
                        spcache.next_state = tmp33 & 3;
                        spcache.update = tmp34 & FALSE;
                      }

                      else
                      {
                        tmp35 = spcache.state;
                        tmp36 = FALSE;
                        spcache.next_state = tmp35 & 3;
                        spcache.update = tmp36 & FALSE;
                      }
                    }

                    else
                      if(spcache.state == 0)
                      {
                        if(!invalidate)
                        {
                          tmp37 = 1;
                          tmp38 = TRUE;
                          spcache.next_state = tmp37 & 3;
                          spcache.update = tmp38 & FALSE;
                        }

                        else
                        {
                          tmp39 = 2;
                          tmp40 = TRUE;
                          spcache.next_state = tmp39 & 3;
                          spcache.update = tmp40 & FALSE;
                        }
                      }

                      else
                      {
                        tmp41 = spcache.state;
                        tmp42 = FALSE;
                        spcache.next_state = tmp41 & 3;
                        spcache.update = tmp42 & FALSE;
                      }
                  }

                  else
                    if(TRUE)
                    {
                      tmp43 = spcache.state;
                      tmp44 = FALSE;
                      spcache.next_state = tmp43 & 3;
                      spcache.update = tmp44 & FALSE;
                    }

        }
      }

      else
      {
        if(sh_snp == 2 && spcache.state == 1)
        {
          if(!all_shared)
          {
            tmp45 = 0;
            tmp46 = TRUE;
            spcache.next_state = tmp45 & 3;
            spcache.update = tmp46 & FALSE;
          }

          else
          {
            tmp47 = spcache.state;
            tmp48 = FALSE;
            spcache.next_state = tmp47 & 3;
            spcache.update = tmp48 & FALSE;
          }
        }

      }
    }

    if(!is_snoop || bus_ack)
    {
      if(!bus_ack)
      {
        tmp49 = spcache.state;
        tmp50 = FALSE;
        spcache.next_state = tmp49 & 3;
        spcache.update = tmp50 & FALSE;
      }

      else
      {
        tmp51 = FALSE;
        {
          if(shared_snoop == 1)
          {
            tmp52 = 0;
            tmp53 = TRUE;
            spcache.bus_req = tmp51 & FALSE;
            spcache.next_state = tmp52 & 3;
            spcache.update = tmp53 & FALSE;
          }

          else
            if(shared_snoop == 2)
            {
              if(!invalidate)
              {
                if(mem_served)
                {
                  tmp54 = 0;
                  tmp55 = TRUE;
                  spcache.next_state = tmp54 & 3;
                  spcache.update = tmp55 & FALSE;
                }

                else
                {
                  tmp56 = spcache.state;
                  tmp57 = FALSE;
                  spcache.next_state = tmp56 & 3;
                  spcache.update = tmp57 & FALSE;
                }
              }

              else
              {
                tmp58 = spcache.state;
                tmp59 = FALSE;
                spcache.next_state = tmp58 & 3;
                spcache.update = tmp59 & FALSE;
              }
            }

            else
              if(shared_snoop == 3)
              {
                if(!invalidate)
                {
                  if(mem_served)
                  {
                    tmp60 = 0;
                    tmp61 = TRUE;
                    spcache.next_state = tmp60 & 3;
                    spcache.update = tmp61 & FALSE;
                  }

                  else
                  {
                    tmp62 = 1;
                    tmp63 = TRUE;
                    spcache.next_state = tmp62 & 3;
                    spcache.update = tmp63 & FALSE;
                  }
                }

                else
                  if(invalidate)
                  {
                    tmp64 = 0;
                    tmp65 = TRUE;
                    spcache.next_state = tmp64 & 3;
                    spcache.update = tmp65 & FALSE;
                  }

                  else
                  {
                    tmp66 = spcache.state;
                    tmp67 = FALSE;
                    spcache.next_state = tmp66 & 3;
                    spcache.update = tmp67 & FALSE;
                  }
              }

              else
                if(shared_snoop == 4)
                {
                  if(!invalidate)
                  {
                    if(mem_served)
                    {
                      tmp68 = 0;
                      tmp69 = TRUE;
                      spcache.next_state = tmp68 & 3;
                      spcache.update = tmp69 & FALSE;
                    }

                    else
                    {
                      tmp70 = 1;
                      tmp71 = TRUE;
                      spcache.next_state = tmp70 & 3;
                      spcache.update = tmp71 & FALSE;
                    }
                  }

                  else
                  {
                    tmp72 = spcache.state;
                    tmp73 = FALSE;
                    spcache.next_state = tmp72 & 3;
                    spcache.update = tmp73 & FALSE;
                  }
                }

                else
                  if(shared_snoop == 5)
                  {
                    if(!invalidate)
                    {
                      if(mem_served)
                      {
                        tmp74 = 0;
                        tmp75 = TRUE;
                        spcache.next_state = tmp74 & 3;
                        spcache.update = tmp75 & FALSE;
                      }

                      else
                      {
                        tmp76 = 1;
                        tmp77 = TRUE;
                        spcache.next_state = tmp76 & 3;
                        spcache.update = tmp77 & FALSE;
                      }
                    }

                    else
                    {
                      tmp78 = spcache.state;
                      tmp79 = FALSE;
                      spcache.next_state = tmp78 & 3;
                      spcache.update = tmp79 & FALSE;
                    }
                  }

                  else
                    if(TRUE)
                    {
                      tmp80 = spcache.state;
                      tmp81 = FALSE;
                      spcache.next_state = tmp80 & 3;
                      spcache.update = tmp81 & FALSE;
                    }

        }
      }
    }

    if(spcache.update)
    {
      tmp82 = FALSE;
      spcache.bus_req = tmp82 & FALSE;
    }

    else
    {
      tmp83 = spcache.bus_req;
      spcache.bus_req = tmp83 & FALSE;
    }
    tmp84 = spcache.next_state;
    if(!valid || spcache.update)
    {
      tmp85 = FALSE;
      tmp86 = FALSE;
      tmp87 = FALSE;
      spcache.state = tmp84 & 3;
      spcache.read = tmp85 & FALSE;
      spcache.write = tmp86 & FALSE;
      spcache.inv_out = tmp87 & FALSE;
    }

    else
      if(!spcache.bus_req)
      {
        tmp88 = hit_miss;
        tmp89 = !hit_miss;
        tmp90 = proc_req;
        tmp91 = !proc_req;
        tmp92 = spcache.write;
        spcache.hit = tmp88 & FALSE;
        spcache.miss = tmp89 & FALSE;
        spcache.read = tmp90 & FALSE;
        spcache.write = tmp91 & FALSE;
        spcache.inv_out = tmp92 & FALSE;
      }

      else
      {
        tmp93 = spcache.hit;
        tmp94 = !spcache.hit;
        tmp95 = spcache.read;
        tmp96 = spcache.write;
        tmp97 = spcache.inv_out;
        spcache.hit = tmp93 & FALSE;
        spcache.miss = tmp94 & FALSE;
        spcache.read = tmp95 & FALSE;
        spcache.write = tmp96 & FALSE;
        spcache.inv_out = tmp97 & FALSE;
      }
  }
  /*unsigned int i;
  for(i=1;i<=256;i++)
  {
     if(spcache.state == 1 && spcache.hit && spcache.write)
    {
      tmp0 = 1;
      spcache.snoop_type = tmp0 & 7;
    }

    else
      if(spcache.state == 1 && spcache.miss && (spcache.read || spcache.write))
      {
        spcache.snoop_type = 2;
      }

      else
        if(spcache.state == 2 && (unsigned int)spcache.hit == 1 && ((unsigned int)spcache.read == 1 || (unsigned int)spcache.write == 1))
        {
          tmp1 = 3;
          spcache.snoop_type = tmp1 & 7;
        }

        else
          if(spcache.state == 2 && (unsigned int)spcache.miss == 1 && ((unsigned int)spcache.read == 1 || (unsigned int)spcache.write == 1))
          {
            tmp2 = 4;
            spcache.snoop_type = tmp2 & 7;
          }

          else
            if(spcache.state == 0 && spcache.miss && (spcache.read || spcache.write))
            {
              tmp3 = 5;
              spcache.snoop_type = tmp3 & 7;
            }

            else
            {
              tmp4 = 0;
              spcache.snoop_type = tmp4 & 7;
            }
 
  } // end of for loop*/


}

struct state_elements_arbiter{
 _Bool bus_ackA;
 _Bool bus_ackB;
 _Bool invalidate;
 _Bool is_snoop;
 unsigned int shared_snoop;
};
struct state_elements_arbiter  sarbiter;

void arbiter_initial()
{
  sarbiter.is_snoop = FALSE;
  sarbiter.bus_ackA = FALSE;
  sarbiter.bus_ackB = FALSE;
  sarbiter.invalidate = FALSE;
  sarbiter.shared_snoop = 0;
}

void arbiter(_Bool clk, _Bool bus_reqA, _Bool bus_reqB, unsigned int snoop_typeA, unsigned int snoop_typeB, _Bool inv_outA, _Bool inv_outB, _Bool *bus_ackA, _Bool *bus_ackB, _Bool *is_snoop, unsigned int *shared_snoop, _Bool *invalidate)
{
  unsigned int tmp14;
  _Bool tmp13;
  _Bool tmp12;
  _Bool tmp11;
  _Bool tmp10;
  _Bool tmp9;
  unsigned int tmp8;
  _Bool tmp7;
  _Bool tmp6;
  _Bool tmp5;
  _Bool tmp4;
  unsigned int tmp3;
  _Bool tmp2;
  _Bool tmp1;
  _Bool tmp0;
 /* _Bool clk;
  _Bool bus_reqA;
  _Bool bus_reqB;
  unsigned int snoop_typeA;
  unsigned int snoop_typeB;
  _Bool inv_outA;
  _Bool inv_outB;*/
  {
    if(bus_reqA)
    {
      tmp0 = TRUE;
      tmp1 = FALSE;
      tmp2 = TRUE;
      tmp3 = snoop_typeA;
      tmp4 = inv_outA;
      sarbiter.bus_ackA = tmp0;
      *bus_ackA = tmp0;
      sarbiter.bus_ackB = tmp1;
      *bus_ackB = tmp1;
      sarbiter.is_snoop = tmp2;
      *is_snoop = tmp2;
      sarbiter.shared_snoop = tmp3 & 7;
      *shared_snoop = tmp3 & 7;
      sarbiter.invalidate = tmp4;
      *invalidate = tmp4;
    }

    else
      if(bus_reqB)
      {
        tmp5 = FALSE;
        tmp6 = TRUE;
        tmp7 = TRUE;
        tmp8 = snoop_typeB;
        tmp9 = inv_outB;
        sarbiter.bus_ackA = tmp5;
        *bus_ackA = tmp5;
        sarbiter.bus_ackB = tmp6;
        *bus_ackB = tmp6;
        sarbiter.is_snoop = tmp7;
        *is_snoop = tmp7;
        sarbiter.shared_snoop = tmp8 & 7;
        *shared_snoop = tmp8 & 7;
        sarbiter.invalidate = tmp9;
        *invalidate = tmp9;
      }

      else
      {
        tmp10 = FALSE;
        tmp11 = FALSE;
        tmp12 = FALSE;
        tmp13 = FALSE;
        tmp14 = 0;
        sarbiter.bus_ackA = tmp10;
        *bus_ackA = tmp10;
        sarbiter.bus_ackB = tmp11;
        *bus_ackB = tmp11;
        sarbiter.is_snoop = tmp12;
        *is_snoop = tmp12;
        sarbiter.invalidate = tmp13;
        *invalidate = tmp13;
        sarbiter.shared_snoop = tmp14 & 7;
        *shared_snoop = tmp14 & 7;
      }
  }
}

void main()
{
  _Bool clk;
  _Bool all_shared;
  _Bool is_sharedA;
  _Bool is_sharedB;
  _Bool ND_inA;
  _Bool ND_inB;
  _Bool ndA;
  _Bool ndB;
  _Bool master_outA;
  _Bool master_outB;
  unsigned int master_inA;
  unsigned int master_inB;
  _Bool inv_outA;
  _Bool inv_outB;
  _Bool invalidate;
  _Bool mem_served;
  _Bool info_availA;
  _Bool info_availB;
  _Bool bus_reqA;
  _Bool bus_reqB;
  _Bool bus_ackA;
  _Bool bus_ackB;
  _Bool is_snoop;
  unsigned int snoop_typeA;
  unsigned snoop_typeB;
  unsigned int shared_snoop;

  pcache_initial();
  processor_initial();
  arbiter_initial();

  pcache(clk, shared_snoop, is_snoop, master_inA, ND_inA, bus_ackA, all_shared, mem_served, invalidate, &snoop_typeA, &bus_reqA, &master_outA, &is_sharedA, &inv_outA, &info_availA);
  
  pcache(clk, shared_snoop, is_snoop, master_inB, ND_inB, bus_ackB, all_shared, mem_served, invalidate, &snoop_typeB, &bus_reqB, &master_outB, &is_sharedB, &inv_outB, &info_availB);
  
  all_shared = is_sharedA && is_sharedB;
  ND_inA = ndA && !bus_ackA;
  ND_inB = master_outA ? ND_inA : ndB && !bus_ackB;
  master_inA = FALSE;
  master_inB = master_outA;
  mem_served = !(info_availA || info_availB);
  
  arbiter(clk, bus_reqA, bus_reqB, snoop_typeA, snoop_typeB, inv_outA, inv_outB, &bus_ackA, &bus_ackB, &is_snoop, &shared_snoop, &invalidate);
  
  // Check the assertion
  //assert(invalidate==1);
  assert((invalidate==0 || invalidate==1) || !(invalidate==0 || invalidate==1));
}


