/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   classify_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layala-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 17:20:30 by layala-s          #+#    #+#             */
/*   Updated: 2024/10/06 17:20:32 by layala-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

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
