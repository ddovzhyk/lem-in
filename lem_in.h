/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddovzhik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 11:24:38 by ddovzhik          #+#    #+#             */
/*   Updated: 2017/08/09 11:24:39 by ddovzhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "./libft/libft.h"
# include "./libft/get_next_line.h"
# include "./libft/ft_printf.h"

typedef struct s_room	t_room;
typedef struct s_link	t_link;
typedef struct s_way	t_way;

struct	s_room
{
	char	*name;
	int		coord_x;
	int		coord_y;
	t_link	*links;
	t_room	*next;
	int		dist;
	int		ant;
	t_room	*prev;
};

struct	s_link
{
	t_room	*room;
	int		mark;
	t_link	*next;
};

struct	s_way
{
	int		len;
	t_room	**rooms;
	t_way	*next;
};

int		read_input_lines(t_room **first, t_room **start, t_room **end);

int		read_num_ants(int *num_ants);

int		read_rooms(t_room **first, t_room **start, t_room **end, char *line);
t_room	*do_command(t_room *first, char *line, t_room **start, t_room **end);
t_room	*check_and_create_room(t_room *first, char *line);
void	add_room(t_room **first, t_room *new);

int		read_links(t_room *first);
int		check_and_create_link(t_room *first, char *line);

int		check_num_atoi(char **line, int *num);
t_room	*presence_room(t_room *curr, char *name, size_t len_name);

int		find_ways(t_way **all_way, t_room *first, t_room *start, t_room *end);
void	set_mark_on_way(t_room **way);
void	clear_all_distances(t_room *first);
t_way	*new_way(int length);
void	add_way_back(t_way **first, t_way *new);

void	run_ants(t_way *all_ways, t_room *start, t_room *end, int index_ant);

void	delete_list_rooms(t_room **first);
void	delete_all_data(t_room **first, t_way **all_ways);

#endif
