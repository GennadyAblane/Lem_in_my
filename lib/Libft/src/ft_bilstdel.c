/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bilstdel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowpea <esnowpea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 17:59:31 by esnowpea          #+#    #+#             */
/*   Updated: 2020/08/28 17:59:31 by esnowpea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bilstdel(t_bilist **alst, void (*del)(void*, size_t))
{
	t_bilist	*next;
	t_bilist	*tmp;

	if (!alst || !(*alst) || !del)
		return ;
	tmp = *alst;
	next = tmp->next;
	while (tmp)
	{
		ft_bilstdelone(&tmp, del);
		tmp = next;
		if (tmp)
			next = tmp->next;
	}
	*alst = tmp;
}
