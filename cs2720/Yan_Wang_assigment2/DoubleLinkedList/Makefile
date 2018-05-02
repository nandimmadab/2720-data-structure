FLAGS = -Wall -O0 -g -std=c++14 -pedantic-errors

.Phony: clean all

all: itemType DoubleLinkedList main

run: itemType DoubleLinkedList main
	./main input.txt

main: main.o ItemType.o DoubleLinkedList.o
	g++ $(FLAG) -o main main.o ItemType.o DoubleLinkedList.o

main.o: main.cpp
	g++ $(FLAG) -c main.cpp

DoubleLinkedList: DoubleLinkedList.cpp DoubleLinkedList.h
	g++ $(FLAG) -c DoubleLinkedList.cpp


itemType: ItemType.cpp ItemType.h
	g++ $(FLAG) -c ItemType.cpp

clean:
	rm -rf *.o
	rm main