#include "datatype.h"

void selectionSort(element* arr, int l, int r){
	/*sort arr[l] ~ arr[r] in non-decreasing-order by element key*/
	element t;
	for(int i = l; i < r; i++){
		int min = i;
		int j;
		for(j = i + 1; j <= r; j++){
			if(arr[j].key < arr[min].key){
				min = j;
			}
		}
		SWAP(arr[i], arr[min], t);
	}
}
