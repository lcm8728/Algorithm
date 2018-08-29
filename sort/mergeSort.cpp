#include "datatype.h"
#include <cstring>

void merge(element* arr, element* buffer, int l, int r){
	/*merge two part of sorted array*/
	int mid = (r+l)/2;
	memcpy(buffer + l, arr + l, sizeof(element)*(r-l+1));
	
	int i=l;
	int j=mid+1;
	int k=l;
	while(i <= mid && j <= r){
		if(buffer[i].key < buffer[j].key){
			arr[k++] = buffer[i++];
		}
		else{
			arr[k++] = buffer[j++];
		}
	}
	while(i <= mid)
		arr[k++] = buffer[i++];
	while(j <= r)
		arr[k++] = buffer[j++];
}

void sort(element* arr, element* buffer, int l, int r){
	if(l < r){
		int mid = (l+r)/2;
		sort(arr, buffer, l, mid);
		sort(arr, buffer, mid+1, r);
		merge(arr, buffer, l, r);
	}
}

void mergeSort(element* arr, int l, int r){
	/*sort arr[l] ~ arr[r] in non-decreasing-order by element key*/
	// make buffer
	element* buffer = new element[r-l+1];
	memcpy(buffer, arr, sizeof(element)*(r-l+1));
	// sort
	sort(arr, buffer, l, r);
}
