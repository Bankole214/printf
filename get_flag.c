#include "main.h"

/**
 * get_flag - turns on flags if _printf finds
 * a flag modifier in the format string
 * @s: character that holds the flag
 * @f: pointer to the struct flags
 *
 * Return: 1 if a flag has been turned on, 0 otherwise
 */
int get_flag(char s, flags_type *f)
{
	int a = 0;

	switch (s)
	{
		case '+':
			f -> plus = 1;
			a = 1;
			break;
		case ' ':
			f -> space = 1;
			a = 1;
			break;
		case '#':
			f -> hash = 1;
			a = 1;
			break;
	}

	return (a);
}
