/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rounding.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowpea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 12:31:59 by esnowpea          #+#    #+#             */
/*   Updated: 2020/07/27 16:10:38 by esnowpea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int			nl(unsigned long long int j)
{
	int		i;

	i = 0;
	while (j > 1)
	{
		i++;
		j /= 10;
	}
	return (i);
}

int			rod(t_double a, int accur)
{
	int						i;
	unsigned long long int	j;

	if (accur % nl(MAX_NL) == 0)
		return ((int)(a.div_array[accur / nl(MAX_NL) - 1] % 10));
	i = 0;
	j = a.div_array[accur / nl(MAX_NL)];
	while (i < nl(MAX_NL) - accur % nl(MAX_NL))
	{
		j /= 10;
		i++;
	}
	return ((int)(j % 10));
}

t_double	rounding_plus(t_double a, int accur)
{
	int			i;
	t_double	b;

	b = first_double();
	i = 0;
	while (i < accur)
	{
		b = shift_double_right(b);
		i++;
	}
	return (sum_double(a, b));
}

t_double	rounding_five(t_double a, int accur)
{
	int i;

	i = accur + 2;
	while (i % nl(MAX_NL))
	{
		if (rod(a, i) != 0)
			return (rounding_plus(a, accur));
		i++;
	}
	if (rod(a, i + 1) != 0)
		return (rounding_plus(a, accur));
	i = accur / nl(MAX_NL) == 0 ? accur / nl(MAX_NL) + 1 : accur / nl(MAX_NL);
	while (i < MAX_NB)
	{
		if (a.div_array[i] != 0)
			return (rounding_plus(a, accur));
		i++;
	}
	if (rod(a, accur) % 2 == 1)
		return (rounding_plus(a, accur));
	return (a);
}

t_double	rounding(t_double a, int accur)
{
	if (rod(a, accur + 1) > 5)
		return (rounding_plus(a, accur));
	else if (rod(a, accur + 1) < 5)
		return (a);
	else
		return (rounding_five(a, accur));
}
