#include "main.h"

/**
 * get_print - selects the right printing function
 * depending on the conversion specifier passed to _printf
 * @s: character that holds the conversion specifier
 * Description: the function loops through the structs array
 * func_arr[] to find a match between the specifier passed to _printf
 * and the first element of the struct, and then the approriate
 * printing function
 * Return: a pointer to the matching printing function
 */
int (*get_print(char s))(va_list, flags_type *)
{
	ph func_arr[] = {
		{'i', print_int},
		{'s', print_string},
		{'c', print_char},
		{'d', print_int},
		{'u', print_unsigned},
		{'x', print_hex},
		{'X', print_hex_upper},
		{'b', print_binary},
		{'o', print_octal},
		{'R', print_rot13string},
		{'r', print_reverse},
		{'S', print_upperS},
		{'p', print_address},
		{'%', print_percent}
		};
	int flags = 14;

	register int a;

	for (a = 0; a < flags; a++)
		if (func_arr[a].c == s)
			return (func_arr[a].f);
	return (NULL);
}
