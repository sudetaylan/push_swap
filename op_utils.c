/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: staylan <staylan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 19:03:01 by staylan           #+#    #+#             */
/*   Updated: 2025/03/25 19:03:04 by staylan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


t_stack	*last_node(t_stack *node)
{
	if (!node) //seg faultu önlemek için , boş liste durumu
		return (NULL);
	while (node->next) // sonraki bulunmayana kadar yani sonuncuya kadar geç
		node = node->next;
	return(node); // sonuncu node u döndür
}
int	list_size(t_stack *node)
{
	size_t	len;

	len = 0;
	while(node)
	{
		node = node->next;
		len++;
	}
	return (len);
}