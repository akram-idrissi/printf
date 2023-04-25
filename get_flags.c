#include "main.h"

/**
 * get_flags - Calculates active flags
 * @format: Formatted string in which to print the arguments
 * @i: take a parameter.
 *
 * Return: Flags:
 */
int get_flags(const char *format, int *i)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int j, curr_i;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	/*These are the characters that represents the different flags*/
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};
	/*flag values (bitwise OR of F_MINUS, F_ZERO,F_HASH, and F_SPACE)*/

	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	/*Iterate the char in 'format' starting from the char after the '%'*/
	{
		for (j = 0; FLAGS_CH[j] != '\0'; j++)
	/*Check if the current char matches any of the flag characters*/
			if (format[curr_i] == FLAGS_CH[j])
			{
	/*If it does, set the corresponding bit in the 'flags' int using bitwise OR*/
				flags |= FLAGS_ARR[j];
				break;
			}
	/*If we reach a char that is not a flag character, stop parsing*/

		if (FLAGS_CH[j] == 0)
			break;
	}

	/*Update the value of 'i'*/
	*i = curr_i - 1;

	return (flags);
}
