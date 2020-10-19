/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablane <ablane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 14:11:38 by ablane            #+#    #+#             */
/*   Updated: 2020/10/09 14:50:18 by ablane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
#define LEM_IN_H
# include "libft.h"
# include "ft_printf.h"
# include "error_message.h"
# include <fcntl.h>

typedef struct			s_room
{
	char				*name;
	int					coord_x;
	int					coord_y;
	t_bilist			*links;
	t_bilist			*removed_links;
	struct s_room		*parent;
	int					is_start;
	int					is_end;
}						t_room;

typedef struct			s_lem_in
{
	int					ants;
	t_room				*start_room;
	t_room				*end_room;
	t_bilist			*rooms;
	t_bilist			*corridors;
	t_bilist			*solutions;
}						t_lem_in;

t_lem_in				*init_lem_in();

t_room					*new_room(char *name, int x, int y);

t_bilist				*find_short_corridor(t_room *end_room);

int						find_length_corridor_with_ants(int ants, t_bilist *solution);

void					terminate(char *s);
void					find_solution(t_lem_in *lem_in);
void					parsing_input(t_lem_in *lem_in, int fd);
void					print_result(int ants, t_lem_in *lem_in);
void					del_node(void *content, size_t content_size);
void					find_parant(t_room *start, t_bilist *dont_visit);
void					add_corridor(t_bilist *corridor, t_bilist **corridors);

char					*ft_free_line(char *line);
char					*ft_next_gnl(char *line, int fd);

#endif //LEM_IN_H
