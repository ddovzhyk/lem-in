/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_links.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddovzhik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 15:00:40 by ddovzhik          #+#    #+#             */
/*   Updated: 2017/08/07 15:00:41 by ddovzhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_link	*new_link(t_room *linked_room)
{
	t_link	*tmp;

	tmp = (t_link *)malloc(sizeof(t_link));
	if (tmp)
	{
		tmp->room = linked_room;
		tmp->mark = 0;
		tmp->next = NULL;
	}
	return (tmp);
}

void	add_link(t_room *elem1, t_room *elem2)
{
	t_link	*new;

	new = new_link(elem2);
	if (new)
	{
		new->next = elem1->links;
		elem1->links = new;
	}
}

int		presence_of_link(t_room *room1, t_room *room2)
{
	t_link	*curr;

	curr = room1->links;
	while (curr)
	{
		if (curr->room == room2)
			return (1);
		curr = curr->next;
	}
	return (0);
}

int		check_and_create_link(t_room *first, char *line)
{
	char	*p;
	t_room	*elem1;
	t_room	*elem2;

	p = line;
	while (ft_isalnum(*p))
		p++;
	if (*p != '-')
		return (0);
	elem1 = presence_room(first, line, p - line);
	if (elem1 == NULL)
		return (0);
	p++;
	elem2 = presence_room(first, p, ft_strlen(p));
	if (elem2 == NULL)
		return (0);
	if (!presence_of_link(elem1, elem2))
	{
		add_link(elem1, elem2);
		add_link(elem2, elem1);
	}
	return (1);
}
