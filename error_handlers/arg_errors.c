/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layala-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:05:30 by layala-s          #+#    #+#             */
/*   Updated: 2024/09/23 14:05:36 by layala-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	few_arguments(void)
{
	write(2, "USAGE: ./push_swap '<ARG 1> <ARG 2> <ARG 3> ...'", 49);
	exit(EXIT_FAILURE);
}
void	check_dup(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = i + 1;
		while (j < ac)
		{
			if (ft_atoll(av[i]) == ft_atoll(av[j]))
			{
				write(2, "ERROR: Duplicates are forbidden", 32);
				exit(EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
}
