#include "main.h"
#include <stdlib.h>


void print_con(char con[], int *buff_ind);

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	int a, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char con[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (a = 0; format && format[i] != '\0'; a++)
	{
		if (format[i] != '%')
		{
			con[buff_ind++] = format[a];
			if (buff_ind == BUFF_SIZE)
				print_con(con, &buff_ind);
			/* write(1, &format[a], 1);*/
			printed_chars++;
		}
		else
		{
			print_con(con, &buff_ind);
			flags = get_flags(format, &a);
			width = get_width(format, &a, list);
			precision = get_precision(format, &a, list);
			size = get_size(format, &a);
			++a;
			printed = handle_print(format, &a, list, con,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	print_con(con, &buff_ind);

	va_end(list);

	return (printed_chars);
}

/**
 * print_con - Prints the contents of the buffer if it exist
 * @con: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */
void print_con(char con[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &con[0], *buff_ind);

	*buff_ind = 0;
}
