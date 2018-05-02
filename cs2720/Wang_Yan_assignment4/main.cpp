/*
 * main.cpp
 *
 *  Created on: Nov 21, 2017
 *      Author: XIaofeng
 */
#include"Sorting.h"
#include<cstdlib>
#include<fstream>
#include<iostream>

using namespace std;

int main(int argc, char* argv[]) {
	Sorting sort;
	int arr[999999];
	int temp[999999];
	int length = 0;
	int i = 0;
	int input;
	char a;
	fstream fs;

	fs.open(argv[1], std::fstream::in);
	if(fs.is_open()) {
		fs >> input;
		while(!fs.eof()) {
			arr[i] = input;
			i++;
			length++;
			fs >> input;
		}
       	} else {
		cout << "file could not be opened. Try again." << endl;
		return 0;
	}


	
	cout << "Command -Insertion Sort(i), Merge Sort(m), Quick Sort(q), exit(e)" << endl;

	while(true) {

		cout << "Enter the algorithm for sorting: ";
		cin >> a;
		if(a == 'i') {
			cout << "Insertion sort: ";
			for(int i = 0; i < length; i++) {
				temp[i] = arr[i];
			}
			sort.Insertion(temp, length);
			sort.print(temp, length);
			cout << endl;
			cout << "Total # comparisons: "<< sort.counter << endl;
		}
		if(a == 'm') {
			cout << "Merge sort: ";
			for(int i = 0; i < length; i++) {
				temp[i] = arr[i];
			}
			sort.mergeSort(temp, length);
			sort.print(temp, length);
			cout << endl;
			cout << "Total # comparisons: "<< sort.counter << endl;
		}
		if(a == 'q') {
			cout << "Quick sort: ";
			for(int i = 0; i < length; i++) {
				temp[i] = arr[i];
			}
			sort.QuikSort(temp, length);
			sort.print(temp, length);
			cout << endl;
			cout << "Total # comparisons: "<< sort.counter << endl;
		}
		if(a == 'e') {
			cout << "Exit program..." << endl;
			return 0;
		}
	}

	
}



