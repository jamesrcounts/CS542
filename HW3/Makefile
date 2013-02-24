###################################
# Makefile
# HW 3
# CS542 - OO - Spring 2013
# Jim Counts
###################################
CC = g++
INCLUDE = -I ../igloo
CFLAGS = -O2 -Wall -fno-strict-overflow
SRCS = test.cpp String.h String.cpp hw3.cpp
CHKFLAGS = -v --inline-suppr --enable=all

all: hw3

run: hw3
	./hw3

hw3: check hw3.cpp String.o
	$(CC) $(INCLUDE) hw3.cpp String.o -o hw3 $(CFLAGS)

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