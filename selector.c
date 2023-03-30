#include "main.h"
#include <stdarg.h>
#include <string.h>

/**
 * _identify - is a functiont that return pointer to func
 * @specifier: is a formated string
 * @args: is argument to be parsed
 * Return: pointer to func
 */

int _identify(char specifier, va_list args)
{
	int ret = 0;
	int i;
	_printer put[] = {
		{"c", _print_char},
		{"s", _print_string},
		{"i", _print_int},
		{"d", _print_int},
		{NULL, NULL}
	};
	i = 0;
	while (put[i].specifier != NULL)
	{
		if (put[i].specifier[0] ==  specifier)
		{
			ret = put[i].funct(args);
			break;
		}
		i++;
	}
	return (ret);
}

/**
 * _print - is a  function that determines what to print
 * @format: is the format of the character to be printed
 * @args: is the character to be printed
 * Return: number of printed characters
 */
int _print(const char *format, va_list args)
{
	int printed = 0;

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
			{
				return (-1);
			}
			while (*format == ' ')
			{
				format++;
			}
			if (*format == '%')
			{
				printed	+= _write(*format);
			}
			else if (_validate_char(*format) == 0)
			{
				printed = _print_invalid_spec(format[-1], *format, printed);
			}
			else
			{
				printed += _identify(*format, args);
			}
		}
		else
		{
			printed += _write(*format);
		}
		format++;
	}
	return (printed);
}

/**
 * _print_invalid_spec - handle an invalid format specifier
 * @prev: the previous character in the format string
 * @c: the invalid specifier character
 * @count: the current count of printed characters
 *
 * Return: the updated count of printed characters
 */
int _print_invalid_spec(char prev, char c, int count)
{
	if (prev == '%')
	{
		_write('%');
		count++;
	}
	_write(c);
	count++;
	return (count);
}

/**
 * _validate_char - validate a format specifier character
 * @c: the character to validate
 *
 * Return: 1 if valid, 0 if invalid
 */
int _validate_char(char c)
{
	char *valid_chars = "cdisu";

	while (*valid_chars)
	{
		if (c == *valid_chars++)
		return (1);
	}
	return (0);
}

