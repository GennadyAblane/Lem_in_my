/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowpea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 17:30:03 by esnowpea          #+#    #+#             */
/*   Updated: 2020/07/27 16:10:38 by esnowpea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	num;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		num = (unsigned int)(-1 * n);
	}
	else
		num = (unsigned int)n;
	if (num < 10)
		ft_putchar_fd(num + '0', fd);
	else
	{
		ft_putnbr_fd((int)(num / 10), fd);
		ft_putchar_fd(num % 10 + '0', fd);
	}
}
