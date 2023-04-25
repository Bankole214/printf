#include "main.h"

/************************* PRINT UNSIGNED NUMBER *************************/
/**
 * print_unsigned - Prints an unsigned number
 * @types: List a of arguments
 * @con: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed.
 */
int print_unsigned(va_list types, char con[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		con[i--] = '0';

	con[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		con[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_unsgnd(0, i, con, flags, width, precision, size));
}

/************* PRINT UNSIGNED NUMBER IN OCTAL  ****************/
/**
 * print_octal - Prints an unsigned number in octal notation
 * @types: Lista of arguments
 * @con: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_octal(va_list types, char con[],
	int flags, int width, int precision, int size)
{

	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		con[i--] = '0';

	con[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		con[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		con[i--] = '0';

	i++;

	return (write_unsgnd(0, i, con, flags, width, precision, size));
}

/************** PRINT UNSIGNED NUMBER IN HEXADECIMAL **************/
/**
 * print_hexadecimal - Prints an unsigned number in hexadecimal notation
 * @types: Lista of arguments
 * @con: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_hexadecimal(va_list types, char con[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", con,
		flags, 'x', width, precision, size));
}

/************* PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL **************/
/**
 * print_hexa_upper - Prints an unsigned number in upper hexadecimal notation
 * @types: Lista of arguments
 * @con: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_hexa_upper(va_list types, char con[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", con,
		flags, 'X', width, precision, size));
}

/************** PRINT HEXX NUM IN LOWER OR UPPER **************/
/**
 * print_hexa - Prints a hexadecimal number in lower or upper
 * @types: Lista of arguments
 * @map_to: Array of values to map the number to
 * @con: Buffer array to handle print
 * @flags:  Calculates active flags
 * @flag_ch: Calculates active flags
 * @width: get width
<<<<<<< HEAD
 * @prec: Precision specification
=======
 * @precision: Precision specification
>>>>>>> 68dd29217d3c685270342031e676058d62328c87
 * @size: Size specifier
 * @size: Size specification
 * Return: Number of chars printed
 */
<<<<<<< HEAD
int print_hexa(va_list types, char hex_map[], char con[],
	int flags, char flag_char, int width, int prec, int size)
/*
 * @precision_value: Precision specification
 * @data_size: Size specification
 * Return: Number of chars printed
 */
int print_hexa(va_list types, char map_to[], char con[],
	int flags, char flag_char, int width, int precision_value, int data_size)

=======
int print_hexa(va_list types, char map_to[], char con[],
	int flags, char flag_ch, int width, int precision, int size)
>>>>>>> 68dd29217d3c685270342031e676058d62328c87
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		con[i--] = '0';

	con[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		con[i--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		con[i--] = flag_ch;
		con[i--] = '0';
	}

	i++;

<<<<<<< HEAD
	return (write_unsgnd(0, i, con, flags, width, prec, size));
	return (write_unsgnd(0, i, con, flags, width, precision_value, data_size));

=======
	return (write_unsgnd(0, i, con, flags, width, precision, size));
>>>>>>> 68dd29217d3c685270342031e676058d62328c87
}

