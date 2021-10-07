#include <unistd.h>
#include <stdarg.h>

// Lib for testing
#include <stdio.h>

int	printf_s(char *s)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	while (s[i] != '\0')
		ret += write(1, &s[i++], 1);
	return (ret);
}

int	ft_putptr(unsigned long hex, int reset)
{
	static int	ret;
	char		c;

	if (reset == 0)
		ret = 0;
	if (hex / 16)
		ft_putptr(hex / 16, 1);
	if ((hex % 16) > 9)
	{
		c = 'a' + (hex % 16) - 10;
	}
	else
	{
		c = '0' + hex % 16;
	}
	ret += write(1, &c, 1);
	return (ret);
}

int	printf_p(unsigned long p)
{
	int		ret;

	ret = 0;
	if (p == 0)
	{
		ret = write(1, "0x0", 3);
	}
	else
	{
		ret += write(1, "0x", 2);
		ret += ft_putptr(p, 0);
	}
	return (ret);
}

int	ft_puthex(unsigned int hex, int reset)
{
	static int	ret;
	char		c;

	if (reset == 0)
	{
		ret = 0;
	}
	if (hex / 16)
		ft_puthex(hex / 16, 1);
	if ((hex % 16) > 9)
	{
		c = 'a' + (hex % 16) - 10;
	}
	else
	{
		c = '0' + hex % 16;
	}
	ret += write(1, &c, 1);
	return (ret);
}

int	printf_x(unsigned int x)
{
	return (ft_puthex(x, 0));
}

int	ft_putnbr(int d, int reset)
{
	static int	ret;
	char		nbr;

	if (reset == 0)
		ret = 0;
	if (d / 10)
		ft_putnbr(d / 10, 1);
	nbr = '0' + (d % 10);
	ret += write(1, &nbr, 1);
	return (ret);
}

int	printf_d(int d)
{
	return (ft_putnbr(d, 0));
}

int	ft_printf(const char *fmt, ...) /* '...' is C syntax for a variadic function */
{
	va_list			ap;
	char			*s;
	int				i;
	int				ret;
	int				d;
	unsigned int	x;
	unsigned long	p;

	ret = 0;
	i = 0;
	x = 0;
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
			if (fmt[i] == 'p')
			{
				p = (unsigned long)va_arg(ap, void *);
				ret += printf_p(p);
			}
			if (fmt[i] == 'x')
			{
				x = va_arg(ap, unsigned int);
				ret += printf_x(x);
			}
			if (fmt[i] == 'd')
			{
				d = va_arg(ap, int);
				ret += printf_d(d);
			}
			//more types...
		}
		i++;
	}
	va_end(ap);
	return (ret);
}

int	main(void)
{
	char	*str = "Hello 42Heilbronn";
	int		x = 0xAABB;
	int		d = 4242;

	ft_printf(" Ret: %d \n", ft_printf("%s", str));
	ft_printf(" Ret: %d \n", ft_printf("%p", &str));
	ft_printf(" Ret: %d \n", ft_printf("%x", x));
	ft_printf(" Ret: %d \n", ft_printf("%d", d));
	printf(" Ret: %d \n", printf("%s", str));
	printf(" Ret: %d \n", printf("%p", &str));
	printf(" Ret: %d \n", printf("%x", x));
	printf(" Ret: %d \n", printf("%d", d));
	return (0);
}
