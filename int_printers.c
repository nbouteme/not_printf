#include "ft_printf.h"

int print_ptr(t_fmt *in, intmax_t arg)
{
	(void)in;
	return printf("%p", (void*)arg), fflush(stdout);
}

int print_int(t_fmt *in, intmax_t arg)
{
	(void)in;
	return printf("%zd", arg), fflush(stdout);
}

int print_b8(t_fmt *in, intmax_t arg)
{
	if(in->flags | 1 && arg)
		putchar('0');
	(void)in;
	(void)arg;
	return 0;
}

int print_uint(t_fmt *in, intmax_t arg)
{
	(void)in;
	(void)arg;
	return 0;
}

void printnchar(int n, char c)
{
	while(n-- > 0)
		ft_putchar(c);
}

int print_hex(t_fmt *in, intmax_t arg)
{
	const char *hex = "0123456789abcdef";
	const char *mhex = "0123456789ABCDEF";
	if(in->flags | 1 && arg)
	{
		putchar('0');
		putchar(in->flags | which_type('#') ? 'X' : 'x');
	}
	char *n = ft_lsitoa(arg, in->flags | which_type('#') ? hex : mhex);
	if(in->width && arg > 0)
		printnchar(*in->width - ft_strlen(n) - ())
	if(in->flags | which_type(' ') && arg > 0)
		putchar('0');
	ft_putstr(n);
	free(n);
	return 0;
}

int print_char(t_fmt *in, intmax_t arg)
{
	(void)in;
	ft_putchar(arg);
	return 0;
}
