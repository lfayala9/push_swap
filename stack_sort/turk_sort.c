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
		ft_printf(" ");
		// set_nodes_a(*stack_a, *stack_b);
		// do_moves_a(stack_a, stack_b);
	}
	// sort_three(stack_a);
	// while (*stack_b)
	// {
	// 	set_nodes_b(*stack_a, *stack_b);
	// 	do_moves_b(stack_a, stack_b);
	// }
	// get_median(*stack_a);
	// min_on_top(stack_a);
}
