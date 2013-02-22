###################################
# Makefile
# HW 3
# CS542 - OO - Spring 2013
# Jim Counts
###################################
CC = g++
INCLUDE = -I ../igloo
CFLAGS = -O2 -Wall 
SRCS = test.cpp
CHKFLAGS = -v --inline-suppr --suppress=unmatchedSuppression --enable=all

all: check 

runtest: test
	./test

test: test.cpp format
	$(CC) $(INCLUDE) test.cpp -o test $(CFLAGS)	

server.o: 
	$(CC) $(INCLUDE) -c server.h $(CFLAGS)

object: 
	$(CC) -c LinkedStack.h LinkedStack.cpp $(CFLAGS)

format: 
	astyle -YfDHUbps4yj -k3 $(SRCS)

check: runtest
	cppcheck $(CHKFLAGS) $(SRCS)

# DO NOT DELETE