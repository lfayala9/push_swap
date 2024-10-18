/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layala-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:51:43 by layala-s          #+#    #+#             */
/*   Updated: 2024/10/11 12:26:17 by layala-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <limits.h>
# include <stdbool.h>
# include "./libft/libft.h"

typedef struct s_stack
{
	int				val;
	int				pos;
	bool			cheap_move;
	bool			is_above;
	int				cost;
	struct s_stack	*target;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

/* LIBFT FUNCTIONS */

char	**ft_split(char const *s, char c);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
size_t	ft_strlen(const char *str);
int		ft_printf(char const *s, ...);
int		ft_isdigit(int num);

/*STACK UTILS*/

t_stack	*init_stack(t_stack **stack, char **av, int start);
t_stack	*get_min(t_stack **stack);
t_stack	*get_max(t_stack **stack);
int		stack_size(t_stack *stack);
void	free_stack(t_stack *stack);
char	**cleaner(char **result);

/*SORT FUNCTIONS*/
void	sort_three(t_stack **stack);
void	simple_sort(t_stack **stack, size_t size);
int		is_sorted(t_stack *stack);
void	sort_stack(t_stack **stack_a, t_stack **stack_b, int size);
void	get_median(t_stack *stack);
void	set_nodes(t_stack *stack_a, t_stack *stack_b);
void	set_target(t_stack *stack_a, t_stack *stack_b);
void	set_cost(t_stack *stack_a, t_stack *stack_b);
t_stack	*get_cheapest(t_stack *stack);

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

/*ERROR HANDLER*/
void	check_input(int ac, char **av);
void	check_dup(int ac, char **av);
void	check_str(char **av);

#endif
