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

t_stack	*get_target(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*target_min;
	t_stack	*target_max;
	t_stack	*node_b;

	target_max = NULL;
	target_min = NULL;
	node_b = stack_b;
	while (node_b)
	{
		if (node_b->val < stack_a->val) // a: 4 2 3 10 -5 b: 1 9 
		{
			if (!target_min || node_b->val > target_min->val)
				target_min = node_b;
		}
		if (!target_max || node_b->val > target_max->val)
			target_max = node_b;
		node_b = node_b->next;
	}
	if (target_min)
		return (target_min);
	return (target_max);
}

void	set_target_a(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*node_a;

	node_a = stack_a;
	while (node_a)
	{
		node_a->target = get_target(node_a, stack_b);
		node_a = node_a->next;
	}
}

void	set_nodes_a(t_stack *stack_a, t_stack *stack_b)
{
	get_median(stack_a);
	get_median(stack_b);
	set_target_a(stack_a, stack_b);
}