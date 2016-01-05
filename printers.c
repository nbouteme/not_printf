#include "ft_printf.h"

int print_fmt(t_fmt *in, intmax_t arg)
{
	const t_printer print[] = { &print_str, &print_str, &print_ptr,
								&print_int, &print_int, &print_b8,
								&print_uint, &print_hex, &print_hex,
								&print_char };
	return print[in->type](in, arg);
}

int render_fmt(t_fmt *in, va_list ap)
{
	intmax_t arg;
	t_va *va = (void*)ap;
	ft_memcpy(&arg, va->region + va->offset, *in->length);
	va->offset += *in->length;
	return print_fmt(in, arg);
}
