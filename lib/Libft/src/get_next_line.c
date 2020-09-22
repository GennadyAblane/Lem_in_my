/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablane <ablane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 15:39:41 by ablane            #+#    #+#             */
/*   Updated: 2020/07/27 16:12:05 by esnowpea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_cpline(char **ost, size_t n)
{
	char	*op;
	char	*tmp;
	size_t	i;
	ssize_t p;

	i = 0;
	if ((*ost)[i] == '\n')
		op = ft_strnew(0);
	else if ((*ost)[i] == '\0')
		return (NULL);
	else
	{
		op = ft_strnew(n);
		while (i < n)
		{
			op[i] = (*ost)[i];
			i++;
		}
	}
	n++;
	p = (ft_strlen(*ost) - n);
	tmp = ft_strsub(*ost, n, p);
	free(*ost);
	(*ost) = tmp;
	return (op);
}

int			ft_redjoin(char **ost, int fd)
{
	char	buf[BUFF_SIZE + 1];
	char	*tmp;
	ssize_t	res_read;

	res_read = read(fd, buf, BUFF_SIZE);
	if (res_read < 1)
	{
		if (res_read == 0)
			return (0);
		else
			return (-1);
	}
	buf[res_read] = '\0';
	tmp = ft_strjoin(*ost, buf);
	free(*ost);
	*ost = tmp;
	return (1);
}

int			ft_job(const int fd, char **line, char **ost)
{
	ssize_t	n;
	ssize_t res_read;

	res_read = 1;
	n = 0;
	while ((*ost)[n] != '\n' && res_read > 0)
	{
		if ((*ost)[n] == '\0')
		{
			if ((res_read = ft_redjoin(ost, fd)) < 1)
			{
				if ((*ost)[0] != '\0')
				{
					*line = (ft_cpline(ost, n));
					return (1);
				}
				ft_strdel(ost);
				return (res_read);
			}
			n--;
		}
		n++;
	}
	*line = (ft_cpline(ost, n));
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	static char *ost[4864];

	if (fd < 0 || !line || BUFF_SIZE < 1 ||
		(read(fd, NULL, 0)) < 0 || (fd > OPEN_MAX))
		return (-1);
	if (!ost[fd])
		ost[fd] = ft_strnew(0);
	return (ft_job(fd, line, &ost[fd]));
}