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
	// Iterate over the characters in 'format' starting from the character after the '%'
	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
		// if the current character is a digit, add it to 'width' 
		if (is_digit(format[curr_i]))
		{
			width *= 10;
			width += format[curr_i] - '0';
		}
		// if the current character is a '*', read the next argument from 'list' as width
		else if (format[curr_i] == '*')
		{
			curr_i++;
			width = va_arg(list, int);
			break;
		}
		// if the current character is not a digit or '*', stop parsing
		else
			break;
	}
	// Update the value of 'i' so that it points to the last width character that was parsed

	*i = curr_i - 1;
	// Return the width of the field to be printed

	return (width);
}
