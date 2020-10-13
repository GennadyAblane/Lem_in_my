/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowpea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 19:12:44 by esnowpea          #+#    #+#             */
/*   Updated: 2020/10/13 16:04:42 by ablane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	size_t	i;
	size_t	len;
	size_t	j;

	if (!s)
		return (0);
	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	len = ft_strlen(s);
	while ((s[len] == ' ' || s[len] == '\n' || s[len] == '\t' \
	|| s[len] == '\0') && (i < len))
		len--;
	str = (char*)malloc(sizeof(char) * (len - i + 2));
	if (!str)
		return (0);
	j = 0;
	while (i + j <= len)
	{
		str[j] = s[i + j];
		j++;
	}
	str[j] = '\0';
	return (str);
}
