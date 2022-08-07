/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 01:55:47 by nloutfi           #+#    #+#             */
/*   Updated: 2022/08/04 05:27:11 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	count_of_args(char *s)
{
	int	i;
	int	n;
	int	flag;

	flag = 0;
	i = 0;
	n = 0;
	while (s[i])
	{
		while (s[i] && s[i] != ' ')
		{
			if (flag == 0)
			{
				flag = 1;
				n++;
			}
			i++;
		}
		if (s[i] == ' ')
		{
			i++;
			flag = 0;
		}
	}
	return (n);
}

char	**total_of_args(char **av)
{
	char	**nums;
	int		i;
	int		n;

	i = 0;
	n = 0;
	while (av[i])
	{
		n = n + count_of_args(av[i]);
		i++;
	}
	nums = malloc(sizeof(char *) * (n + 1));
	return (nums);
}

char	*copy(char *x)
{
	char	*y;

	y = ft_strdup(x);
	free(x);
	return (y);
}

char	**parsing(char **av)
{
	char	**nums;
	char	**tmp;
	int		i;
	int		j;
	int		n;

	nums = total_of_args(av);
	i = 0;
	n = 0;
	while (nums && av[i])
	{
		tmp = ft_split(av[i], ' ');
		j = 0;
		while (tmp[j])
		{
			nums[n] = copy(tmp[j]);
			n++;
			j++;
		}
		free(tmp);
		i++;
	}
	if (nums)
		nums[n] = NULL;
	return (nums);
}