#include "ft_printf.h"

/* static int cnt_fmt(const char *s) */
/* { */
/* 	int n = 0; */

/* 	while(*s) */
/* 	{ */
/* 		n += s[0] == '%'; */
/* 		++s; */
/* 		s += s[0] == '%'; */
/* 	} */
/* 	return n; */
/* } */

void parse_ltype(const char *s, t_fmt *out)
{
	if(which_size(*s) != -1)
	{
		out->length = malloc(4);
		if(s[0] == 'h')
		{
			*out->length = sizeof(short);
			*out->length = s[1] == 'h' ? sizeof(unsigned char) : *out->length;
		}
		else if(s[0] == 'l')
		{
			*out->length = sizeof(long);
			*out->length = s[1] == 'l' ? sizeof(unsigned long long) : *out->length;
		}
		else if(s[0] == 'j')
			*out->length = sizeof(uintmax_t);
		else if(s[0] == 'z')
			*out->length = sizeof(size_t);
	}
	out->type = which_type(*(s + (-1 != which_size(*s)) + (s[0] == s[1])));
	*out->length = out->type <= 2 ? sizeof(void*) : *out->length;
}

void dtor_fmt(t_fmt *self)
{
	free(self->width);
	free(self->precision);
	free(self->length);
	ft_memset(self, 0, sizeof(t_fmt));
}

const char *end_fmt(const char *s)
{
	int p;

	++s;
	while (which_flag(*s) != -1)
		++s;
	if ((p = ft_strindexof(s, '$')) != -1)
		s += p + 1;
	while (which_flag(*s) != -1)
		++s;
	while (ft_isdigit(*s))
		++s;
	s += *s == '.';
	while (ft_isdigit(*s) || which_size(*s) != -1)
		++s;
	return s + 1;
}

void parse_fmt(const char *s, t_fmt *out)
{
	const char *e;
	int p;

	e = ++s;
	if((p = which_type(*s)) != -1)
	{
		out->type = which_type(*s);
		out->length = malloc(4);
		*out->length = out->type <= 2 ? sizeof(void*) : 4;
		return;
	}
	while (which_flag(*e) != -1)
		++e;
	if ((p = ft_strindexof(s, '$')) != -1 && (out->argn = ft_atoi(s)))
		s += p + 1;
	while ((p = which_flag(*s)) != -1 && ++s)
		out->flags |= 1 << p;
	if (ft_isdigit(*s) && (out->width = malloc(4)))
		*out->width = ft_atoi(s);
	while (ft_isdigit(*s))
		++s;
	if (*s == '.' && (out->precision = malloc(4)))
		*out->precision = ft_atoi(++s);
	while (ft_isdigit(*s))
		++s;
	parse_ltype(s, out);
}
