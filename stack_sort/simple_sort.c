/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layala-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 13:17:46 by layala-s          #+#    #+#             */
/*   Updated: 2024/10/03 13:17:47 by layala-s         ###   ########.fr       */
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

void	sort_three(t_stack **stack)
{
	if ((*stack)->val > (*stack)->next->val \
		&& (*stack)->val > (*stack)->next->next->val)
		ra(stack);
	else if ((*stack)->next->val > (*stack)->val \
			&& (*stack)->next->val > (*stack)->next->next->val)
		rra(stack);
	if ((*stack)->val > (*stack)->next->val)
		sa(stack);
}

