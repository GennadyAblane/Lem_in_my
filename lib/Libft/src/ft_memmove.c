/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowpea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 14:35:33 by esnowpea          #+#    #+#             */
/*   Updated: 2020/07/27 16:10:38 by esnowpea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*tmp1;
	unsigned char	*tmp2;

	if (!dest && !src)
		return (dest);
	tmp1 = (unsigned char*)dest;
	tmp2 = (unsigned char*)src;
	i = 0;
	if (tmp1 <= tmp2 || tmp1 >= (tmp2 + n))
		while (i < n)
		{
			tmp1[i] = tmp2[i];
			i++;
		}
	else
	{
		i = n;
		while (--i > 0)
			tmp1[i] = tmp2[i];
		tmp1[i] = tmp2[i];
	}
	return (tmp1);
}
