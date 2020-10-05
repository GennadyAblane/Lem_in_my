/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablane <ablane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 14:11:38 by ablane            #+#    #+#             */
/*   Updated: 2020/09/22 12:15:05 by ablane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
#define LEM_IN_H
# include "libft.h"
# include "ft_printf.h"
# include "error_message.h"

typedef struct			s_room
{
	char				*name;
	int					coord_x;
	int					coord_y;
	t_bilist			*links;
	int					is_start;
	int					is_end;
}						t_room;

typedef struct			s_lem_in
{
	int					ants;
	t_bilist			*rooms;
	t_bilist			*corridors;
	t_bilist			*solutions;
}						t_lem_in;

void					terminate(char *s);
t_lem_in				*init_lem_in();
void					parsing_input(t_lem_in *lem_in);
t_room					*new_room(char *name, int x, int y);
//void					del_node(void *content, size_t content_size);
//void					find_solution(t_lem_in *lem_in);
//void					add_corridor(t_bilist *corridor, t_bilist **corridors);
char					*ft_free_line(char *line);
char					*ft_next_gnl(char *line);
void					print_result(int ants, t_bilist *solution);

#endif //LEM_IN_H
