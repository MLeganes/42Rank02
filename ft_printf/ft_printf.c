#include "ft_printf.h"

static int printf_s(char *s)
{
	int ret;
	int i;

	ret = 0;
	i = 0;

	if (s == NULL)
		return (write(1, "(null)", 6));

	while(s[i])
	{
		ret += write(1, &s[i], 1);
		i++;
	}
	return ret;

}

static int printf_d(int d, int reset)
{
	static int ret;
	char nbr;

	if (reset == 1)
	{
		ret = 0;
	}
	
	if (d == -2147483648)
	{
		ret += write(1, "-2147483648", 11 );
		return ret;
	}
	if ( d < 0)
	{
		ret += write(1, "-", 1);
		d *= (-1);
	}
	if( d / 10)
		printf_d(d/10, 0);
	nbr = '0' +  d % 10;
	ret += write(1, &nbr, 1);
	return ret;
}

static int printf_x(unsigned int x, int reset)
{
	static int ret;
	char c;

	if (reset == 1)
	{
		ret = 0;
	}
	//more checks
	if (x == 0)
		return (write(1, "0", 1));
	if (x / 16)
		printf_x( x / 16, 0);
	if ((x % 16) > 9)
		c = 'a' + (x % 16) - 10;
	else
		c = '0' + (x % 16); 
	ret += write(1, &c, 1);
	return ret;
}

static int printf_p(unsigned long ptr, int reset)
{
	static int ret;
	char c;

	if (reset)
		ret = 0;	
	
	if (ptr / 16)
		printf_p(ptr / 16, 0);
	if ( ptr % 16 > 9)
		c = 'a' + (ptr % 16) - 10;
	else
		c = '0' + (ptr % 16);
	ret += write (1, &c, 1);
	return (ret);
}

int ft_printf(const char *fmt, ...)
{
	int i;
	int ret;
	va_list ap;
	char *s;
	int d;
	unsigned int x;
	char c;
	unsigned long ptr;

	ret = 0;
	i = 0;
	va_start(ap, fmt);
	while (fmt[i])
	{
		if( fmt[i] != '%')
		{
			ret += write(1, &fmt[i], 1);
		}
		else{
			i++;

			if (fmt[i] == 'c')
			{
				c = (char)va_arg(ap, int);
				ret += write(1,&c, 1);
			}
			if(fmt[i] == 's')
			{
				s = va_arg(ap, char *);
				ret += printf_s(s);
			}
			if(fmt[i] == 'd' || fmt[i] == 'i')
			{
				d = va_arg(ap, int);			
				ret += printf_d(d, 1);
			}

			if(fmt[i] == 'x')
			{
				x = va_arg(ap, unsigned int);
				ret += printf_x(x, 1);
			}
			if(fmt[i] == 'p')
			{
				ptr = (unsigned long)va_arg(ap, void *);
				if (ptr == 0)
					ret += write(1, "0x0", 3);
				else
				{
					ret += write(1, "0x", 2);
					ret += printf_p(ptr, 1);					
				}				
			}
			if(fmt[i] == '%')
			{
				ret += write(1,"%", 1);
			}			
		}
		i++;

	}	
	va_end(ap);
	return ret;
}
