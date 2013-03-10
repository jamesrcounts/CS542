###################################
# Makefile
# HW 6
# CS542 - OO - Spring 2013
# Jim Counts
###################################
CC = g++
INCLUDE = -I ../igloo
CFLAGS = -O2 -Wall -fno-strict-overflow
SRCS = *.cpp Array.h
CHKFLAGS = -v --inline-suppr --enable=all

all: runtest

clean: 
	rm -f hw6 test *.o *.orig *.gch

run: hw6
	./hw6

hw6: hw6.cpp Array.h
	$(CC) $(INCLUDE) hw6.cpp -o hw6 $(CFLAGS)

runtest: test
	./test

Array.gch: Array.h
	$(CC) $(INCLUDE) Array.h $(CFLAGS)

test: test.cpp Array.h Array.gch format
	$(CC) $(INCLUDE) test.cpp -o test $(CFLAGS)	

format:
	astyle -YfDHUbps4yj -k3 $(SRCS)

check: runtest
	cppcheck $(CHKFLAGS) $(SRCS)

# DO NOT DELETE