#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

void print_char(Write *params,va_list arg);
void print_string(Write *params,va_list arg);
void print_prcnt(Write *params,va_list arg);
void myprint(Write *params);
/**
 * myprint - is a function that prints a buffer to the std output
 * @params: is a pointer to struct
 * Return: void
 */
void myprint(Write *params) {   
        write(params->fd, params->buf, params->len);
}

/**
 * print_char - is a functiont that prints character based on a format
 * specifier %c
 * @params: pointer to struct
 * @arg: is the argument to be printed
 * Return: void
 */
void print_char(Write *params, va_list arg)
{
	char *buf = (char*)malloc(2 * sizeof(char));
	char ch = va_arg(arg, int);
	buf[0] = ch;
	buf[1] = '\0';
	params->buf = buf;
	params->len = 1;
	myprint(params);
	free(buf);
}

/**
 * print_string - is a function that prints a string based on a format
 * specifier %s
 * @params: pointer to struct
 * @arg: is the argument to be printed
 * Return: void
 */

void print_string (Write *params, va_list arg)
{
	char *str;
	str = va_arg(arg, char *);
	if (str == NULL)
	{
		str = "(null)";
		
	}
	params->buf = str;
	params->len = strlen(str);
	myprint(params);
}

/**
 * print_prcnt - function to print percentile
 * @params: is pointer to a struct
 * @arg: is the argument to be printed
 * Return: void
 */
void print_prcnt(Write *params, va_list arg __attribute__((unused)))
{
	char *buf = (char*)malloc(2 * sizeof(char));
	buf[0] = '%';
	buf[1] = '\0';
	params->buf = buf;
	params->len = 1;
	myprint(params);
	free(buf);
}




int print_f(const char *format, ...)
{
	int i, x, printed;
	va_list arg;
	_printer put[] = {
		{"c", print_char},
		{"s", print_string},
		{"%", print_prcnt},
		{NULL, NULL}
	};
	Write *params = malloc(sizeof(Write));
	params->fd = STDOUT_FILENO;
	params->buf = "";
	params->len = 0;

	i = 0;
	printed = 0;
	va_start(arg,format);
	while (format != NULL && format[i] != '\0')
	{
		if (format [i] == '%')
		{
			i++;
			x = 0;

			while (put[x].specifier != NULL)
			{
				if (format[i] == *(put[x].specifier))
				{
					put[x].funct(params,arg);
					printed++;
					break;
				}
				x++;
			}
		}
		else
		{
			params->buf = (char*)&format[i];
			params->len = 1;
			myprint(params);
			printed++;
		}
		i++;
	}
	va_end(arg);
	free(params);
	return (printed);
}
