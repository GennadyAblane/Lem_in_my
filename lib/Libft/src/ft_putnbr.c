/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowpea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 17:09:36 by esnowpea          #+#    #+#             */
/*   Updated: 2020/07/27 16:10:38 by esnowpea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	unsigned int	num;

	if (n < 0)
	{
		ft_putchar('-');
		num = (unsigned int)(-1 * n);
	}
	else
		num = (unsigned int)n;
	if (num < 10)
		ft_putchar(num + '0');
	else
	{
		ft_putnbr((int)(num / 10));
		ft_putchar(num % 10 + '0');
	}
}
