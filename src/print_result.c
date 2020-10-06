/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_result.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablane <ablane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 13:27:11 by ablane            #+#    #+#             */
/*   Updated: 2020/10/06 18:12:11 by ablane           ###   ########.fr       */
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

void	ft_step_ants2(t_bilist *solution)
{
	t_bilist *tmp;

	tmp = (t_bilist*)solution->content;
	while (tmp->next)
		tmp = tmp->next;
	while (tmp->prev)
	{
		if (tmp->content_size && tmp->next)
		{
			tmp->next->content_size = tmp->content_size;
			tmp->content_size = 0;
		}
		tmp = tmp->prev;
	}
}

void	ft_step_ants(t_bilist *solution)
{
	t_bilist *tmp;

	tmp = solution;
	 while (tmp)
	 {
	 	ft_step_ants2(tmp);
	 	tmp = tmp->next;
	 }
}

int		ft_next_step(int ants, int an, t_bilist *solution)
{
	t_bilist	*tmp_sol;
	t_bilist	*tmp;
	int			n;

	n = ants - an + 1;
	ft_step_ants(solution);
	tmp_sol = solution;
	while (tmp_sol)
	{
		tmp = (t_bilist*) solution;
		tmp->content_size = n++;
		an--;
		tmp_sol = tmp_sol->next;
	}
	return (an);
}

int		ft_last_step_of_solution(t_bilist *solution)
{
	t_bilist *tmp;
	int i;

	i = 0;
	tmp = solution;
	while (tmp)
	{
		while (tmp->content)
		tmp = tmp->next;
	}
	return (i);
}

void	print_result(int ants, t_bilist *solution)
{
	int	an;

	an = ants;
	while (an > 0)
	{
		an = ft_next_step(ants, an, solution);
		print_current_position_ants(solution);
	}
	while (ft_last_step_of_solution(solution))
	{

		print_current_position_ants(solution);
	}
}