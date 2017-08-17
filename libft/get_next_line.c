/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddovzhik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 15:07:46 by ddovzhik          #+#    #+#             */
/*   Updated: 2017/02/05 15:07:48 by ddovzhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_fd	*search_fd_create(t_fd **first, const int fd, t_fd **prev)
{
	t_fd	*elem;

	elem = *first;
	*prev = NULL;
	while (elem && elem->fd != fd)
	{
		*prev = elem;
		elem = elem->next;
	}
	if (!elem && (elem = (t_fd *)malloc(sizeof(t_fd))))
	{
		*prev = NULL;
		elem->fd = fd;
		if (!(elem->tmp = ft_strnew(0)))
		{
			free(&elem);
			return (NULL);
		}
		elem->next = *first;
		*first = elem;
	}
	return (elem);
}

void	del_waste_elem(t_fd **first, t_fd *prev, t_fd **elem)
{
	if (!prev)
		*first = (*elem)->next;
	else
		prev->next = (*elem)->next;
	ft_strdel(&((*elem)->tmp));
	free(*elem);
}

int		newline(char **line, char **tmp, int k, int i)
{
	char	*s;

	while ((*tmp)[i] && (*tmp)[i] != '\n')
		i++;
	if ((*tmp)[i] == '\n')
	{
		if (!(*line = ft_strsub(*tmp, 0, i))
			|| !(s = ft_strsub(*tmp, i + 1, ft_strlen(*tmp) - i - 1)))
		{
			(*line) ? ft_strdel(line) : 0;
			return (-1);
		}
		ft_strdel(tmp);
		*tmp = s;
		return (1);
	}
	if (!k && **tmp)
	{
		if (!(*line = ft_strdup(*tmp)))
			return (-1);
		ft_strdel(tmp);
		*tmp = ft_strnew(0);
		return (1);
	}
	return (0);
}

int		gnl(const int fd, char **line, char **tmp, char *buff)
{
	int			q;
	char		*f;
	int			k;

	*line = NULL;
	k = 0;
	if (!ft_strchr(*tmp, '\n'))
		while ((k = read(fd, buff, BUFF_SIZE)))
		{
			f = *tmp;
			if (!(*tmp = ft_strjoin(f, buff)))
				return (-1);
			ft_strdel(&f);
			if ((q = newline(line, tmp, k, 0)))
				return (q);
			ft_strclr(buff);
		}
	if ((q = newline(line, tmp, k, 0)))
		return (q);
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static t_fd	*first;
	t_fd		*elem;
	t_fd		*prev;
	char		*buff;
	int			res;

	buff = NULL;
	res = -1;
	if (BUFF_SIZE < 1 || !line || fd < 0 || !(buff = ft_strnew(BUFF_SIZE)) ||
		read(fd, buff, 0) < 0)
	{
		if (buff)
			ft_strdel(&buff);
		return (-1);
	}
	if ((elem = search_fd_create(&first, fd, &prev)))
	{
		res = gnl(fd, line, &(elem->tmp), buff);
		if (!res && !(*(elem->tmp)))
			del_waste_elem(&first, prev, &elem);
	}
	ft_strdel(&buff);
	return (res);
}
