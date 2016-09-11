/* q.sort */
#include <iostream>

void swap(int A[], int i, int j) {
	int temp;
	temp = A[i];
	A[i] = A[j];
	A[j] = temp;
}

void quickSort(int A[], int lower, int upper) {
	int x, i, j;
	i = lower;
	j = upper;
	x = A[(lower + upper) / 2]; // x is pivot
	do {
		while (A[i] < x)
			i++;
		while (A[j] > x)
			j--;
		if (i <= j) {
			swap(A, i, j);
			i++;
			j--;
		}
	}
	while (i <= j);
	if (j > lower) // Now, position of j is left of pivot
		quickSort(A, lower, j);
	if (i < upper) // Now, position of i is right of pivot
		quickSort(A, i, upper);
}
//
int main30() {
	int Arr[10] = { 1, 3, 9, 4, 5, 0, 7, 2, 6, 8 };
	quickSort(Arr, 0,9);
	for (int i = 0; i <= 9; i++)
		printf(" %d", Arr[i]);
	return 0;
}
