all: prog

prog: main.o
	g++ main.cpp -o prog

main.o: main.cpp
	g++ main.cpp -c

clean:
	rm -rf *o prog
