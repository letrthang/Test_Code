/*
 * BinarySearch.cpp
 *
 *  Created on: Jul 13, 2015
 *      Author: Thang Le
 */
#include <iostream>
#include <cstdlib>

using namespace std;

//Binary Search Function
//Function accepts an array, the lower bound and upper bound subscripts...
//to be searched, and the key number for which we are searching.
//There is nothing returned.
	void binarySearch( int *array, int lowerbound, int upperbound, int key)
	{
	       int position;
	       int comparisonCount = 1;//count the number of comparisons (optional)

	       // To start, find the subscript of the middle position.
	       position = ( lowerbound + upperbound) / 2;

	       while((array[position] != key) && (lowerbound <= upperbound))
	       {
	              comparisonCount++;
			  if (array[position] > key)   // If the number is > key, ..
			 {                             // decrease position by one.
	              	  upperbound = position - 1;
	         }
			 else
			 {		// Else, increase position by one.
				   lowerbound = position + 1;
			 }
			 position = (lowerbound + upperbound) / 2;
	       }// end while

	      if (lowerbound <= upperbound)
	      {
			cout<< "The number was found in array subscript: "<< position<<endl<<endl;
			cout<< "The binary search found the number after: " << comparisonCount
				<< " comparisons.\n";
			// printing the number of comparisons is optional
	       }
	       else
			 cout<< "Sorry, the number is not in this array.  The binary search made "
			 <<comparisonCount << " comparisons.";

	       return;  // you may also consider returning the subscript
	}

int main()
{
	// function call to the binary search function (listed below)
	// for the array shown above
	int num[] = {10, 15, 24, 36, 45, 55, 64, 73, 90, 98};

	int n = sizeof num / sizeof num[0];
	binarySearch(num, 0, n-1, 64);

}




