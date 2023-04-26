#include "main.h"

/**
 * print_string - loops through a string and prints
 * every character
 * @list: va_list arguments from _printf
 * @p: pointer to the struct flags
 * Return: number of char printed
 */
int print_string(va_list list, flags_typ *p)
{
	char *s = va_arg(list, char *);

	(void)p;

	if (!s)
		s = "(null)";
	return (_puts(s));
}

/**
 * print_char - prints a character
 * @list: arguments from _printf
 * @p: pointer to the struct flags
 * Return: number of char printed
 */
int print_char(va_list list, flags_typ *p)
{
	(void)p;
	_putchar(va_arg(list, int));
	return (1);
}
