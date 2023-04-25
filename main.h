#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define CON_SIZE 1024

/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* SIZES */
#define LON_G 2
#define SHOR_T 1

/**
 * struct fmt - Struct op
 *
 * @fmt_s: The format.
 * @fn: The function associated.
 */
struct fmt_s
{
	char fmt_s;
	int (*fn)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct fmt_s fmt_t - Struct op
 *
 * @fmt_s: The format.
 * @fmt_t: The function associated.
 */
typedef struct fmt_s fmt_t;

int _printf(const char *format, ...);
int handle_print(const char *fmt_s, int *p,
va_list list, char con[], int flags, int width, int precision_value, int data_size);

/*FUNCTIONS*/

/* Funtions to print chars and strings */
int print_char(va_list types, char con[],
	int flags, int width, int precision_value, int data_size);
int print_string(va_list types, char con[],
	int flags, int width, int precision_value, int data_size);
int print_percent(va_list types, char con[],
	int flags, int width, int precision_value, int data_size);

/* Functions to print numbers */
int print_int(va_list types, char con[],
	int flags, int width, int precision_value, int data_size);
int print_binary(va_list types, char con[],
	int flags, int width, int precision_value, int data_size);
int print_unsigned(va_list types, char con[],
	int flags, int width, int precision_value, int data_size);
int print_octal(va_list types, char con[],
	int flags, int width, int precision_value, int data_size);
int print_hexadecimal(va_list types, char con[],
	int flags, int width, int precision_value, int data_size);
int print_hexa_upper(va_list types, char con[],
	int flags, int width, int precision_value, int data_size);

int print_hexa(va_list types, char hex_map[],
char con[], int flags, char flag_ch, int width, int precision_value, int data_size);

/* Function to print non printable characters */
int print_non_printable(va_list types, char con[],
	int flags, int width, int precision_value, int data_size);

/* Funcion to print memory address */
int print_pointer(va_list types, char con[],
	int flags, int width, int precision_value, int data_size);

/* Functions to handle other specifiers */
int get_flags(const char *format, int *a);
int get_width(const char *format, int *a, va_list list);
int get_precision_value(const char *format, int *a, va_list list);
int get_size(const char *format, int *a);

/*Function to print string in reverse*/
int print_reverse(va_list types, char con[],
	int flags, int width, int precision_value, int data_size);

/*Function to print a string in rot 13*/
int print_rot13(va_list types, char con[],
	int flags, int width, int precision_value, int data_size);

/* width handler */
int handle_write_char(char ch, char con[],
	int flags, int width, int precision_value, int data_size);
int write_number(int its_positive, int index, char con[],
	int flags, int width, int precision_value, int data_size);
int write_num(int index, char bff[], int flags, int width, int precision_value,
	int len, char padding_char, char extra_char);
int write_pointer(char con[], int index, int len,
	int width, int flags, char padding_char, char extra_char, int start_padding);

int unsgnd_num(int its_negative, int index,char con[],
	int flags, int width, int precision_value, int data_size);

/* UTILS.c */
int printable_c(char);
int append_hexa(char, char[], int);
int is_digit(char);

long int convert_size_num(long int num_to_cast, int data_size);
long int convert_size(unsigned long int num_to_cast int data_size);

#endif
