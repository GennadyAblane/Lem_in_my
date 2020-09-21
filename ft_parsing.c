/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablane <ablane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 15:11:27 by ablane            #+#    #+#             */
/*   Updated: 2020/09/21 16:44:53 by ablane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_ants()
{
	char	*line;
	int		ants;
	int i;

	i = 0;
	ants = 0;
	line = NULL;
	while (get_next_line(0, &line) > 0 && line && line[i] == '#')
		ft_free_line(line);
	while (line && line[i] != '\0')
	{
		if (line[i] == ' ' || line[i] == '\t')
			return (0);
		i++;
	}
	if (line)
	{
		ants = ft_atoi(line);
		free(line);
	}
	return (ants);
}

char	*ft_add_this_name(char *line)
{
	int i;
	char *name;

	i = 0;
	if (!line)
		return (NULL);
	while (line[i] != ' ' && line[i] != '\0')
		i++;
	if (line[i] == '\0' || (!(name = (char *)malloc(sizeof(char) * i + 1))))
		return (NULL);
	name[i] = '\0';
	while (i != -1)
	{
		name[i] = line [i];
		if (name[i] == '-')
		{
			ft_free_line(name);
			i = 0;
		}
		i--;
	}
	return (name);
}

void	ft_add_coordinate(t_room *room, char *line, int i)
{
	if (!room->name)
		return ;
	while (line[i] != ' ' && line[i] != '\0')
		i++;
	if (line[i] == '\0')
	{
		ft_free_line(room->name);
		return ;
	}
	i++;
	room->coord_x = ft_atoi(&line[i]);
	while (line[i] != ' ' && line[i] != '\0')
		i++;
	if (line[i] == '\0')
	{
		ft_free_line(room->name);
		return ;
	}
	i++;
	room->coord_y = ft_atoi(&line[i]);
}

char	*ft_search_name(char *line)
{
	char *name;
	int i;

	i = 0;
	while (line[i] != '-' && line[i] != '\0')
		i++;
	name = ft_strnew(i);
	name[i--] = '\0';
	while (i != -1)
	{
		name[i] = line[i];
		i--;
	}
	return (name);
}

t_room *ft_search_name_struct(t_bilist *room, char *name)
{
	t_bilist *tmp;

	tmp = room;
	while (!(ft_strequ(((t_room *)tmp->content)->name, name)))
		tmp = tmp->next;
	return ((t_room *)tmp->content);
}

void	ft_add_edge(t_lem_in *lem_in, char *line)
{
	char *name1;
	char *name2;
	t_room *tmp1;
	t_room *tmp2;
	int i;

	i = 0;
	if (line && ft_strlen(line) > 1 && line[0] == '#')
		return ;
	name1 = ft_search_name(line);
	while (line[i] != '-' && line[i] != '\0')
		i++;
	name2 = ft_search_name(&line[i]);
	tmp1 = ft_search_name_struct(lem_in->rooms, name1);
	tmp2 = ft_search_name_struct(lem_in->rooms, name2);
	ft_bilstadd(&tmp1->links, ft_bilstnew(tmp2, sizeof(t_room)));
	ft_bilstadd(&tmp2->links, ft_bilstnew(tmp1, sizeof(t_room)));
}

void	ft_start_end(t_room *room, int start)
{
	if (!start)
		return ;
	if (start == 1)
		room->is_start = 1;
	else
		room->is_end = 1;
}


void	ft_add_vertex(t_lem_in *lem_in, char *line)
{
	int len;
	int start;
	t_room *room;

	start = 0;
	len = ft_strlen(line);
	if (line && len > 1 && line[0] == '#')
	{
		if (ft_strequ(line, "##start"))
			start = 1;
		else if (ft_strequ(line, "##end"))
			start = 2;
		else
			return ;
		line = ft_next_gnl(line);
	}
	room = new_room(NULL, 0 , 0);
	room->name = ft_add_this_name(line);
	ft_start_end(room, start);
	ft_add_coordinate(room, line, 0);
	ft_bilstadd(&lem_in->rooms, ft_bilstnew(room, sizeof(t_room)));
}

void	ft_last_chek(int gnl, t_lem_in *lem_in)
{
	if (gnl < 0)
		terminate(ERR_GNL_READ);
//	if (!check_start_and_end(lem_in)) //todo CHECK!!!
//		terminate(ERR_BAD_INPUT);
}

void	parsing_input(t_lem_in *lem_in)
{
	char	*line;
	int		gnl;
	int 	i;

	i = 0;
	line = NULL;
	lem_in->ants = ft_ants();
	while ((gnl = get_next_line(0, &line)) > 0 && i == 0)
	{
		if (!ft_strchr(line, ' '))
			ft_add_vertex(lem_in, line);
		else
		{
			i = 1;
			ft_add_edge(lem_in, line);
		}
		ft_free_line(line);
	}
	while (gnl > 0 && (gnl = get_next_line(0, &line)) > 0)
	{
		ft_add_edge(lem_in, line);
		ft_free_line(line);
	}
	ft_last_chek(gnl, lem_in);
}