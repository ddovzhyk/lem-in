/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddovzhik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 21:38:47 by ddovzhik          #+#    #+#             */
/*   Updated: 2016/12/01 21:38:49 by ddovzhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*b;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (!(b = ft_strdup(s)))
		return (NULL);
	while (b[i])
	{
		b[i] = f(b[i]);
		i++;
	}
	return (b);
}
