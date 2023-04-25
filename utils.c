#include "main.h"

/**
 * printable_c - Evaluates if a char is printable
 * @ch: Character to be evaluated.
 *
 * Return: 1 if ch is printable, 0 otherwise
 */
int printable_c(char ch)

/*ASCII codes for printable characters are between 32 and 126*/
{
	if (ch >= 32 && ch < 127)
		return (1);

	return (0);
}

/**
 * append_hexa - Append ASCII in hexadecimal code to con
 * @con: Array of chars.
 * @a: Index at which to start appending.
 * @ascii_c: ASCII CODE.
 * Return: 3
 */
int append_hexa(char ascii_c, char con[], int a)
{
	char hex_map[] = "0123456789ABCDEF";

	/* The hexa format code is always 2 digits long */
	if (ascii_c < 0)
		ascii_c *= -1;

	con[a++] = '\\';
	con[a++] = 'x';

	con[a++] = hex_map[ascii_c / 16];
	con[a] = hex_map[ascii_c % 16];

	return (3);
}

/**
 * is_digit - Verifies if a char is a digit
 * @ch: Char
 *
 * Return: 1 if ch is a digit, 0 otherwise
 */
int is_digit(char ch)
{
	if (ch >= '0' && ch <= '9')
		return (1);

	return (0);
}

/**
 * convert_size_num - Casts a number to the specified size
 * @num_to_cast: Number to be casted.
 * @cast_size: Number indicating the type to be casted.
 *
 * Return: Casted value of num_to_cast
 */
long int convert_size_num(long int num_to_cast, int cast_size)
{
	if (cast_size == LON_G)
		return (num_to_cast);
	else if (cast_size == SHOR_T)
		return ((short)num_to_cast);

	return ((int)num_to_cast);
}

/**
 * convert_size - Casts a number to the specified size
 * @num_to_size: Number to be casted
 * @cast_size: Number indicating the type to be casted
 *
 * Return: Casted value of num_to_cast
 */
long int convert_size(unsigned long int num_to_cast, int cast_size)
{
	if (cast_size == LON_G)
		return (num_to_cast);

	else if (cast_size == SHOR_T)
		return ((unsigned short)num_to_cast);

	return ((unsigned int)num_to_cast);
}
