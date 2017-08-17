/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddovzhik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 18:42:11 by ddovzhik          #+#    #+#             */
/*   Updated: 2016/12/03 18:42:12 by ddovzhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	t;

	t = (n > 0) ? (unsigned int)n : (unsigned int)(-n);
	if (n < 0)
		ft_putchar_fd('-', fd);
	if (t > 9)
		ft_putnbr_fd(t / 10, fd);
	ft_putchar_fd((t % 10) + '0', fd);
}
