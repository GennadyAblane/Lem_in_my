/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowpea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 13:14:19 by esnowpea          #+#    #+#             */
/*   Updated: 2020/10/13 16:04:42 by ablane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*tmp1;
	unsigned char	*tmp2;

	i = 0;
	tmp1 = (unsigned char*)dest;
	tmp2 = (unsigned char*)src;
	while (i < n && tmp2[i] != (unsigned char)c)
	{
		tmp1[i] = tmp2[i];
		i++;
	}
	if (tmp2[i] == (unsigned char)c)
		tmp1[i] = tmp2[i];
	if (tmp1[i] == (unsigned char)c)
		return (tmp1 + i + 1);
	else
		return (NULL);
}
