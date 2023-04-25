#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * print_unsigned - Prints an unsigned number
 * @types: List a of arguments
 * @con:  array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision_value: Precision specification
 * @data_size: Size specifier
 * Return: Number of chars printed.
 */
int print_unsigned(va_list types, char con[],
	int flags, int width, int precision_value, int data_size)
{
	int a = CON_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = unsgnd_num(num, data_size);

	if (num == 0)
		con[a--] = '0';

	con[CON_SIZE - 1] = '\0';

	while (num > 0)
	{
		con[a--] = (num % 10) + '0';
		num /= 10;
	}

	a++;

	return (write_unsgnd(0, a, con, flags, width, precision_value, data_size));
}

/**
 * print_octal - Prints an unsigned number in octal notation
 * @types: List of arguments
 * @con: array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision_value: Precision specification
 * @data_size: Size specifier
 * Return: Number of chars printed
 */
int print_octal(va_list types, char con[],
	int flags, int width, int precision_value, int data_size)
{

	int b = CON_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = unsgnd_num(num, data_size);

	if (num == 0)
		con[b--] = '0';

	con[CON_SIZE - 1] = '\0';

	while (num > 0)
	{
		con[b--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		con[b--] = '0';

	b++;

	return (write_unsgnd(0, b, con, flags, width, precision_value, data_size));
}

/**
 * print_hexadecimal - Prints an unsigned number in hexadecimal notation
 * @types: List of arguments
 * @con: array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision_value: Precision specification
 * @data_size: Size specifier
 * Return: Number of chars printed
 */
int print_hexadecimal(va_list types, char con[],
	int flags, int width, int precision_value, int data_size)
{
	return (print_hexa(types, "0123456789abcdef", con,
		flags, 'x', width, precision_value, data_size));
}

/**
 * print_hexa_upper - Prints an unsigned number in upper hexadecimal notation
 * @types: List of arguments
 * @con: array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision_value: Precision specification
 * @data_size: Size specifier
 * Return: Number of chars printed
 */
int print_hexa_upper(va_list types, char con[],
	int flags, int width, int precision_value, int data_size)
{
	return (print_hexa(types, "0123456789ABCDEF", con,
		flags, 'X', width, precision_value, data_size));
}

/**
 * print_hexa - Prints a hexadecimal number in lower or upper
 * @types: List of arguments
 * @map_to: Array of values to map the number to
 * @con: array to handle print
 * @flags:  Calculates active flags
 * @flag_char: Calculates active flags
 * @width: get width
 * @precision_value: Precision specification
 * @data_size: Size specification
 * Return: Number of chars printed
 */
int print_hexa(va_list types, char map_to[], char con[],
	int flags, char flag_char, int width, int precision_value, int data_size)
{
	int i = CON_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = unsgnd_num(num, data_size);

	if (num == 0)
		con[i--] = '0';

	con[CON_SIZE - 1] = '\0';

	while (num > 0)
	{
		con[i--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		con[i--] = flag_char;
		con[i--] = '0';
	}

	i++;

	return (write_unsgnd(0, i, con, flags, width, precision_value, data_size));
}
