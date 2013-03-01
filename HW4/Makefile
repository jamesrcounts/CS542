###################################
# Makefile
# HW 3
# CS542 - OO - Spring 2013
# Jim Counts
###################################
CC = g++
INCLUDE = -I ../igloo
CFLAGS = -O2 -Wall -fno-strict-overflow
SRCS = test.cpp String.h String.cpp hw4.cpp
CHKFLAGS = -v --inline-suppr --enable=all

all: hw4

run: hw4
	./hw4

hw4: check hw4.cpp String.o
	$(CC) $(INCLUDE) hw4.cpp String.o -o hw4 $(CFLAGS)

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