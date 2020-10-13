/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowpea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 16:43:50 by esnowpea          #+#    #+#             */
/*   Updated: 2020/10/13 16:04:42 by ablane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define MAX_LINT 9223372036854775807

static int	ft_skip(const char *str, int *minus)
{
	int i;

	i = 0;
	*minus = 0;
	while ((str[i] == '\n') || (str[i] == '\t') || (str[i] == '\v') || \
	(str[i] == ' ') || (str[i] == '\f') || (str[i] == '\r'))
		i++;
	if (str[i] == '-')
		*minus = 1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	return (i);
}

int			ft_atoi(const char *str)
{
	size_t					i;
	int						minus;
	long int				a;
	unsigned long long int	kostyl;

	a = 0;
	kostyl = 0;
	i = ft_skip(str, &minus);
	while (i < (ft_strlen(str)) && ((str[i] >= '0') && (str[i] <= '9')))
	{
		a = a * 10 + str[i] - '0';
		if (kostyl <= MAX_LINT)
			kostyl = kostyl * 10 + str[i] - '0';
		i++;
	}
	if (kostyl > MAX_LINT && minus == 0)
		return (-1);
	if (kostyl > MAX_LINT && minus == 1)
		return (0);
	if (minus == 1)
		return ((int)(-a));
	else
		return ((int)a);
}
