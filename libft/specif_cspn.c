/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specif_cspn.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddovzhik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 20:59:02 by ddovzhik          #+#    #+#             */
/*   Updated: 2017/03/24 20:59:03 by ddovzhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	specif_c_lc(va_list f, t_print *pr, char *sp)
{
	int		c;
	short	size;
	char	*tmp;

	c = va_arg(f, int);
	if (*sp == 'c' && !(check_l_for_cs(sp)))
	{
		c = (unsigned char)c;
		size = 1;
	}
	else
		size = size_char(c);
	if (!size)
		return ;
	pr->byte += size;
	(pr->hyphen == 1) ? put_wchar(c, size) : 0;
	tmp = ft_strnew(0);
	add_width_str(&tmp, *pr, (size_t)size);
	pr->byte += ft_strlen(tmp);
	ft_putstr(tmp);
	(pr->hyphen == 0) ? put_wchar(c, size) : 0;
	ft_strdel(&tmp);
}

void	specif_s(va_list f, t_print *pr)
{
	char *tmp;
	char *res;

	tmp = va_arg(f, char *);
	if (!tmp)
		tmp = "(null)";
	if (pr->prec >= 0 && ft_strlen(tmp) > (size_t)pr->prec)
		res = ft_strsub(tmp, 0, (size_t)pr->prec);
	else
		res = ft_strdup(tmp);
	add_width_str(&res, *pr, ft_strlen(res));
	pr->byte += ft_strlen(res);
	ft_putstr(res);
	ft_strdel(&res);
}

void	specif_ls(va_list f, t_print *pr, int i)
{
	int		*str;
	int		size;
	int		n;
	char	*tmp;
	short	flag_null;

	flag_null = 0;
	str = va_arg(f, int *);
	(!str) ? str = wstr_null("(null)", &flag_null) : 0;
	size = 0;
	n = 0;
	while (str[i] && (pr->prec == -1 || size + size_char(str[i]) <= pr->prec))
	{
		size += size_char(str[i++]);
		n++;
	}
	pr->byte += size;
	(pr->hyphen == 1) ? put_wstr(str, n) : 0;
	tmp = ft_strnew(0);
	add_width_str(&tmp, *pr, (size_t)size);
	pr->byte += ft_strlen(tmp);
	ft_putstr(tmp);
	(pr->hyphen == 0) ? put_wstr(str, n) : 0;
	ft_strdel(&tmp);
	(flag_null) ? free(str) : 0;
}

void	specif_n(va_list f, t_print pr)
{
	int		*v;

	v = va_arg(f, int *);
	if (ft_strcmp(pr.size, "hh") == 0)
		*v = (signed char)pr.byte;
	else if (ft_strcmp(pr.size, "h") == 0)
		*v = (short)pr.byte;
	else
		*v = pr.byte;
}

void	specif_p(va_list f, t_print *pr)
{
	char	*res;

	res = toa_base(va_arg(f, unsigned long), 16, "0123456789abcdef", 0);
	if (num_is_zero(res) && pr->prec == 0)
	{
		ft_strdel(&res);
		res = ft_strnew(0);
	}
	add_zeros_nbr(&res, pr);
	if (pr->zero == 0)
	{
		flag_hash(&res, 'p');
		add_width_str(&res, *pr, ft_strlen(res));
	}
	else
	{
		if (pr->width >= 2)
			pr->width -= 2;
		add_width_str(&res, *pr, ft_strlen(res));
		flag_hash(&res, 'p');
	}
	pr->byte += ft_strlen(res);
	ft_putstr(res);
	ft_strdel(&res);
}
