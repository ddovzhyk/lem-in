/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddovzhik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 16:35:45 by ddovzhik          #+#    #+#             */
/*   Updated: 2016/12/02 16:35:47 by ddovzhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	k;
	char	*t;

	i = 0;
	if (!s)
		return (NULL);
	if (!(k = ft_strlen(s)))
		return (ft_strnew(0));
	while ((s[i]) && ((s[i] == ' ') || (s[i] == '\n') || (s[i] == '\t')))
		i++;
	k--;
	while ((k > i) && ((s[k] == ' ') || (s[k] == '\n') || (s[k] == '\t')))
		k--;
	if (!(t = ft_strnew(k - i + 1)))
		return (NULL);
	return (ft_strncpy(t, s + i, k - i + 1));
}
