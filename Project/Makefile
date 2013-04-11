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
all: runtest 

clean: 
	rm -f tests/*.orig tests/bin/*_tests pomodoro/*.orig

runtest: tests
	./tests/bin/timer_tests
	./tests/bin/menu_tests

tests: tests/bin/menu_tests tests/bin/timer_tests tests/bin

pomodoro: pomodoro/obj/Menus.o pomodoro/obj/Timer.o pomodoro/obj

tests/bin/timer_tests: pomodoro tests/timer_tests.cpp 
	cppcheck $(CHKFLAGS) tests/timer_tests.cpp
	astyle $(STYLE) tests/timer_tests.cpp
	$(CC) $(TI) tests/timer_tests.cpp pomodoro/obj/Timer.o -o tests/bin/timer_tests $(CFLAGS);

tests/bin/menu_tests: pomodoro tests/menu_tests.cpp 
	cppcheck $(CHKFLAGS) tests/menu_tests.cpp
	astyle $(STYLE) tests/menu_tests.cpp
	$(CC) $(TI) tests/menu_tests.cpp pomodoro/obj/Menus.o -o tests/bin/menu_tests $(CFLAGS)

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

# DO NOT DELETE