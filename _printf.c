#include "main.h"
#include <stdarg.h>

/**
 * _printf - is a function that prints a string
 * @format: is the format the string is going to be
 * printed in
 * Return: numbers of printed characters
 */

int _printf(const char *format, ...)
{
	va_list arg;
	int ret;

	if (!format)
	{
		return (-1);
	}
	va_start(arg, format);
	ret = _print(format, arg);
	va_end(arg);

	return (ret);
}
