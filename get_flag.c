#include "main.h"

/**
 * get_flag_on - turns on flags if _printf finds
 * a flag modifier in the format string
 * @s: character that holds the flag specifier
 * @p: pointer to the struct flags in which we turn the flags on
 *
 * Return: 1 if a flag has been turned on, 0 otherwise
 */
int get_flag_on(char s, flags_typ *p)
{
	int a = 0;

	switch (s)
	{
		case '+':
			p->plus = 1;
			a = 1;
			break;
		case ' ':
			p->space = 1;
			a = 1;
			break;
		case '#':
			p->hash = 1;
			a = 1;
			break;
	}

	return (a);
}
