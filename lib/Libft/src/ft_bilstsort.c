/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bilstsort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowpea <esnowpea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 15:29:50 by esnowpea          #+#    #+#             */
/*   Updated: 2020/10/13 16:04:42 by ablane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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