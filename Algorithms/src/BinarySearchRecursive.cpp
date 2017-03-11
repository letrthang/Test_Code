/*
 * Binary Search Function using Recursive method
 * Created on: 10 Mar 2017
 * Author: Thang Le
 */
#include <iostream>
#include <cstdlib>
using namespace std;

//Function accepts an array, the lower bound and upper bound subscripts...
//to be searched, and the key number for which we are searching.
//There is nothing returned.
int binarySearchRecursive(int *array, int lowerbound, int upperbound, int key) {
	int position;
	if (lowerbound > upperbound) {
		return -1;
	}
	// To start, find the subscript of the middle position.
	position = (lowerbound + upperbound) / 2;
	if (array[position] > key)   // If the number is > key, ..
			{                             // decrease position by one.
		upperbound = position - 1;
	} else if (array[position] < key) {		// Else, increase position by one.
		lowerbound = position + 1;
	} else {
		return position;
	}
	return binarySearchRecursive(array, lowerbound, upperbound, key);
}
int main() {
	// function call to the binary search function (listed below)
	// for the array shown above
	int num[] = { 10, 15, 24, 36, 45, 55, 64, 73, 90, 98 };
	int ret;
	int n = sizeof num / sizeof num[0];
	ret = binarySearchRecursive(num, 0, n - 1, 55);
	if (ret == -1) {
		cout << "this element is not in given array" << endl;
	} else {
		cout << "found index = " << ret << endl;
	}

}

