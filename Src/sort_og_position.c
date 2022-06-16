/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_og_position.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: rharing <rharing@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/06 12:53:54 by rharing       #+#    #+#                 */
/*   Updated: 2022/05/12 17:10:42 by rharing       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	compare_nodes_position(t_node *first, t_node *second)
{
	if (second == NULL)
		return (0);
	if (first->og_position > second->og_position)
		return (1);
	return (0);
}

void	swap_nodes(t_node **stack)
{
	t_node	*temp;

	temp = (*stack)->next;
	(*stack)->next = temp->next;
	temp->next = *stack;
	*stack = temp;
}

void	sort_og_position(t_node **list_a, int total_arguments)
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
			if (compare_nodes_position(*temp, (*temp)->next) == 1)
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
