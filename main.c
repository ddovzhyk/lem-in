/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddovzhik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 22:49:44 by ddovzhik          #+#    #+#             */
/*   Updated: 2017/08/08 22:49:46 by ddovzhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	main(void)
{
	t_room	*first;
	t_room	*start;
	t_room	*end;
	t_way	*all_ways;

	first = NULL;
	start = NULL;
	end = NULL;
	all_ways = NULL;
	if (!read_input_lines(&first, &start, &end))
	{
		ft_printf("\nERROR\n");
		return (0);
	}
	if (!find_ways(&all_ways, first, start, end))
	{
		ft_printf("\nERROR\n");
		delete_all_data(&first, &all_ways);
		return (0);
	}
	ft_printf("\n");
	run_ants(all_ways, start, end, 0);
	delete_all_data(&first, &all_ways);
	return (0);
}
