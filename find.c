/*
 * Implementation of functions that find values in strings.
 *****
 * YOU MAY NOT USE ANY FUNCTIONS FROM <string.h>
 *****
 */

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "find.h"

#define NOT_FOUND (-1) // integer indicator for not found.

/*
 * Return the index of the first occurrence of <ch> in <string>,
 * or (-1) if the <ch> is not in <string>.
 */
int find_ch_index(char string[], char ch)
{
	//index variable to iterate through the string
	int i = 0;

	//Check to see if string at index i is equal to ch if so return 
	//position(index) if nothing found return NOT_FOUND.
	while (string[i] != '\0')
	{
		if (string[i] == ch)
		{
			return i;
		}
		++i;
	}
	return NOT_FOUND;
}

/*
 * Return a pointer to the first occurrence of <ch> in <string>,
 * or NULL if the <ch> is not in <string>.
 *****
 * YOU MAY *NOT* USE INTEGERS OR ARRAY INDEXING.
 *****
 */
char *find_ch_ptr(char *string, char ch)
{
	//run while loop as long as the pointers value is not terminate char
	while (*string != '\0')
	{
		//If pointers value is equal to ch then return address of pointer. 
		//If nothing found return NULL pointer.
		if (*string == ch)
		{
			return string;
		}
		++string;
	}
	return NULL;
}

/*
 * Return the index of the first occurrence of any character in <stop>
 * in the given <string>, or (-1) if the <string> contains no character
 * in <stop>.
 */
int find_any_index(char string[], char stop[])
{
	//Both i and j used for nested loops to iterate through both string
	//and stop. Will iterate through stop entirely for every char in string 
	//and returns i when both char values are equal. If nothing found returns 
	//NOT_FOUND global constant.
	int i = 0;
	int j = 0;

	while (string[i] != '\0')
	{
		while (stop[j] != '\0')
		{
			if (string[i] == stop[j])
			{
				return i;
			}
			++j;
		}
		//Reset j so when we move to the next char in string we can 
		//start from beginning of stop.
		j = 0;
		++i;
	}
	return NOT_FOUND;
}

/*
 * Return a pointer to the first occurrence of any character in <stop>
 * in the given <string> or NULL if the <string> contains no characters
 * in <stop>.
 *****
 * YOU MAY *NOT* USE INTEGERS OR ARRAY INDEXING.
 *****
 */
char *find_any_ptr(char *string, char *stop)
{
	//Very similar approach to my approach in the find_any_index method 
	//above except using pointers. 
	//Nested loops will iterate through both 
	//char pointers string and stop.

	//Here we have a "copy" of the pointer stop which points to stops first 
	//byte this allows us to reset our stop pointer so when we move to the next 
	//char in string we can start from beginning of stop.
	char *cpy = stop;
	while (*string != '\0')
	{
		while (*stop != '\0')
		{
			if (*string == *stop)
			{
				return string;
			}
			++stop;
		}
		//implementation to reset stop to point to its first byte
		stop = cpy;
		++string;
	}
	return NULL;
}

/*
 * Return a pointer to the first character of the first occurrence of
 * <substr> in the given <string> or NULL if <substr> is not a substring
 * of <string>.
 * Note: An empty <substr> ("") matches *any* <string> at the <string>'s
 * start.
 *****
 * YOU MAY *NOT* USE INTEGERS OR ARRAY INDEXING.
 *****
 */
char *find_substr(char *string, char *substr)
{
	//counter is used to subtract it from the latest position of the 
	//string pointer. This gives us first occurance of substring.
	int counter = 0;

	//red_blue is used to keep track of whether or not substr last char 
	//is equal('b' for blue) to the last char string points too because 
	//if it is, its a substring of string, and if not red_blue is assigned 
	//('r' for red) to denote its not equal. We use this value later in a condition 
	//to return NULL or a pointer to the occurace of substr
	char red_blue = 0;

	//Implementation Below:

	//if substr is empty return pointer of first byte of string

	//else run a loop that checks both string and substr pointers char by char
	//if there equal assign 'b' to red_blue and increment the counter
	//and move both string and substr pointers forward and run again
	// else assign 'r' to red_blue and only increment the strings pointer
	//to the next char until string and substr point to the same values

	//if statement inside else checks to see if we have reached the last char in substr
	//if so jump out of the while loop there is no need to check any more chars in string.

	if (*substr == '\0')
	{
		return string;
	}
	else
	{
		while (*substr != '\0')
		{
			if (*string == *substr)
			{
				red_blue = 'b';
				++counter;
				++string;
				++substr;
			}
			else
			{
				red_blue = 'r';
				++string;
				if (*++substr == '\0')
				{
					break;
				}
				else
				{
					--substr;
				}
			}
		}
	}
	if (counter == 0 || red_blue == 'r')
	{
		return NULL;
	}
	else
	{
		return string - counter;
	}
}
