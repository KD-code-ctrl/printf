#include "main.h"
#include <unistd.h>

/**
 * _write - is a function that write to the standard ouput
 * @c: character to be printed
 * Return: 1 if successful
 */
int _write(char c)
{
	return (write(1, &c, 1) == 1 ? 1  : -1);
}
