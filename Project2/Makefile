###################################
# Makefile
# Pomodoro Project
# CS542 - OO - Spring 2013
# Jim Counts
###################################
CC = g++
TI = -I ../igloo -I pomodoro -I ../approvals
LIB = -Lpomodoro/lib
CFLAGS = -Wall
CHKFLAGS = -v --inline-suppr --enable=all
STYLE = -YfDHUbps4yj -k3

all: runtest build

build: pomodoro

clean: 
	rm -f tests/*.orig tests/bin/*_tests pomodoro/*.orig pomodoro/obj/*.o

runtest: tests
	./tests/bin/messagecache_tests
	./tests/bin/tomato_tests
	./tests/bin/logmanager_tests
	./tests/bin/timer_tests
	./tests/bin/menu_tests

tests: tests/bin/messagecache_tests tests/bin/tomato_tests tests/bin/logmanager_tests tests/bin/menu_tests tests/bin/timer_tests tests/bin

pomodoro: pomodoro/bin pomodoro/obj  pomodoro/bin/pomodoro pomodoro/obj/LogManager.o  

pomodoro/bin/pomodoro: pomodoro/pomodoro.cpp pomodoro/lib/libtomato.a
	cppcheck $(CHKFLAGS) pomodoro/pomodoro.cpp
	astyle $(STYLE) pomodoro/pomodoro.cpp
	$(CC) $(LIB) pomodoro/pomodoro.cpp -o pomodoro/bin/pomodoro $(CFLAGS) -ltomato

pomodoro/lib/libtomato.a: pomodoro/lib pomodoro/obj/Menus.o pomodoro/obj/Tomato.o pomodoro/obj/LogManager.o pomodoro/obj/Timer.o pomodoro/obj/MessageCache.o
	ar rcs pomodoro/lib/libtomato.a pomodoro/obj/Menus.o pomodoro/obj/Tomato.o pomodoro/obj/LogManager.o pomodoro/obj/Timer.o pomodoro/obj/MessageCache.o

tests/bin/messagecache_tests: pomodoro pomodoro/lib/libtomato.a tests/messagecache_tests.cpp
	cppcheck $(CHKFLAGS) tests/messagecache_tests.cpp
	astyle $(STYLE) tests/messagecache_tests.cpp
	chmod 666 tests/messagecache_tests.cpp
	$(CC) $(TI) $(LIB) tests/messagecache_tests.cpp -ltomato -o tests/bin/messagecache_tests $(CFLAGS)

tests/bin/tomato_tests: pomodoro tests/tomato_tests.cpp pomodoro/lib/libtomato.a
	cppcheck $(CHKFLAGS) tests/tomato_tests.cpp
	astyle $(STYLE) tests/tomato_tests.cpp
	$(CC) $(TI) $(LIB) tests/tomato_tests.cpp -ltomato -o tests/bin/tomato_tests -g -O0 $(CFLAGS)	

tests/bin/logmanager_tests: pomodoro tests/logmanager_tests.cpp pomodoro/lib/libtomato.a
	cppcheck $(CHKFLAGS) tests/logmanager_tests.cpp
	astyle $(STYLE) tests/logmanager_tests.cpp
	$(CC) $(TI) $(LIB) tests/logmanager_tests.cpp -ltomato -o tests/bin/logmanager_tests $(CFLAGS);	

tests/bin/timer_tests: pomodoro tests/timer_tests.cpp 
	cppcheck $(CHKFLAGS) tests/timer_tests.cpp
	astyle $(STYLE) tests/timer_tests.cpp
	$(CC) $(TI) tests/timer_tests.cpp pomodoro/obj/Timer.o -o tests/bin/timer_tests $(CFLAGS);

tests/bin/menu_tests: pomodoro tests/menu_tests.cpp 
	cppcheck $(CHKFLAGS) tests/menu_tests.cpp
	astyle $(STYLE) tests/menu_tests.cpp
	$(CC) $(TI) tests/menu_tests.cpp pomodoro/obj/Menus.o -o tests/bin/menu_tests $(CFLAGS)

pomodoro/obj/MessageCache.o: pomodoro/MessageCache.h pomodoro/MessageCache.cpp 
	cppcheck $(CHKFLAGS) pomodoro/MessageCache.h pomodoro/MessageCache.cpp
	astyle $(STYLE) pomodoro/MessageCache.h pomodoro/MessageCache.cpp
	chmod 666 pomodoro/MessageCache.h pomodoro/MessageCache.cpp
	$(CC) -c pomodoro/MessageCache.cpp -o pomodoro/obj/MessageCache.o $(CFLAGS)

pomodoro/obj/Tomato.o: pomodoro/Tomato.h pomodoro/Tomato.cpp 
	cppcheck $(CHKFLAGS) pomodoro/Tomato.h pomodoro/Tomato.cpp
	astyle $(STYLE) pomodoro/Tomato.h pomodoro/Tomato.cpp
	$(CC) -c pomodoro/Tomato.cpp -o pomodoro/obj/Tomato.o $(CFLAGS)

pomodoro/obj/LogManager.o: pomodoro/LogManager.h pomodoro/LogManager.cpp
	cppcheck $(CHKFLAGS) pomodoro/LogManager.h pomodoro/LogManager.cpp
	astyle $(STYLE) pomodoro/LogManager.h pomodoro/LogManager.cpp
	$(CC) -c pomodoro/LogManager.cpp -o pomodoro/obj/LogManager.o $(CFLAGS)

pomodoro/obj/Timer.o: pomodoro/Timer.h pomodoro/Timer.cpp
	cppcheck $(CHKFLAGS) pomodoro/Timer.h pomodoro/Timer.cpp
	astyle $(STYLE) pomodoro/Timer.h pomodoro/Timer.cpp
	$(CC) -c pomodoro/Timer.cpp -o pomodoro/obj/Timer.o $(CFLAGS)

pomodoro/obj/Menus.o: pomodoro/Menus.h pomodoro/Menus.cpp
	cppcheck $(CHKFLAGS) pomodoro/Menus.h pomodoro/Menus.cpp
	astyle $(STYLE) pomodoro/Menus.h pomodoro/Menus.cpp
	$(CC) -c pomodoro/Menus.cpp -o pomodoro/obj/Menus.o $(CFLAGS)

tests/bin: 
	mkdir tests/bin

pomodoro/obj:
	mkdir pomodoro/obj

pomodoro/bin:
	mkdir pomodoro/bin

pomodoro/lib:
	mkdir pomodoro/lib

# DO NOT DELETE