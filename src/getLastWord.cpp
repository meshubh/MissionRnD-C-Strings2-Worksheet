/*

Problem : Return the Last word in a string

Input : I will do this without using String Library
Output : Library

Note:Dont modify original string Neglect Spaces at the right end and at left end if required .
->Create a new string and return it , Use dynamic memory allocation .
*/
#include <stdlib.h>

char * get_last_word(char * str)
{
	if (str == NULL)
		return NULL;
	else
	{
		int iterator = 0, LastSpace = 0, iterator2 = 0, str_len = 0;
		while (str[iterator])
		{
			str_len++;
			iterator++;
		}
		while (str[str_len - 1] == ' ')
		{
			if (str[str_len - 1] == ' ')
				str_len--;
		}
		iterator = 0;
		while (iterator<str_len)
		{
			if (str[iterator] == ' ')
				LastSpace = iterator + 1;
			iterator++;
		}
		char *result = (char *)malloc(sizeof(char *));
		while (LastSpace < str_len)
		{
			*(result + iterator2) = str[LastSpace];
			LastSpace++;
			iterator2++;
		}
		*(result + iterator2) = '\0';
		return result;
	}
}