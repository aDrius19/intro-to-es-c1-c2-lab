#
# example Makefile to build an executable, just change the name of the PROG constant
#
PROG=day1_part2

all: $(PROG).c
	gcc -std=c11 -Wall $(PROG).c -o $(PROG)

clean:
	$(RM) $(PROG)
