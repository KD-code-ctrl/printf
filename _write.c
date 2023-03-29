#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * myprint - is a function that prints a buffer to the std output
 * @params: is a pointer to struct
 * Return: void
 */

void myprint(Write *params)
{
	params->fd = STDOUT_FILENO;
	params->buf = NULL;
	params->len = 0;
	write(params->fd, params->buf, params->len);
}
