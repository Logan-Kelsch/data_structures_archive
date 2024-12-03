#Makefile for main of driver program
#Programmer: Logan Kelsch
#Date: 2/19/24 -- PROJECT COMPLETED 2/20/24

PROG = prog
CC = g++
CPPFLAGS = -g -Wall -std=c++11
OBJS = main.o

$(PROG) : $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

main.o : main.cpp
	$(CC) $(CPPFLAGS) -c main.cpp

clean:
	rm -f core $(PROG) $(OBJS)
