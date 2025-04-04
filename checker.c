#include "push_swap.h"
#include <stdio.h>
int	ft_count(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}

int	is_nbr(int argc, char **argv, int i)
{
	int		j;

	while (i < argc)
	{
		j = 0;
		if (argv[i][0] == '-')
			j++;
		while (argv[i][j])
		{
			if (argv[i][j] <= '9' && argv[i][j] >= '0')
				j++;
			else
				return (0);
		}
		i++;
	}
	return (1);
}

int	is_duplicated(t_stack *a)
{
	t_stack	*tmp;

	while (a)
	{
		tmp = a->next;
		while (tmp)
		{
			if (a->nbr == tmp->nbr)
				return (1);
			tmp = tmp->next;
		}
		a = a->next;
	}
	return (0);
}

static int is_same(char *argv, char *check)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if(argv[i] == '-')
	{
		i++;
		j++;
	}
	while(argv[i] == '0')
		i++;
	while(argv[i] && check[j])
	{
		if(argv[i++] != check[j++])
			return (0);
	}
	return (1);
}

int	is_in_limit(int argc, char **argv, int i)
{
	int		tmp;
	char	*check;

	while (i < argc)
	{
		tmp = ft_atoi(argv[i]);
		check = ft_itoa(tmp);
		if (!is_same(argv[i], check))
		{
			free(check);
			return (0);
		}
		free(check);
		i++;
	}
	return (1);
}
