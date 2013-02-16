###################################
# Makefile
# HW 2
# CS542 - Spring 2013
# Jim Counts
###################################
CC = g++
CFLAGS = -O2 -Wall
SRCS = LinkedStack.cpp LinkedStackMemento.h LinkedStackMember.h LinkedStack.h LinkedStackIterator.h

all: LinkedStackMemento.gch LinkedStackMember.gch LinkedStack.o LinkedStackIterator.gch

LinkedStackIterator.gch: LinkedStack.o
	$(CC) LinkedStackIterator.h $(CFLAGS)

LinkedStack.o: LinkedStackMemento.gch
	$(CC) LinkedStack.cpp -o LinkedStack.o $(CFLAGS)

LinkedStackMemento.gch: LinkedStackMember.gch
	$(CC) LinkedStackMemento.h $(CFLAGS)

LinkedStackMember.gch: format
	$(CC) LinkedStackMember.h $(CFLAGS)

format:
	astyle -bps4 $(SRCS)

# DO NOT DELETE