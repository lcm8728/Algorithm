#include "datatype.h"

void bubbleSort(element* arr, int l, int r){
	/*sort arr[l] ~ arr[r] in non-decreasing-order by element key*/
	element t;
	for(int i = l; i < r; i++){
		for(int j = r; j > 0; j--){
			if(arr[j].key < arr[j-1].key)
				SWAP(arr[j], arr[j-1], t);
		}
	}
}
