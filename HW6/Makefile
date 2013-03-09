###################################
# Makefile
# HW 6
# CS542 - OO - Spring 2013
# Jim Counts
###################################
CC = g++
INCLUDE = -I ../igloo
CFLAGS = -O2 -Wall -fno-strict-overflow
SRCS = *.cpp
CHKFLAGS = -v --inline-suppr --enable=all

all: runtest

clean: 
	rm -f hw6 test *.o *.orig

run: hw6
	./hw6

hw6: hw6.cpp
	$(CC) $(INCLUDE) hw6.cpp -o hw6 $(CFLAGS)

runtest: test
	./test

test: test.cpp format
	$(CC) $(INCLUDE) test.cpp -o test $(CFLAGS)	

format:
	astyle -YfDHUbps4yj -k3 $(SRCS)

check: runtest
	cppcheck $(CHKFLAGS) $(SRCS)

# DO NOT DELETE