/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bilstdelone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowpea <esnowpea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 13:20:23 by esnowpea          #+#    #+#             */
/*   Updated: 2020/09/04 20:49:37 by esnowpea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bilstdelone(t_bilist **alst, void (*del)(void*, size_t))
{
	t_bilist	*tmp;

	if (!alst || !*alst || !del)
		return ;
	tmp = *alst;
	*alst = tmp->next;
	if (tmp->next)
		tmp->next->prev = 0;
	(*del)(tmp->content, tmp->content_size);
	free(tmp);
}

void	ft_bilstdelone_back(t_bilist **alst, void (*del)(void*, size_t))
{
	t_bilist	*tmp;

	if (!alst || !*alst || !del)
		return ;
	tmp = *alst;
	while (tmp->next)
		tmp = tmp->next;
	if (tmp->prev)
		tmp->prev->next = 0;
	(*del)(tmp->content, tmp->content_size);
	free(tmp);
}
