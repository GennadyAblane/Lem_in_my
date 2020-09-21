/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowpea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 19:53:06 by esnowpea          #+#    #+#             */
/*   Updated: 2020/07/27 16:10:38 by esnowpea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*word(const char *str, size_t i, size_t j)
{
	char	*s;
	size_t	k;

	s = (char *)malloc(sizeof(char) * (j + 1));
	if (!s)
		return (0);
	k = 0;
	while (k < j)
	{
		s[k] = str[i + k];
		k++;
	}
	s[k] = '\0';
	return (s);
}

static void	*ft_free_str(char **str, int n)
{
	n--;
	while (n > 0)
		free(str[n--]);
	free(str[0]);
	free(str);
	return (0);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**str;
	size_t	i;
	int		n;
	size_t	j;

	i = 0;
	n = 0;
	if (!s)
		return (0);
	if (!(str = (char **)malloc(sizeof(char *) * (ft_count_words(s, c) + 1))))
		return (0);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		j = 0;
		while (s[i + j] && s[i + j] != c)
			j++;
		if (s[i])
			if (!(str[n++] = word(s, i, j)))
				return (ft_free_str(str, n - 1));
		i += j;
	}
	str[n] = NULL;
	return (str);
}
