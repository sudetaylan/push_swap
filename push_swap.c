#include "push_swap.h"
#include <stdio.h>

char	**checker(int argc, char **argv)
{
	char	**split;
	int		elems;

	if (argc == 2)
	{
		split = ft_split(argv[1], ' ');
		elems = ft_count(split);
		if (elems == 0 || !(is_nbr(elems, split, 0)
				&& is_in_limit(elems, split, 0)))
		{
			free_str(split);
			ft_error();
		}
		return (split);
	}
	else if (!(is_nbr(argc, argv, 1) && is_in_limit(argc, argv, 1)))
		ft_error();
	return (argv);
}

void	add_nums(t_stack **a, char **argv, int i)
{
	int		content;
	
	while (argv[i])
	{
		content = ft_atoi(argv[i]);
		add_back(a, new_stack(content));
		i++;
	}
}

void	process_args(t_stack **a, int argc, char **argv)
{
	if (argc < 2)
		ft_error();
	if(argc == 2)
		add_nums(a, argv, 0);
	else
		add_nums(a, argv, 1);
	if(argc == 2)
		free_str(argv);
}
int	main(int argc, char **argv)//00032 durumunda 32 olarak algılamalı onu ekle
{
	t_stack	*a;
	t_stack *b;
	char **split;
	
	a = NULL;
	b = NULL;
	split = checker(argc, argv);
	process_args(&a, argc, split);
	if (is_duplicated(a))//bunu a ya yer ayırmadan yapsan daha iyi olur
	{
		free_stack(&a);
		ft_error();
	}
	if (!is_sorted(&a))
		handle_sort(&a, &b);
	free_stack(&a);
	return (0);
}
