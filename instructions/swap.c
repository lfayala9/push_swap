/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layala-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 17:32:53 by layala-s          #+#    #+#             */
/*   Updated: 2024/09/17 17:32:55 by layala-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next->prev = first;
	second->next = first;
	first->prev = second;
	*stack = second;
}

void	sa(t_stack **stack_a)
{
	swap(stack_a);
	ft_printf("sa");
}

void	sb(t_stack **stack_b)
{
	swap(stack_b);
	ft_printf("sb");
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_printf("ss");
}

t_stack *create_node(int val)
{
	t_stack *new_node = (t_stack *)malloc(sizeof(t_stack));
	new_node->val = val;
	new_node->next = NULL;
	new_node->prev = NULL;
	return new_node;
}

void push(t_stack **stack, int val)
{
	t_stack *new_node = create_node(val);
	if (*stack == NULL)
	{
		*stack = new_node;
	}
	else
	{
		t_stack *temp = *stack;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new_node;
		new_node->prev = temp;
	}
}

void print_stack(t_stack *stack)
{
	while (stack != NULL)
	{
		ft_printf("%d ", stack->val);
		stack = stack->next;
	}
	ft_printf("\n");
}

int main()
{
	t_stack *stack = NULL;

	// Crear el stack con los valores 1, 2, 3, 4, 5
	push(&stack, 1);
	push(&stack, 2);
	push(&stack, 3);
	push(&stack, 4);
	push(&stack, 5);

	ft_printf("Stack antes del swap:\n");
	print_stack(stack);

	// Probar la función swap
	swap(&stack);

	ft_printf("Stack después del swap:\n");
	print_stack(stack);

	// Liberar memoria
	while (stack != NULL)
	{
		t_stack *temp = stack;
		stack = stack->next;
		free(temp);
	}

	return 0;
}