/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddovzhik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 20:15:38 by ddovzhik          #+#    #+#             */
/*   Updated: 2016/12/08 20:15:39 by ddovzhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstcpy(t_list *first)
{
	t_list *curr;
	t_list *res;
	t_list *t;

	if (!first)
		return (NULL);
	curr = first;
	if (!(t = ft_lstnew(curr->content, curr->content_size)))
		return (NULL);
	res = t;
	curr = curr->next;
	while (curr)
	{
		if (!(t->next = ft_lstnew(curr->content, curr->content_size)))
		{
			ft_lstdel(&res, ft_for_lstdel);
			return (NULL);
		}
		t = t->next;
		curr = curr->next;
	}
	return (res);
}
