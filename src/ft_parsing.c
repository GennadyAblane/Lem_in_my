/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablane <ablane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 15:11:27 by ablane            #+#    #+#             */
/*   Updated: 2020/10/02 14:35:04 by ablane           ###   ########.fr       */
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
		line = ft_free_line(line);
	while (line && line[i] != '\0')
	{
		if (line[i] < '0' || line[i] > '9')
			return (0);
		i++;
	}
	if (line)
	{
		ants = ft_atoi(line);
		line = ft_free_line(line);
	}
	return (ants);
}

char	*ft_add_this_name(char *line)
{
	int i;
	char *name;

	i = 0;
	while (line[i] != ' ' && line[i] != '\0')
		i++;
	if (line[i] == '\0' || (!(name = (char *)malloc(sizeof(char) * i + 1))))
		return (NULL);
	name[i--] = '\0';
	while (i != -1)
	{
		name[i] = line [i];
		if (name[i] == '-')
		{
			name = ft_free_line(name);
			i = 0;
		}
		i--;
	}
	return (name);
}

int		ft_search_coordin(int i, char *line)
{
	while (line[i] != ' ' && line[i] != '\t' && line[i] != '\0')
		i++;
	while ((line[i] == ' ' || line[i] == '\t') && line[i] != '\0')
		i++;
	return (i);
}

void	ft_add_coordinate(t_room *room, char *line, int i)
{
	if (!room->name)
		return ;
	while (line[i] != ' ' && line[i] != '\0')
		i++;
	if (line[i] == '\0')
		terminate(ERR_BAD_COORD);
	i = ft_search_coordin(i, line);
	room->coord_x = ft_atoi(&line[i]);
	i = ft_search_coordin(i, line);
	if (line[i] == '\0')
		terminate(ERR_BAD_COORD);
	room->coord_y = ft_atoi(&line[i]);
}

char	*ft_search_name(char *line)
{
	char *name;
	int i;

	i = 0;
	while (line[i] != '-' && line[i] != '\0')
		i++;
	if (line[i] == '-' && (line[i + 1] == '-' || line[i + 1] == '\0'))
	{
		line = ft_free_line(line);
		terminate(ERR_BAD_LINKS);
	}
	name = ft_strnew(i);
	if (!name)
		terminate(ERR_MALC_INIT);
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
	if (!name)
		return (NULL);
	while (tmp && (!(ft_strequ(((t_room *)tmp->content)->name, name))))
		tmp = tmp->next;
	if (tmp)
		return ((t_room *)tmp->content);
	return (NULL);
}

int		ft_clear_name_tmp(t_room *tmp1, t_room *tmp2, char *n1, char *n2)
{
	if (n1)
		n1 = ft_free_line(n1);
	if (n2)
		n2 = ft_free_line(n2);
	if (tmp1)
	{
		free(tmp1);
		tmp1 = NULL;
	}
	if (tmp1)
	{
		free(tmp2);
		tmp2 = NULL;
	}
	return (1);
}

int 	ft_add_edge(t_lem_in *lem_in, char *line)
{
	char *name1;
	char *name2;
	t_room *tmp1;
	t_room *tmp2;
	int i;

	i = 0;
	if (line && ft_strlen(line) > 1 && line[0] == '#')
		return (1);
	name1 = ft_search_name(line);
	while (line[i] != '-' && line[i] != '\0')
		i++;
	name2 = ft_search_name(&line[i + 1]);
	tmp1 = ft_search_name_struct(lem_in->rooms, name1);
	tmp2 = ft_search_name_struct(lem_in->rooms, name2);
	if (!tmp1 || !tmp2 || !name1 || !name2)
		terminate(ERR_BAD_LINKS);
	name1 = ft_free_line(name1);
	name2 = ft_free_line(name2);
	ft_bilstadd(&tmp1->links, ft_bilstnew(tmp2, sizeof(t_room)));
	ft_bilstadd(&tmp2->links, ft_bilstnew(tmp1, sizeof(t_room)));
	return (1);
}

void	ft_start_end(t_room *room, int start)
{
	if (!start)
		return ;
	if (start == 1)
		room->is_start = 1;
	if (start == 2)
		room->is_end = 1;
}

char	*ft_search_name_for_start_end(char *line)
{
	int i;

	i = 0;
	if (ft_strequ(line, "##start") || ft_strequ(line, "##end"))
		i = 1;
	while (line && ft_strlen(line) > 0 && line[0] == '#')
	{
		line = ft_next_gnl(line);
		if ((ft_strequ(line, "##start") || ft_strequ(line, "##end")) && i == 1)
			return (ft_free_line(line));
	}
	return (line);
}

void	ft_add_vertex(t_lem_in *lem_in, char **line)
{
	int len;
	int start;
	t_room *room;

	start = 0;
	len = ft_strlen(*line);
	if (*line && len > 1 && *line[0] == '#')
	{
		if (ft_strequ(*line, "##start"))
			start = 1;
		else if (ft_strequ(*line, "##end"))
			start = 2;
		else
			return ;
		*line = ft_search_name_for_start_end(*line);
	}
	if (!*line)
		return ;
	if (*line && *line[0] == 'L')
		terminate(ERR_BAD_BIG_L);
	room = new_room(ft_add_this_name(*line), 0 , 0);
	ft_start_end(room, start);
	ft_add_coordinate(room, *line, 0);
	ft_bilstadd(&(lem_in->rooms), ft_bilstnew(room, sizeof(t_room)));
}

void	ft_check_start_end(t_room *room, int *start, int *end)
{
	if (room->is_start == 1)
		*start = 1;
	if (room->is_end == 1)
		*end = 1;
}

void	ft_check_list_name_room(t_bilist *this, t_bilist *tmp)
{
	int x;
	int y;

	x = ((t_room*)this->content)->coord_x;
	y = ((t_room*)this->content)->coord_y;
	while (tmp)
	{
		if ((ft_strequ(((t_room*)this->content)->name,
		((t_room*)tmp->content)->name)))
			terminate(ERR_BAD_ROOMS);
		else if (((t_room*)tmp->content)->coord_y == y &&
		((t_room*)tmp->content)->coord_x == x)
			terminate(ERR_BAD_COORD);
		else
			tmp = tmp->next;
	}
}

void	ft_check_limits(t_room *room, int *start, int *end)
{
	if (room->is_start)
		*start = 1;
	if (room->is_end)
		*end = 1;
}

int		check_start_and_end(t_lem_in *lem_in)
{
	int start;
	int end;
	t_bilist *tmp;
	t_bilist *this;

	start = 0;
	end = 0;
	if (!lem_in->rooms)
		return (0);
	this = lem_in->rooms;
	tmp = this->next;
	while (this->next)
	{
		ft_check_limits((t_room*)tmp->content, &start, &end);
		ft_check_list_name_room(this, tmp);
		this = this->next;
		tmp = this->next;
	}
	if (!start || !end)
		return (0);
	return (1);
}

void	ft_last_chek(int gnl, t_lem_in *lem_in)
{
	if (gnl < 0)
		terminate(ERR_GNL_READ);
	if (!check_start_and_end(lem_in))
		terminate(ERR_BAD_INPUT);
}

int		ft_read_edge(t_lem_in *lem_in, int gnl)
{
	char	*line;

	line = NULL;
	while (gnl > 0)
	{
		gnl = get_next_line(0, &line);
		if (gnl < 1)
			break ;
		if (ft_strchr(line, '-') || (ft_strchr(line, '#')))
			ft_add_edge(lem_in, line);
		else
		{
			line = ft_free_line(line);
			terminate(ERR_BAD_LINKS);
		}
		line = ft_free_line(line);
	}
	return (gnl);
}

void	parsing_input(t_lem_in *lem_in)
{
	char	*line;
	int		gnl;
	int 	i;

	i = 0;
	line = NULL;
	lem_in->ants = ft_ants();
	while (i == 0 && (gnl = get_next_line(0, &line)) > 0)
	{
		if ((ft_strchr(line, ' ') || ft_strchr(line, '#'))
		&& !ft_strchr(line, '-'))
			ft_add_vertex(lem_in, &line);
		else
			i = ft_add_edge(lem_in, line);
		line = ft_free_line(line);
	}
	if (gnl > 0)
		gnl = ft_read_edge(lem_in, gnl);
	ft_last_chek(gnl, lem_in);
}