default: tests.log

FLAGS = --verbosity 10 --acdl --decision ordered --learning first-uip --propagate chaotic --inline

test:
	@../test.pl -c "/usr/bin/time -v /users/rajdeep/git-acdlp/2ls/src/2ls/2ls $(FLAGS)"

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
