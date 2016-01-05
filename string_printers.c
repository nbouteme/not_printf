#include "ft_printf.h"

int print_str(t_fmt *in, intmax_t arg)
{
	if(in->type == 2)
		printf("%S", (wchar_t*)arg);
	else
		ft_putstr((void*)arg);
	return strlen((void*)arg);
}
