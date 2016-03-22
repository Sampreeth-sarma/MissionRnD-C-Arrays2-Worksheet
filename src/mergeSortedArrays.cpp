/*
OVERVIEW: You are given 2 bank statements that are ordered by date - 
Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
int pow1(int, int);
int month(char *);
int year(char *);
int day(char *);
struct transaction {
	int amount;
	char date[11];
	char description[20];
};

struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) {
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
	res = (struct transaction*)malloc((ALen + BLen)*sizeof(struct transaction)); 
	int i = 0, j = 0, k = 0;
	while (i < ALen && j < BLen)
	{
		int year1 = year(A[i].date);
		int month1 = month(A[i].date);
		int day1 = day(A[i].date);
		//while(j<BLen)
		//{
		int year2 = year(B[j].date);
		int month2 = month(B[j].date);
		int day2 = day(B[j].date);

		if (year2 < year1)
		{
			res[k++] = B[j++];
			//break;
		}
		else if (year2 > year1)
		{
			res[k++] = A[i++];
			//break;
		}
		else
		{
			if (month2 < month1)
			{
				res[k++] = B[j++];
				//break;
			}
			else if (month2 > month1)
			{
				res[k++] = A[i++];
				//break;
			}
			else
			{
				if (day2 > day1)
				{
					res[k++] = A[i++];
					//break;
				}
				else if (day2 < day1)
				{
					res[k++] = B[j++];
					//break;
				}
				else
				{
					res[k++] = A[i++];
					j++;
					//break;
				}
			}
			//}
		}
	}
		while (i<ALen)
			res[k++] = A[i++];


	
	while(j < BLen)
	{
		res[k++] = B[j++];
	}
	return res;


	
}
int year(char *ptr)
{
	int j = 4,res=0;
	for (int i = 6; i < 10; i++)
	{
		res = res + (ptr[i]-48) * pow1(1, j--);
	}
	return res;
}
int month(char *ptr)
{
	int j = 2, res = 0;
	for (int i = 3; i < 5; i++)
	{
		res = res + (ptr[i] - 48) * pow1(1, j--);
	}
	return res;
}
int day(char *ptr)
{
	int j = 2, res = 0;
	for (int i = 0; i < 2; i++)
	{
		res = res + (ptr[i] - 48) * pow1(1, j--);
	}
	return res;
}
int pow1(int a, int b)
{
	
	for (int i = 0; i < b-1; i++)
	{
		a=a* 10;
	}
	return a;
}
