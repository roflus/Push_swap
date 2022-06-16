/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   insert_values.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rharing <rharing@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/06 12:32:27 by rharing       #+#    #+#                 */
/*   Updated: 2022/05/12 14:42:31 by rharing       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	bubble_sort(t_node **list_a, int total_arguments)
{
	t_node	**temp;
	int		arg_count;
	int		k;
	int		swapped;

	arg_count = 0;
	while (arg_count <= total_arguments)
	{
		temp = list_a;
		swapped = 0;
		k = 0;
		while (k < total_arguments - arg_count - 1)
		{
			if (compare_nodes(*temp, (*temp)->next) == 1)
			{
				swap_nodes(temp);
				swapped = 1;
			}
			temp = &(*temp)->next;
			k++;
		}
		arg_count ++;
		if (swapped == 0)
			break ;
	}
}

void	give_node_index(t_node **list_a, int argc)
{
	t_node	**temp;
	int		i;

	bubble_sort(list_a, argc - 1);
	temp = list_a;
	i = 0;
	while (argc - 1 != 0)
	{
		(*temp)->index = i;
		temp = &(*temp)->next;
		i++;
		argc--;
	}
}

void	give_node_position(t_node *stack_a)
{
	int	position;

	position = 0;
	while (stack_a)
	{
		stack_a->og_position = position;
		stack_a = stack_a->next;
		position++;
	}
}
