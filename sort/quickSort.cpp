#include "datatype.h"

int partition(element* arr, int l, int r){
	int pivot = l;
	element t;
	for(int i = l; i < r; i++){
		if(arr[i].key < arr[r].key){
			SWAP(arr[i], arr[pivot], t);
			pivot++;
		}
	}
	SWAP(arr[r], arr[pivot], t);

	return pivot;
}

void quickSort(element* arr, int l, int r){
	/*sort arr[l] ~ arr[r] in non-decreasing-order by element key*/
	int pivot;
	// partition
   pivot = partition(arr, l, r);

	// recursion
	if(l < pivot - 1)
		quickSort(arr, l, pivot-1);
	if(r > pivot + 1)
		quickSort(arr, pivot+1, r);
}
