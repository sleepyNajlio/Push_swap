/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 01:46:19 by nloutfi           #+#    #+#             */
/*   Updated: 2022/08/07 20:49:09 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_isnum(char *num)
{
	int	i;

	i = 0;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (1);
		i++;
	}
	return (0);
}

int	dupcheck(char **av, char *num, int i)
{
	i--;
	while (i)
	{
		if (ft_atoi(av[i]) == ft_atoi(num))
			return (1);
		i--;
	}
	return (0);
}

int	out_of_range(char *num)
{
	if (ft_atoi(num) > 2147483647 || ft_atoi(num) < -2147483648)
		return (1);
	return (0);
}

int	check_error(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac && av[i])
	{
		if (ft_isnum(av[i]) || dupcheck(av, av[i], i) || out_of_range(av[i]))
		{
			write(2, "Error\n", 6);
			return (0);
		}
		i++;
	}
	return (1);
}
