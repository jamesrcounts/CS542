###################################
# Makefile
# HW 3
# CS542 - OO - Spring 2013
# Jim Counts
###################################
CC = g++
INCLUDE = -I ../igloo
CFLAGS = -O2 -Wall -fno-strict-overflow
SRCS = test.cpp String.h String.cpp
CHKFLAGS = -v --inline-suppr --enable=all

all: check 

runtest: test
	./test

test: String.o test.cpp format
	$(CC) $(INCLUDE) test.cpp String.o -o test $(CFLAGS)	

String.o: String.h String.cpp
	$(CC) $(INCLUDE) -c String.cpp $(CFLAGS)

format:
	astyle -YfDHUbps4yj -k3 $(SRCS)

check: runtest
	cppcheck $(CHKFLAGS) $(SRCS)

# DO NOT DELETE