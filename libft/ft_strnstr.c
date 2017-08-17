/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddovzhik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 19:50:43 by ddovzhik          #+#    #+#             */
/*   Updated: 2016/11/29 19:50:45 by ddovzhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	while ((big[i]) && (i < len))
	{
		j = 0;
		k = i;
		while ((big[k]) && (little[j]) && (big[k] == little[j]) && (k < len))
		{
			k++;
			j++;
		}
		if (!little[j])
			return ((char*)big + i);
		i++;
	}
	if (!*little)
		return ((char*)big);
	return (NULL);
}
