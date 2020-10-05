/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_result.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablane <ablane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 13:27:11 by ablane            #+#    #+#             */
/*   Updated: 2020/10/05 14:47:46 by ablane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		find_max_length_corridor(t_bilist *corridors)
{
	t_bilist	*corridor;
	int			k;
	int			len;

	len = 0;
	corridor = corridors;
	while (corridor)
	{
		k = ft_bilstlength(((t_bilist**)&(corridor->content)));
		if (k > len)
			len = k;
		corridor = corridor->next;
	}
	return (len);
}

int		find_length_corridor_with_ants(int ants, t_bilist *solution)
{
	t_bilist	*corridor;
	int			n;
	int			max_len;

	max_len = find_max_length_corridor(solution);
	n = ft_bilstlength(&solution);
	corridor = solution;
	while (corridor)
	{
		if (ants > 0)
			ants -= max_len -
					ft_bilstlength(((t_bilist**)&(corridor->content)));
		else
			return (max_len);
		corridor = corridor->next;
	}
	return (max_len + (ants / n) + (ants % n));
}

void print_result(int ants, t_bilist *solution)
{
	int i;
	int j;
	int l;
	char ***array;
	int n;
	t_bilist *tmp1;
	t_bilist *tmp2;

	n = find_length_corridor_with_ants(ants, solution) - 1;
	array = (char***)ft_memalloc(sizeof(char**) * n);
	i = 0;
	while (i < n)
		array[i++] = (char**)ft_memalloc(sizeof(char*) * ants);
	i = 0;
	j = 0;
	while (i < n)
	{
		tmp1 = solution;
		while (tmp1 && j < ants && j < n * (i + 1))
		{
			tmp2 = ((t_bilist*)tmp1->content)->next;
			l = i;
			while (tmp2 && l < n)
			{
				array[l][j] = ((t_room*)tmp2->content)->name;
				l++;
				tmp2 = tmp2->next;
			}
			tmp1 = tmp1->next;
			j++;
		}
		i++;
	}
	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < ants)
		{
			if (array[i][j])
				ft_printf("L%d-%s%s", j + 1, array[i][j], " ");
			j++;
		}
		ft_printf("\n");
		i++;
	}
}