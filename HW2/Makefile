###################################
# Makefile
# HW 2
# CS542 - Spring 2013
# Jim Counts
###################################
CC = g++                                            # use g++ for compiling c++ code or gcc for c code
CFLAGS = -O2 -Wall                                  # compilation flags: -g for debugging. Change to -O or -O2 for optimized code.
PROG = hw2                                           # target executable (output)
HDRS = LinkedStack.h LinkedStackMemento.h CharLinkedListPair.h StackException.h
SRCS = main.cpp                                     # .c or .cpp source files.  
OBJ = $(SRCS:.cpp=.o)                               # object files for the target. Add more to this and next lines if there are more than one source files.

$(PROG): format $(SRCS) $(HDRS) 
	$(CC) $(SRCS) -o $(PROG) $(CFLAGS)

format:
	astyle -bps4 $(SRCS) $(HDRS)

# cleanup
clean:
	rm -f core $(PROG) $(OBJS)

# DO NOT DELETE