/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   small_sort_utils.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: rharing <rharing@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/12 17:11:34 by rharing       #+#    #+#                 */
/*   Updated: 2022/05/12 17:12:26 by rharing       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_lowest_number(t_node **list_a)
{
	int	min;

	min = 2147483647;
	while (*list_a != NULL)
	{
		if (min > (*list_a)->number)
			min = (*list_a)->number;
		list_a = &(*list_a)->next;
	}
	return (min);
}

int	get_lowest_position(t_node **list_a, int lowest)
{
	int	position;

	position = 1;
	while ((*list_a)->number != lowest)
	{
		position++;
		list_a = &(*list_a)->next;
	}
	return (position);
}
