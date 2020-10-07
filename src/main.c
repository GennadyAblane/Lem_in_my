/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablane <ablane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 15:46:40 by ablane            #+#    #+#             */
/*   Updated: 2020/10/07 17:33:04 by ablane           ###   ########.fr       */
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
	while (line[i])
		ft_putchar_fd(line[i++], fd);
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

int		parsing_input_for_file()
{
	int		op = O_RDWR;
	int		gnl;
	int		fd;
	char	*line;

	if((fd = open("./input_data.txt", O_RDWR)) < 1)
		terminate("FUCKING fd");
	while ((gnl = get_next_line(0, &line)) > 0)
	{
		ft_add_line_in_input(line, fd);
		line = ft_free_line(line);
	}
	if	(gnl < 1)
		terminate(ERR_GNL_READ);
	return (fd);
}

int		main()
{
	t_lem_in	*lem_in;
	t_room		*tmp;
	int			fd;

	lem_in = init_lem_in();
	fd = parsing_input_for_file();
	parsing_input(lem_in, fd);
	print_corridor(lem_in->rooms);
	ft_printf("Hello, World!\n");
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
	print_result(lem_in->ants, lem_in->solutions);
//	ft_zafrish(lem_in);
//	free(lem_in);
	exit(0);
}
