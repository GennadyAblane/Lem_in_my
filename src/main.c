/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablane <ablane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 15:46:40 by ablane            #+#    #+#             */
/*   Updated: 2020/10/05 13:25:34 by ablane           ###   ########.fr       */
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

int main()
{
	t_lem_in	*lem_in;
	t_room		*tmp;


	lem_in = init_lem_in();
	parsing_input(lem_in);
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
