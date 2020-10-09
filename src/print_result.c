/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_result.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablane <ablane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 13:27:11 by ablane            #+#    #+#             */
/*   Updated: 2020/10/09 15:57:16 by ablane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

//int		find_max_length_corridor(t_bilist *corridors)
//{
//	t_bilist	*corridor;
//	int			k;
//	int			len;
//
//	len = 0;
//	corridor = corridors;
//	while (corridor)
//	{
//		k = ft_bilstlength(((t_bilist**)&(corridor->content)));
//		if (k > len)
//			len = k;
//		corridor = corridor->next;
//	}
//	return (len);
//}
//
//int		find_length_corridor_with_ants(int ants, t_bilist *solution)
//{
//	t_bilist	*corridor;
//	int			n;
//	int			max_len;
//
//	max_len = find_max_length_corridor(solution);
//	n = ft_bilstlength(&solution);
//	corridor = solution;
//	while (corridor)
//	{
//		if (ants > 0)
//			ants -= max_len -
//					ft_bilstlength(((t_bilist**)&(corridor->content)));
//		else
//			return (max_len);
//		corridor = corridor->next;
//	}
//	return (max_len + (ants / n) + (ants % n));
//}
//
//void print_result(int ants, t_bilist *solution)
//{
//	int i;
//	int j;
//	int l;
//	char ***array;
//	int n;
//	t_bilist *tmp1;
//	t_bilist *tmp2;
//
//	n = find_length_corridor_with_ants(ants, solution) - 1;
//	array = (char***)ft_memalloc(sizeof(char**) * n);
//	i = 0;
//	while (i < n)
//		array[i++] = (char**)ft_memalloc(sizeof(char*) * ants);
//	i = 0;
//	j = 0;
//	while (i < n)
//	{
//		tmp1 = solution;
//		while (tmp1 && j < ants && j < n * (i + 1))
//		{
//			tmp2 = ((t_bilist*)tmp1->content)->next;
//			l = i;
//			while (tmp2 && l < n)
//			{
//				array[l][j] = ((t_room*)tmp2->content)->name;
//				l++;
//				tmp2 = tmp2->next;
//			}
//			tmp1 = tmp1->next;
//			j++;
//		}
//		i++;
//	}
//	i = 0;
//	while (i < n)
//	{
//		j = 0;
//		while (j < ants)
//		{
//			if (array[i][j])
//				ft_printf("L%d-%s%s", j + 1, array[i][j], " ");
//			j++;
//		}
//		ft_printf("\n");
//		i++;
//	}
//}

size_t	ft_count_len_corridor(t_bilist *cor)
{
	size_t	i;

	i = 0;
	while (cor)
	{
		cor = cor->next;
		i++;
	}
	return (i);
}

size_t	ft_one_solution_add_ants(t_bilist *sol, size_t an)
{
	sol->content_size = sol->content_size + an;
	an = 0;
	return (an);
}

void	ft_add_ants_solution(t_bilist *solution, int ants)
{
	t_bilist *tmp;
	size_t	an;

	an = (size_t)ants;
	while (an)
	{
		tmp = solution;
		while (tmp)
		{
			if (!tmp->next && !tmp->prev)
				an = ft_one_solution_add_ants(tmp, an);
			if (tmp->next && tmp->content_size <= tmp->next->content_size && an)
			{
				tmp->content_size++;
				an--;
			}
			if (tmp->prev && tmp->content_size < tmp->prev->content_size && an)
			{
				tmp->content_size++;
				an--;
			}
			tmp = tmp->next;
		}
	}
}

void	ft_subtract_len_corridor_content_size(t_bilist *solution)
{
	t_bilist *tmp;

	tmp = solution;
	while (tmp)
	{
		tmp->content_size -= ft_count_len_corridor((t_bilist*)tmp);
		tmp = tmp->next;
	}
}

void	ft_start_ants_first_room(t_bilist *solution, int ants)
{
	t_bilist *tmp;

	tmp = solution;
	while (tmp)
	{
		tmp->content_size = ft_count_len_corridor((t_bilist*)tmp->content);
		tmp = tmp->next;
	}
	ft_add_ants_solution(solution, ants);
	ft_subtract_len_corridor_content_size(solution);
}

void	ft_step_ants_corridor(t_bilist *cor, size_t *num_ant, int ants)
{
	t_bilist *tmp;

	tmp = (t_bilist*)cor->content;
	while (tmp->next)
		tmp = tmp->next;
	while (tmp->prev)
	{
		tmp->content_size = tmp->prev->content_size;
		tmp->prev->content_size = 0;
		tmp = tmp->prev;
	}
	if (cor->content_size && *num_ant <= (size_t)ants)
	{
		tmp->content_size = *num_ant;
		*num_ant = *num_ant + 1;
		cor->content_size--;
	}
}

int		ft_chek_solution_room_for_ants(t_bilist *solution, size_t an)
{
	t_bilist *tmp;
	t_bilist *cor;

	if (an)
		return (1);
	tmp = solution;
	while (tmp)
	{
		if(tmp->content_size)
			return (1);
		cor = (t_bilist*)tmp->content;
		while (cor)
		{
			if (cor->content_size)
				return (1);
			cor = cor->next;
		}
		tmp = tmp->next;
	}
	return (0);
}

int		ft_step_ants_room(t_bilist *solution, int *ant, int ants)
{
	t_bilist	*tmp;
	size_t		an;

	an = *ant;
	tmp = solution;
	while (tmp)
	{
		ft_step_ants_corridor(tmp, &an, ants);
		tmp = tmp->next;
	}
	*ant = an;
	return (ft_chek_solution_room_for_ants(solution, an));
}

int		ft_search_max_len_corridors(t_bilist *solution)
{
	int len;
	int len_max;
	t_bilist *tmp;

	len_max = 0;
	tmp = solution;
	while (tmp)
	{
		len = ft_count_len_corridor((t_bilist*)tmp->content);
		if (len > len_max)
			len_max = len;
		tmp = tmp->next;
	}
	return (len_max);
}

int 	ft_print_room(t_bilist *cor, int i, int n)
{
	while (cor && n <= i)
	{
		if(cor->content_size)
		{
			ft_printf("L%d-%s", cor->content_size, (char*)cor->content);
			if(cor->next && cor->next->content_size)
				ft_printf(" ");
		}
		n++;
		cor = cor->next;
	}
	return (n);
}

void	print_current_position_ants(t_bilist *solution)
{
	t_bilist *tmp;
	t_bilist *cor;
	int i;
	int n;
	int max_len;

	i = 0;
	n = 0;
	max_len = ft_search_max_len_corridors(solution);
	tmp = solution;
	while (tmp && i <= max_len)
	{
		cor = (t_bilist*)tmp->content;
		n = ft_print_room(cor, i, n);
		tmp = tmp->next;
		if (n > i && !tmp)
		{
			tmp = solution;
			i++;
		}
		n = 0;
	}
}

void	print_result(int ants, t_bilist *solution)
{
	int j;
	int	ant;

	j = 1;
	ant = 1;
	ft_start_ants_first_room(solution, ants);
	while (j > 0)
	{
		j = ft_step_ants_room(solution, &ant, ants);
		if (ant > ants + 1)
			terminate("WTF?!"); //todo такого быть не должно!
		print_current_position_ants(solution);
	}
}