/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sude <sude@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 23:46:56 by beeligul          #+#    #+#             */
/*   Updated: 2025/04/04 01:22:35 by sude             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "unistd.h"
# include "stdlib.h"
# include "libft/libft.h"
# include "stdbool.h"
# include "limits.h"

typedef struct s_stack
{
	int					nbr;
	int					index;
	int					cost;
	bool				above_median;
	struct s_stack		*target;
	struct s_stack		*next;
}	t_stack;

//cheapest
void		find_cost(t_stack *stack_a, t_stack *stack_b);
t_stack		*get_cheapest(t_stack *stack);

//checker
int		ft_count(char **split);
int		is_nbr(int argc, char **argv, int i);
int		is_duplicated(t_stack *a);
int		is_in_limit(int argc, char **argv, int i);

//free end
void	free_str(char **str);
void	free_stack(t_stack **stack);
void	ft_error(void);

//init
void	put_index(t_stack *stack);
void	init_a(t_stack *stack_a, t_stack *stack_b);
void	init_b(t_stack *stack_a, t_stack *stack_b);

//operations
void    sa(t_stack **a, int k);
void	sb(t_stack **b, int k);
void	pa(t_stack **a, t_stack **b, int k);
void	pb(t_stack **a, t_stack **b, int k);
void	rr(t_stack **stack_a, t_stack **stack_b, int k);
void	ra(t_stack **a, int k);
void    rb(t_stack **b, int k);
void    rra(t_stack **a, int k);
void    rrb(t_stack **b, int k);
void	rrr(t_stack **stack_a, t_stack **stack_b, int k);

//push
char	**checker(int argc, char **argv);
void	add_nums(t_stack **a, char **argv, int i);
void	process_args(t_stack **a, int argc, char **argv);

//rotate push
void	do_rr(t_stack **a, t_stack **b, t_stack *cheapest);
void	do_rrr(t_stack **a, t_stack **b, t_stack *cheapest);
void	align_top(t_stack **stack, t_stack *top, char s);

//sort_big
void	big_sort(t_stack **stack_a, t_stack **stack_b);

//sort_small
void	sort_three(t_stack **stack_a);
void	tiny_sort(t_stack **stack_a, int len);
void	handle_sort(t_stack **stack_a, t_stack **stack_b);

//utils
t_stack	*new_stack(int content);
void	add_back(t_stack **stack, t_stack *new_node);
int	is_sorted(t_stack **stack_a);
t_stack	*last_node(t_stack *list);
int	list_size(t_stack *list);

//target
t_stack	*find_highest(t_stack *stack);
t_stack	*find_smallest(t_stack *stack);
void	target_in_a(t_stack *stack_a, t_stack *stack_b);
void	target_in_b(t_stack *stack_a, t_stack *stack_b);

#endif