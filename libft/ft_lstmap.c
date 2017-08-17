/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddovzhik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 20:49:50 by ddovzhik          #+#    #+#             */
/*   Updated: 2016/12/03 20:49:51 by ddovzhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *res;
	t_list *t;
	t_list *curr;

	if (!lst)
		return (NULL);
	curr = lst;
	t = f(curr);
	res = t;
	curr = curr->next;
	while (curr)
	{
		if (!(t->next = f(curr)))
		{
			ft_lstdel(&res, ft_for_lstdel);
			return (NULL);
		}
		t = t->next;
		curr = curr->next;
	}
	return (res);
}
