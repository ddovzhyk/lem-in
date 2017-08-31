/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_rooms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddovzhik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 14:59:30 by ddovzhik          #+#    #+#             */
/*   Updated: 2017/08/07 14:59:33 by ddovzhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room	*new_room(char *name, int x, int y)
{
	t_room	*tmp;

	tmp = (t_room *)malloc(sizeof(t_room));
	if (tmp)
	{
		tmp->name = name;
		tmp->coord_x = x;
		tmp->coord_y = y;
		tmp->links = NULL;
		tmp->next = NULL;
		tmp->dist = 2147483647;
		tmp->ant = 0;
		tmp->prev = NULL;
	}
	return (tmp);
}

void	add_room(t_room **first, t_room *new)
{
	new->next = *first;
	*first = new;
}

int		presence_room_coordinates(t_room *curr, int x, int y)
{
	while (curr != NULL)
	{
		if (curr->coord_x == x && curr->coord_y == y)
			return (1);
		curr = curr->next;
	}
	return (0);
}

t_room	*check_and_create_room(t_room *first, char *line)
{
	char	*name;
	int		x;
	int		y;

	name = line;
	while (ft_isalnum(*line))
		line++;
	if (*line != ' ' || line - name == 0)
		return (NULL);
	name = ft_strsub(name, 0, line - name);
	if (!presence_room(first, name, ft_strlen(name)))
	{
		line++;
		if (check_num_atoi(&line, &x) && *line == ' ')
		{
			line++;
			if (check_num_atoi(&line, &y) && *line == '\0' &&
					!presence_room_coordinates(first, x, y))
				return (new_room(name, x, y));
		}
	}
	ft_strdel(&name);
	return (NULL);
}

t_room	*do_command(t_room *first, char *line, t_room **start, t_room **end)
{
	char	*next_line;
	t_room	*tmp;

	next_line = NULL;
	if ((ft_strequ(line, "##start") && *start != NULL) ||
		(ft_strequ(line, "##end") && *end != NULL))
		return (NULL);
	while (get_next_line(0, &next_line) == 1 && ft_printf("%s\n", next_line) &&
			next_line[0] == '#' &&
			!ft_strequ(next_line, "##start") && !ft_strequ(next_line, "##end"))
		ft_strdel(&next_line);
	if (next_line == NULL ||
			ft_strequ(next_line, "##start") || ft_strequ(next_line, "##end") ||
			!(tmp = check_and_create_room(first, next_line)))
	{
		ft_strdel(&next_line);
		return (NULL);
	}
	if (ft_strequ(line, "##start"))
		*start = tmp;
	else
		*end = tmp;
	ft_strdel(&next_line);
	return (tmp);
}
