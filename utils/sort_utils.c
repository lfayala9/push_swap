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

int	get_node_cost(t_stack *node, int len)
{
	if (node->is_above)
		return (node->pos);
	else
		return (len - node->pos);
}

int	get_target_cost(t_stack *node, int len)
{
	if (node->target->is_above)
		return (node->target->pos);
	else
		return (len - node->target->pos);
}

void	set_push_cost(t_stack *stack_a, t_stack *stack_b)
{
	size_t	size_a;
	size_t	size_b;

	size_a = stack_size(stack_a);
	size_b = stack_size(stack_b);
	while (stack_a)
	{
		stack_a->cost = get_node_cost(stack_a, size_a);
		stack_a->cost = get_target_cost(stack_a, size_b);
		stack_a = stack_a->next;
	}
}

void	set_nodes_a(t_stack *stack_a, t_stack *stack_b)
{
	int		best_val;
	t_stack	*cheapest;

	get_median(stack_a);
	get_median(stack_b);
	set_target_a(stack_a, stack_b);
	set_push_cost(stack_a, stack_b);

	if (!stack_a)
		return ;
	best_val = INT_MAX;
	while (stack_a)
	{
		if (stack_a->cost < best_val)
		{
			best_val = stack_a->cost;
			cheapest = stack_a;
		}
		stack_a = stack_a->next;
	}
	cheapest->cheap_move = true;
}
void	set_nodes_b(t_stack *stack_a, t_stack *stack_b)
{
	get_median(stack_a);
	get_median(stack_b);
	set_target_b(stack_a, stack_b);
}
t_stack	*get_cheapest(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheap_move)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}