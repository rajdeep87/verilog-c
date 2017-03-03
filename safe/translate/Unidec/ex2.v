// Another example of unique decipherability checking from Ash.

// Author: Fabio Somenzi <Fabio@Colorado.EDU>

module unidec(clk, sel1, sel2, found);
    input 	clk;
    input [2:0] sel1;
    input [1:0] sel2;
    output 	found;

    wire [12:0] other;
    reg [12:0] 	word;
    reg 	found;
    reg 	init;

    // This function returns a code word.  Each character is three bits
    // (a: 000, b: 001, c: 010, d: 011, and e: 100).  Each word is up to
    // five characters plus a "stop" bit.  Characters are stored in a word
    // in reverse order so that a right shift produces a suffix.
    function [12:0] code;
	input [2:0] sel;
	begin: _code
	    case (sel)
	      0: code = 13'b0001010001000; // abc
	      1: code = 13'b1011010001000; // abcd
	      2: code = 13'b0000000001100; // e
	      3: code = 13'b0001000001011; // dba
	      4: code = 13'b1100010000001; // bace
	      5: code = 13'b1010000100010; // ceac
	      6: code = 13'b1001000100010; // ceab
	      7: code = 13'b1011001000100; // eabd
	    endcase
	end
    endfunction // code

    // This function extracts a proper prefix of lengh sel from word.
    // If word does not have more than sel characters or sel is 0, it
    // returns an invalid word.
    function [12:0] prefix;
	input [12:0] word;
	input [1:0] sel;
	begin: _prefix
	    case (sel)
	      0: prefix = 13'b0111111111111;
	      1: if (word[12:4] == 0)  prefix = 13'b0111111111111;
	      else prefix = {10'b1, word[2:0]};
	      2: if (word[12:7] == 0)  prefix = 13'b0111111111111;
	      else prefix = { 7'b1, word[5:0]};
	      3: if (word[12:10] == 0) prefix = 13'b0111111111111;
	      else prefix = { 4'b1, word[8:0]};
	    endcase
	end
    endfunction // prefix

    // This function returns a suffix of word dropping the first sel
    // characters.
    function [12:0] suffix;
	input [12:0] word;
	input [1:0] sel;
	begin: _suffix
	    case (sel)
	      0: suffix = 0;
	      1: suffix = {3'b0, word[12:3]};
	      2: suffix = {6'b0, word[12:6]};
	      3: suffix = {9'b0, word[12:9]};
	    endcase
	end
    endfunction // suffix


    initial begin
	word = code(sel1);
	found = 0;
	init = 1;
    end

    assign other = code(sel1);

    always @ (posedge clk) begin
	found = !init && word == other;
	init = 0;
	if (other == prefix(word,sel2)) begin
	    // There is a code word that is a prefix of the current word.
	    // Make the suffix of the current word the next word.
	    word = suffix(word,sel2);
	end else if (prefix(other,sel2) == word) begin
	    // The current word is a prefix of another code word.
	    // Make the suffix of the other word the next word.
	    word = suffix(other,sel2);
	end else begin
	    // Neither applies.  Go to trap state.
	    word = 0;
	end
    end

endmodule // unidec
