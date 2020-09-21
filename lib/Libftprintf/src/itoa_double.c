/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_double.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowpea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 12:10:48 by esnowpea          #+#    #+#             */
/*   Updated: 2020/07/27 16:10:38 by esnowpea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int			len_mod(t_double a)
{
	int						i;
	unsigned long long int	j;
	int						len;

	len = 0;
	i = 0;
	while (i < MAX_NB && a.mod_array[i] == 0)
		i++;
	while (i < MAX_NB)
	{
		j = MAX_NL / 10;
		while (j > 0)
		{
			if (a.mod_array[i] / j != 0 || len > 0)
				len++;
			a.mod_array[i] %= j;
			j /= 10;
		}
		i++;
	}
	if (len == 0)
		len++;
	return (len);
}

int			double_mod_str(t_double a, char *sign, char *str, int k)
{
	int						i;
	unsigned long long int	j;

	i = 0;
	if (ft_strlen(sign))
		str[k++] = *sign;
	while (i < MAX_NB && a.mod_array[i] == 0)
		i++;
	while (i < MAX_NB)
	{
		j = MAX_NL / 10;
		while (j > 0)
		{
			if (a.mod_array[i] / j != 0 || k > (int)ft_strlen(sign))
				str[k++] = a.mod_array[i] / j + '0';
			a.mod_array[i] %= j;
			j /= 10;
		}
		i++;
	}
	if (k == (int)ft_strlen(sign))
		str[k++] = '0';
	str[k++] = '.';
	return (k);
}

int			double_div_str(t_double a, int len, char *str, int k)
{
	int						i;
	unsigned long long int	j;

	i = 0;
	while (i < MAX_NB && k < len)
	{
		j = MAX_NL / 10;
		while (j > 0 && k < len)
		{
			str[k++] = a.div_array[i] / j + '0';
			a.div_array[i] %= j;
			j /= 10;
		}
		i++;
	}
	return (k);
}

char		*double_to_str(t_double a, int len, char *sign)
{
	char	*str;
	int		k;

	if (!(str = ft_strnew(len)))
		return (0);
	k = double_mod_str(a, sign, str, 0);
	k = double_div_str(a, len, str, k);
	return (str);
}

char		*itoa_double(t_double a, int accur, char *sign)
{
	int		len;

	a = rounding(a, accur);
	len = len_mod(a);
	len += accur + 1 + ft_strlen(sign);
	if (a.nan == '+')
		return (ft_strdup("inf"));
	else if (a.nan == '-')
		return (ft_strdup("-inf"));
	else if (a.nan == 'n')
		return (ft_strdup("nan"));
	return (double_to_str(a, len, sign));
}
