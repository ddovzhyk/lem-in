/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddovzhik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 20:13:38 by ddovzhik          #+#    #+#             */
/*   Updated: 2017/03/24 20:13:39 by ddovzhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	clear_struct(t_print *pr)
{
	pr->hyphen = 0;
	pr->plus = 0;
	pr->space = 0;
	pr->hash = 0;
	pr->zero = 0;
	pr->dollar = 0;
	pr->size = "";
	pr->prec = -1;
	pr->width = 0;
}

void	add_zeros_nbr(char **num, t_print *pr)
{
	size_t	n;
	char	*res;

	if (pr->prec != -1)
		(pr->zero) ? pr->zero = 0 : 0;
	n = ft_strlen(**num == '-' ? *num + 1 : *num);
	if ((ssize_t)n < pr->prec)
	{
		res = ft_strnew((size_t)pr->prec + (**num == '-' ? 1 : 0));
		(**num == '-') ? *res = '-' : 0;
		ft_strcpy(res + pr->prec - n, *num);
		ft_memset(res + (**num == '-' ? 1 : 0), '0', (size_t)(pr->prec - n));
		ft_strdel(num);
		*num = res;
	}
}

void	add_width_str(char **str, t_print pr, size_t len)
{
	char	*z;
	char	*tmp;
	char	c;

	if (len < (unsigned int)pr.width)
	{
		z = ft_strnew(pr.width - len);
		c = (char)(pr.zero && !pr.hyphen ? '0' : ' ');
		ft_memset(z, c, pr.width - len);
		tmp = (pr.hyphen) ? ft_strjoin(*str, z) : ft_strjoin(z, *str);
		ft_strdel(&z);
		ft_strdel(str);
		*str = tmp;
	}
}

void	flag_apostrophe(char **num)
{
	char			*tmp;
	int				n;
	int				k;
	int				i;

	n = (int)ft_strlen((**num == '-') ? *num + 1 : *num);
	k = (n % 3 == 0 && (n / 3) > 0) ? n / 3 - 1 : n / 3;
	if (k == 0)
		return ;
	n += (**num == '-') ? k + 1 : k;
	tmp = ft_strnew((size_t)n);
	k = 0;
	i = (int)ft_strlen(*num);
	while (--i >= 0)
	{
		k++;
		tmp[--n] = *(*num + i);
		(k == 3) ? tmp[--n] = ',' : 0;
		k %= 3;
	}
	ft_strdel(num);
	*num = tmp;
}

void	flag_hash(char **num, char sp)
{
	char *res;
	char *tmp;

	tmp = NULL;
	(sp == 'p' || sp == 'x') ? tmp = "0x" : 0;
	(sp == 'o') ? tmp = "0" : 0;
	(sp == 'X') ? tmp = "0X" : 0;
	res = *num;
	*num = ft_strjoin(tmp, res);
	ft_strdel(&res);
}
