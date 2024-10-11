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

void	sort_stack(t_stack **stack_a, t_stack **stack_b, size_t size)
{
	while (!is_sorted(*stack_a) &&  size-- > 3)
		pb(stack_a, stack_b);
	sort_three(stack_a);
	while (*stack_b)
	{
		
	}
}
