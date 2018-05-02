FLAGS = -Wall -O0 -g -std=c++14 -pedantic-errors

.Phony: clean all

all: itemType LinkedList main

run: itemType LinkedList main
	./main input.txt

main: main.o ItemType.o LinkedList.o
	g++ $(FLAG) -o main main.o ItemType.o LinkedList.o

main.o: main.cpp
	g++ $(FLAG) -c main.cpp

LinkedList: LinkedList.cpp LinkedList.h
	g++ $(FLAG) -c LinkedList.cpp


itemType: ItemType.cpp ItemType.h
	g++ $(FLAG) -c ItemType.cpp

clean:
	rm -rf *.o
	rm main