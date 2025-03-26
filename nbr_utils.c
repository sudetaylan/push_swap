#include "push_swap.h"

int	ft_atol(const char *str)
{
	int				sign;
	long long int	result;

	result = 0;
	sign = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\f'
		|| *str == '\v' || *str == '\r')
		str++;
	if (*str == '-' || *str == '+')
	{
        if(*str == '-')
		    sign = -1;
		str++;
	}
	while (*str)
	{
		if (!is_numeric(*str))
			ft_error();
		result = result * 10 + (*str - 48);
		str++;
	}
	if ((sign * result) > 2147483647 || (sign * result) < -2147483648)
		ft_error();
	return (sign * result);
}

