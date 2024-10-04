/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layala-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 19:15:04 by layala-s          #+#    #+#             */
/*   Updated: 2024/09/22 19:15:09 by layala-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	check_input(ac, av);
	if (ac == 2)
	{
		av = ft_split(av[1], ' ');
		stack_a = init_stack(&stack_a, av, 0);
	}
	else if (ac > 2)
		stack_a = init_stack(&stack_a, av, 1);
	sort_three(&stack_a);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
