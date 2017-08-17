/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr_digit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddovzhik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 19:26:31 by ddovzhik          #+#    #+#             */
/*   Updated: 2016/12/09 19:26:32 by ddovzhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_nbr_digit(int n)
{
	size_t			res;
	unsigned int	t;

	if (!n)
		return (0);
	t = (n >= 0) ? (unsigned int)n : (unsigned int)(-n);
	res = 0;
	while (t != 0)
	{
		res++;
		t /= 10;
	}
	return (res);
}
