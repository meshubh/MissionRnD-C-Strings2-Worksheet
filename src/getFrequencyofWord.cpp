/*

Problem : Return the Count of how many times the word occurred in given string in two ways
Way1: Not using Recursion
Way2:Using Recursion [Optional]

Input : "Hello HelloAgain HelloAGAINAGAIN commonItsHelloagain","Hello"
Output : 4

Note: Dont modify original str or word,Just return count ,Spaces can also be part of words like "ab cd" in "ab cd ab cd" returns 2
*/

#include <stdlib.h>

int str_len(char *string)
{
	if (!string)
		return 0;
	int iterator = 0;
	while (string[iterator]) 
		iterator++;
	return iterator;
}
int count_word_in_str_way_1(char *str, char *word)
{
	if (str == NULL || word == NULL)
		return 0;
	else
	{
		int wrd_len = str_len(word);
		int string_len = str_len(str);
		int iterator = 0, iterator1 = 0, freq_count = 0;
		while (iterator < string_len)
		{
			if (str[iterator] == word[iterator1])
			{
				iterator1++;
				if (iterator1 == wrd_len)
				{
					freq_count++;
					iterator1 = 0;
					if (wrd_len == 1)
						iterator++;
				}
				else
					iterator++;
			}
			else
			{
				iterator++;
				iterator1 = 0;
			}
		}
		return freq_count;
	}
}

int count_word_int_str_way_2_recursion(char *str, char *word)
{
	if (str == NULL || word == NULL)
		return 0;
	else
	{
		int wrd_len = str_len(word);
		int string_len = str_len(str);
		int iterator = 0;
		if (!str[iterator])
			return 0;
		while (str[iterator] == word[iterator] && str[iterator] && word[iterator])
			iterator++;
		if (!word[iterator])
		{
			return 1 + count_word_int_str_way_2_recursion(str + 1, word);
		}
		return count_word_int_str_way_2_recursion(str + 1, word);
	}
}
