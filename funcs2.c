#include "main.h"
int print_rev(va_list types, char con[],
	int flags, int width, int precision_value, int data_size);
int print_rot13string(va_list types, char con[],
	int flags, int width, int precision_value, int data_size);

/**
 * print_pointer - Prints the value of a pointer variable
 * @types: List of arguments
 * @con: array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision_value: Precision specification
 * @data_size: Size specifier
 * Return: Number of chars printed.
 */
int print_pointer(va_list types, char con[],
	int flags, int width, int precision_value, int data_size)
{
	char extra_char = 0, padding_char = ' ';
	int index = CON_SIZE - 2, len = 2, start_padding = 1; /* len=2, for '0x' */
	unsigned long num_addrs;
	char point_map[] = "0123456789abcdef";
	void *addrs = va_arg(types, void *);

	UNUSED(width);
	UNUSED(data_size);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	con[CON_SIZE - 1] = '\0';
	UNUSED(precision_value);

	num_addrs = (unsigned long)addrs;

	while (num_addrs > 0)
	{
		con[index--] = point_map[num_addrs % 16];
		num_addrs /= 16;
		len++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padding_char = '0';
	if (flags & F_PLUS)
		extra_char = '+', len++;
	else if (flags & F_SPACE)
		extra_char = ' ', len++;

	index++;

	return (write_pointer(con, index, len,
		width, flags, padding_char, extra_char, start_padding));
}
/**
 * print_non_printable - Prints ascii codes in hexa of non printable chars
 * @types: List of arguments
 * @con: array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision_value: Precision specification
 * @data_size: Size specifier
 * Return: Number of chars printed
 */
int print_non_printable(va_list types, char con[],
	int flags, int width, int precision_value, int data_size)
{
	int j = 0, count = 0;
	char *str = va_arg(types, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision_value);
	UNUSED(data_size);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[j] != '\0')
	{
		if (is_printable(str[j]))
			con[j + count] = str[j];
		else
			count = count + append_hexa(str[j], con, j + count);

		j++;
	}

	con[j + count] = '\0';

	return (write(1, con, j + count));
}

/**
 * print_rev - Prints reverse string.
 * @types: List of arguments
 * @con: array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision_value: Precision specification
 * @data_size: Size specifier
 * Return: Numbers of chars printed
 */

int print_rev(va_list types, char con[],
	int flags, int width, int precision_value, int data_size)
{
	char *str;
	int a, count = 0;

	UNUSED(con);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(data_size);

	str = va_arg(types, char *);

	if (str == NULL)
	{
		UNUSED(precision_value);

		str = ")Null(";
	}
	for (a = 0; str[a]; a++)
		;

	for (a = a - 1; a >= 0; a--)
	{
		char z = str[a];

		write(1, &z, 1);
		count++;
	}
	return (count);
}
/**
 * print_rot13 - Print a string in rot13.
 * @types: List of arguments
 * @con: array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision_value: Precision specification
 * @data_size: Size specifier
 * Return: Numbers of chars printed
 */
int print_rot13(va_list types, char con[],
	int flags, int width, int precision_value, int data_size)
{
	char i;
	char *str;
	unsigned int a, b;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(types, char *);
	UNUSED(con);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision_value);
	UNUSED(data_size);

	if (str == NULL)
		str = "(AHYY)";
	for (a = 0; str[a]; a++)
	{
		for (b = 0; in[b]; b++)
		{
			if (in[b] == str[a])
			{
				i = out[b];
				write(1, &i, 1);
				count++;
				break;
			}
		}
		if (!in[b])
		{
			i = str[a];
			write(1, &x, 1);
			count++;
		}
	}
	return (count);
}
