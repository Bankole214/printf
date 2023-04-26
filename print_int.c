#include "main.h"

/**
 * print_int - prints an integer
 * @list: list of arguments from _printf
 * @p: pointer to the struct flags
 * Return: number of char printed
 */
int print_int(va_list list, flags_typ *p)
{
	int a = va_arg(list, int);
	int res = counter_digit(a);

	if (p->space == 1 && p->plus == 0 && a >= 0)
		res = res + _putchar(' ');
	if (p->plus == 1 && a >= 0)
		res = res + _putchar('+');
	if (a <= 0)
		res++;
	print_number(n);
	return (res);
}

/**
 * print_unsigned - prints an unsigned integer
 * @list: va_list of arguments from _printf
 * @p: pointer to the struct flags
 * Return: number of char printed
 */
int print_unsigned(va_list list, flags_typ *p)
{
	unsigned int b = va_arg(list, unsigned int);
	char *str = convert(u, 10, 0);

	(void)p;
	return (_puts(str));
}

/**
 * print_number - function that loops through
 * an integer and prints all its digits
 * @a: integer to be printed
 */
void print_number(int a)
{
	unsigned int a1;

	if (a < 0)
	{
		_putchar('-');
		a1 = -a;
	}
	else
		a1 = a;

	if (a1 / 10)
		print_number(a1 / 10);
	_putchar((a1 % 10) + '0');
}

/**
 * counter_digit - returns the number of digits in an integer
 * @c: integer to evaluate
 * Return: number of digits
 */
int counter_digit(int c)
{
	unsigned int d = 0;
	unsigned int b;

	if (c < 0)
		b = c * -1;
	else
		b = c;
	while (b != 0)
	{
		b /= 10;
		d++;
	}
	return (d);
}
