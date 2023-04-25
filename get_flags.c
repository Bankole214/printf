#include "main.h"

/**
 * get_flags - Calculates active flags
 * @format: Formatted string in which to print the arguments
 * @a: parameter
 * Return: Flags
 */
int get_flags(const char *format, int *a)
{

	int b, pres_index;
	int flags = 0;
	const char FLAGS_CHAR[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARG[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (pres_index = *a + 1; format[pres_index] != '\0'; pres_index++)
	{
		for (b = 0; FLAGS_CHAR[b] != '\0'; b++)
			if (format[pres_index] == FLAGS_CHAR[b])
			{
				flags |= FLAGS_ARG[b];
				break;
			}

		if (FLAGS_CHAR[b] == 0)
			break;
	}

	*a = pres_index - 1;

	return (flags);
}
