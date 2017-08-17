/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toa_base.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddovzhik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 21:19:25 by ddovzhik          #+#    #+#             */
/*   Updated: 2017/03/27 21:19:27 by ddovzhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	func_for_toa_base(uintmax_t v, short *base_i, char *s, char *t)
{
	if (v >= (unsigned int)base_i[0])
		func_for_toa_base(v / base_i[0], base_i, s, t);
	s[(base_i[1])++] = t[v % base_i[0]];
}

char		*toa_base(uintmax_t value, short base, char *tmp, int negative)
{
	char	*s;
	short	base_i[2];

	base_i[0] = base;
	base_i[1] = 0;
	if (!(s = ft_strnew(65)))
		return (NULL);
	if (negative)
		s[base_i[1]++] = '-';
	func_for_toa_base(value, base_i, s, tmp);
	return (s);
}
