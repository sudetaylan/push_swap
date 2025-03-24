/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: staylan <staylan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 18:55:50 by staylan           #+#    #+#             */
/*   Updated: 2025/03/24 18:55:51 by staylan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



int main(int argc, char **argv)
{
    char *tmp;

    tmp = NULL;
    if(argc < 2)
        ;//error
    else if(argc == 2)//"1 2 3 4 5 6"her bir elemanı alıp stack e yerleştirmek lazım ayrıca alphanumeric control
    {
        if(is_alphanumeric(argv[1]))
            tmp = ft_split(argv[1], ' ');
    }
    else
        //bu durumda direkt index ile değerler alınıp stack e yerleştirilecek
}