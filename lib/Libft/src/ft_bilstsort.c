/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bilstsort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowpea <esnowpea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 15:29:50 by esnowpea          #+#    #+#             */
/*   Updated: 2020/09/04 16:28:05 by esnowpea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_bilstlength(t_bilist *alst)
{
	t_bilist	*tmp;
	int			i;

	i = 0;
	if (alst)
	{
		tmp = alst;
		while (tmp->prev)
			tmp = tmp->prev;
		while (tmp)
		{
			i++;
			tmp = tmp->next;
		}
	}
	return (i);
}

void	ft_bilstswap(t_bilist *a, t_bilist *b)
{
	t_bilist	*tmp_a;
	t_bilist	*tmp_b;

	tmp_a = a->next;
	tmp_b = b->next;
	a->next = tmp_b;
	b->next = tmp_a;
	if (tmp_a)
		tmp_a->prev = b;
	if (tmp_b)
		tmp_b->prev = a;
	tmp_a = a->prev;
	tmp_b = b->prev;
	a->prev = tmp_b;
	b->prev = tmp_a;
	if (tmp_a)
		tmp_a->next = b;
	if (tmp_b)
		tmp_b->next = a;
}

void	ft_bilstsort(t_bilist **alst, int (*cmp)(void*, void*))
{
	t_bilist	*tmp;

	if (alst && *alst)
	{
		tmp = *alst;
		while (tmp->prev)
			tmp = tmp->prev;
		while (tmp->next)
		{
			if (cmp(tmp->content, tmp->next->content))
			{
				ft_bilstswap(tmp, tmp->next);
				while (tmp->prev)
					tmp = tmp->prev;
				continue;
			}
			tmp = tmp->next;
		}
		while (tmp->prev)
			tmp = tmp->prev;
		*alst = tmp;
	}
}