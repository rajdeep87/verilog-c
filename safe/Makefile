default: tests.log

FLAGS = --verbosity 10 --acdl --decision ordered --learning first-uip --propagate chaotic --inline 
TIMEOUT=600

test:
	@../test.pl -c "runsolver -C $(TIMEOUT) -d 1 -M 32768 /users/rajdeep/acdlp/2ls/src/2ls/2ls $(FLAGS)"

tests.log: ../test.pl
	@../test.pl -c "/users/rajdeep/git-acdlp/2ls/src/2ls/2ls $(FLAGS)"

show:
	@for dir in *; do \
		if [ -d "$$dir" ]; then \
			vim -o "$$dir/*.c" "$$dir/*.out"; \
		fi; \
	done;

clean:
	@rm -f *.log
	@for dir in *; do rm -f $$dir/*.out; done;
