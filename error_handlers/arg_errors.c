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

void	print_error(char *error)
{
	write(2, error, ft_strlen(error));
	exit(EXIT_FAILURE);
}

int	is_digit(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			print_error("ERROR: Only digits are allowed");
		i++;
	}
	return (1);
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
			if (is_digit(av[i]) && is_digit(av[j]))
			{
				if (ft_atoll(av[i]) == ft_atoll(av[j]))
					print_error("ERROR: Duplicates are forbidden");
			}
			j++;
		}
		i++;
	}
}

void	check_str(char **av)
{
	char	**numbers;
	int		count;

	count = 0;
	numbers = ft_split(av[1], ' ');
	while (numbers[count])
		count++;
	check_dup(count, numbers);
	free(numbers);
}

void	check_input(int ac, char **av)
{
	if (ac == 2)
		check_str(av);
	else if (ac > 2)
		check_dup(ac, av);
}
