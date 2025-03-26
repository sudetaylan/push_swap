/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sude <sude@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 19:07:49 by staylan           #+#    #+#             */
/*   Updated: 2025/03/26 13:51:14 by sude             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <errno.h>
# include <limits.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <ctype.h>
# include <stdbool.h>

typedef struct s_stack
{
	long			nbr;
	long			index;
	bool			min;//
	bool			max;//
	int				cost;//
	struct s_stack	*target;
	struct s_stack	*next;
}	t_stack;

//find_cheapest
void find_index(t_stack **stack);
void cost(t_stack **stack1, t_stack **stack2);
t_stack *find_cheapest(t_stack **stack);

//free
void	free_str(char **str);
void	free_stack(t_stack **stack);
void	ft_error(void);

//nbr_utils
int	ft_atol(const char *str);

//new_stack
t_stack	*new_stack(int content);
void	add_back(t_stack **stack, t_stack *stack_new);

//op_utils
t_stack	*last_node(t_stack *node);
int	list_size(t_stack *node);
int	is_duplicated(t_stack *a);
int	is_sorted(t_stack *a);
int is_numeric(int c);

//push_swap
t_stack *add_args(char **argv, int flag);

//operations
void    sa(t_stack **a, int k);
void	sb(t_stack **b, int k);
void	ss(t_stack **a, t_stack **b, int k);
void	pa(t_stack **a, t_stack **b, int k);
void	pb(t_stack **a, t_stack **b, int k);
void    ra(t_stack **a, int k);
void    rb(t_stack **b, int k);
void    r_rr(t_stack **a, t_stack **b, int k, int reverse);
void    rra(t_stack **a, int k);
void    rrb(t_stack **b, int k);

//target_utils
t_stack	*find_smallest(t_stack **stack);
t_stack	*find_highest(t_stack **stack);

//target
void	target_a(t_stack **stack_a, t_stack **stack_b);
void	target_b(t_stack **stack_a, t_stack **stack_b);

#endif
