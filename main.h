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
        int (*funct)(Write *, va_list arg);
}_printer;

int (*_identify(const char *format))(Write *, va_list);
int _printf(const char *format, ...);
int print_char(Write *params, va_list arg);
int print_string(Write *params, va_list arg);
int print_prcnt(Write *params, va_list arg);
void myprint(Write *params);

#endif
