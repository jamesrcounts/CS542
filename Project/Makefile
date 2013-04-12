###################################
# Makefile
# Pomodoro Project
# CS542 - OO - Spring 2013
# Jim Counts
###################################
CC = g++
TI = -I ../igloo -I pomodoro -I ../approvals
CFLAGS = -Wall
CHKFLAGS = -v --inline-suppr --enable=all
STYLE = -YfDHUbps4yj -k3

all: runtest build

build: pomodoro

clean: 
	rm -f tests/*.orig tests/bin/*_tests pomodoro/*.orig pomodoro/obj/*.o

runtest: tests
	./tests/bin/tomato_tests
	./tests/bin/logmanager_tests
	./tests/bin/timer_tests
	./tests/bin/menu_tests

tests: tests/bin/tomato_tests tests/bin/logmanager_tests tests/bin/menu_tests tests/bin/timer_tests tests/bin

pomodoro: pomodoro/bin pomodoro/obj pomodoro/bin/pomodoro pomodoro/obj/LogManager.o  

pomodoro/bin/pomodoro: pomodoro/pomodoro.cpp pomodoro/obj/Menus.o pomodoro/obj/Tomato.o 
	cppcheck $(CHKFLAGS) pomodoro/pomodoro.cpp
	astyle $(STYLE) pomodoro/pomodoro.cpp
	$(CC) pomodoro/pomodoro.cpp pomodoro/obj/Menus.o pomodoro/obj/Tomato.o pomodoro/obj/Timer.o -o pomodoro/bin/pomodoro $(CFLAGS) 

tests/bin/tomato_tests: pomodoro tests/tomato_tests.cpp
	cppcheck $(CHKFLAGS) tests/tomato_tests.cpp
	astyle $(STYLE) tests/tomato_tests.cpp
	$(CC) $(TI) tests/tomato_tests.cpp pomodoro/obj/Tomato.o pomodoro/obj/Menus.o pomodoro/obj/Timer.o -o tests/bin/tomato_tests $(CFLAGS);	

tests/bin/logmanager_tests: pomodoro tests/logmanager_tests.cpp
	cppcheck $(CHKFLAGS) tests/logmanager_tests.cpp
	astyle $(STYLE) tests/logmanager_tests.cpp
	$(CC) $(TI) tests/logmanager_tests.cpp pomodoro/obj/Timer.o pomodoro/obj/LogManager.o -o tests/bin/logmanager_tests $(CFLAGS);	

tests/bin/timer_tests: pomodoro tests/timer_tests.cpp 
	cppcheck $(CHKFLAGS) tests/timer_tests.cpp
	astyle $(STYLE) tests/timer_tests.cpp
	$(CC) $(TI) tests/timer_tests.cpp pomodoro/obj/Timer.o -o tests/bin/timer_tests $(CFLAGS);

tests/bin/menu_tests: pomodoro tests/menu_tests.cpp 
	cppcheck $(CHKFLAGS) tests/menu_tests.cpp
	astyle $(STYLE) tests/menu_tests.cpp
	$(CC) $(TI) tests/menu_tests.cpp pomodoro/obj/Menus.o -o tests/bin/menu_tests $(CFLAGS)

pomodoro/obj/Tomato.o: pomodoro/Tomato.h pomodoro/Tomato.cpp pomodoro/obj/Timer.o
	cppcheck $(CHKFLAGS) pomodoro/Tomato.h pomodoro/Tomato.cpp
	astyle $(STYLE) pomodoro/Tomato.h pomodoro/Tomato.cpp
	$(CC) -c pomodoro/Tomato.cpp pomodoro/obj/Timer.o -o pomodoro/obj/Tomato.o $(CFLAGS)

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

# DO NOT DELETE