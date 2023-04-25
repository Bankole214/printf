#include "main.h"
#include <stdlib.h>


void print_con(char con[], int *con_index);

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	int a, print_out = 0, chars_printed = 0;
	int flags, width, precision_value, data_size, con_index = 0;
	va_list list;
	char con[CON_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (a = 0; format && format[a] != '\0'; a++)
	{
		if (format[a] != '%')
		{
			con[con_index++] = format[a];
			if (con_index == CON_SIZE)
				print_con(con, &con_index);

			chars_printed++;
		}

		else
		{
			print_con(con, &con_index);
			flags = get_flags(format, &a);
			width = get_width(format, &a, list);
			precision_value = get_precision(format, &a, list);
			data_size = get_size(format, &a);
			++a;
			print_out = handle_print(format, &a, list, con,
				flags, width, precision_value, data_size);
			if (print_out == -1)
				return (-1);
			chars_printed = chars_printed + print_out;
		}
	}

	print_con(con, &con_index);

	va_end(list);

	return (chars_printed);
}

/**
 * print_con - Prints the contents of the container if it exists
 * @con: Array of chars
 * @con_index: represents the length.
 */
void print_con(char con[], int *con_index)
{
	if (*con_index > 0)
		write(1, &con[0], *con_index);

	*con_index = 0;
}
