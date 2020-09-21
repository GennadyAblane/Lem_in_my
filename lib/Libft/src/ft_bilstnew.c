/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bilistnew.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowpea <esnowpea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 13:15:16 by esnowpea          #+#    #+#             */
/*   Updated: 2020/08/28 13:15:16 by esnowpea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bilist	*ft_bilstnew(void const *content, size_t content_size)
{
	t_bilist	*bilist;

	bilist = (t_bilist*)malloc(sizeof(t_bilist));
	if (!bilist)
		return (0);
	bilist->next = NULL;
	bilist->prev = NULL;
	bilist->content = 0;
	bilist->content_size = 0;
	if (!content)
		return (bilist);
	bilist->content = (void*)content;
	bilist->content_size = content_size;
	return (bilist);
}
