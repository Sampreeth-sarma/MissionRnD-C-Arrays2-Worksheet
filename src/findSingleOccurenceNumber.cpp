/*
OVERVIEW: Given an array where every element occurs three times, except one element which occurs only
once. Find the element that occurs once.
E.g.: Input: arr = 12, 1, 12, 3, 12, 1, 1, 2, 3, 3
ouput: 2

INPUTS: Integer array and length of the array.

OUTPUT: Element that occurs only once.

ERROR CASES: Return -1 for invalid inputs.

NOTES:
There are better ways of solving the problem than a brute-force solution which is of O(n^2)
complexity .
*/
#include<stdio.h>
void sort(int *, int, int);
int findSingleOccurenceNumber(int *A, int len) {
	if (A == NULL)
		return -1;
	if (len <= 0)
		return -1;
	sort(A,0,len-1);
	int i = 0;
	while (i < len - 1)
	{
		if (A[i] != A[i + 1])
			return A[i];
		else
			i+=3;
	}
	return A[len - 1];


}

void sort(int *A, int first, int last){
	int pivot, j, temp, i;

	if (first<last){
		pivot = first;
		i = first;
		j = last;

		while (i<j){
			while (A[i] <= A[pivot] && i<last)
				i++;
			while (A[j]>A[pivot])
				j--;
			if (i<j){
				temp = A[i];
				A[i] = A[j];
				A[j] = temp;
			}
		}

		temp = A[pivot];
		A[pivot] = A[j];
		A[j] = temp;
		sort(A, first, j - 1);
		sort(A, j + 1, last);

	}
}