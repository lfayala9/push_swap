/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layala-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 18:36:27 by layala-s          #+#    #+#             */
/*   Updated: 2024/10/16 12:14:42 by layala-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_stacks(t_stack **stack_a, t_stack **stack_b, t_stack *cheap, \
					bool reverse)
{
	while (*stack_a != cheap->target && *stack_b != cheap)
	{
		if (reverse)
			rrr(stack_a, stack_b);
		else
			rr(stack_a, stack_b);
	}
}

void	finish_rotation(t_stack **stack, t_stack *head, \
					void (*rotate)(t_stack **), void (*rev_rotate)(t_stack **))
{
	while (*stack != head)
	{
		if (head->is_above)
			rotate(stack);
		else
			rev_rotate(stack);
	}
}

void	do_moves(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*cheap;

	cheap = get_cheapest(*stack_b);
	if (cheap->is_above && cheap->target->is_above)
		rotate_stacks(stack_a, stack_b, cheap, false);
	else if (!(cheap->is_above) && !(cheap->target->is_above))
		rotate_stacks(stack_a, stack_b, cheap, true);
	finish_rotation(stack_b, cheap, rb, rrb);
	finish_rotation(stack_a, cheap->target, ra, rra);
	pa(stack_a, stack_b);
}

void	top_min(t_stack **stack)
{
	t_stack	*min;

	min = get_min(stack);
	if (min->is_above)
	{
		while (min != *stack)
			ra(stack);
	}
	else
	{
		while (min != *stack)
			rra(stack);
	}
}

void	sort_stack(t_stack **stack_a, t_stack **stack_b, int size)
{
	while (size > 3)
	{
		pb(stack_a, stack_b);
		size--;
	}
	sort_three(stack_a);
	while (*stack_b)
	{
		set_nodes(*stack_a, *stack_b);
		do_moves(stack_a, stack_b);
	}
	top_min(stack_a);
}
