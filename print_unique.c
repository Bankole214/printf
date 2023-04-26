#include "main.h"

/**
 * print_nonC - Non printable characters
 * @list: list of arguments from _printf
 * @p: pointer to the struct flags
 * Return: number of char printed
 */
int print_nonC(va_list list, flags_typ *p)
{
	int a, counter = 0;
	char *res;
	char *s = va_arg(list, char *);

	(void)p;
	if (!s)
		return (_puts("(null)"));

	for (a = 0; s[a]; a++)
	{
		if (s[a] > 0 && (s[a] < 32 || s[a] >= 127))
		{
			_puts("\\x");
			counter +=  2;
			res = convert(s[a], 16, 0);
			if (!res[1])
				counter = counter + _putchar('0');
			counter = counter + _puts(res);
		}
		else
			counter = counter + _putchar(s[a]);
	}
	return (counter);
}

/**
 * print_reverse - prints a string in reverse
 * @list: list of argument from _printf
 * @p: pointer to the struct flags that determines
 * Return: length of the printed string
 */
int print_reverse(va_list list, flags_typ *p)
{
	int a = 0, b;
	char *s = va_arg(list, char *);

	(void)p;
	if (!s)
		s = "(null)";

	while (s[a])
		a++;

	for (b = a - 1; b >= 0; b--)
		_putchar(s[b]);

	return (a);
}

/**
 * print_rot13string - prints a string using rot13
 * @list: list of arguments from _printf
 * @p: pointer to the struct flags
 * Return: length of the printed string
 */
int print_rot13string(va_list list, flags_typ *p)
{
	int a, b;
	char rot13[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char ROT13[] = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
	char *s = va_arg(list, char *);

	(void)p;
	for (b = 0; s[b]; b++)
	{
		if (s[b] < 'A' || (s[b] > 'Z' && s[b] < 'a') || s[b] > 'z')
			_putchar(s[b]);
		else
		{
			for (a = 0; a <= 52; a++)
			{
				if (s[b] == rot13[a])
					_putchar(ROT13[a]);
			}
		}
	}

	return (b);
}

/**
 * print_percent - prints a percent
 * @list: list arguments from _printf
 * @p: pointer to the struct flags in which we turn the flags on
 * Return: number of char printed
 */
int print_percent(va_list list, flags_typ *p)
{
	(void)list;
	(void)p;
	return (_putchar('%'));
}
