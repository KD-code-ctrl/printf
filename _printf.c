#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * _printf - is a function that prints a string
 * @format: is the format the string is going to be
 * printed in
 * Return: numbers of printed characters
 */

int _printf(const char *format, ...)
{
	int i, printed;
	va_list arg;
	int (*print_func)(Write *, va_list);
	Write *params = malloc(sizeof(Write));

	i = 0;
	printed = 0;
	va_start(arg, format);
	while (format != NULL && format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			print_func = _identify(&format[i]);

			if (print_func != NULL)
			{
				printed += print_func(params, arg);
			}
			else
			{
				params->buf = (char *)&format[i - 1];
				params->len = 2;
				myprint(params);
				printed++;
			}
			while (format[i] && format[i] != '%')
			{
				i++;
			}
		}
		else
		{
			params->buf = (char *)&format[i];
			params->len = 1;
			myprint(params);
			printed++;
		}
		i++;
	}
	va_end(arg);
	free (params->buf);
	free(params);
	return (printed);
}
