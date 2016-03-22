/*
OVERVIEW: You are given 2 bank statements that are ordered by date. 
Write a function that returns dates common to both statements
(ie both statements have transactions in these dates).
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[3] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" }, { 320, "27-08-2015", "Seventh" } };
Output: { { 10, "09-10-2003", "First" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Transactions having same dates.


ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
int pow2(int, int);
int month_1(char *);
int year_1(char *);
int day_1(char *);
struct transaction {
	int amount;
	char date[11];
	char description[20];
};

struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen) {

	if (A == NULL)
		return NULL;
	if (B == NULL)
		return NULL;
	if (ALen <= 0 && BLen > 0)
		return B;
	if (BLen <= 0 && ALen > 0)
		return A;
	if (ALen <= 0 && BLen <= 0)
		return NULL;
	struct transaction *res;
	res = (struct transaction*)malloc((ALen)*sizeof(struct transaction));
	int i = 0, j = 0, k = 0;
	while (i < ALen && j < BLen)
	{
		int start = i;
		int year1 = year_1(A[i].date);
		int month1 = month_1(A[i].date);
		int day1 = day_1(A[i].date);
		int year2 = year_1(B[j].date);
		int month2 = month_1(B[j].date);
		int day2 = day_1(B[j].date);

		if (year2 == year1)
		{

			if (month2 == month1)
			{

				if (day2 == day1)
				{
					res[k++] = A[i++];
					j = 0;
				}

			}
		}
		if (start == i && j < BLen)
			j++;
		else if (j == BLen - 1){
			j = 0; i++;
		}


	}
	if (i == 0)
		return NULL;
	else if (i>0)
	return res;



}
int year_1(char *ptr)
{
	int j = 4, res = 0;
	for (int i = 6; i < 10; i++)
	{
		res = res + (ptr[i] - 48) * pow2(1, j--);
	}
	return res;
}
int month_1(char *ptr)
{
	int j = 2, res = 0;
	for (int i = 3; i < 5; i++)
	{
		res = res + (ptr[i] - 48) * pow2(1, j--);
	}
	return res;
}
int day_1(char *ptr)
{
	int j = 2, res = 0;
	for (int i = 0; i < 2; i++)
	{
		res = res + (ptr[i] - 48) * pow2(1, j--);
	}
	return res;
}
int pow2(int a, int b)
{

	for (int i = 0; i < b - 1; i++)
	{
		a = a * 10;
	}
	return a;
}
