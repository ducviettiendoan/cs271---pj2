# -*- Makefile -*-

# target: dependencies
# 	action

all: main test_minqueue

main: main.o
	g++ main.o -o main

main.o: main.cpp minqueue.cpp
	g++ -c main.cpp

test_minqueue: test_minqueue.o
	g++ test_minqueue.o -o test_minqueue

test_minqueue.o: test_minqueue.cpp minqueue.cpp
	g++ -c test_minqueue.cpp

minqueue.o: minqueue.cpp
	g++ -c minqueue.cpp								

clean:
	rm -f *.o minqueue test_minqueue main
