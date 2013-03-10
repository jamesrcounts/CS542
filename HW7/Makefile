###################################
# Makefile
# HW 7
# CS542 - OO - Spring 2013
# Jim Counts
###################################
CC = g++
INCLUDE = -I ../igloo
CFLAGS = -O3 -Wall -fno-strict-overflow
SRCS = *.cpp
CHKFLAGS = -v --inline-suppr --enable=all

all: runtest format check

clean: 
	rm -f hw7 test array_test matrix_test *.o *.orig *.gch

run: hw7
	./hw7

hw7: hw7.cpp 
	$(CC) $(INCLUDE) hw7.cpp -o hw7 $(CFLAGS)

runtest: test
	./test

test: test.cpp
	$(CC) $(INCLUDE) test.cpp -o test $(CFLAGS)

format:
	astyle -YfDHUbps4yj -k3 $(SRCS)

check: 
	cppcheck $(CHKFLAGS) $(SRCS)

# DO NOT DELETE