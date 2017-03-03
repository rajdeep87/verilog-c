// Another example of unique decipherability checking from Ash.

// Author: Fabio Somenzi <Fabio@Colorado.EDU>

module unidec(clk, sel1, sel2, found);
    input 	clk;
    input [2:0] sel1;
    input [2:0] sel2;
    output 	found;

    wire [6:0] 	other;
    reg [6:0] 	word;
    reg 	found;
    reg 	init;

    // This function returns a code word.  Each word is up to six
    // characters (0 or 1) plus a "stop" bit.  Characters are stored in a
    // word in reverse order so that a right shift produces a suffix.
    function [6:0] code;
	input [2:0] sel;
	begin: _code
	    case (sel)
	      0: code = 7'b0001010; // 010
	      1: code = 7'b0011000; // 0001
	      2: code = 7'b0010110; // 0110
	      3: code = 7'b0010011; // 1100
	      4: code = 7'b0111000; // 00011
	      5: code = 7'b0101100; // 00110
	      6: code = 7'b0101111; // 11110
	      7: code = 7'b1110101; // 101011
	    endcase
	end
    endfunction // code

    // This function extracts a proper prefix of lengh sel from word.
    // If word does not have more than sel characters, it returns
    // an invalid word.
    function [6:0] prefix;
	input [6:0] word;
	input [2:0] sel;
	begin: _prefix
	    case (sel)
	      1: if (word[6:2] == 0) prefix = 7'b0111111;
	      else prefix = {6'b1, word[0]};
	      2: if (word[6:3] == 0) prefix = 7'b0111111;
	      else prefix = {5'b1, word[1:0]};
	      3: if (word[6:4] == 0) prefix = 7'b0111111;
	      else prefix = {4'b1, word[2:0]};
	      4: if (word[6:5] == 0) prefix = 7'b0111111;
	      else prefix = {3'b1, word[3:0]};
	      5: if (word[6] == 0)   prefix = 7'b0111111;
	      else prefix = {2'b1, word[4:0]};
	      default: prefix = 7'b0111111;
	    endcase
	end
    endfunction // prefix

    // This function returns a suffix of word dropping the first sel
    // characters.
    function [6:0] suffix;
	input [6:0] word;
	input [2:0] sel;
	begin: _suffix
	    case (sel)
	      1: suffix = {1'b0, word[6:1]};
	      2: suffix = {2'b0, word[6:2]};
	      3: suffix = {3'b0, word[6:3]};
	      4: suffix = {4'b0, word[6:4]};
	      5: suffix = {5'b0, word[6:5]};
	      default: suffix = 0;
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
