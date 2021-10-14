#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h> 		//man 2 write
# include <stdarg.h>		//man va_arg
# include <stdio.h>

int ft_printf(const char *fmt, ...);

#endif