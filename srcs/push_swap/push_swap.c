/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sude <sude@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 18:55:50 by staylan           #+#    #+#             */
/*   Updated: 2025/03/27 13:53:36 by sude             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*add_split(char **argv)
{
	t_stack	*a;
	char	**tmp;
	int		i;
	int		j;

	a = NULL;
	i = 0;
	tmp = ft_split(argv[1], 32);
	while (tmp[i])
	{
		j = ft_atol(tmp[i]);
		add_back(&a, new_stack(j));
		i++;
	}
	free_str(tmp);
	free(tmp);
	return (a);
}
t_stack *add_args(int argc, char **argv)
{
	t_stack	*a;
	int		i;
	int		j;

	i = 1;
	a = NULL;
	if (argc < 2)
		ft_error();
	if (argc == 2)
		a = add_split(argv);
	else
	{
		while (i < argc)
		{
			j = ft_atol(argv[i]);
			add_back(&a, new_stack(j));
			i++;
		}
	}
	return (a);
}

int	main(int argc, char **argv)
{
	t_stack	*a;

	a = add_args(argc, argv);
	if (!a || is_duplicated(a))
	{
		free_stack(&a);
		ft_error();
	}
	if (!is_sorted(a))
	    sort_list(&a);
	free_stack(&a);
	return (0);
}

