#include "main.h"
#include <stdarg.h>
#include <string.h>

/**
 * _print_char - function that prints a character
 * @args: argument to be printed
 * Return: num of printed char
 */

int _print_char(va_list args)
{
	return (_write(va_arg(args, int)));
}

/**
 * _print_string - print a string of characters
 * @args: the va_list containing the string to print
 *
 * Return: the number of characters printed
 */
int _print_string(va_list args)
{
	int count = 0;
	char *str = va_arg(args, char *);

	if (str == NULL)
	{
		str = "(null)";
	}
	while (*str)
	{
		count += _write(*str++);
	}
	return (count);
}

/**
 * _print_int - print an integer
 * @args: the va_list containing the integer to print
 *
 * Return: the number of characters printed
 */
int _print_int(va_list args)
{
	char buf[32];
	unsigned int n = va_arg(args, int);
	int i, m, ret;

	i = 0;
	m = 0;
	ret = 0;
	m = n;
	if (m < 0)
	{
		_write('-');
		m *= -1;
		n = (unsigned int)m;
		ret++;
	}
	else
	{
		n = m;
	}
	if (n == 0)
	{
		_write('0');
		return (1);
	}
	while (n > 0)
	{
		buf[i++] = (n % 10) + '0';
		n /= 10;
	}
	ret  += i;
	while (i > 0)
	{
		_write(buf[--i]);
	}
	return (ret);
}
