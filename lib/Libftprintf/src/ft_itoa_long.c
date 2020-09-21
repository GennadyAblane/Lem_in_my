/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowpea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 15:26:31 by esnowpea          #+#    #+#             */
/*   Updated: 2020/07/27 16:10:38 by esnowpea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static int						ft_len_n(unsigned long long int n, int base)
{
	int i;

	i = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= base;
		i++;
	}
	return (i);
}

static unsigned long long int	ft_prov(long long int n, int *minus)
{
	unsigned long long int	num;

	if (n < 0)
	{
		*minus = 1;
		num = (unsigned long long int)(-1 * n);
	}
	else
		num = (unsigned long long int)n;
	return (num);
}

char							*itoa_base_long(long long int n, int base)
{
	char					*str;
	int						minus;
	int						i;
	unsigned long long int	num;

	minus = 0;
	num = ft_prov(n, &minus);
	if (!(str = (char*)malloc(ft_len_n(num, base) + minus + 1)))
		return (0);
	i = ft_len_n(num, base) + minus;
	str[i--] = '\0';
	if (num == 0)
		str[i--] = '0';
	while (num)
	{
		str[i--] = (num % base < 10) ? num % base + '0' : num % base + 'A' - 10;
		num /= base;
	}
	if (minus)
		str[i] = '-';
	return (str);
}

char							*itoa_u(unsigned long long n, int base)
{
	char					*str;
	int						i;

	if (!(str = (char*)malloc(ft_len_n(n, base) + 1)))
		return (0);
	i = ft_len_n(n, base);
	str[i--] = '\0';
	if (n == 0)
		str[i--] = '0';
	while (n)
	{
		str[i--] = (n % base < 10) ? n % base + '0' : n % base + 'A' - 10;
		n /= base;
	}
	return (str);
}
