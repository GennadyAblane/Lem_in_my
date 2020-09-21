/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_g.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowpea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 15:19:42 by esnowpea          #+#    #+#             */
/*   Updated: 2020/07/27 16:10:37 by esnowpea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int			shift_e_left(t_double *a)
{
	int		k;
	int		i;
	int		len;

	i = 0;
	k = 0;
	while (i < MAX_NB)
	{
		if ((*a).div_array[i] != 0)
		{
			len = kol_nl((*a).div_array[i]);
			while (k > -i * nl(MAX_NL) - (nl(MAX_NL) - len) - 1)
			{
				*a = shift_double_left(*a);
				k--;
			}
			return (k);
		}
		i++;
	}
	return (k);
}

int			shift_e(t_double *a)
{
	int		k;
	int		i;
	int		len;

	k = 0;
	i = 0;
	while (i < MAX_NB)
	{
		if ((*a).mod_array[i] != 0)
		{
			len = kol_nl((*a).mod_array[i]);
			while (k < (MAX_NB - 1 - i) * nl(MAX_NL) + len - 1)
			{
				*a = shift_double_right(*a);
				k++;
			}
			return (k);
		}
		i++;
	}
	k = shift_e_left(a);
	return (k);
}

t_str_len	ft_g_help(t_format_sp spec, t_long_a nb)
{
	t_str_len		s1;
	t_str_len		s2;

	s1.str = itoa_double_e(mant_double(nb.number.sign, nb.number.exp - 16383,\
			nb.number.mant), spec.accur, spec.sign);
	s2.str = itoa_double(mant_double(nb.number.sign, nb.number.exp - 16383,\
			nb.number.mant), spec.accur, spec.sign);
	if (spec.accur == 0 && !(spec.flags & 8))
		s2.str[ft_strlen(s2.str) - 1] = '\0';
	if (spec.accur == 0 && !(spec.flags & 8))
	{
		ft_memcpy(ft_strchr(s1.str, '.'), ft_strchr(s1.str, '.') + 1, \
		ft_strlen(ft_strchr(s1.str, '.') + 1));
		s1.str[ft_strlen(s1.str) - 1] = '\0';
	}
	if (ft_strlen(s1.str) < ft_strlen(s2.str))
	{
		free(s2.str);
		return (handler_flags(s1.str, spec));
	}
	else
	{
		free(s1.str);
		return (handler_flags(s2.str, spec));
	}
}

t_str_len	del_zero(t_str_len s)
{
	int		i;

	i = ft_strlen(s.str) - 1;
	while (i > 0 && s.str[i] == '0')
	{
		i--;
	}
	if (s.str[i] == '.')
		s.str[i] = '\0';
	else
		s.str[i + 1] = '\0';
	s.len = ft_strlen(s.str);
	return (s);
}

t_str_len	ft_g(t_format_sp spec, va_list ap)
{
	t_long_a		nb;

	if (spec.accur == -1)
		spec.accur = 5;
	if (spec.size & 16)
		nb.db = va_arg(ap, long double);
	else
		nb.db = (long double)va_arg(ap, double);
	if (nb.db < 0)
		*spec.sign = '-';
	if (nb.db >= 0 && (spec.flags & 4))
		*spec.sign = ' ';
	if (nb.db >= 0 && (spec.flags & 2))
		*spec.sign = '+';
	return (del_zero(ft_g_help(spec, nb)));
}
