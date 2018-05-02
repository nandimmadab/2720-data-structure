FLAGS = -Wall -O0 -g -std=c++14 -pedantic-errors

.Phony: clean all

all: itemType BinaryTree main

run: itemType BinaryTree main
	./main input.txt

main: main.o ItemType.o BinaryTree.o
	g++ $(FLAG) -o main main.o ItemType.o BinaryTree.o

main.o: main.cpp
	g++ $(FLAG) -c main.cpp

BinaryTree: BinaryTree.cpp BinaryTree.h
	g++ $(FLAG) -c BinaryTree.cpp


itemType: ItemType.cpp ItemType.h
	g++ $(FLAG) -c ItemType.cpp

clean:
	rm -rf *.o
	rm main