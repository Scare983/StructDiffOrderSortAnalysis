#include "Sorting.h"
#include <iostream>
using namespace std;

Sorting::Sorting(int * myData, int size) {
	myArray = myData;
	this->size = size;
	numberComparisons = 0;
}

void Sorting::insertAlgorithm() {
for(int i =0; i < size; i++) {
	
	insertTheItem(myArray, 0, i);
}
	
}
void Sorting::insertTheItem(int * anArray, int start, int last) {
	bool finished = false;
	int current = last;
	bool moreToSearch = (current!=start);
	
	while(moreToSearch && !finished) {
		numberComparisons++;
		if(anArray[current] < anArray[current-1])  {
			
			int value = anArray[current-1];
			int nextValue = anArray[current];
			anArray[current] = value;
			anArray[current-1] = nextValue;
			current--;
			moreToSearch = (current != start);
		}
		else  {
			finished = true;
		}
		}
	
	
}


void Sorting::mergeAlgorithm() {

	mergeSort(0, size-1);
	
}
void Sorting::mergeSort(int first, int last) {
	if(first < last) {
		int mid = (first + last) / 2;
		mergeSort(first, mid);
		mergeSort(mid+1, last);
		merge(first, mid, last);
	}
	
}
void Sorting::merge(int first, int middle, int last) {
	int tempArray[size];
	for(int i = first; i <= last; i++) {
		tempArray[i] = myArray[i];
	}
	 int increment = first;
	 int afterMid = middle+1;
	 int index = first;
	 while(increment <= middle && afterMid <= last) {
		 numberComparisons++;
		 if(tempArray[increment] < tempArray[afterMid]) {
			 myArray[index] = tempArray[increment];
			 increment++;
		 }
		 else {
			 myArray[index] = tempArray[afterMid];
			 afterMid++;
		 }
		 index++;
	 }
	
	 while(increment <= middle) { //we are not comparing here, we are simply filling in
		 
		 myArray[index] = tempArray[increment];
		 index++;
		 increment++;
	 }
	 while(afterMid <= last) { // we are not oomparing here, we are simply filling in
		 
		 myArray[index] = myArray[afterMid];
		 afterMid++;
		 index++;
	 }
	 
	
}
void Sorting::quickSortAlgorithm() { //quick sort where splitpoint is halfway point / will take longer time to sort through sorted.
	initiateQuickSort(0, size-1);
	
}
void Sorting::initiateQuickSort(int start, int last) {
	if(start < last) {
			int pivotIndex = (start + last) / 2;
			int nextPivotIndex;
			partition(start, last, pivotIndex, nextPivotIndex);
			initiateQuickSort(start, nextPivotIndex -1); //checks left side
			initiateQuickSort(nextPivotIndex + 1, last);//checks right side
		
		
	}
	
	
}
void Sorting::partition(int start, int last, int pivotIndex, int& nextPivotIndex) {
	int pivotValue = myArray[pivotIndex];
	while(start < last) {
		while(myArray[start] < pivotValue) { //we are comparing to pivot value 
			numberComparisons++; 
			start++;
		}
		while(myArray[last] > pivotValue) { //we are comparing to pivot value
			numberComparisons++;
			last--;
		}
		//we increment because this is before the pairing and therfore we always have at least one 'compare' when partition is called
		numberComparisons++;
		if(start < last && myArray[start] != myArray[last]) {
			int temp = myArray[start];
			int secondTemp = myArray[last];
			myArray[start] = secondTemp;
			myArray[last] = temp;
		}
		else {
			
			nextPivotIndex = last;
			break;
		}
		
	}
		nextPivotIndex = last;
}

void Sorting::printList() {
	for(int i = 0; i < size; i++) {
		cout << myArray[i] << " ";
	}
	cout << endl;
	
}
int Sorting::getNumberComparisons() {
	return numberComparisons;
}