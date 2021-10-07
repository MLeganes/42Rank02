#include <fcntl.h>
#include <unistd.h>
#include <stdarg.h>

int printf_s(char *s)
{
	int i;
	int ret;

	ret = 0;
	while(s[i])
	{
		ret +=write(1, &s[i], 1);
		i++;
	}
	return(ret);
}

int printf(const char *fmt, ...)   /* '...' is C syntax for a variadic function */

{
	va_list ap;
	char c;
	char *s;
	int d;
	int i;
	int ret;
	unsigned int x;
	unsigned long p;

	ret = 0;
	i = 0;
	va_start(ap, fmt);
	while (fmt[i])
	{
		if (fmt[i] != '%')
		{
			ret += write(1, &fmt[i], 1);
		}
		else
		{
			i++;
			if (fmt[i] == 's'){
				s = va_arg(ap, char *);
				ret += printf_s(s);
			}
			if (fmt[i] == 'p'){
				p = va_arg(ap, void *); // Pointer Unsigned long!!!!!!!!
				ret += printf_p(p);
			}
			if (fmt[i] == 'x'){
				x = va_arg(ap, unsigned int);// Hex Unsigned int!!!!!!!
				ret += printf_s(x);

			}
			//more types...
			i++;
	}
	va_end(ap);
}