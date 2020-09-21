/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_e.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowpea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 14:56:42 by esnowpea          #+#    #+#             */
/*   Updated: 2020/07/27 16:10:37 by esnowpea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"
#include "../inc/ft_printf.h"

int			kol_nl(unsigned long long a)
{
	int	i;

	i = 0;
	while (a > 0)
	{
		a /= 10;
		i++;
	}
	return (i);
}

char		*add_e_nb(char *str, int k)
{
	if (kol_nl(k) < 3)
	{
		str[ft_strlen(str)] = k / 10 + '0';
		str[ft_strlen(str)] = k % 10 + '0';
	}
	else
	{
		str[ft_strlen(str)] = k / 100 + '0';
		str[ft_strlen(str)] = k / 10 % 10 + '0';
		str[ft_strlen(str)] = k % 10 + '0';
	}
	return (str);
}

char		*add_e(char *str, int k)
{
	char	*s;
	int		len;

	len = (int)ft_strlen(str) + (k > 0 ? 0 : 1) + 5;
	if (!(s = ft_strnew(len)))
		return (0);
	ft_memcpy(s, str, ft_strlen(str));
	free(str);
	s[ft_strlen(s)] = 'E';
	if (k < 0)
	{
		s[ft_strlen(s)] = '-';
		k = k > 0 ? k : -k;
	}
	else
		s[ft_strlen(s)] = '+';
	s = add_e_nb(s, k);
	return (s);
}

char		*itoa_double_e(t_double a, int accur, char *sign)
{
	int		len;
	int		k;
	char	*str;

	k = shift_e(&a);
	a = rounding(a, accur);
	k += shift_e(&a);
	len = accur + ft_strlen(sign) + 2;
	if (a.nan == '+')
		return (ft_strdup("inf"));
	else if (a.nan == '-')
		return (ft_strdup("-inf"));
	else if (a.nan == 'n')
		return (ft_strdup("nan"));
	else if (!(str = double_to_str(a, len, sign)))
		return (0);
	return (add_e(str, k));
}

t_str_len	ft_e(t_format_sp spec, va_list ap)
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
	else if (nb.db >= 0 && (spec.flags & 2))
		*spec.sign = '+';
	else if (nb.db >= 0 && (spec.flags & 4))
		*spec.sign = ' ';
	s.str = itoa_double_e(mant_double(nb.number.sign, nb.number.exp - 16383,\
			nb.number.mant), spec.accur, spec.sign);
	if (spec.accur == 0 && !(spec.flags & 8))
	{
		ft_memcpy(ft_strchr(s.str, '.'), ft_strchr(s.str, '.') + 1, \
				ft_strlen(ft_strchr(s.str, '.') + 1));
		s.str[ft_strlen(s.str) - 1] = '\0';
	}
	return (handler_flags(s.str, spec));
}
