/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create_list.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rharing <rharing@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/05 15:45:41 by rharing       #+#    #+#                 */
/*   Updated: 2022/05/16 13:38:39 by rharing       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// create head node, first node in list
static	t_node	*create_head_node(char **argv, int argc)
{
	t_node	*head;

	head = (t_node *)malloc(sizeof(t_node));
	if (!head)
		error_exit("Error", 1);
	head->number = ft_atoi(argv[argc - 1]);
	head->index = 0;
	head->og_position = 0;
	head->next = NULL;
	return (head);
}

// create new node, malloc size and assigning argv[] to it
static	t_node	*new_node(int number)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		error_exit("Error", 1);
	new->number = number;
	new->index = 0;
	new->og_position = 0;
	new->next = NULL;
	return (new);
}

// add node to front of list and make that node the head node
static	void	push(t_node **head, int number)
{
	t_node	*node;

	node = new_node(number);
	if (!node || !head)
		error_exit("Error", 1);
	node->next = *head;
	*head = node;
}

// create list by adding notes to front of head node and 
// changing that node to head node
static	t_node	*link_list(int argc, char **argv)
{
	t_node	*head;
	int		arg_count;

	head = create_head_node(argv, argc);
	arg_count = argc - 2;
	while (arg_count)
	{
		push(&head, ft_atoi(argv[arg_count]));
		arg_count--;
	}
	return (head);
}

// create stack by using the create list function, then asserting
// index and position value to every node.
// if stack is sorted free list and exit.
// returns head of list/stack.
t_node	*create_list(int argc, char **argv)
{
	t_node	*stack_a;

	stack_a = link_list(argc, argv);
	if (check_if_sorted(&stack_a) == 1)
	{
		free_list(stack_a);
		exit(1);
	}
	if (argc > 6)
	{
		give_node_position(stack_a);
		give_node_index(&stack_a, argc);
	}
	return (stack_a);
}
