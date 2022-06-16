/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rharing <rharing@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/05 12:34:27 by rharing       #+#    #+#                 */
/*   Updated: 2022/05/16 13:49:13 by rharing       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*list_a;
	t_node	*list_b;

	if (argc == 1)
		return (0);
	check_integer(argv, argc);
	if (check_duplicate(argv, argc) == 0)
		error_exit("Error", 1);
	list_a = create_list(argc, argv);
	list_b = NULL;
	if (argc <= 6)
		short_stack_sort(argc, &list_a, &list_b);
	else
	{
		sort_og_position(&list_a, argc - 1);
		big_sort(&list_a, &list_b);
	}
	return (0);
}
