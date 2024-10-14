/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layala-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 18:36:27 by layala-s          #+#    #+#             */
/*   Updated: 2024/10/07 18:36:29 by layala-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_stacks(t_stack **stack_a, t_stack **stack_b, t_stack *cheap)
{
	while (*stack_a != cheap->target && *stack_b != cheap)
		rr(stack_a, stack_b);
	get_median(*stack_a);
	get_median(*stack_b);
}

void	rev_rotate_stacks(t_stack **stack_a, t_stack **stack_b, t_stack *cheap)
{
	while (*stack_a != cheap->target && *stack_b != cheap)
		rrr(stack_a, stack_b);
	get_median(*stack_a);
	get_median(*stack_b);
}

void	finish_rotation(t_stack **stack, t_stack *first, char name)
{
	while (*stack != first)
	{
		if (name == 'a')
		{
			if (first->is_above)
				ra(stack);
			else
				rra(stack);
		}
		else if (name == 'b')
		{
			if (first->is_above)
				rb(stack);
			else
				rrb(stack);
		}
	}
}

void	do_moves_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*cheap;

	cheap = get_cheapest(*stack_a);
	if (cheap->is_above && cheap->target->is_above)
		rotate_stacks(stack_a, stack_b, cheap);
	else if (!((cheap->is_above)) && !((cheap->target->is_above)))
		rev_rotate_stacks(stack_a, stack_b, cheap);
	finish_rotation(stack_a, cheap, 'a');
	finish_rotation(stack_b, cheap->target, 'b');
	pb(stack_a, stack_b);
}
void	do_moves_b(t_stack **stack_a, t_stack **stack_b)
{
	finish_rotation(stack_a, (*stack_b)->target, 'a');
	pa(stack_a, stack_b);
}

static void	min_on_top(t_stack **a) //Define a function that moves the smallest number to the top
{
	while ((*a)->val != get_min(a)->val) //As long as the smallest number is not at the top
	{
		if (get_min(a)->is_above) //Rotate or reverse rotate according to the position of the node on the median
			ra(a);
		else
			rra(a);
	}
}

void	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	int	size_a;

	size_a = stack_size(*stack_a);
	if (size_a-- > 3 && !is_sorted(*stack_a))
		pb(stack_a, stack_b);
	if (size_a-- > 3 && !is_sorted(*stack_a))
		pb(stack_a, stack_b);
	while (size_a-- > 3 && !is_sorted(*stack_a))
	{
		set_nodes_a(*stack_a, *stack_b);
		do_moves_a(stack_a, stack_b);
	}
	sort_three(stack_a);
	while (*stack_b)
	{
		set_nodes_b(*stack_a, *stack_b);
		do_moves_b(stack_a, stack_b);
	}
	get_median(*stack_a);
	min_on_top(stack_a);
}
