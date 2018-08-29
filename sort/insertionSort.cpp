#include "datatype.h"

void insertionSort(element* arr, int l, int r){
	/*sort arr[l] ~ arr[r] in non-decreasing-order by element key*/
	for(int i = l + 1; i < r + 1; i++){
		element t = arr[i];
		int j = i - 1;
		while(j >= 0 && arr[j].key > t.key){
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = t;
	}
}
