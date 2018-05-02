#include"Sorting.h"
#include <iostream>
#include<array>

using namespace std;


void swap(int &a, int &b){
  int temp = a;
  a = b;
  b = temp;
}


void Sorting::QuikSort(int arr[],int low, int high){
  if(low>=high){
    // if one element left, exist
    return;
  }

  int pivot = arr[low];
  int i=low;
  for(int j=low+1;j<=high;j++){
    if(arr[j]<=pivot){ 		        //a[j] is smaller than pivot
      i++;   			        //a[i] is bigger than pivot
      if(i!=j){				//a[i] is not equal to a[j]
	swap(arr[i],arr[j]);
      }
    }
      counter++;
  }
  swap(arr[low],arr[i]); 		//swap pivot to middle position

  QuikSort(arr,low,i-1);       	        //a[i] is the pivot now
  QuikSort(arr,i+1,high);
}

void Sorting::QuikSort(int arr[], int length){
  counter = 0;
  QuikSort(arr,0,length-1);

}

void swapInsertion(int &j, int arr[]) {
	int temp;

	temp = arr[j];
	arr[j] = arr[j+1];
	arr[j+1] = temp;
}


void Sorting::Insertion(int arr[], int length) {
  counter = 0;
	for(int i = 1; i < length; i++) {
		int key = arr[i];
		for(int j = i-1; j >= 0; j--) {
			if(key < arr[j]) {
				swapInsertion(j, arr);
			        counter++;
			} else {
			  	counter++;
				break;
			}
		}
	}
}

void Sorting::mergeHelper(int arr[], int start, int end) {
	int mid = (start + end) / 2;
	int leftStart = start;
	int leftEnd = mid;
	int rightStart = mid + 1;
	int rightEnd = end;
	int size = end - start + 1;
	int *temp = new int[size];
	int index = 0;

	while(leftStart <= leftEnd && rightStart <= rightEnd) {
		if(arr[leftStart] < arr[rightStart]) {
			temp[index] = arr[leftStart];
			leftStart++;
		} else {
			temp[index] = arr[rightStart];
			rightStart++;
		}
		index++;
		counter++;
	}

	while(leftStart <= leftEnd) {
		temp[index] = arr[leftStart];
		index++;
		leftStart++;
	}
	while(rightStart <= rightEnd) {
		temp[index] = arr[rightStart];
		index++;
		rightStart++;
	}

	for(int i = 0; i < size; i++) {
		arr[start] = temp[i];
		start++;
	}
	delete[] temp;
}

void Sorting::merge(int arr[], int start, int end) {
	if(start >= end)
		return;
	int mid = (start+end) / 2;
	merge(arr, start, mid);
	merge(arr, mid+1, end);
	mergeHelper(arr, start, end);
}

void Sorting::mergeSort(int arr[], int length) {
	counter = 0;
	merge(arr, 0, length-1);

}




void Sorting::print(int arr[], int length) {
	for(int i = 0; i < length; i++) {
		cout << arr[i] << " ";
	}
}
