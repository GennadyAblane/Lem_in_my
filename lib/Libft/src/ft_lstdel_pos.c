/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel_pos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowpea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 14:00:53 by esnowpea          #+#    #+#             */
/*   Updated: 2020/10/13 16:04:42 by ablane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel_pos(t_list **alst, size_t n)
{
	size_t	i;
	t_list	*tmp;

	if (!alst && !(*alst))
		return ;
	i = 0;
	if (n == 0)
	{
		tmp = (*alst)->next;
		ft_lstdelone(alst, ft_del);
		alst = &tmp;
		return ;
	}
	while (i < n)
	{
		if (!(*alst))
			return ;
		i++;
		tmp = (*alst);
		(*alst) = (*alst)->next;
	}
	if (!(*alst))
		return ;
	tmp->next = (*alst)->next;
	ft_lstdelone(alst, ft_del);
}
