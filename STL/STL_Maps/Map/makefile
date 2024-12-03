#Created by Don Spickler  1/28/2022

PROG = prog
CC = g++
CPPFLAGS = -g -Wall -std=c++11
OBJS = main.o Die.o

$(PROG) : $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

main.o : main.cpp
	$(CC) $(CPPFLAGS) -c main.cpp

Die.o : Die.cpp
	$(CC) $(CPPFLAGS) -c Die.cpp

clean:
	rm -f core $(PROG) $(OBJS)

rebuild:
	make clean
	make
