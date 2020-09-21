/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowpea <esnowpea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 16:01:45 by esnowpea          #+#    #+#             */
/*   Updated: 2020/07/27 16:10:38 by esnowpea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

t_type		fun_to_type(char c, t_str_len (*func)(t_format_sp, va_list))
{
	t_type		type;

	type.type = c;
	type.func = func;
	return (type);
}

void		array_t_type(t_type type[])
{
	type[0] = fun_to_type('c', &ft_c);
	type[1] = fun_to_type('%', &ft_c);
	type[2] = fun_to_type('s', &ft_s);
	type[3] = fun_to_type('d', &ft_d);
	type[4] = fun_to_type('i', &ft_d);
	type[5] = fun_to_type('p', &ft_d);
	type[6] = fun_to_type('o', &ft_d);
	type[7] = fun_to_type('u', &ft_d);
	type[8] = fun_to_type('x', &ft_d);
	type[9] = fun_to_type('X', &ft_d);
	type[10] = fun_to_type('b', &ft_d);
	type[11] = fun_to_type('f', &ft_f);
	type[12] = fun_to_type('e', &ft_e);
	type[13] = fun_to_type('E', &ft_e);
	type[14] = fun_to_type('g', &ft_g);
	type[15] = fun_to_type('G', &ft_g);
}

t_str_len	find_function(t_format_sp spec, va_list ap)
{
	int			i;
	t_str_len	s;
	t_type		type[SPEC_FUN];

	array_t_type(type);
	i = 0;
	while (i < SPEC_FUN)
	{
		if (type[i].type == spec.type)
			return (type[i].func(spec, ap));
		i++;
	}
	s.len = 0;
	s.str = ft_strnew(s.len);
	return (s);
}

int			ft_printf(const char *format, ...)
{
	va_list		ap;
	char		*ptr;
	int			len_out;
	t_str_len	s;

	va_start(ap, format);
	len_out = 0;
	while ((ptr = ft_strchr(format, '%')))
	{
		write(FD, format, (int)ft_strlen(format) - (int)ft_strlen(ptr));
		len_out += (int)ft_strlen(format) - (int)ft_strlen(ptr);
		format = ptr + 1;
		s = find_function(parsing(&format, ap), ap);
		if (s.str == NULL && s.len == 0)
			exit(EXIT_FAILURE);
		write(FD, s.str, s.len);
		len_out += s.len;
		free(s.str);
	}
	write(FD, format, (int)ft_strlen(format));
	len_out += (int)ft_strlen(format);
	va_end(ap);
	return (len_out);
}

int			ft_printf_fd(int fd, const char *format, ...)
{
	va_list		ap;
	char		*ptr;
	int			len_out;
	t_str_len	s;

	va_start(ap, format);
	len_out = 0;
	while ((ptr = ft_strchr(format, '%')))
	{
		write(fd, format, (int)ft_strlen(format) - (int)ft_strlen(ptr));
		len_out += (int)ft_strlen(format) - (int)ft_strlen(ptr);
		format = ptr + 1;
		s = find_function(parsing(&format, ap), ap);
		if (s.str == NULL && s.len == 0)
			exit(EXIT_FAILURE);
		format += *format ? 1 : 0;
		write(fd, s.str, s.len);
		len_out += s.len;
		free(s.str);
	}
	write(fd, format, (int)ft_strlen(format));
	len_out += (int)ft_strlen(format);
	va_end(ap);
	return (len_out);
}
