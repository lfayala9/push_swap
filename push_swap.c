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

t_stack	*init_stack(t_stack **stack, char **av)
{
	t_stack	*node;
	t_stack	*new_node;
	int		i;

	i = 0;
	while (av[++i])
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
	}
	return (*stack);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac == 2)
		av = ft_split(av[1], ' ');
	return (0);
}
