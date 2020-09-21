/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mult_double.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowpea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 12:43:25 by esnowpea          #+#    #+#             */
/*   Updated: 2020/07/27 16:10:38 by esnowpea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

t_double	zero_double(void)
{
	int			i;
	t_double	num;

	i = 0;
	while (i < MAX_NB)
	{
		num.div_array[i] = 0;
		num.mod_array[i++] = 0;
	}
	return (num);
}

t_double	first_double(void)
{
	int			i;
	t_double	num;

	i = 0;
	while (i < MAX_NB)
	{
		num.div_array[i] = 0;
		num.mod_array[i++] = 0;
	}
	num.mod_array[MAX_NB - 1] = 1;
	return (num);
}

t_double	trunce_nb(t_double c, int i, char n, char m)
{
	if (n == 'm' && m == 'm')
	{
		c.mod_array[i - 1] += c.mod_array[i] / MAX_NL;
		c.mod_array[i] %= MAX_NL;
	}
	else if (n == 'd' && m == 'd')
	{
		c.div_array[i - 1] += c.div_array[i] / MAX_NL;
		c.div_array[i] %= MAX_NL;
	}
	else
	{
		c.mod_array[MAX_NB - 1] += c.div_array[i] / MAX_NL;
		c.div_array[i] %= MAX_NL;
	}
	return (c);
}

t_double	sum_double(t_double a, t_double b)
{
	int			i;
	t_double	c;

	c = zero_double();
	i = MAX_NB - 1;
	while (i >= 0)
	{
		c.mod_array[i] += a.mod_array[i] + b.mod_array[i];
		c.div_array[i] += a.div_array[i] + b.div_array[i];
		if (i != 0 && c.mod_array[i] > MAX_NL - 1)
			c = trunce_nb(c, i, 'm', 'm');
		if (i != 0 && c.div_array[i] >= MAX_NL)
			c = trunce_nb(c, i, 'd', 'd');
		if (i == 0 && c.div_array[i] >= MAX_NL)
			c = trunce_nb(c, i, 'm', 'd');
		i--;
	}
	return (c);
}

t_double	mult_double(t_double a, unsigned int b)
{
	int			i;
	t_double	c;

	c = zero_double();
	i = MAX_NB - 1;
	while (i >= 0)
	{
		c.mod_array[i] += a.mod_array[i] * b;
		c.div_array[i] += a.div_array[i] * b;
		if (i != 0 && c.mod_array[i] > MAX_NL - 1)
			c = trunce_nb(c, i, 'm', 'm');
		if (i != 0 && c.div_array[i] >= MAX_NL)
			c = trunce_nb(c, i, 'd', 'd');
		if (i == 0 && c.div_array[i] >= MAX_NL)
			c = trunce_nb(c, i, 'm', 'd');
		i--;
	}
	return (c);
}
