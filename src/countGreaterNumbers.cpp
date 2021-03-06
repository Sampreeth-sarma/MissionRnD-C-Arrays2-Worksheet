/*
OVERVIEW: You are given a bank statement where transactions are ordered by date. Write a function that finds the number of transactions in that statement after a given date.
-- find the count of numbers greater than a given number in a sorted array.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
date = "19-10-2004"
Output: 1 (as there is only one transaction { 30, "03-03-2005", "Third" })

INPUTS: One bank statement (array of transactions) and date.

OUTPUT: Return the number of transactions in that statement after a given date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/
#include<stdio.h>
struct transaction {
	int amount;
	char date[11];
	char description[20];
};

int countGreaterNumbers(struct transaction *Arr, int len, char *date) {
	if (Arr == NULL)
		return NULL;
	if (date == NULL)
		return NULL;
		int i,check,j=0,count=0,res;
	for ( i = 0; i < 11; i++)
	{
		if (j < len)
		{
			if (Arr[j].date[i] == date[i] && i<10)
				continue;
			
			else
			{
				if (i == 10)
				{
					count++; res = j; j++; i = 0;
				}
				else
				{
					j++; i = 0;
				}
			}
		}
	}
	if (count==1)
		return (len - res-1);
	else if (j==len || count>1)
		return 0;
	

}
