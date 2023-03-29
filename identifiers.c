#include "main.h"

/**
 * _identify - is a function that select the correct function to call
 * @format: string pointer
 * Return: pointer to the function that corresponds to the operator given
 * as parameter
 */

int (*_identify(const char *format))(Write *, va_list)
{
	int i;
	_printer put[] = {
		{"c", print_char},
		{"s", print_string},
		{"%", print_prcnt},
		{NULL, NULL}
	};
	i = 0;

	while (put[i].specifier != NULL)
	{
		if (strcmp(put[i].specifier, format) == 0)
		{
			break;
		}
		i++;
	}
	return (put[i].funct);
}

