#include "datatype.h"

void adjust(element* arr, int top, int bottom) {
	int parent = top;
	int child = top * 2 + 1;
	element t;   // t for SWAP
	
	while (child <= bottom) {
		if (child < bottom && arr[child].key < arr[child + 1].key) child++;   // choose bigger one
		if (arr[parent].key >= arr[child].key) break;
		SWAP(arr[parent], arr[child], t);
		parent = child;
		child = parent * 2 + 1;
	}
}

void heapSort(element* arr, int l, int r){
	for (int i = (r - 1) / 2; i >= l; i--) {
		adjust(arr, i, r);   // make max heap
	}
	element t;   // t for SWAP
	for (int i = r; i > l; i--) {
		SWAP(arr[l], arr[i], t);
		adjust(arr, l, i - 1);
	}
}
