all: prog

prog: main.o
	g++ main.cpp -o prog

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm -rf *o prog
