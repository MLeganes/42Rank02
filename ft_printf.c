#include <fcntl.h>
#include <unistd.h>
#include <stdarg.h>

int printf_s(char *s)
{
	int i;
	int ret;

	ret = 0;
	while (s[i] != '\0')
	{
		ret += write(1, &s[i], 1);
		i++;
	}
	return (ret);
}

int ft_putptr(unsigned long hex, int reset)
{
	int ret;
	char c;

	if( reset == 0 )
	{
		ret = 0;
	}
	if(hex / 16)
		ft_putptr(hex/16, 1);

	if( (hex % 16) > 9)
	{
		c = 'a' + (hex % 16) - 10;
	}else{
		c = '0' + hex % 16;
	}
	ret += write(1, &c, 1);
	return (ret);
}

int printf_p(unsigned long p)
{
	 int ret;
	 ret = 0;
	 if( p == 0 )
	 {
		 ret = write(1, "0x0", 3);
	 }else
	 {
		ret += write(1, "0x", 2);
	 	ret += ft_putptr(p, 0);
	 }
	 return (ret);
}

int ft_puthex(unsigned int hex, int reset)
{
	int ret;
	char c;

	if( reset == 0 )
	{
		ret = 0;
	}
	if(hex / 16)
		ft_puthex(hex/16, 1);

	if( (hex % 16) > 9)
	{
		c = 'a' + (hex % 16) - 10;
	}else{
		c = '0' + hex % 16;
	}
	ret += write(1, &c, 1);
	return (ret);
}

int printf_x(unsigned long x)
{
	return (ft_puthex(x, 0));
}

int ft_printf(const char *fmt, ...) /* '...' is C syntax for a variadic function */
{
	va_list ap;
	//char c;
	char *s;
	//int d;
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
			if (fmt[i] == 's')
			{
				s = va_arg(ap, char *);
				ret += printf_s(s);
			}
			if (fmt[i] == 'p'){
				p = (unsigned long) va_arg(ap, void *); // Pointer Unsigned long!!!!!!!!
				ret += printf_p(p);
			}
			if (fmt[i] == 'x')
			{
				x = va_arg(ap, unsigned int);// Hex Unsigned int!!!!!!!
				ret += printf_x(x);
			}
			//more types...
		}
		i++;
	}
	va_end(ap);
	return (ret);
}

#include <stdio.h>

int main()
{
	char *str = "Hola cara cola";
	unsigned char hex;

	hex = 0xA;

	ft_printf("%s \n", str);
	ft_printf("%p \n", &str);
	ft_printf("%x \n", &hex);
	printf("%s \n", str);
	printf("%p \n", &str);
	printf("%x \n", hex);
	return (0);
}
