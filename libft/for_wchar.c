/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_wchar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddovzhik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 20:11:35 by ddovzhik          #+#    #+#             */
/*   Updated: 2017/03/24 20:11:36 by ddovzhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

short	size_char(int c)
{
	if (c < 0)
		return (0);
	else if (c < 256)
		return (1);
	else if (c < 2048)
		return (2);
	else if (c < 131072)
		return (3);
	else if (c < 8388608)
		return (4);
	return (0);
}

void	put_wchar(int c, short size)
{
	int				v;
	unsigned char	h;

	v = c >> ((size - 1) * 6);
	(size == 2) ? v = v | 192 : 0;
	(size == 3) ? v = v | 224 : 0;
	(size == 4) ? v = v | 240 : 0;
	ft_putchar((char)v);
	while (--size > 0)
	{
		h = (unsigned char)(c >> ((size - 1) * 6));
		h = (unsigned char)((h & 63) + 128);
		ft_putchar((char)h);
	}
}

void	put_wstr(int *str, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		put_wchar(str[i], size_char(str[i]));
		i++;
	}
}

int		*wstr_null(char *str, short *flag)
{
	int *wstr;
	int i;

	i = 0;
	wstr = (int *)malloc(sizeof(int) * 7);
	while (i < 7)
	{
		wstr[i] = (int)str[i];
		i++;
	}
	*flag = 1;
	return (wstr);
}

int		check_l_for_cs(char *s)
{
	int i;

	i = 0;
	while (*(--s) != '%')
		(*s == 'l') ? i++ : 0;
	return (i % 2);
}
