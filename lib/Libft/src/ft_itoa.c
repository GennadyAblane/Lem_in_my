/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowpea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 15:05:14 by esnowpea          #+#    #+#             */
/*   Updated: 2020/10/13 16:04:42 by ablane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_len_n(int n)
{
	int i;

	i = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static unsigned int	ft_prov(int n, int *minus)
{
	unsigned int	num;

	if (n < 0)
	{
		*minus = 1;
		num = (unsigned int)(-1 * n);
	}
	else
		num = (unsigned int)n;
	return (num);
}

char				*ft_itoa(int n)
{
	char			*str;
	int				minus;
	int				i;
	unsigned int	num;

	i = 0;
	minus = 0;
	num = ft_prov(n, &minus);
	if (!(str = (char*)malloc(ft_len_n(num) + minus + 1)))
		return (0);
	i = ft_len_n(num) + minus;
	str[i--] = '\0';
	if (num == 0)
		str[i--] = '0';
	while (num)
	{
		str[i--] = num % 10 + '0';
		num /= 10;
	}
	if (minus)
		str[i--] = '-';
	return (str);
}
