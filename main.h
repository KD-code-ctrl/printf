#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stddef.h>

/**
 * struct symbols - is a structure
 * @specifier: To determine what format should be printed
 * @funct: is a pointer to function
 */
typedef struct symbols
{
	char *specifier;
	int (*funct)(va_list arg);
}_printer;



int _identify(char specifier, va_list args);
int _print(const char *format, va_list args);
int _print_char(va_list args);
int _print_string(va_list args);
int _print_int(va_list args);
int _print_invalid_spec(char prev, char c, int count);
int _validate_char(char c);
int _write(char c);
int _printf(const char *format, ...);

#endif
