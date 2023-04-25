#include "main.h"
/**
 * print_char - Prints a char
 * @types: List a of arguments
 * @con: array to handle print
 * @flags:  Calculates active flags
 * @width: Width
 * @precision_value: Precision specification
 * @data_size: Size specifier
 * Return: Number of chars printed
 */
int print_char(va_list types, char con[],
	int flags, int width, int precision_value, int data_size)
{
	char c = va_arg(types, int);

	return (handle_write_char(c, con, flags, width, precision_value, data_size));
}
/**
 * print_string - Prints a string
 * @types: List a of arguments
 * @con: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision_value: Precision specification
 * @data_size: Size specifier
 * Return: Number of chars printed
 */
int print_string(va_list types, char con[],
	int flags, int width, int precision_value, int data_size)
{
	int len = 0, a;
	char *str = va_arg(types, char *);

	UNUSED(con);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision_value);
	UNUSED(data_size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision_value_value >= 6)
			str = "      ";
	}

	while (str[len] != '\0')
		len++;

	if (precision_value >= 0 && precision_value < len)
		len = precision_value;

	if (width > len)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], len);
			for (a = width - len; a > 0; a--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (a = width - len; a > 0; a--)
				write(1, " ", 1);
			write(1, &str[0], len);
			return (width);
		}
	}

	return (write(1, str, len));
}
/**
 * print_percent - Prints a percent sign
 * @types: List of arguments
 * @con: array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision_value: Precision specification
 * @data_size: Size specifier
 * Return: Number of chars printed
 */
int print_percent(va_list types, char con[],
	int flags, int width, int precision_value, int data_size)
{
	UNUSED(types);
	UNUSED(con);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision_value);
	UNUSED(data_size);
	return (write(1, "%%", 1));
}
/**
 * print_int - Print int
 * @types: Lista of arguments
 * @con: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision_value: Precision specification
 * @data_size: Size specifier
 * Return: Number of chars printed
 */
int print_int(va_list types, char con[],
	int flags, int width, int precision_value, int data_size)
{
	int a = CON_SIZE - 2;
	int its_negative = 0;
	long int n = va_arg(types, long int);
	unsigned long int num;

	n = convert_size_number(n, data_size);

	if (n == 0)
		con[a--] = '0';

	con[CON_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		its_negative = 1;
	}

	while (num > 0)
	{
		con[a--] = (num % 10) + '0';
		num /= 10;
	}

	a++;

	return (write_number(its_negative, a, con, flags,
				width, precision_value, data_size));
}

/**
 * print_binary - Prints an unsigned number
 * @types: Lista of arguments
 * @con: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision_value: Precision specification
 * @data_size: Size specifier
 * Return: Numbers of char printed.
 */
int print_binary(va_list types, char con[],
	int flags, int width, int precision_value, int data_size)
{
	/*declaring and initializing variables*/
	unsigned int num, mask, a, sum;
	unsigned int binary_digits[32];
	int count;

/*ignore unused parameters*/
	UNUSED(con);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision_value);
	UNUSED(data_size);

/*retrieve arguement from argument list*/
	num = va_arg(types, unsigned int);

	/*convert decimal to binary using repeated division*/
	mask = 2147483648; /* (2 ^ 31) */
	binary_digits[0] = num / mask;
	for (a = 1; a < 32; a++)
	{
		mask /= 2;
		binary_digits[a] = (num / mask) % 2;
	}
	/*output the binary digits*/
	for (a = 0, sum = 0, count = 0; a < 32; a++)
	{
		sum = sum + binary_digits[a];
		if (sum || a == 31)
		{
			char char_digit = '0' + binary_digits[a];

			write(1, &char_digit, 1);
			count++;
		}
	}
	/*return the number of binary digits output*/
	return (count);
}

