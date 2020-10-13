/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowpea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 18:40:28 by esnowpea          #+#    #+#             */
/*   Updated: 2020/10/13 16:04:42 by ablane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (s)
	{
		if ((size_t)start + len > ft_strlen(s))
			return (0);
		str = (char*)malloc(sizeof(char) * (len + 1));
		if (!str)
			return (0);
		i = (size_t)start;
		while (i < (size_t)start + len)
		{
			str[i - (size_t)start] = s[i];
			i++;
		}
		str[i - (size_t)start] = '\0';
		return (str);
	}
	return (0);
}
