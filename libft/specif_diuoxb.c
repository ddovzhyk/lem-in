/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specif_diuoxb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddovzhik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 21:02:58 by ddovzhik          #+#    #+#             */
/*   Updated: 2017/03/24 21:03:00 by ddovzhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			num_is_zero(char *num)
{
	while (*num)
	{
		if (*num != '0')
			return (0);
		num++;
	}
	return (1);
}

static void	for_specif_di(t_print *pr, char **res, char *tmp)
{
	if (pr->zero == 0 || pr->hyphen == 1)
	{
		if (**res != '-' && (pr->plus || pr->space))
		{
			*res = (pr->plus) ? ft_strjoin("+", tmp) : ft_strjoin(" ", tmp);
			ft_strdel(&tmp);
		}
		add_width_str(res, *pr, ft_strlen(*res));
	}
	else if (**res == '-' && (size_t)pr->width > ft_strlen(*res))
	{
		*res = ft_strsub(tmp, 1, ft_strlen(*res));
		ft_strdel(&tmp);
		add_width_str(res, *pr, ft_strlen(*res));
		**res = '-';
	}
	else if (**res != '-' && (pr->plus || pr->space))
	{
		add_width_str(res, *pr, ft_strlen(*res) + 1);
		tmp = *res;
		*res = (pr->plus) ? ft_strjoin("+", tmp) : ft_strjoin(" ", tmp);
		ft_strdel(&tmp);
	}
	else
		add_width_str(res, *pr, ft_strlen(*res));
}

void		specif_di_ld(va_list f, t_print *pr, char sp)
{
	intmax_t	v;
	char		*res;

	v = va_arg(f, intmax_t);
	(sp == 'D') ? pr->size = "l" : 0;
	if (*pr->size == '\0')
		v = (int)v;
	else if (ft_strcmp(pr->size, "hh") == 0)
		v = (signed char)v;
	else if (ft_strcmp(pr->size, "h") == 0)
		v = (short int)v;
	else if (ft_strcmp(pr->size, "l") == 0)
		v = (long int)v;
	else if (ft_strcmp(pr->size, "ll") == 0)
		v = (long long int)v;
	res = toa_base((uintmax_t)((v < 0) ? -v : v), 10, "0123456789",
		(v < 0) ? 1 : 0);
	(pr->apostrophe == 1) ? flag_apostrophe(&res) : 0;
	(num_is_zero(res) && pr->prec == 0) ? *res = '\0' : 0;
	add_zeros_nbr(&res, pr);
	for_specif_di(pr, &res, res);
	pr->byte += ft_strlen(res);
	ft_putstr(res);
	ft_strdel(&res);
}

static void	for_specif_uoxb(char *res, char sp, t_print *pr)
{
	(pr->apostrophe == 1 && sp == 'u') ? flag_apostrophe(&res) : 0;
	if (num_is_zero(res) && (pr->prec == 0 || (sp == 'o' && pr->prec == 1)))
		*res = '\0';
	if (pr->hash == 1 && sp == 'o' && (pr->prec > -1 || *res != '0'))
		flag_hash(&res, sp);
	add_zeros_nbr(&res, pr);
	if (pr->zero == 0)
	{
		if (pr->hash == 1 && (sp == 'x' || sp == 'X') && !num_is_zero(res))
			flag_hash(&res, sp);
		add_width_str(&res, *pr, ft_strlen(res));
	}
	else
	{
		(pr->hash == 1 && pr->width >= 2 && (sp == 'x' || sp == 'X') &&
			!num_is_zero(res)) ? pr->width -= 2 : 0;
		add_width_str(&res, *pr, ft_strlen(res));
		(pr->hash == 1 && (sp == 'x' || sp == 'X') &&
			!num_is_zero(res)) ? flag_hash(&res, sp) : 0;
	}
	pr->byte += ft_strlen(res);
	ft_putstr(res);
	ft_strdel(&res);
}

void		specif_uoxb_luoxb(va_list f, char sp, t_print *pr)
{
	unsigned int	base;
	uintmax_t		num;

	if ((sp == 'O' || sp == 'U') && (pr->size = "l"))
		sp = (char)ft_tolower(sp);
	(sp == 'u') ? base = 10 : 0;
	(sp == 'o') ? base = 8 : 0;
	(sp == 'x' || sp == 'X') ? base = 16 : 0;
	(sp == 'b') ? base = 2 : 0;
	num = va_arg(f, uintmax_t);
	if (*pr->size == '\0')
		num = (unsigned int)num;
	else if (ft_strcmp(pr->size, "hh") == 0)
		num = (unsigned char)num;
	else if (ft_strcmp(pr->size, "h") == 0)
		num = (unsigned short int)num;
	else if (ft_strcmp(pr->size, "l") == 0)
		num = (unsigned long int)num;
	else if (ft_strcmp(pr->size, "ll") == 0)
		num = (unsigned long long int)num;
	else if (ft_strcmp(pr->size, "z") == 0)
		num = (size_t)num;
	for_specif_uoxb(toa_base(num, base,
		(sp == 'X') ? "0123456789ABCDEF" : "0123456789abcdef", 0), sp, pr);
}
