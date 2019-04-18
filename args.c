#include <stdio.h>
#include <stdarg.h>

void foo(char *fmt, ...)
{
        va_list ap;
        int d;
        char c, *s;

        va_start(ap, fmt);
        while(*fmt) {
                switch(*fmt++) {
                case 's':
                        s = va_arg(ap, char *);
                        printf("string %s\n", s);
                        break;
                case 'd':
                        d = va_arg(ap, int);    
                        printf("int %d\n", d);
                        break;
                case 'c':
                        c = va_arg(ap, int);
                        printf("char %c\n", c);
                        break;
                }
        }
}

int main(int argc, char *argv[])
{
        foo("%d %s %c", 23, "hello", 'z');
        return 0;
}
