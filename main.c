#include "ft_printf.h"

int ft_printf(const char *format, ...)
{
	va_list ap;
	t_fmt *fmt = ft_memset(malloc(sizeof(t_fmt)), 0, sizeof(t_fmt));
	unsigned total = 0;
	va_start(ap, format);
	while(*format)
	{
		if(*format != '%' && ++total)
			write(1, format++, 1);
		else
		{
			parse_fmt(format, fmt);
			total += render_fmt(fmt, ap);
			format = end_fmt(format);
			dtor_fmt(fmt);
		}
	}
	free(fmt);
	va_end(ap);
	return total;
}

int main()
{
	//char *s = "AI";
	//t_fmt *f = ft_memset(malloc(sizeof(*f)), 0, sizeof(*f));
	ft_printf("KIKOETANDA, %s\n", "UNMEI WO NOROBU KOE DA");
	ft_printf("SONO OKU NO %zd\n", 12UL);
	//printf("%hhd\n", 0x65);
	//printf("%c\n", 0x65);
	//print_format(f);
    return 0;
}
