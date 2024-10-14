/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   classify_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layala-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 17:20:30 by layala-s          #+#    #+#             */
/*   Updated: 2024/10/12 16:04:00 by layala-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*get_min(t_stack **stack)
{
	t_stack	*small;
	t_stack	*curr;

	if (!stack || !(*stack))
		return (NULL);
	curr = *stack;
	small = *stack;
	while (curr)
	{
		if (curr->val < small->val)
			small = curr;
		curr = curr->next;
	}
	return (small);
}

t_stack	*get_max(t_stack **stack)
{
	t_stack	*big;
	t_stack	*curr;

	if (!stack || !(*stack))
		return (NULL);
	curr = *stack;
	big = *stack;
	while (curr)
	{
		if (curr->val > big->val)
			big = curr;
		curr = curr->next;
	}
	return (big);
}

void	get_median(t_stack *stack)
{
	int	i;

	i = 0;
	if (!stack)
		return ;
	while (stack)
	{
		stack->pos = i;
		if (i <= stack_size(stack) / 2)
			stack->is_above = true;
		else
			stack->is_above = false;
		stack = stack->next;
		i++;
	}
}

t_stack	*find_target_a(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*node_b;
	t_stack	*target;
	int		best_value;

	node_b = stack_b;
	target = NULL;
	best_value = INT_MIN;
	while (node_b)
	{
		if (node_b->val < stack_a->val && node_b->val > best_value)
		{
			best_value = node_b->val;
			target = node_b;
		}
		node_b = node_b->next;
	}
	return (target);
}

void	set_target_a(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*target;

	while (stack_a)
	{
		target = find_target_a(stack_a, stack_b);
		if (target == NULL)
			stack_a->target = get_max(&stack_b);
		else
			stack_a->target = target;
		stack_a = stack_a->next;
	}
}
t_stack	*find_target_b(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*node_a = NULL;
	t_stack	*target;
	int		best_value;

	while (node_a)
	{
		best_value = INT_MAX;
		node_a = stack_a;
		if (node_a->val > stack_b->val && node_a->val < best_value)
		{
			best_value = node_a->val;
			target = node_a;
		}
		node_a = node_a->next;
	}
	return (target);
}

void	set_target_b(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*target;

	while (stack_b)
	{
		target = find_target_b(stack_a, stack_b);
		if (target == NULL)
			stack_b->target = get_min(&stack_b);
		else
			stack_b->target = target;
		stack_b = stack_b->next;
	}
}