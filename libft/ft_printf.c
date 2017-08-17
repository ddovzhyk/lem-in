/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddovzhik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 18:13:27 by ddovzhik          #+#    #+#             */
/*   Updated: 2017/03/29 18:13:30 by ddovzhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf(const char *format, ...)
{
	va_list		f;
	va_list		start;
	char		*str;
	t_print		print;

	print.byte = 0;
	str = (char *)format;
	va_start(f, format);
	va_start(start, format);
	while (*str)
	{
		if (*str == '%')
		{
			clear_struct(&print);
			check_modificator(&str, f, &print);
			check_spec_char(&str, f, &print, start);
		}
		else
		{
			write(1, str, 1);
			print.byte++;
		}
		str++;
	}
	return (print.byte);
}
