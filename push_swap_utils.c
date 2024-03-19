/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedina- <rmedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:23:28 by rmedina-          #+#    #+#             */
/*   Updated: 2024/03/19 18:46:41 by rmedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isnum(int c)
{
	if (c >= '0' && c <= '9')
		return (SUCCESS);
	else if( c == '-' || c == '+')
		return(SUCCESS);
	else
		return (ERROR);
	return (0);
}

int	ft_atoi(const char *str)
{
	long		i;
	long		result;
	long		sign;

	i = 0;
	result = 0;
	sign = 1;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i] - 48;
		i++;
	}
	if(result > 2147483647)
		return (ERROR);
	result *= sign;
	return (result);
}

int	ft_isdupli(int argc, char **argv)
{
	int	count;
	int	count2;
	long	num1;
	long	num2;

	count = 1;
	while (count < argc)
	{
		count2 = 1;
		while (argv[count2])
		{
			num1 = ft_atoi(argv[count]);
			num2 = ft_atoi(argv[count2]);
			if ((count != count2 && num1 == num2))
				return (ERROR);
			count2++;
		}
		if(num1 == ERROR)
			return (ERROR);
		count++;
	}
	return (0);
}

void	positive_or_negative(const char *str, int *a, int *sign)
{
	if (str[*a] == '-')
	{
		*sign = -1;
		a++;
	}
	else if (str[*a] == '+')
		a++;
}
