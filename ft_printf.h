#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>
#include <libft/std.h>
#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>
#include <unistd.h>

typedef union	u_val
{
	intmax_t	imm;
	void		*ptr;
}				t_val;

typedef struct	s_fmt
{
	int flags;
	unsigned *width;
	unsigned *precision;
	unsigned *length;
	int type;
	int argn;
}				t_fmt;

typedef struct	s_va
{
	unsigned offset;
	unsigned unknown1;
	void *unknown2;
	void *region;
}				t_va;

typedef int(*t_printer)(t_fmt *in, intmax_t arg);

int which_flag(char c);
int which_size(char c);
int which_type(char c);

void parse_ltype(const char *s, t_fmt *out);
void dtor_fmt(t_fmt *self);
const char *end_fmt(const char *s);
void parse_fmt(const char *s, t_fmt *out);

int print_fmt(t_fmt *in, intmax_t arg);
int render_fmt(t_fmt *in, va_list ap);

int print_str(t_fmt *in, intmax_t arg);
int print_ptr(t_fmt *in, intmax_t arg);
int print_int(t_fmt *in, intmax_t arg);
int print_b8(t_fmt *in, intmax_t arg);
int print_uint(t_fmt *in, intmax_t arg);
int print_hex(t_fmt *in, intmax_t arg);
int print_char(t_fmt *in, intmax_t arg);

int ft_printf(const char *format, ...) __attribute__ ((format (printf, 1, 2)));

#endif
