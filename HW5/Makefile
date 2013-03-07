###################################
# Makefile
# HW 5
# CS542 - OO - Spring 2013
# Jim Counts
###################################
CC = g++
INCLUDE = -I ../igloo
CFLAGS = -O2 -Wall -fno-strict-overflow
SRCS = *.cpp *.h
CHKFLAGS = -v --inline-suppr --enable=all

all: runtest

run: hw5
	./hw5

hw5: hw5.cpp
	$(CC) $(INCLUDE) hw5.cpp -o hw5 $(CFLAGS)

Alien.o: Alien.cpp Alien.h
	$(CC) $(INCLUDE) -c Alien.cpp $(CFLAGS)

Horse.o: Horse.cpp Horse.h
	$(CC) $(INCLUDE) -c Horse.cpp $(CFLAGS)

Snake.o: Snake.cpp Snake.h
	$(CC) $(INCLUDE) -c Snake.cpp $(CFLAGS)

Animal.o: Animal.cpp Animal.h
	$(CC) $(INCLUDE) -c Animal.cpp $(CFLAGS)

runtest: test
	./test

test: test.cpp Alien.o Animal.o Snake.o Horse.o format
	$(CC) $(INCLUDE) test.cpp *.o -o test $(CFLAGS)	

format:
	astyle -YfDHUbps4yj -k3 $(SRCS)

check: runtest
	cppcheck $(CHKFLAGS) $(SRCS)

# DO NOT DELETE