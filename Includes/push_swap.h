/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rharing <rharing@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/05 12:34:30 by rharing       #+#    #+#                 */
/*   Updated: 2022/05/16 15:10:56 by rharing       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <libft.h>

typedef struct s_node
{
	int				index;
	int				og_position;
	int				number;
	struct s_node	*next;
}				t_node;

// argument check
int		check_duplicate(char **argv, int argc);
void	check_integer(char **argv, int argc);

// big sort
void	big_sort(t_node **stack, t_node **stack_b);

// create list
t_node	*create_list(int argc, char **argv);

// error_function
void	error_exit(char *str, int exit_code);

// insert values
void	give_node_index(t_node **list_a, int argc);
void	give_node_position(t_node *stack_a);

// operations
void	lstswap(t_node **stack);
void	reverse_rotate(t_node **stack);
void	rotate(t_node **stack);
void	push_to_stack_a(t_node **stack_a, t_node **stack_b);
void	push_to_stack_b(t_node **stack_a, t_node **stack_b);

// small sort utis
int		get_lowest_number(t_node **list_a);
int		get_lowest_position(t_node **list_a, int lowest);

// small sort
void	short_stack_sort(int argc, t_node **list_a, t_node **list_b);

// sort check
int		compare_nodes(t_node *first, t_node *second);
int		check_if_sorted(t_node **stack_a);

// sort og position
void	swap_nodes(t_node **stack);
void	sort_og_position(t_node **list_a, int total_arguments);

// utils list
int		lstsize(t_node *stack_a);
t_node	*lstlast(t_node *lst);
void	free_list(t_node *head);

#endif
