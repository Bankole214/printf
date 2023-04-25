#include "main.h"

/**
 * get_width - Calculates the width
 * @format: Formatted string
 * @a: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: width.
 */
int get_width(const char *format, int *a, va_list list)
{
	int pres_index;
	int width = 0;

	for (pres_index = *a + 1; format[pres_index] != '\0'; pres_index++)
	{
		if (is_digit(format[pres_index]))
		{
			width *= 10;
			width = width + format[pres_index] - '0';
		}
		else if (format[pres_index] == '*')
		{
			pres_index++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*a = pres_index - 1;

	return (width);
}
