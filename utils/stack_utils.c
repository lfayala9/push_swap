/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layala-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 12:55:49 by layala-s          #+#    #+#             */
/*   Updated: 2024/10/03 12:55:53 by layala-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_sorted(t_stack *stack)
{
	while (stack->next)
	{
		if (stack->val > stack->next->val)
			return (0);
		stack = stack->next;
	}
	return (1);
}

size_t	stack_size(t_stack *lst)
{
	size_t	i;
	t_stack	*cur;

	i = 0;
	cur = lst;
	while (cur != NULL)
	{
		cur = cur->next;
		i++;
	}
	return (i);
}

void	free_stack(t_stack *stack)
{
	t_stack	*tmp;

	while (stack)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}

t_stack	*init_stack(t_stack **stack, char **av, int start)
{
	t_stack	*node;
	t_stack	*new_node;

	while (av[start])
	{
		new_node = (t_stack *)malloc(sizeof(t_stack));
		if (!new_node)
			return (NULL);
		new_node->val = ft_atoll(av[start]);
		new_node->next = NULL;
		if (!(*stack))
		{
			*stack = new_node;
			node = new_node;
		}
		else
		{
			node->next = new_node;
			node = new_node;
		}
		start++;
	}
	return (*stack);
}
