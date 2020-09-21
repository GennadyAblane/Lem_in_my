/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowpea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 12:15:40 by esnowpea          #+#    #+#             */
/*   Updated: 2020/07/27 16:10:38 by esnowpea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;
	char	*tmp;

	i = 0;
	j = 0;
	tmp = (char*)str;
	while (str[i] != '\0' && i < len)
	{
		j = 0;
		while (str[i + j] == to_find[j] && i + j < len)
		{
			if (to_find[j + 1] == '\0')
				return (tmp + i);
			j++;
		}
		i++;
	}
	if (ft_strcmp(to_find, "") == 0)
		return (tmp);
	return (0);
}
