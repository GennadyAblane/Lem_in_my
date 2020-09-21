/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowpea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 13:51:48 by esnowpea          #+#    #+#             */
/*   Updated: 2020/07/27 16:10:38 by esnowpea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*begin;
	t_list	*tmp;
	t_list	*new;

	if (!lst || !f)
		return (0);
	tmp = 0;
	begin = 0;
	while (lst)
	{
		new = ft_lstnew(lst->content, lst->content_size);
		if (!new)
		{
			ft_lstdel(&begin, ft_del);
			return (0);
		}
		new = (*f)(lst);
		ft_lstadd_back(&tmp, new);
		lst = lst->next;
	}
	return (tmp);
}
