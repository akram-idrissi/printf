#include "main.h"

/**
 * get_width - Calculates the width for printing
 * @format: Formatted string in which to print the arguments.
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: width.
 */
int get_width(const char *format, int *i, va_list list)
{
	int curr_i;
	int width = 0;
	/*Iterate over the chars in 'format' starting from the char after the '%'*/
	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
		/*if the current character is a digit, add it to 'width'*/
		if (is_digit(format[curr_i]))
		{
			width *= 10;
			width += format[curr_i] - '0';
		}
		/*if the current character is a '*', read the argument from 'list' as width*/
		else if (format[curr_i] == '*')
		{
			curr_i++;
			width = va_arg(list, int);
			break;
		}
		/* if the current character is not a digit or '*', stop parsing*/
		else
			break;
	}
	/*Update the value of 'i'*/

	*i = curr_i - 1;

	return (width);
}
