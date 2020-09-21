/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowpea <esnowpea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 16:01:35 by esnowpea          #+#    #+#             */
/*   Updated: 2020/07/27 16:10:37 by esnowpea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <zconf.h>
# include "libft.h"

# define FD			1
# define SPEC_FUN	16
# define MAX_NB		33
# define MAX_NL		10000000000

typedef struct				s_format_sp
{
	unsigned short			flags;
	int						width;
	int						accur;
	unsigned short			size;
	char					type;
	int						base;
	char					sign[3];
}							t_format_sp;

typedef struct				s_str_len
{
	char					*str;
	int						len;
}							t_str_len;

typedef struct				s_type
{
	char					type;
	t_str_len				(*func)(t_format_sp spec, va_list ap);
}							t_type;

typedef union				u_long_a
{
	long double				db;
	struct
	{
		unsigned long long	mant : 64;
		unsigned int		exp : 15;
		unsigned int		sign : 1;
	}						number;
}							t_long_a;

typedef struct				s_double
{
	unsigned long long		mod_array[MAX_NB];
	unsigned long long		div_array[MAX_NB];
	char					nan;
}							t_double;

/*
**	FLAGS:
**	'-'	- 00001
**	'+'	- 00010
**	' '	- 00100
**	'#'	- 01000
**	'0'	- 10000
**
**	SIZE:
**	'l'	- 00001
**	'll'- 00010
**	'h'	- 00100
**	'hh'- 01000
**	'L'	- 10000
*/

int							ft_printf(const char *format, ...);
int							ft_printf_fd(int fd, const char *format, ...);
t_format_sp					parsing(const char **format, va_list ap);
t_str_len					ft_c(t_format_sp spec, va_list ap);
t_str_len					ft_s(t_format_sp spec, va_list ap);
t_str_len					ft_d(t_format_sp spec, va_list ap);
t_str_len					ft_f(t_format_sp spec, va_list ap);
t_str_len					ft_e(t_format_sp spec, va_list ap);
t_str_len					ft_g(t_format_sp spec, va_list ap);
char						*itoa_base_long(long long int n, int base);
char						*itoa_u(unsigned long long n, int base);
t_str_len					handler_flags(char *str, t_format_sp spec);
char						*itoa_double(t_double a, int accur, char *sign);
char						*itoa_double_e(t_double a, int accur, char *sign);
char						*double_to_str(t_double a, int len, char *sign);
t_double					sum_double(t_double a, t_double b);
t_double					mult_double(t_double a, unsigned int b);
t_double					shift_double_right(t_double a);
t_double					shift_double_left(t_double a);
t_double					mant_double(int sign, int exp, \
							unsigned long long mant);
t_double					first_double(void);
t_double					zero_double(void);
t_double					rounding(t_double a, int accur);
int							min(int a, int b);
int							max(int a, int b);
int							nl(unsigned long long int j);
int							kol_nl(unsigned long long a);
int							shift_e(t_double *a);

#endif
