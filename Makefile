# -*- Makefile -*-

# target: dependencies
# 	action

all: minqueue

minqueue: minqueue.o 
	g++ minqueue.o -o minqueue

minqueue.o: minqueue.cpp
	g++ -c minqueue.cpp								

clean:
	rm -f *.o minqueue
