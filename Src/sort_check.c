/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_check.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rharing <rharing@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/02 15:57:49 by rharing       #+#    #+#                 */
/*   Updated: 2022/05/10 16:01:18 by rharing       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	compare_nodes(t_node *first, t_node *second)
{
	if (second == NULL)
		return (-1);
	if (first->number > second->number)
		return (1);
	return (0);
}

int	check_if_sorted(t_node **stack_a)
{
	t_node	*temp;

	temp = (*stack_a);
	while (temp->next != NULL)
	{
		if (compare_nodes(temp, temp->next) == 1)
			return (0);
		temp = temp->next;
	}
	return (1);
}
