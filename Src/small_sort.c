/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   small_sort.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rharing <rharing@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/02 15:56:05 by rharing       #+#    #+#                 */
/*   Updated: 2022/05/16 15:14:41 by rharing       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	sort_two(t_node **list_a)
{
	lstswap(list_a);
}

static	void	sort_three(t_node **list_a)
{
	int	first_second;
	int	second_third;
	int	third_first;

	first_second = compare_nodes(*list_a, (*list_a)->next);
	second_third = compare_nodes((*list_a)->next, (*list_a)->next->next);
	third_first = compare_nodes((*list_a)->next->next, *list_a);
	if (first_second == 1 && second_third == 0 && third_first == 1)
		lstswap(list_a);
	if (first_second == 1 && second_third == 1 && third_first == 0)
	{
		lstswap(list_a);
		reverse_rotate(list_a);
	}
	if (first_second == 1 && second_third == 0 && third_first == 0)
		rotate(list_a);
	if (first_second == 0 && second_third == 1 && third_first == 1)
	{
		lstswap(list_a);
		rotate(list_a);
	}
	if (first_second == 0 && second_third == 1 && third_first == 0)
		reverse_rotate(list_a);
}

static	void	sort_four(t_node **list_a, t_node **list_b)
{
	int	lowest;
	int	position;

	lowest = get_lowest_number(list_a);
	position = get_lowest_position(list_a, lowest);
	if (position == 2)
		rotate(list_a);
	if (position == 3)
	{
		rotate(list_a);
		rotate(list_a);
	}
	if (position == 4)
		reverse_rotate(list_a);
	if (check_if_sorted(list_a) == 0)
	{
		push_to_stack_b(list_a, list_b);
		sort_three(list_a);
		push_to_stack_a(list_b, list_a);
	}
}

static	void	sort_five(t_node **list_a, t_node **list_b)
{
	int	lowest;
	int	position;

	lowest = get_lowest_number(list_a);
	position = get_lowest_position(list_a, lowest);
	if (position == 2)
		rotate(list_a);
	if (position == 3)
	{
		rotate(list_a);
		rotate(list_a);
	}
	if (position == 4)
	{
		reverse_rotate(list_a);
		reverse_rotate(list_a);
	}
	if (position == 5)
		reverse_rotate(list_a);
	if (check_if_sorted(list_a) == 0)
	{
		push_to_stack_b(list_a, list_b);
		sort_four(list_a, list_b);
		push_to_stack_a(list_b, list_a);
	}
}

void	short_stack_sort(int argc, t_node **list_a, t_node **list_b)
{
	if (argc == 3)
		sort_two(list_a);
	if (argc == 4)
		sort_three(list_a);
	if (argc == 5)
		sort_four(list_a, list_b);
	if (argc == 6)
		sort_five(list_a, list_b);
}
