#include "main.h"
#include <string.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * print_char - is a functiont that prints character based on a format
 * specifier %c
 * @params: pointer to struct
 * @arg: is the argument to be printed
 * Return: void
 */
int print_char(Write *params, va_list arg)
{
	char ch;

	ch = va_arg(arg, int);
	params->buf = &ch;
	params->len = 1;
	myprint(params);
	return (1);
}

/**
 * print_string - is a function that prints a string based on a format
 * specifier %s
 * @params: pointer to struct
 * @arg: is the argument to be printed
 * Return: void
 */

int print_string(Write *params, va_list arg)
{
	char *str;
	int i;

	str = va_arg(arg, char*);
	i = 0;

	if (str != NULL)
	{
		int len = strlen(str);
		char *buf = malloc(len + 1);

		strcpy(buf, str);
		for (i = 0; i < len; i++)
		{
			params->buf = &buf[i];
			params->len = 1;
			myprint(params);
		}
		free(buf);
		return (i);
	}
	else
	{
		str = "(null)";
		params->buf = str;
		params->len = strlen(str);
		myprint(params);
		return (6);
	}
}


/**
 * print_prcnt - function to print percentile
 * @params: is pointer to a struct
 * @arg: is the argument to be printed
 * Return: void
 */

int print_prcnt(Write *params, va_list arg __attribute__((unused)))
{
	char c = '%';

	params->buf = &c;
	params->len = 1;
	myprint(params);
	return (1);
}
