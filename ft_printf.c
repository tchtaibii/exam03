#include <unistd.h>
#include <stdarg.h>

int ft_putchar(char c)
{
    write(1, &c, 1);
    return (1);
}

int ft_putstr(char  *str)
{
    int i = -1;

    if (!str)
        return (ft_putstr("(null)"));
    while (str[++i])
        ft_putchar(str[i]);
    return i;
}

int ft_putnbr(int n)
{
    int c = 0;

    if (n == -2147483648)
        return (ft_putstr("-2147483648"));
    if (n < 0)
    {
        c += ft_putchar('-');
        n *= -1;
    }
    if (n >= 10)
    {
        c += ft_putnbr(n / 10);
        c += ft_putnbr(n % 10);
    }
    else
        c =+ ft_putchar(n + 48);
    return c;
}

int ft_puthex(unsigned int n)
{
    int c = 0;
    char hex[] = "0123456789abcdef"
    if (n >= 10)
    {
        c += ft_puthex(n / 10);
        c += ft_puthex(n % 10);
    }
    else
        c += ft_putchar(hex[n]);
}

int ft_printf(const char *str, ...)
{
    int k = 0;;
    int i = 0;
    va_list va;

    va_start(va, str);
    while (str[i])
    {
        if (str[i] == '%')
        {
            i++;
            if (str[i] == 'd')
                k += ft_putnbr(va_arg(va, int));
            else if (str[i] == 's')
                k += ft_putstr(va_arg(va, char *));
            else if (str[i] == 'x')
                k += ft_puthex(va_arg(va, unsigned int));
        }
        else
            k += ft_putchar(str[i]);
        i++;
    }
    va_end(va);
    
}