/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layala-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:51:43 by layala-s          #+#    #+#             */
/*   Updated: 2024/09/17 11:51:46 by layala-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include "./libft/libft.h"

typedef struct s_stack
{
	int				val;
	int				pos;
	int				cheap_move;
	int				is_above;
	struct s_stack	*target;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

/* LIBFT FUNCTIONS */
char	**ft_split(char const *s, char c);
int		ft_printf(char const *s, ...);

/*MOVES*/
void	pb(t_stack **stack_a, t_stack **stack_b);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rotate(t_stack **stack);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	swap(t_stack **stack);
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	reverse_rotate(t_stack **stack);
void	rra(t_stack **stack_a);
void	rrr(t_stack **stack_a, t_stack **stack_b);
void	rrb(t_stack **stack_b);

/*ERROR HANDLERS*/
void	few_arguments(void);
void	check_dup(int ac, char **av);

#endif