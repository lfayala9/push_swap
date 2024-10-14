/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layala-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:05:30 by layala-s          #+#    #+#             */
/*   Updated: 2024/10/11 12:27:22 by layala-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_error(void)
{
	write(2, "Error", 5);
	exit(EXIT_FAILURE);
}

int	is_valid_digit(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) \
		|| (ft_atoll(&str[i]) > 2147483647 || ft_atoll(&str[i]) < -2147483647))
			print_error();
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
			if (is_valid_digit(av[i]) && is_valid_digit(av[j]))
			{
				if (ft_atoll(av[i]) == ft_atoll(av[j]))
					print_error();
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
	cleaner(numbers);
}
