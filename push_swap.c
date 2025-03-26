/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sude <sude@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 18:55:50 by staylan           #+#    #+#             */
/*   Updated: 2025/03/26 13:40:17 by sude             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *add_args(char **argv, int flag)
{
    t_stack *a;
    char **split_args;
    int i;
    int num;

    i = 0;
    a = NULL;
    if (flag == 2)
        split_args = ft_split(argv[1], 32);
    else
        split_args = argv;
    while (split_args[i])
    {
        num = ft_atoi2(split_args[i]);
        add_back(&a, new_stack(num));
        i++;
    }
    if(flag == 2)
    {
        free_str(split_args);
        free(split_args);        
    }
    return (a);
}

int main(int argc, char **argv)
{
    t_stack *a;
    int num;

    a = NULL;
    if(argc < 2 || argv[1] == NULL)
        ft_error();
    a = add_args(argv, argc);
    if (!a || is_duplicated(a))
	{
		free_stack(&a);
		ft_error();
	}
	if (!is_sorted(a))
		sort_stack(&a);
	free_stack(&a);
	return (0);
}
