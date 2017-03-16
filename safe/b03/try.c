
	  ASSEGNA: begin
              if (fu1 | fu2 | fu3 | fu4) begin
		  case (smain.coda0)
		    U1:	grant = 4'b1000;
		    U2: grant = 4'b0100;
		    U3: grant = 4'b0010;
		    U4: grant = 4'b0001;
		    default: grant = 4'b0000;
		  endcase
 		  smain.coda0 = smain.coda1;
		  smain.coda1 = smain.coda2;
		  smain.coda2 = smain.coda3;
		  smain.coda3 = 0;
	      end
	      smain.ru1 = REQUEST1;
	      smain.ru2 = REQUEST2;
	      smain.ru3 = REQUEST3;
	      smain.ru4 = REQUEST4;
	      smain.stato = ANALISI_REQ;
	  end
	endcase
    end
