/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_f.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowpea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 14:44:14 by esnowpea          #+#    #+#             */
/*   Updated: 2020/07/27 16:10:37 by esnowpea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

t_str_len	ft_f(t_format_sp spec, va_list ap)
{
	t_long_a		nb;
	t_str_len		s;

	if (spec.accur == -1)
		spec.accur = 6;
	if (spec.size & 16)
		nb.db = va_arg(ap, long double);
	else
		nb.db = (long double)va_arg(ap, double);
	if (nb.number.sign == 1)
		*spec.sign = '-';
	else if (nb.number.sign == 0 && (spec.flags & 2))
		*spec.sign = '+';
	else if (nb.number.sign == 0 && (spec.flags & 4))
		*spec.sign = ' ';
	s.str = itoa_double(mant_double(nb.number.sign, nb.number.exp - 16383,\
			nb.number.mant), spec.accur, spec.sign);
	if (spec.accur == 0 && !(spec.flags & 8))
		s.str[ft_strlen(s.str) - 1] = '\0';
	return (handler_flags(s.str, spec));
}

t_double	shift_double_right(t_double a)
{
	int i;

	i = MAX_NB - 1;
	a.div_array[i] /= 10;
	i--;
	while (i >= 0)
	{
		a.div_array[i + 1] += a.div_array[i] % 10 * MAX_NL / 10;
		a.div_array[i--] /= 10;
	}
	i = MAX_NB - 1;
	a.div_array[0] += a.mod_array[i] % 10 * MAX_NL / 10;
	a.mod_array[i] /= 10;
	i--;
	while (i >= 0)
	{
		a.mod_array[i + 1] += a.mod_array[i] % 10 * MAX_NL / 10;
		a.mod_array[i--] /= 10;
	}
	return (a);
}

t_double	shift_double_left(t_double a)
{
	int i;

	i = 0;
	a.mod_array[i] /= (MAX_NL / 10);
	i++;
	while (i < MAX_NB)
	{
		a.mod_array[i - 1] += a.mod_array[i] / (MAX_NL / 10);
		a.mod_array[i] %= (MAX_NL / 10);
		a.mod_array[i++] *= 10;
	}
	i = 0;
	a.mod_array[MAX_NB - 1] += a.div_array[i] / (MAX_NL / 10);
	a.div_array[i] %= (MAX_NL / 10);
	a.div_array[i++] *= 10;
	while (i < MAX_NB)
	{
		a.div_array[i - 1] += a.div_array[i] / (MAX_NL / 10);
		a.div_array[i] %= (MAX_NL / 10);
		a.div_array[i++] *= 10;
	}
	return (a);
}

t_double	power_two(int n)
{
	int			i;
	t_double	a;

	a = first_double();
	i = 0;
	while (i < n && n > 0)
	{
		a = mult_double(a, 2);
		i++;
	}
	while (i < -n && n <= 0)
	{
		a = shift_double_right(mult_double(a, 5));
		i++;
	}
	return (a);
}

t_double	mant_double(int sign, int exp, unsigned long long mant)
{
	int			i;
	t_double	a;
	char		s[65];

	i = 0;
	s[64] = '\0';
	while (i < 64)
	{
		s[i++] = mant % 2 + '0';
		mant /= 2;
	}
	i = 63;
	a = zero_double();
	while (i >= 0)
	{
		if (s[i] == '1')
			a = sum_double(a, power_two(exp + i - 63));
		i--;
	}
	a.nan = '\0';
	if (exp == 16384 && ft_strchr(s, '1') == &s[63])
		a.nan = sign == 1 ? '-' : '+';
	if (exp == 16384 && ft_strchr(s, '1') != &s[63])
		a.nan = 'n';
	return (a);
}
