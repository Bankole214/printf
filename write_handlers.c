#include "main.h"
/**
 * handle_write_char - Prints a string
 * @ch: char types.
 * @con: array to handle print
 * @flags: Calculates active flags.
 * @width: width.
 * @precision_value: precision
 * @cast_size: Size
 * Return: Number of ch printed.
 */
int handle_write_char(char ch, char con[],
	int flags, int width, int precision_value, int cast_size)
{
	int a = 0;
	char padding_char = ' ';

	UNUSED(precision_value);
	UNUSED(cast_size);
	if (flags & F_ZERO)
		padding_char = '0';
	con[a++] = c;
	con[a] = '\0';
	if (width > 1)
	{
		con[CON_SIZE - 1] = '\0';
		for (a = 0; a < width - 1; a++)
			con[CON_SIZE - a - 2] = padding_char;
		if (flags & F_MINUS)
			return (write(1, &con[0], 1) +
					write(1, &con[CON_SIZE - a - 1], width - 1));
		else
			return (write(1, &con[CON_SIZE - a - 1], width - 1) +
					write(1, &con[0], 1));
	}
	return (write(1, &con[0], 1));
}
/**
 * write_number - Prints a string
 * @its_negative: List of arguments
 * @index: char types
 * @con: array to handle print
 * @flags: Calculates active flags
 * @width: get width.
 * @precision_value: precision specifier
 * @cast_size: Size specifier
 * Return: Number of ch printed.
 */
int write_number(int its_negative, int index, char con[],
	int flags, int width, int precision_value, int cast_size)
{
	int len = CON_SIZE - index - 1;
	char padding_char = ' ', extra_ch = 0;

	UNUSED(cast_size);
	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padding_char = '0';
	if (its_negative)
		extra_ch = '-';
	else if (flags & F_PLUS)
		extra_ch = '+';
	else if (flags & F_SPACE)
		extra_ch = ' ';
	return (write_num(index, buffer, flags, width, precision_value,
		length, padding_char, extra_ch));
}
/**
 * write_num - Write a number
 * @index: Index
 * @con: container
 * @flags: Flags
 * @width: width
 * @precision: Precision specifier
 * @len: length
 * @padding_char: Padding char
 * @extra_char: Extra character
 * Return: Number of printed chars.
 */
int write_num(int index, char con[],
	int flags, int width, int precision,
	int len, char padding_char, char extra_char)
{
	int a, start_padding = 1;

	if (precision == 0 && index == CON_SIZE - 2 &&
			con[index] == '0' && width == 0)
		return (0);
	if (precision == 0 && index == CON_SIZE - 2 && con[index] == '0')
		con[index] = padding_char = ' ';
	if (precision > 0 && precision < len)
		padding_char = ' ';
	while (precision > len)
		con[--index] = '0', len++;
	if (extra_char != 0)
		len++;
	if (width > len)
	{
		for (a = 1; a < width - len + 1; a++)
			con[a] = padding_char;
	 con[a] = '\0';
	if (flags & F_MINUS && padding_char == ' ')
{
		if (extra_char)
			con[--index] = extra_char;
	return (write(1, &con[index], len) + write(1, &con[1], a - 1));
}
	else if (!(flags & F_MINUS) && padding_char == ' ')
	{
		if (extra_char)
			con[--index] = extra_char;
	return (write(1, &con[1], a - 1) + write(1, &con[index], len));
	}
	else if (!(flags & F_MINUS) && padding_char == '0')
	{
		if (extra_char)
			con[--start_padding] = extra_char;
	return (write(1, &con[start_padding], a - start_padding) +
		write(1, &con[index], len - (1 - start_padding)));
	}
}
	if (extra_char)
	con[--index] = extra_char;
	return (write(1, &con[index], len));
}

/**
 * unsgnd_num - Writes an unsigned number
 * @its_negative: Number indicating if the number is negative
 * @index: Index at which the number starts in the container
 * @con: Array of chars
 * @flags: Flags specifiers
 * @width: Width value
 * @precision_value: Precision
 * @cast_size: Size specifier
 * Return: Number of written chars.
 */
int unsgnd_num(int its_negative, int index,
	char con[], int flags, int width, int precision_value, int cast_size)
{
	int len = CON_SIZE - index - 1, a = 0;
	char padding_char = ' ';

	UNUSED(its_negative);
	UNUSED(cast_size);
	if (precision_value == 0 && index == CON_SIZE - 2 && con[index] == '0')
		return (0);
	if (precision_value > 0 && precision_value < len)
		padding_char = ' ';
	while (precision_value > len)
	{
		con[--index] = '0';
		len++;
	}
	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padding_char = '0';
	if (width > len)
	{
		for (a = 0; a < width - len; a++)
			con[a] = padding_char;
		con[a] = '\0';
		if (flags & F_MINUS)
		{
			return (write(1, &con[index], len) + write(1, &con[0], a));
		}
		else
		{
			return (write(1, &con[0], a) + write(1, &con[index], len));
		}
	}
	return (write(1, &con[index], len));
}
/**
 * write_pointer - Write a memory address
 * @con: Arrays of chars
 * @index: Index at which the number starts
 * @len: Length
 * @width: Width specifier
 * @flags: Flags specifier
 * @padding_char: Char representing the padding
 * @extra_char: Char representing extra char
 * @start_padding: where the padding should start
 * Return: Number of written chars.
 */
int write_pointer(char con[], int index, int len,
	int width, int flags, char padding_char, char extra_char, int start_padding)
{
	int a;

	if (width > len)
	{
		for (a = 3; a < width - len + 3; a++)
			con[a] = padding_char;
		con[a] = '\0';
		if (flags & F_MINUS && padding_char == ' ')
		{
			con[--index] = 'x';
			con[--index] = '0';
			if (extra_char)
				con[--index] = extra_char;
			return (write(1, &con[index], len) + write(1, &con[3], a - 3));
		}
		else if (!(flags & F_MINUS) && padding_char == ' ')
		{
			con[--index] = 'x';
			con[--index] = '0';
			if (extra_char)
				con[--index] = extra_char;
			return (write(1, &con[3], a - 3) + write(1, &con[index], len));
		}
		else if (!(flags & F_MINUS) && padding_char == '0')
		{
			if (extra_char)
				con[--start_padding] = extra_char;
			con[1] = '0';
			con[2] = 'x';
			return (write(1, &con[start_padding], a - start_padding) +
					write(1, &con[index], len - (1 - start_padding) - 2));
		}
	}
	con[--index] = 'x';
	con[--index] = '0';
	if (extra_char)
		con[--index] = extra_char;
	return (write(1, &con[index], CON_SIZE - index - 1));
}
