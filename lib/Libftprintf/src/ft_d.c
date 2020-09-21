/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowpea <esnowpea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 16:37:18 by esnowpea          #+#    #+#             */
/*   Updated: 2020/07/27 16:10:37 by esnowpea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char		*ft_d_size(t_format_sp spec, va_list ap, int base)
{
	if (spec.type == 'p')
		return (itoa_u((unsigned long long)va_arg(ap, void*), base));
	else if ((spec.size & 1) && (spec.type == 'd' || spec.type == 'i'))
		return (itoa_base_long((long long)va_arg(ap, long), base));
	else if ((spec.size & 2) && (spec.type == 'd' || spec.type == 'i'))
		return (itoa_base_long(va_arg(ap, long long), base));
	else if ((spec.size & 4) && (spec.type == 'd' || spec.type == 'i'))
		return (itoa_base_long((long long)((short)va_arg(ap, int)), base));
	else if ((spec.size & 8) && (spec.type == 'd' || spec.type == 'i'))
		return (itoa_base_long((long long)((char)va_arg(ap, int)), base));
	else if (spec.type == 'd' || spec.type == 'i')
		return (itoa_base_long((long long)va_arg(ap, int), base));
	else if (spec.size & 1)
		return (itoa_u((unsigned long long)va_arg(ap, unsigned long), base));
	else if (spec.size & 2)
		return (itoa_u(va_arg(ap, unsigned long long), base));
	else if (spec.size & 4)
		return (itoa_u((unsigned long long)(unsigned short)va_arg(ap, \
				unsigned int), base));
	else if (spec.size & 8)
		return (itoa_u((unsigned long long)(unsigned char)va_arg(ap, \
				unsigned int), base));
	else
		return (itoa_u((unsigned long long)va_arg(ap, unsigned int), base));
}

t_format_sp	ft_flags_d(t_format_sp spec, char *str)
{
	if ((spec.type == 'o' && (spec.accur > (int)ft_strlen(str))) || \
	*str == '0' || (spec.type != 'o' && !*str))
		spec.flags &= ~8;
	if (spec.type == 'p')
		spec.flags |= 8;
	if (*str == '-')
		ft_memcpy(spec.sign, "-", 1);
	else if ((spec.flags & 2) && (spec.type != 'x' && spec.type != 'X' \
	&& spec.type != 'p' && spec.type != 'o' && spec.type != 'u' \
	&& spec.type != 'b'))
		ft_memcpy(spec.sign, "+", 1);
	else if ((spec.flags & 4) && (spec.type != 'x' && spec.type != 'X' \
	&& spec.type != 'p' && spec.type != 'o' && spec.type != 'u' \
	&& spec.type != 'b'))
		ft_memcpy(spec.sign, " ", 1);
	else if (spec.flags & 8 && spec.type == 'o')
		ft_memcpy(spec.sign, "0", 1);
	else if (spec.flags & 8 && (spec.type == 'x' || spec.type == 'X' \
	|| spec.type == 'p'))
		ft_memcpy(spec.sign, "0X", 2);
	return (spec);
}

t_str_len	ft_d(t_format_sp spec, va_list ap)
{
	char		*str;
	t_str_len	s;
	int			len_s;
	int			sign;

	s.str = 0;
	s.len = 0;
	if (!(str = ft_d_size(spec, ap, spec.base)))
		return (s);
	if (*str == '0' && spec.accur == 0)
		ft_memset(str, '\0', ft_strlen(str));
	spec = ft_flags_d(spec, str);
	sign = *str == '-' ? 1 : 0;
	len_s = max((int)ft_strlen(str + sign), spec.accur);
	len_s += ft_strlen(spec.sign);
	if (!(s.str = ft_strnew(len_s)))
		return (s);
	ft_memset(s.str, '0', len_s);
	ft_memcpy(s.str + len_s - (int)ft_strlen(str + sign), str + sign, \
	(int)ft_strlen(str + sign));
	ft_memcpy(s.str, spec.sign, ft_strlen(spec.sign));
	free(str);
	return (handler_flags(s.str, spec));
}
