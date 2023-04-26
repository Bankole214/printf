#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdarg.h>

/**
 * struct flags - struct containing flags
 * when a flag specifier is passed to _printf()
 * @plus: flag for the '+' character
 * @space: flag for the ' ' character
 * @hash: flag for the '#' character
 */
typedef struct flags
{
	int plus;
	int space;
	int hash;
} flags_typ;

/**
 * struct printHandler - struct to choose the right function
 * on the format specifier passed to _printf()
 * @c: format specifier
 * @p: pointer to the correct printing function
 */
typedef struct printHandler
{
	char c;
	int (*p)(va_list ap, flags_typ *p);
} ph;

/* print_nums */
int print_int(va_list list, flags_typ *p);
void print_number(int b);
int print_unsigned(va_list list, flags_typ *p);
int count_digit(int a);

/* print_bases */
int print_hex(va_list list, flags_typ *p);
int print_hex_upper(va_list list, flags_typ *p);
int print_binary(va_list list, flags_typ *p);
int print_octal(va_list list, flags_typ *p);

/* converter */
   char *convert(unsigned long int num, int base, int lowercase);


/* _printf */
int _printf(const char *format, ...);

/* get_print */
int (*get_print(char s))(va_list, flags_typ *);

/* get_flag */
int get_flag_on(char s, flags_typ *p);

/* print_alphabet */
int print_string(va_list list, flags_typ *p);
int print_char(va_list list, flags_typ *p);

/* write_funcs */
int _putchar(char c);
int _puts(char *str);

/* print_custom */
int print_rot13string(va_list list, flags_typ *p);
int print_reverse(va_list list, flags_typ *p);
int print_nonC(va_list list, flags_typ *p);


/* print_address */
int print_address(va_list list, flags_typ *p);

/* print_percent */
int print_percent(va_list list, flags_typ *p);

#endif
