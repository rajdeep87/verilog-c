#PASS: From every state the trap state is rachable in one step.
AG EX word[15:0]=0;

#PASS: The trap state lives up to its name.
AG(word[15:0]=0 -> AX word[15:0]=0);

#PASS: Eventually the trap is inevitable.
AF word[15:0]=0;

#PASS: The initial states are: a, c, ad, abb, bad, deb, bbcde.
word[15:0]={b0000000000001000,
            b0000000000001010,
            b0000000001011000,
            b0000001001001000,
            b0000001011000001,
            b0000001001100011,
            b1100011010001001};

#PASS: The states in the first onion ring are d, bb, and Trap.
word[15:0]=b0000000000001000 -> EX word[15:0]=b0000000000001011;
word[15:0]=b0000000000001000 -> EX word[15:0]=b0000000001001001;

AX(word[15:0]=b0000000000001011 + word[15:0]=b0000000001001001 +
   word[15:0]=0);

#PASS: The states in the second onion ring are eb and cde.
word[15:0]=b0000000000001000 -> EX:2(word[15:0]=b0000000001001100);
word[15:0]=b0000000000001000 -> EX:2(word[15:0]=b0000001100011010);

AX:2(word[15:0]=b0000000001001100 + word[15:0]=b0000001100011010 +
     word[15:0]=0);

#PASS: The state in the third onion ring is de.
word[15:0]=b0000000000001000 -> EX:3(word[15:0]=b0000000001100011);

AX:3(word[15:0]=b0000000001100011 + word[15:0]=0);

#PASS: The state in the fourth onion ring is b.
word[15:0]=b0000000000001000 -> EX:4(word[15:0]=b0000000000001001);

AX:4(word[15:0]=b0000000000001001 + word[15:0]=0);

#PASS: The state in the fifth onion ring is bcde.  State ad is also
# reachable at this point.
word[15:0]=b0000000000001000 -> EX:5(word[15:0]=b0000000001011000);
word[15:0]=b0000000000001000 -> EX:5(word[15:0]=b0001100011010001);

AX:5(word[15:0]=b0000000001011000 + word[15:0]=b0001100011010001 +
     word[15:0]=0);

#PASS: Every path of length eight or more reaches the Trap.
AX:8(word[15:0]=0);

#PASS: Only three initial states have successors that are not the Trap.
word[15:0]={b0000000000001000,b0000000001011000,b0000001001001000} +
AX word[15:0]=0;

#FAIL: The counterexample to this property shows that the code is not
# uniquely decipherable.
AG found=0;
