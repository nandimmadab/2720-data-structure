/*
 * Sorting.h
 *
 *  Created on: Nov 21, 2017
 *      Author: XIaofeng
 */

#ifndef SORTING_H_
#define SORTING_H_

class Sorting{


	public:
	long counter = 0;
	void Insertion(int arr[], int length);
	void QuikSort(int arr[], int length);
	void QuikSort(int arr[],int low, int high);
	void mergeSort(int arr[], int length);
	void mergeHelper(int arr[], int start, int end);
	void merge(int arr[], int start, int end) ;



	void print(int arr[], int length);

};



#endif /* SORTING_H_ */
