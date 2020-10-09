/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablane <ablane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 15:03:40 by ablane            #+#    #+#             */
/*   Updated: 2020/09/24 14:08:34 by ablane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char	*ft_free_line(char *line)
{
	if (line)
	{
		free(line);
		line = NULL;
	}
	return (line);
}

char	*ft_next_gnl(char *line, int fd)
{
	line = ft_free_line(line);
	if (get_next_line(fd, &line) > 0)
		return (line);
	return (NULL);
}
