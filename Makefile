#
# example Makefile to build an executable, just change the name of the PROG constant to the other .c files
#
PROG=day6_part1

buildandrun: 
	gcc -std=c11 -Wall $(PROG).c -o $(PROG)
	./$(PROG).exe
clean:
	$(RM) $(PROG).exe
