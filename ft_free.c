/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablane <ablane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 15:03:40 by ablane            #+#    #+#             */
/*   Updated: 2020/09/21 15:11:17 by ablane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_free_line(char *line)
{
	if (line)
	{
		free(line);
		line = NULL;
	}
}

char	*ft_next_gnl(char *line)
{
	ft_free_line(line);
	if (get_next_line(0, &line) > 0)
		return (line);
	return (NULL);
}