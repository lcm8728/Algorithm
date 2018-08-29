#include <iostream>
#include <cstdlib>
#include <ctime>
#include "datatype.h"
#define NUM_DATA 1000

using namespace std;

int ordered(element* arr, int num) {
	// print "ordered" and return 1 when array is ordered
	// otherwise, print "inordered" and return 0
	for (int i = 0; i < num - 1; i++) {
		if (arr[i].key > arr[i + 1].key) {
			cout << "array unodered" << endl;
			return 0;
		}
	}
	cout << "array ordered" << endl;
	return 1;
}

void check_time(void func(element*, int, int), element* arr, int num) {
	// make a copy of array to preserve original one
	element* copy = new element[NUM_DATA];
	memcpy(copy, arr, sizeof(element)*NUM_DATA);

	// check time
	clock_t start = clock();
	cout << ":::Sorting........";
	func(copy, 0, NUM_DATA - 1);
	cout << "done" << endl;
	cout << ":::Time : " << ((float)(clock() - start) / CLOCKS_PER_SEC) << "s" << endl;
	cout << ":::Result : ";
	ordered(copy, NUM_DATA);

	cout << "------------------------------------------" << endl;
}

int main(){
	// create an array
	element* arr = new element[NUM_DATA];
	for(int i = 0; i < NUM_DATA; i++){
		arr[i].key = rand()%NUM_DATA;
	}
	cout << "Number of elements : " << NUM_DATA << endl;
	cout << "------------------------------------------" << endl;
	
	// check time of algorithms
	cout << ":::Insertion_Sort" << endl;
	check_time(insertionSort, arr, NUM_DATA);
	cout << ":::Selection_Sort" << endl;
	check_time(selectionSort, arr, NUM_DATA);
	cout << ":::Bubble_Sort" << endl;
	check_time(bubbleSort, arr, NUM_DATA);
	cout << ":::Quick_Sort" << endl;
	check_time(quickSort, arr, NUM_DATA);
	cout << ":::Merge_Sort" << endl;
	check_time(mergeSort, arr, NUM_DATA);
	cout << ":::Heap_Sort" << endl;
	check_time(heapSort, arr, NUM_DATA);

	return 0;
}
