#include <unistd.h>
#include <stdarg.h>

void    put_string(char *s,int *len)
{
    if(!s)
    s = "(null)";
    while(*s)
    *len = *len + write(1,s++,1);
}
void   put_num(long long int n,int base ,int *len)
{
    char *hexa = "0123456789abcdef";
    if(n < 0)
    {
        n = n*-1;
        *len = *len + write(1,"-",1);
    }
    if(n >= base)
    put_num((n/base),base,len);
    *len = *len + write(1,&hexa[n % base],1);
}
int ft_printf(const char *format, ...)
{
    int len = 0;
    va_list arg;
    va_start(arg,format);
    while(*format)
    {
        if((*format == '%') &&  ((*(format + 1) == 's') || (*(format + 1)=='d') || (*(format + 1) == 'x')))
        {
                format++;
                if(*format == 's')
                put_string(va_arg(arg, char*),&len);
                else if(*format == 'd')
                put_num((long long int)va_arg(arg,int),10,&len);
                else if(*format == 'x')
                put_num((long long int)va_arg(arg,unsigned int),16,&len);
        }
        else
        len = len + write(1,format,1);
        format++;
    }
    return(va_end(arg),len);
}

