/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: staylan <staylan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 19:02:13 by staylan           #+#    #+#             */
/*   Updated: 2025/03/24 19:02:21 by staylan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_word_len(char *str, char c)
{
	int len;
	int	sp_flag;

	len = 0;
	while( str[len])
	{
		if (str[len] != c  && sp_flag == 0)
		{
			len++;
			sp_flag == 1;
		}
		else if (str[len] == c)
			sp_flag == 0;
	}
	return (len);
}

int is_alphanumeric(char *str)
{
	int i;

	i = 0;
	while(str[i])
	{
		if ((str[i] <= 57 && str[i] >= 48) || str[i] == ' ')
			i++;
		else
			return (0);
	}
	return (1);
}
char	*ft_subret(char *str, int i, char c)
{
	int		f_i;
	int		j;
	char	*sub;

	f_i = i;
	while(str[i] != c)
	{
		i++;
	}
	sub = (char *)malloc(sizeof(char) * (f_i - i + 1));
	if(!sub)
		return (NULL);
	j = 0;
	while(j < f_i - i)
		sub[j++] = str[f_i++];
	sub[j] = '\0';
	return(sub);
}
char **ft_split(char *str, int c)
{
	int		i;
	int		j;
	char	**ret;

	ret = (char **)malloc(sizeof(char*) * ft_word_len(str, c));
	if(!ret)
		return (NULL);
	
	i = 0;
	j = 0;
	while(i < ft_word_len(str, c))
	{
		if(str[i] == ' ')
			i++;
		else if(str[i] && j < ft_word_len)
			ret[j++] = ft_subret(str, i, c);
	}
	ret[j] = 0;
	return (ret);
}
