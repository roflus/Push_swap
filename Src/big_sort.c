/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   big_sort.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rharing <rharing@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/10 16:47:26 by rharing       #+#    #+#                 */
/*   Updated: 2022/05/16 13:45:46 by rharing       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	get_biggest_number_in_stack(t_node **stack_a)
{
	t_node	*temp;

	temp = lstlast(*stack_a);
	return (temp->og_position);
}

static	int	get_max_bits(t_node **stack)
{
	int	max_bits;
	int	max_num;

	max_num = get_biggest_number_in_stack(stack);
	max_bits = 0;
	while ((max_num >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	big_sort(t_node **stack, t_node **stack_b)
{
	int	i;
	int	k;
	int	max_bits;
	int	stack_size;

	i = 0;
	stack_size = lstsize(*stack);
	max_bits = get_max_bits(stack);
	while (i < max_bits)
	{
		k = 0;
		while (k < stack_size)
		{
			if ((((*stack)->index >> i) & 1) == 1)
				rotate(stack);
			else
				push_to_stack_b(stack, stack_b);
			k++;
		}
		i++;
		while ((*stack_b)->next != NULL)
			push_to_stack_a(stack_b, stack);
		push_to_stack_a(stack_b, stack);
	}
}
