#include "main.h"

/**
 * get_precision - Calculates the precision value
 * @format: Formatted string
 * @a: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: Precision value
 */
int get_precision(const char *format, int *a, va_list list)
{
	int pres_index = *a + 1;
	int precision_value = -1;

	if (format[pres_index] != '.')
		return (precision_value);

	precision_value = 0;

	for (pres_index = pres_index + 1; format[pres_index] != '\0'; pres_index++)
	{
		if (is_digit(format[pres_index]))
		{
			precision_value *= 10;
			precision_value = precision_value + format[pres_index] - '0';
		}
		else if (format[pres_index] == '*')
		{
			pres_index++;
			precision_value = va_arg(list, int);
			break;
		}

		else
			break;
	}

	*a = pres_index - 1;

	return (precision_value);
}
