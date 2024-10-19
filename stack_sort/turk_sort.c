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

void	finish_rotation(t_stack **stack, t_stack *head, char stack_name)
{
	while (*stack != head)
	{
		if (stack_name == 'a')
		{
			if (head->is_above)
				ra(stack);
			else
				rra(stack);
		}
		else if (stack_name == 'b')
		{
			if (head->is_above)
				rb(stack);
			else
				rrb(stack);			
		}
	}
}
t_stack	*ft_cheapest(t_stack *stack)
{
	t_stack	*cheap;

	cheap = stack;
	while (stack)
	{
		if (stack->cheap_move)
		{
			cheap = stack;
			return (cheap);
		}
		stack = stack->next;
	}
	return (cheap);
}
void	do_moves(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*cheap;

	cheap = ft_cheapest(*stack_b);
	if (cheap->is_above && cheap->target->is_above)
		rotate_stacks(stack_a, stack_b, cheap);
	else if (!(cheap->is_above) && !(cheap->target->is_above))
		rev_rotate_stacks(stack_a, stack_b, cheap);
	finish_rotation(stack_b, cheap, 'b');
	finish_rotation(stack_a, cheap->target, 'a');
	pa(stack_a, stack_b);
}

void	sort_stack(t_stack **stack_a, t_stack **stack_b, int size)
{
	t_stack	*min;
	while (size -- > 3)
		pb(stack_a, stack_b);
	sort_three(stack_a);
	while (*stack_b)
	{
		set_nodes(*stack_a, *stack_b);
		do_moves(stack_a, stack_b);
	}
	get_median(*stack_a);
	min = get_min(stack_a);
	if (min->is_above)
		while (min != *stack_a)
			ra(stack_a);
	else
		while (min != *stack_a)
			rra(stack_a);	
}
