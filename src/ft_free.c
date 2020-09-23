/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablane <ablane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 15:03:40 by ablane            #+#    #+#             */
/*   Updated: 2020/09/22 16:38:50 by ablane           ###   ########.fr       */
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

char	*ft_next_gnl(char *line)
{
	line = ft_free_line(line);
	if (get_next_line(0, &line) > 0)
		return (line);
	return (NULL);
}

t_room			*new_room(char *name, int x, int y)
{
	t_room		*room;

	if (!(room = (t_room*)ft_memalloc(sizeof(t_room))))
		terminate(ERR_MALC_INIT);
	room->name = name;
	room->coord_x = x;
	room->coord_y = y;
	return (room);
}