/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddovzhik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 22:35:08 by ddovzhik          #+#    #+#             */
/*   Updated: 2016/12/01 22:35:09 by ddovzhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *t;

	if (!s)
		return (NULL);
	if (!(t = ft_strnew(len)))
		return (NULL);
	return ((char *)ft_memcpy((void *)t, (const void *)(s + start), len));
}
