/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_exept.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddovzhik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 22:13:08 by ddovzhik          #+#    #+#             */
/*   Updated: 2016/12/08 22:13:10 by ddovzhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_split_exept(char **res, size_t last)
{
	size_t i;

	i = last - 1;
	while (i > 0)
	{
		free(res[i - 1]);
		res[i - 1] = NULL;
		i--;
	}
	free(res);
	res = NULL;
	return (1);
}
