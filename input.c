/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddovzhik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 22:42:41 by ddovzhik          #+#    #+#             */
/*   Updated: 2017/08/08 22:42:42 by ddovzhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		read_input_lines(t_room **first, t_room **start, t_room **end)
{
	int	num_ants;

	if (!read_num_ants(&num_ants))
		return (0);
	if (!read_rooms(first, start, end, NULL))
	{
		delete_list_rooms(first);
		return (0);
	}
	(*start)->ant = num_ants;
	read_links(*first);
	return (1);
}

int		read_num_ants(int *num_ants)
{
	char	*line;
	char	*tmp;

	line = NULL;
	while (get_next_line(0, &line) == 1 && ft_printf("%s\n", line)
			&& line[0] == '#' &&
			!ft_strequ(line, "##start") && !ft_strequ(line, "##end"))
		ft_strdel(&line);
	if (line == NULL || *line == '\0' ||
			ft_strequ(line, "##start") || ft_strequ(line, "##end"))
	{
		ft_strdel(&line);
		return (0);
	}
	tmp = line;
	if (*line != '-' && check_num_atoi(&line, num_ants) && *line == '\0')
	{
		ft_strdel(&tmp);
		return (1);
	}
	ft_strdel(&tmp);
	return (0);
}

int		read_rooms(t_room **first, t_room **start, t_room **end, char *line)
{
	t_room	*tmp;

	while (get_next_line(0, &line) == 1 && ft_printf("%s\n", line) &&
			*line != 'L')
	{
		if ((ft_strequ(line, "##start") || ft_strequ(line, "##end")) &&
				(tmp = do_command(*first, line, start, end)))
			add_room(first, tmp);
		else if (ft_strequ(line, "##start") || ft_strequ(line, "##end"))
			break ;
		else if (*line == '#')
			;
		else if ((tmp = check_and_create_room(*first, line)))
			add_room(first, tmp);
		else if (*start && *end && check_and_create_link(*first, line))
		{
			ft_strdel(&line);
			return (1);
		}
		else
			break ;
		ft_strdel(&line);
	}
	ft_strdel(&line);
	return (0);
}

int		read_links(t_room *first)
{
	char	*line;

	while (get_next_line(0, &line) == 1)
	{
		ft_printf("%s\n", line);
		if (*line != 'L' &&
			!ft_strequ(line, "##start") && !ft_strequ(line, "##end"))
			if (*line == '#' || check_and_create_link(first, line))
			{
				ft_strdel(&line);
				continue ;
			}
		ft_strdel(&line);
		return (0);
	}
	return (1);
}
