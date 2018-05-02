FLAGS = -Wall -O0 -g -std=c++14 -pedantic-errors
run: Sorting main
	g++ $(FLAGS) main.o Sorting.o -o main
Sorting:
	g++ -c $(FLAGS) Sorting.cpp
main:
	g++ -c $(FLAGS) main.cpp

clean:
	rm *.o main