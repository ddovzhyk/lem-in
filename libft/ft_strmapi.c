/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddovzhik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 22:13:58 by ddovzhik          #+#    #+#             */
/*   Updated: 2016/12/01 22:13:59 by ddovzhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
		b[i] = f(i, b[i]);
		i++;
	}
	return (b);
}
