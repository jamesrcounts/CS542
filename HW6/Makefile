###################################
# Makefile
# HW 6
# CS542 - OO - Spring 2013
# Jim Counts
###################################
CC = g++
INCLUDE = -I ../igloo
CFLAGS = -O3 -Wall -fno-strict-overflow
SRCS = *.cpp *.h
CHKFLAGS = -v --inline-suppr --enable=all

all: runtest run format check

clean: 
	rm -f hw6 test array_test matrix_test *.o *.orig *.gch

run: hw6
	./hw6

hw6: hw6.cpp Array.h
	$(CC) $(INCLUDE) hw6.cpp -o hw6 $(CFLAGS)

runtest: array_test matrix_test
	./array_test
	./matrix_test

Array.gch: Array.h
	$(CC) $(INCLUDE) Array.h $(CFLAGS)

Matrix.gch: Matrix.h Array.h
	$(CC) $(INCLUDE) Matrix.h $(CFLAGS)

array_test: array_test.cpp Array.h Array.gch 
	$(CC) $(INCLUDE) array_test.cpp -o array_test $(CFLAGS)

matrix_test: matrix_test.cpp Array.h Array.gch Matrix.h Matrix.gch 
	$(CC) $(INCLUDE) matrix_test.cpp -o matrix_test $(CFLAGS)

format:
	astyle -YfDHUbps4yj -k3 $(SRCS)

check: runtest
	cppcheck $(CHKFLAGS) $(SRCS)

# DO NOT DELETE