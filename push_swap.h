/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: staylan <staylan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 19:07:49 by staylan           #+#    #+#             */
/*   Updated: 2025/03/25 17:32:58 by staylan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

typedef struct s_stack
{
	long			nbr;
	long			index;
	bool			min;//
	bool			max;//
	bool			cheapest;//
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

#endif
