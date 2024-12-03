#Created by Don Spickler  1/28/2022
#Used by Logan Kelsch 2/27/24
#could not make a better makefile

PROG = prog
CC = g++
CPPFLAGS = -g -Wall -std=c++20
OBJS = main.o

$(PROG) : $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

main.o : main.cpp
	$(CC) $(CPPFLAGS) -c main.cpp

clean:
	rm -f core $(PROG) $(OBJS)

rebuild:
	make clean
	make
