# -*- Makefile -*-

# target: dependencies
# 	action

all: test_minqueue

test_minqueue: test_minqueue.o
	g++ test_minqueue.o -o test_minqueue

test_minqueue.o: test_minqueue.cpp minqueue.cpp
	g++ -c test_minqueue.cpp

# minqueue: minqueue.o 
# 	g++ minqueue.o -o minqueue

# minqueue.o: minqueue.cpp
# 	g++ -c minqueue.cpp								

clean:
	rm -f *.o minqueue test_minqueue
