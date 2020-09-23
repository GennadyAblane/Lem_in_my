/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablane <ablane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 15:46:40 by ablane            #+#    #+#             */
/*   Updated: 2020/09/21 15:46:40 by ablane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

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


int main()
{
	t_lem_in *lem_in;


	lem_in = init_lem_in();
	parsing_input(lem_in);
	ft_printf("Hello, World!\n");
	exit(0);
}
