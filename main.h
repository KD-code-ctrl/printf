#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <string.h>


typedef struct {
    int fd;
    char *buf;
    size_t len;
}Write;



typedef struct print
{
        char *specifier;
        void (*funct)(Write *, va_list arg);
}_printer;

int print_f(const char *format, ...);

#endif
