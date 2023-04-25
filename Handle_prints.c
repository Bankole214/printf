#include "main.h"
/**
 * handle_print - Prints an argument based on its type
 * @fmt_s: Formatted string
 * @list: List of arguments to be printed.
 * @p: Pointer to the current position in the format string
 * @con: array to handle print.
 * @cast_size: the number of size casted
 * @flags: flags
 * @width: the width
 * @precision_value: Precision
 * Return: 1 or 2
*/
int handle_print(const char *fmt_s, int *p, va_list list, char con[],
		int flags, int width, int precision_value, int cast_size)
{

	/* Array of format types and their corresponding print functions */
	int a, unknown_len = 0, printed_chars = -1;
	fmt_s fmt_typ[] = {
		{'c', print_char}, {'s', print_string},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'p', print_pointer},
		{'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hexa_upper}, {'S', print_non_printable}, {'r', print_rev},
		{'R', print_rot13}, {'%', print_percent{'\0', NULL}
};
/* Loop over the format types and call the corresponding print function */
	for (a = 0; fmt_typ[a].fmt_s != '\0'; a++)
		if (fmt_s[*p] == fmt_typ[a].fmt_s)
			return (fmt_typ[a].fn(list, con, flags, width, precision_value, cast_size));

		if (fmt_typ[a].fmt_s == '\0')
			/* If format is not recognized, print it as it is */
	{
		if (fmt[*p] == '\0')
			return (-1);
		len = len + write(1, "%%", 1);

		if (fmt_s[*p - 1] == ' ')
			len = len +  write(1, " ", 1);

		else if (width)
		{
			--(*p);
			while (fmt_s[*p] != ' ' && fmt_s[*p] != '%')
				--(*p);

			if (fmt_s[*p] == ' ')
				--(*p);
			return (1);
		}
		len = len + write(1, &fmt_s[*p], 1);
		return (len);
	} /* Return the number of characters printed */
	return (printed_chars);
}
