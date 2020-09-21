/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowpea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 11:59:57 by esnowpea          #+#    #+#             */
/*   Updated: 2020/07/27 16:10:37 by esnowpea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

t_str_len	ft_c(t_format_sp spec, va_list ap)
{
	char		c;
	char		*str;
	t_str_len	s;

	s.len = 0;
	s.str = 0;
	c = '%';
	if (spec.type != '%')
		c = va_arg(ap, int);
	if (!(str = ft_strnew(2)))
		return (s);
	*str = c;
	return (handler_flags(str, spec));
}
