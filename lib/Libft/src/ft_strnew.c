/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowpea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 14:42:53 by esnowpea          #+#    #+#             */
/*   Updated: 2020/10/13 16:04:42 by ablane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;
	size_t	i;

	i = 0;
	if (size == (size_t)(-1))
		return (0);
	str = (char*)malloc(size + 1);
	if (!str)
		return (0);
	while (i <= size)
		str[i++] = '\0';
	return (str);
}
