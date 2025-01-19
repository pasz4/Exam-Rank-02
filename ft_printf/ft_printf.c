#include <stdarg.h>
#include <unistd.h>

static void ft_put_string(char *str, int *len)
{
 int i = 0;
 if (!str)
  str = "(null)";
 while (str[i])
 {
  *len += write(1, &str[i], 1);
  i++;
 }
}

static void ft_put_digit(long long int num, int base, int *len)
{
 if (num < 0)
 {
  num = num * -1;
  *len += write(1, "-", 1);
 }
 if (num >= base)
  put_digit((num / base), base, len);
 *len += write(1, &"0123456789abcdef"[num % base], 1);
}

int ft_printf(const char *fmt, ...) /* You can find all this function in the manual. "man va_arg", "man 2 va_arg", "man 3 va_arg" */
{
 va_list ptr;
 int i = 0;
 int len = 0;
 va_start(ptr, fmt);
 while (fmt[i])
 {
  if ((fmt[i] == '%') && ((fmt[i + 1] == 's') || (fmt[i + 1] == 'd') || (fmt[i + 1] == 'x')))
  {
   i++;
   if (fmt[i] == 's')
    put_string(va_arg(ptr, char *), &len);
   else if (fmt[i] == 'd')
    put_digit((long long int)va_arg(ptr, int), 10, &len);
   else if (format[i] == 'x')
    put_digit((long long int)va_arg(ptr, unsigned int), 16, &len);
  }
  else
   len += write(1, &fmt[i], 1);
  i++;
 }
 return (va_end(ptr), len);
}
