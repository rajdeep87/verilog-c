#!/bin/bash

# command to run cbmc
time cbmc MAC_top.c --unwind 4 --no-unwinding-assertions

#time cbmc MAC_top.c --unwind 5 --no-unwinding-assertions --z3

# command to run SYMEX
#time hasco-pi MAC_top.c --unwind 5 --no-unwinding-assertions
