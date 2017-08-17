/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddovzhik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 22:02:12 by ddovzhik          #+#    #+#             */
/*   Updated: 2016/12/02 22:02:16 by ddovzhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	size_t			i;
	unsigned int	t;
	char			*res;

	i = 0;
	if (n == 0)
		return (ft_strdup("0"));
	i = (n > 0) ? ft_nbr_digit(n) : ft_nbr_digit(n) + 1;
	if (!(res = ft_strnew(i)))
		return (NULL);
	t = (n > 0) ? (unsigned int)n : (unsigned int)(-n);
	while (t > 0)
	{
		res[--i] = (t % 10) + '0';
		t /= 10;
	}
	if (n < 0)
		res[--i] = '-';
	return (res);
}
