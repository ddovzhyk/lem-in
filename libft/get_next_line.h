/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddovzhik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 15:35:59 by ddovzhik          #+#    #+#             */
/*   Updated: 2017/02/01 15:36:01 by ddovzhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"

# define BUFF_SIZE 1

typedef struct		s_fd
{
	int				fd;
	char			*tmp;
	struct s_fd		*next;
}					t_fd;

int					get_next_line(const int fd, char **line);

#endif
