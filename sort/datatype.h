#define SWAP(x, y, t) (((t)=(x)),((x)=(y)),((y)=(t)))

typedef struct{
	int key;
}element;

void insertionSort(element*, int, int);
void bubbleSort(element*, int, int);
void quickSort(element*, int, int);
void selectionSort(element*, int, int);
void mergeSort(element*, int, int);
void heapSort(element*, int, int);