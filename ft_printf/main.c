#include "ft_printf.h"

int main(void)
{

	char	*str = "Hello 42Heilbronn";
	int		d = -2147483648;
	int		x = 0xAABBcc;

	ft_printf(" Ret: %d \n", ft_printf("%s", str));
	ft_printf(" Ret: %d \n", ft_printf("%d", d));
	ft_printf(" Ret: %d \n", ft_printf("%x", x));
	//ft_printf(" Ret: %d \n", ft_printf("%p", &str));
	printf(" Ret: %d \n", printf("%s", str));
	printf(" Ret: %d \n", printf("%d", d));
	printf(" Ret: %d \n", printf("%x", x));
	//printf(" Ret: %d \n", printf("%p", &str));

	return 0;	
}