#include "main.h"

/**
 * get_size - a function that calculates the size
 * @format: a pointer to a formatted string
 * @a: determines the size of the argument
 * based on the format string
 *
 * Return: The size of the argument
 */
int get_size(const char *format, int *a)
{
	/*Get the next index of the format string*/
	int pres_index = *a + 1;
	int cast_size = 0;

/*Check if the format string has a 'l'*/
	if (format[pres_index] == 'l')
		cast_size = LON_G;

/*Check if the format string has a 'h'*/
	else if (format[pres_index] == 'h')
		cast_size = SHOR_T;

/*If there is no size,set the index to the previous value*/
	if (cast_size == 0)
		*a = pres_index - 1;
	else
		*a = pres_index;

 /*Return the size of the argument*/
	return (cast_size);
}
