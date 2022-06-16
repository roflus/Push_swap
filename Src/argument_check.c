/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   argument_check.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: rharing <rharing@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/05 13:26:47 by rharing       #+#    #+#                 */
/*   Updated: 2022/05/13 16:29:41 by rharing       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	string_check(char **argv, char *string, int index, int argc)
{
	while (index < argc -1)
	{
		index++;
		if (ft_atoi(string) - ft_atoi(argv[index]) == 0)
			return (0);
	}
	return (1);
}

int	check_duplicate(char **argv, int argc)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (string_check(argv, argv[i], i, argc) == 0)
			return (0);
		i++;
	}
	return (1);
}

void	check_integer(char **argv, int argc)
{
	int		i;
	int		k;
	int		max_int;

	i = 1;
	max_int = 2147483647;
	while (i - 1 < argc - 1)
	{
		k = 0;
		if (ft_atoi(argv[i]) > max_int || ft_atoi(argv[i]) < -2147483648)
			error_exit("Error", 1);
		while (argv[i][k] != '\0')
		{
			if (argv[i][k] != '0' && argv[i][k] != '1' && argv[i][k] != '2' && \
				argv[i][k] != '3' && argv[i][k] != '4' && argv[i][k] != '5' && \
				argv[i][k] != '6' && argv[i][k] != '7' && argv[i][k] != '8' && \
				argv[i][k] != '9' && argv[i][k] != '-')
				error_exit("Error", 1);
			if ((argv[i][k] == '-' && argv[i][k + 1] == '\0') || \
				(argv[i][k] == '-' && argv[i][k + 1] == '-'))
				error_exit("Error", 1);
			k++;
		}
		i++;
	}
}
