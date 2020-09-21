/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowpea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 15:24:26 by esnowpea          #+#    #+#             */
/*   Updated: 2020/07/27 16:10:38 by esnowpea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

/*
**	FLAGS:
**	'-'	- 00001
**	'+'	- 00010
**	' '	- 00100
**	'#'	- 01000
**	'0'	- 10000
*/

int			max(int a, int b)
{
	return (a > b ? a : b);
}

int			min(int a, int b)
{
	return (a < b ? a : b);
}

void		up_to_low(char **s)
{
	int		i;
	int		len;
	char	*str;

	str = *s;
	i = 0;
	len = ft_strlen(str);
	while (i < len)
	{
		str[i] = (str[i] >= 'A' && str[i] <= 'Z') ? str[i] + 32 : str[i];
		i++;
	}
}

void		hf_help_func(t_str_len s, int len_s, t_format_sp spec)
{
	ft_memset(s.str, '0', s.len - len_s);
	if (ft_strlen(spec.sign))
	{
		ft_memcpy(s.str + s.len - len_s, "00", ft_strlen(spec.sign));
		ft_memcpy(s.str, spec.sign, ft_strlen(spec.sign));
	}
}

t_str_len	handler_flags(char *str, t_format_sp spec)
{
	int			len_s;
	t_str_len	s;

	len_s = spec.type != 'c' ? (int)ft_strlen(str) : 1;
	s.len = max(len_s, spec.width);
	if (!(s.str = ft_strnew(s.len)))
		return (s);
	ft_memset(s.str, ' ', s.len);
	if (spec.flags & 1)
		ft_memcpy(s.str, str, len_s);
	else
		ft_memcpy(s.str + s.len - len_s, str, len_s);
	if (spec.flags & 16 && (spec.accur < 0 || spec.type == 'f') &&
	!(spec.flags & 1))
		hf_help_func(s, len_s, spec);
	if (spec.type == 'x' || spec.type == 'p' || spec.type == 'e'
	|| spec.type == 'g')
		up_to_low(&s.str);
	free(str);
	return (s);
}
