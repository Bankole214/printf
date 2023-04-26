#include "main.h"
#include <limits.h>
#include <stdio.h>

/**
 * _printf - produces output according to a format
 * @format: format string containing the characters
 * Return: length of the formatted output string
 */
int _printf(const char *format, ...)
{
	int (*funptr)(va_list, flags_typ *);
	const char *chr;
	va_list args;
	flags_typ flags = {0, 0, 0};

	register int counter = 0;

	va_start(args, format);
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (chr = format; *chr; chr++)
	{
		if (*chr == '%')
		{
			chr++;
			if (*chr == '%')
			{
				counter = counter + _putchar('%');
				continue;
			}
			while (get_flag_on(*chr, &flags))
				chr++;
			funptr = get_print(*chr);
			counter += (funptr)
				? funptr(args, &flags)
				: _printf("%%%c", *chr);
		} else
			counter = counter + _putchar(*chr);
	}
	_putchar(-1);
	va_end(args);
	return (counter);

}
