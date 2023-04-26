#include "main.h"

/**
 * print_address - prints address of input in hexa format
 * @list: arguments from _printf
 * @p: pointer to the struct flags
 * Return: number of char printed
 */
int print_address(va_list list, flags_typ *p)
{
	char *str;
	unsigned long int a = va_arg(list, unsigned long int);

	register int counter = 0;

	(void)p;

	if (!a)
		return (_puts("(nil)"));
	str = convert(a, 16, 1);
	counter += _puts("0x");
	counter += _puts(str);
	return (counter);
}
