#include "ft_printf.h"

int which_flag(char c)
{
	return ft_strindexof("# 0-+", c);
}

int which_size(char c)
{
	return ft_strindexof("hljz", c);
}

int which_type(char c)
{
	return ft_strindexof("sSpdiouxXc%", c);
}
