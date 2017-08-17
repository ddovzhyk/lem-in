/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddovzhik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 19:20:00 by ddovzhik          #+#    #+#             */
/*   Updated: 2016/11/29 19:20:01 by ddovzhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *t;
	char *res;

	t = (char *)s;
	res = NULL;
	while (*t)
	{
		if (*t == (char)c)
			res = t;
		t++;
	}
	if (*t == (char)c)
		return (res = t);
	else
		return (res);
}
