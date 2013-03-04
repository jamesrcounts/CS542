###################################
# Makefile
# HW 3
# CS542 - OO - Spring 2013
# Jim Counts
###################################
CC = g++
INCLUDE = -I ../igloo
CFLAGS = -O2 -Wall -fno-strict-overflow
SRCS = test.cpp hw5.cpp
CHKFLAGS = -v --inline-suppr --enable=all

all: runtest

run: hw5
	./hw5

hw5: hw5.cpp
	$(CC) $(INCLUDE) hw5.cpp -o hw5 $(CFLAGS)

runtest: test
	./test

test: test.cpp format
	$(CC) $(INCLUDE) test.cpp -o test $(CFLAGS)	

format:
	astyle -YfDHUbps4yj -k3 $(SRCS)

check: runtest
	cppcheck $(CHKFLAGS) $(SRCS)

# DO NOT DELETE