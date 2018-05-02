FLAGS = -Wall -O0 -g -std=c++14 -pedantic-errors

.Phony: clean all

all: itemType CircularLinkedList main

run: itemType CircularLinkedList main
	./main input.txt

main: main.o ItemType.o CircularLinkedList.o
	g++ $(FLAG) -o main main.o ItemType.o CircularLinkedList.o

main.o: main.cpp
	g++ $(FLAG) -c main.cpp

CircularLinkedList: CircularLinkedList.cpp CircularLinkedList.h
	g++ $(FLAG) -c CircularLinkedList.cpp


itemType: ItemType.cpp ItemType.h
	g++ $(FLAG) -c ItemType.cpp

clean:
	rm -rf *.o
	rm main