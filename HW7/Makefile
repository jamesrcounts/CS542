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

runtest: wordcounter_test numbersorter_test
	./numbersorter_test
	./wordcounter_test

numbersorter_test: numbersorter_test.cpp NumberSorter.o
	$(CC) $(INCLUDE) numbersorter_test.cpp NumberSorter.o -o numbersorter_test $(CFLAGS)

wordcounter_test: wordcounter_test.cpp WordCounter.o
	$(CC) $(INCLUDE) wordcounter_test.cpp WordCounter.o -o wordcounter_test $(CFLAGS)

NumberSorter.o: NumberSorter.h NumberSorter.cpp
	$(CC) $(INCLUDE) -c NumberSorter.cpp $(CFLAGS)

WordCounter.o: WordCounter.h WordCounter.cpp
	$(CC) $(INCLUDE) -c WordCounter.cpp $(CFLAGS)

format:
	astyle -YfDHUbps4yj -k3 $(SRCS)

check: 
	cppcheck $(CHKFLAGS) $(SRCS)

# DO NOT DELETE