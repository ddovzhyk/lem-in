/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddovzhik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 19:51:46 by ddovzhik          #+#    #+#             */
/*   Updated: 2016/12/02 19:51:47 by ddovzhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	**res;

	i = 0;
	k = 0;
	if ((!s) ||
		(!(res = (char **)malloc(sizeof(char *) * ft_countwrd(s, c) + 1))))
		return (NULL);
	while (s[i])
	{
		j = i;
		while ((s[j]) && (s[j] != c))
			j++;
		if (j != i)
			if (!(res[k++] = ft_strsub(s, i, j - i)) && ft_split_exept(res, k))
				return (NULL);
		i = (j != i) ? j : i + 1;
	}
	res[k] = NULL;
	return (res);
}
