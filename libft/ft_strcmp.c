/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddovzhik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 20:20:40 by ddovzhik          #+#    #+#             */
/*   Updated: 2016/11/29 20:20:41 by ddovzhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	return (ft_memcmp(s1, s2,
		(ft_strlen(s1) > ft_strlen(s2)) ? ft_strlen(s1) : ft_strlen(s2)));
}
