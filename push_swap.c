/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layala-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 19:15:04 by layala-s          #+#    #+#             */
/*   Updated: 2024/10/11 12:25:35 by layala-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_input(int ac, char **av)
{
	if (ac == 2)
		check_str(av);
	else if (ac > 2)
		check_dup(ac, av);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	check_input(ac, av);
	if (ac < 2)
		return (0);
	else if (ac == 2)
	{
		av = ft_split(av[1], ' ');
		stack_a = init_stack(&stack_a, av, 0);
		cleaner(av);
	}
	else if (ac > 2)
		stack_a = init_stack(&stack_a, av, 1);
	if (!is_sorted(stack_a))
	{
		if (stack_size(stack_a) <= 3)
			simple_sort(&stack_a, stack_size(stack_a));
		else
			sort_stack(&stack_a, &stack_b, stack_size(stack_a));
	}
	free_stack(stack_a);
	return (0);
}
