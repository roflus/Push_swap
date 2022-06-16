/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rharing <rharing@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/13 12:14:11 by rharing       #+#    #+#                 */
/*   Updated: 2022/05/12 19:46:05 by rharing       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lstswap(t_node **stack)
{
	t_node	*temp;

	temp = (*stack)->next;
	(*stack)->next = temp->next;
	temp->next = *stack;
	*stack = temp;
	ft_putendl_fd("sa", 1);
}

void	reverse_rotate(t_node **stack)
{
	t_node	*temp;
	int		total_length;
	int		i;

	i = 0;
	total_length = lstsize(*stack);
	temp = lstlast(*stack);
	temp->next = *stack;
	*stack = temp;
	while (temp)
	{
		if ((i + 1) == total_length)
		{
			temp->next = NULL;
			break ;
		}
		i++;
		temp = temp->next;
	}
	ft_putendl_fd("rra", 1);
}

void	rotate(t_node **stack)
{
	t_node	*temp;
	t_node	*temp_first;
	int		i;

	i = 0;
	temp_first = *stack;
	temp = lstlast(*stack);
	temp->next = temp_first;
	temp_first = temp_first->next;
	(*stack)->next = NULL;
	*stack = temp_first;
	ft_putendl_fd("ra", 1);
}

void	push_to_stack_a(t_node **stack_a, t_node **stack_b)
{
	t_node	*new;

	new = *stack_a;
	if (new == NULL)
		return ;
	*stack_a = new->next;
	new->next = *stack_b;
	*stack_b = new;
	ft_putendl_fd("pa", 1);
}

void	push_to_stack_b(t_node **stack_a, t_node **stack_b)
{
	t_node	*new;

	new = *stack_a;
	if (new == NULL)
		return ;
	*stack_a = new->next;
	new->next = *stack_b;
	*stack_b = new;
	ft_putendl_fd("pb", 1);
}
