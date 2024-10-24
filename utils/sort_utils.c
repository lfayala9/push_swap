/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layala-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 12:55:49 by layala-s          #+#    #+#             */
/*   Updated: 2024/10/16 12:15:41 by layala-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*get_target(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*target_min;
	t_stack	*target;
	t_stack	*node_a;

	target_min = NULL;
	target = NULL;
	node_a = stack_a;
	while (node_a)
	{
		if (node_a->val > stack_b->val)
		{
			if (!target || node_a-> val < target->val)
				target = node_a;
		}
		if (!target_min || node_a-> val < target_min->val)
			target_min = node_a;
		node_a = node_a->next;
	}
	if (target)
		return (target);
	return (target_min);
}

void	set_target(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*node_b;

	node_b = stack_b;
	while (node_b)
	{
		node_b->target = get_target(stack_a, node_b);
		node_b = node_b->next;
	}
}

void	set_cheapest(t_stack *stack_b)
{
	t_stack	*cheapest;

	cheapest = stack_b;
	if (!stack_b)
		return ;
	while (stack_b)
	{
		if (stack_b->cost < cheapest->cost)
			cheapest = stack_b;
		stack_b = stack_b->next;
	}
	cheapest->cheap_move = true;
}

void	set_nodes(t_stack *stack_a, t_stack *stack_b)
{
	get_median(stack_a);
	get_median(stack_b);
	set_target(stack_a, stack_b);
	set_cost(stack_a, stack_b);
	set_cheapest(stack_b);
}
