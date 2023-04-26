#include "main.h"

/**
 * print_hex - prints a number in hexadecimal base,
 * in lowercase
 * @list: list arguments from _printf
 * @p: pointer to the struct flags
 * Return: the number of char printed
 */
int print_hex(va_list list, flags_typ *p)
{
	unsigned int num = va_arg(list, unsigned int);
	char *str = convert(num, 16, 1);
	int counter = 0;

	if (f->hash == 1 && str[0] != '0')
		counter = counter + _puts("0x");
	count = counter + _puts(str);
	return (counter);
}

/**
 * print_hex_upper - prints a number in hexadecimal base,
 * in uppercase
 * @list: list arguments from _printf
 * @p: pointer to the struct
 * Return: the number of char printed
 */
int print_hex_upper(va_list list, flags_typ *p)
{
	unsigned int num = va_arg(l, unsigned int);
	char *str = convert(num, 16, 0);
	int countter = 0;

	if (f->hash == 1 && str[0] != '0')
		counter = counter + _puts("0X");
	counter = counter +  _puts(str);
	return (counter);
}

/**
 * print_binary - prints a number in base 2
 * @list: list arguments from _printf
 * @p: pointer to the struct
 * Return: the number of char printed
 */
int print_binary(va_list list, flags_typ *p)
{
	unsigned int num = va_arg(list, unsigned int);
	char *str = convert(num, 2, 0);

	(void)p;
	return (_puts(str));
}

/**
 * print_octal - prints a number in base 8
 * @list: list arguments from _printf
 * @p: pointer to the struct
 * Return: the number of char printed
 */
int print_octal(va_list list, flags_typ *p)
{
	unsigned int num = va_arg(list, unsigned int);
	char *str = convert(num, 8, 0);
	int counter = 0;

	if (p->hash == 1 && str[0] != '0')
		counter = counter + _putchar('0');
	counter = counter + _puts(str);
	return (counter);
}
