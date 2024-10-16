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

// t_stack	*get_min(t_stack **stack)
// {
// 	t_stack	*small;
// 	t_stack	*curr;

// 	if (!stack || !(*stack))
// 		return (NULL);
// 	curr = *stack;
// 	small = *stack;
// 	while (curr)
// 	{
// 		if (curr->val < small->val)
// 			small = curr;
// 		curr = curr->next;
// 	}
// 	return (small);
// }

// t_stack	*get_max(t_stack **stack)
// {
// 	t_stack	*big;
// 	t_stack	*curr;

// 	if (!stack || !(*stack))
// 		return (NULL);
// 	curr = *stack;
// 	big = *stack;
// 	while (curr)
// 	{
// 		if (curr->val > big->val)
// 			big = curr;
// 		curr = curr->next;
// 	}
// 	return (big);
// }
int	get_node_cost(t_stack *node, int size)
{
	if (node->is_above)
		return (node->pos);
	else
		return (size - node->pos);
}

int	get_target_cost(t_stack *node, int size)
{
	if (node->target->is_above)
		return (node->target->pos);
	else
		return (size - node->target->pos);
}

void	set_cost(t_stack *stack_a, t_stack *stack_b)
{
	int	size_a;
	int	size_b;

	size_a = stack_size(stack_a);
	size_b = stack_size(stack_b);
	while (stack_b)
	{
		stack_b->cost = get_node_cost(stack_b, size_b);
		stack_b->cost += get_target_cost(stack_b, size_a);
		stack_b = stack_b->next;
	}
}

void	get_median(t_stack *stack)
{
	int	i;
	int	median;

	i = 0;
	if (!stack)
		return ;
	median = stack_size(stack) / 2;
	while (stack)
	{
		stack->pos = i;
		if (i <= median)
			stack->is_above = true;
		else
			stack->is_above = false;
		stack = stack->next;
		i++;
	}
}
