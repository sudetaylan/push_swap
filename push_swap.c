/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: staylan <staylan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 18:55:50 by staylan           #+#    #+#             */
/*   Updated: 2025/03/25 19:08:47 by staylan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    t_stack *a;

    a = NULL;
    if(argc < 2 || argv[1] == NULL)
        ft_error();
    else if(argc == 2)//"1 2 3 4 5 6"her bir elemanı alıp stack e yerleştirmek lazım ayrıca alphanumeric control
    {
        
    }
    else
        ;//bu durumda direkt index ile değerler alınıp stack e yerleştirilecek
}