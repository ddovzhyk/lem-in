/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddovzhik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 16:35:28 by ddovzhik          #+#    #+#             */
/*   Updated: 2016/11/29 16:35:30 by ddovzhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while ((dst[i]) && (i < size))
		i++;
	if (i == size)
		return (i + ft_strlen(src));
	while ((src[j]) && (i < size - 1))
		dst[i++] = src[j++];
	dst[i] = '\0';
	return (i + (ft_strlen(src) - j));
}
