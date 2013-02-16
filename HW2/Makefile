###################################
# Makefile
# HW 2
# CS542 - Spring 2013
# Jim Counts
###################################
CC = g++
CFLAGS = -O2 -Wall
SRCS = hw2.cpp hw1.cpp LinkedStackMemento.cpp LinkedStack.cpp LinkedStackMemento.h LinkedStackMember.h LinkedStack.h LinkedStackIterator.h

all: hw1 hw2 format

hw1: 
	$(CC) hw1.cpp -o hw1 $(CFLAGS)

hw2: LinkedStack.o LinkedStackMemento.o
	$(CC) hw2.cpp LinkedStack.o LinkedStackMemento.o -o hw2 $(CFLAGS)

LinkedStackIterator.gch: LinkedStack.o
	$(CC) LinkedStackIterator.h $(CFLAGS)

LinkedStack.o: LinkedStackMemento.o
	$(CC) -c LinkedStack.h LinkedStack.cpp $(CFLAGS)

LinkedStackMemento.o: LinkedStackMember.gch
	$(CC) -c LinkedStackMemento.h LinkedStackMemento.cpp $(CFLAGS)

LinkedStackMember.gch: format
	$(CC) LinkedStackMember.h $(CFLAGS)

format:
	astyle -bps4 $(SRCS)

# DO NOT DELETE