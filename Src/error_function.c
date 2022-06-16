/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_function.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: rharing <rharing@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/07 11:47:24 by rharing       #+#    #+#                 */
/*   Updated: 2022/04/07 11:56:53 by rharing       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(char *str, int exit_code)
{
	ft_putendl_fd(str, 2);
	exit(exit_code);
}
