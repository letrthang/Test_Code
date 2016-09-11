/*
 * ============================================================================
 * Name        : QuickSort.cpp
 * Author      : Thang Le
 * Version     : Mar, 2015
 * Copyright   : www.letrungthang.blogspot.com
 * Description : quick sort implementation
 * ============================================================================
 */

#include <iostream>
using namespace std;

void quick_sort(int *x, int low, int high) {
	int pivot, temp, down, up;

	pivot = x[low]; // this is the pivot
	down = low;
	up = high;

	if (low >= high) {
		return;
	}

	while (down < up) {
		while (x[down] <= pivot) {
			down++;
			if (down == high)
				break; // it is possible to down > high. To avoid out of array accessing
		}
		while (x[up] > pivot) {
			up--;
			if (up == low)
				break; // it is possible to up < low. To avoid out of array accessing
		}
		if (down < up) {
			temp = x[down];
			x[down] = x[up];
			x[up] = temp;
		}
	}

	// now we move the pivot to the position that all elements lesser than it
	// is standing at its left side and else its right side is all elements bigger than it.
	if (low < up) {
		temp = x[low];
		x[low] = x[up];
		x[up] = temp;
	}

	// we sort again all elements at left side and right side of the pivot.
	// To prevent cyclic recursive, we need exclude the pivot in sorting of substrings
	quick_sort(x, low, up - 1);
	quick_sort(x, up + 1, high);
}

int main_qs(){

	int a[] = { 4, 65, 2, -31, 0, 99, 2, 83, 782, 1 };
	//int a[] = { 0, 2, 2, 2 };
	int n = sizeof a / sizeof a[0];

	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << "\n";

	quick_sort(a, 0, n - 1);

	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << "\n";

	return 0;

}
