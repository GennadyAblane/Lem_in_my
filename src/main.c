/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablane <ablane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 15:46:40 by ablane            #+#    #+#             */
/*   Updated: 2020/10/08 16:52:11 by ablane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

void	print_corridor(t_bilist *rooms)
{
	t_bilist	*room;

	room = rooms;
	while (room && room->prev)
		room = room->prev;
	while (room)
	{
		if (room->content)
			ft_printf("[%s]%s", ((t_room *) room->content)->name,
					  room->next ? "->" : "\n");
		room = room->next;
	}
}

void	terminate(char *s)
{
	ft_putendl_fd(s, 2);
	exit(0);
}

t_lem_in		*init_lem_in(void)
{
	t_lem_in	*lem_in;

	if (!(lem_in = (t_lem_in*)ft_memalloc(sizeof(t_lem_in))))
		terminate(ERR_MALC_INIT);
	return (lem_in);
}


void	ft_zafrish(t_lem_in *lem_in)
{
	t_bilist *tmp;

	while (lem_in->rooms)
	{
		tmp = lem_in->rooms;
		free(((t_room*)lem_in->rooms)->name);
		lem_in->rooms = tmp->next;
		free(tmp);
	}
}

void	ft_add_line_in_input(const char *line, int fd)
{
	int i;

	i = 0;
	if (!line)
		terminate(ERR_GNL_READ);
	if (line && !line[i])
		terminate(ERR_BAD_MAP);
	ft_putstr_fd(line, fd);
	ft_putchar_fd('\n', fd);
}

//void ft_create_n_open_file(t_lemin *lemin, char *file, int *fd)
//{
//	if (*fd > 1)
//		close(*fd);
//	*fd = open(file, O_RDWR | O_TRUNC | O_CREAT, S_IREAD | S_IWRITE);
//	if (*fd < 0)
//		ft_error_n_exit("Error open file\n", lemin, NULL, NULL);
//}

void	parsing_input_for_file(int *fd, char *file)
{
	int		gnl;
	char	*line;

	*fd = open(file, O_RDWR | O_TRUNC | O_CREAT, 0777);
	if (*fd < 0)
		terminate("FUCKING fd");
	while ((gnl = get_next_line(0, &line)) > 0)
	{
		ft_add_line_in_input(line, *fd);
		line = ft_free_line(line);
	}
	if (*fd > 1)
		close(*fd);
	*fd = open(file, O_RDONLY, 0777);
	if	(gnl < 0)
		terminate(ERR_GNL_READ);
}

int		main()
{
	t_lem_in	*lem_in;
	t_room		*tmp;
	int			fd;

	fd = 0;
	lem_in = init_lem_in();
	parsing_input_for_file(&fd, "../input_data.txt");
	parsing_input(lem_in, fd);
	print_corridor(lem_in->rooms);
	while (lem_in->rooms)
	{
		tmp = ((t_room*)lem_in->rooms->content);
		ft_printf("%s \t}- %d-%d -{ \t---%s\n", ((t_room*)
		lem_in->rooms->content)
		->name, (
				(t_room*)lem_in->rooms->content)->coord_x, ((t_room*)
				lem_in->rooms->content)->coord_y,
				  ((t_room*)tmp->links->content)->name);
		lem_in->rooms = lem_in->rooms->next;
	}
	//todo print fd;
	close(fd);
	print_result(lem_in->ants, lem_in->solutions);
//	ft_zafrish(lem_in);
//	free(lem_in);
	exit(0);
}
