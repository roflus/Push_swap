/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils_list.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rharing <rharing@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/13 12:10:03 by rharing       #+#    #+#                 */
/*   Updated: 2022/05/16 15:10:55 by rharing       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	lstsize(t_node *stack_a)
{
	int	nodes;

	nodes = 0;
	while (stack_a)
	{
		nodes++;
		stack_a = stack_a->next;
	}
	return (nodes);
}

t_node	*lstlast(t_node *lst)
{
	if (!lst)
		return (NULL);
	while (lst)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

void	free_list(t_node *head)
{
	t_node	*temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}
