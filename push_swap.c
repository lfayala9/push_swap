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

t_stack	*init_stack(t_stack **stack, char **av, int start)
{
	t_stack	*node;
	t_stack	*new_node;
	int		i;

	i = start;
	while (av[i])
	{
		new_node = (t_stack *)malloc(sizeof(t_stack));
		if (!new_node)
			return (NULL);
		new_node->val = ft_atoll(av[i]);
		new_node->next = NULL;
		if (*stack == NULL)
		{
			*stack = new_node;
			node = new_node;
		}
		else
		{
			node->next = new_node;
			node = new_node;
		}
		i++;
	}
	return (*stack);
}

void print_stack(t_stack *stack)
{
	while (stack)
	{
		ft_printf("%d\n", stack->val);
		stack = stack->next;
	}
}
int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac == 2)
	{
		av = ft_split(av[1], ' ');
		stack_a = init_stack(&stack_a, av, 0);	
	}
	else if (ac > 2)
		stack_a = init_stack(&stack_a, av, 1);
	print_stack(stack_a);
	pb(&stack_a, &stack_b);
	print_stack(stack_b);
	write(1, "----------\n", 11);
	print_stack(stack_a);
	write(1, "----------\n", 11);
	pb(&stack_a, &stack_b);
	print_stack(stack_b);
	write(1, "----------\n", 11);
	print_stack(stack_a);
	write(1, "----------\n", 11);
	pa(&stack_a, &stack_b);
	print_stack(stack_a);
	pa(&stack_a, &stack_b);
	print_stack(stack_a);
	return (0);
}
