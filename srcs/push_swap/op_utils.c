/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: staylan <staylan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 19:03:01 by staylan           #+#    #+#             */
/*   Updated: 2025/03/27 22:23:59 by staylan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*last_node(t_stack *node)
{
	if (!node)
		return (NULL);//seg faultu önlemek için , boş liste durumu
	while (node->next)
		node = node->next;// sonraki bulunmayana kadar yani sonuncuya kadar geç
	return (node);// sonuncu node u döndür
}

int	list_size(t_stack *node)
{
	size_t	len;

	len = 0;
	while (node)
	{
		node = node->next;
		len++;
	}
	return (len);
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

int	is_sorted(t_stack *a)
{
	int	i;

	i = a->nbr;
	while (a)
	{
		if (i > a->nbr)
			return (0);
		i = a->nbr;
		a = a->next;
	}
	return (1);
}

int	is_numeric(int c)
{
	if (c > 47 && c < 58)
		return (1);
	return (0);
}
