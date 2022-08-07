/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 12:50:36 by nloutfi           #+#    #+#             */
/*   Updated: 2022/08/07 21:03:27 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	*convert(int ac, char **av)
{
	int	*tab;
	int	i;

	i = 0;
	tab = malloc(sizeof(int) * (ac - 1));
	while (av[i + 1])
	{
		tab[i] = ft_atoi(av[i + 1]);
		i++;
	}
	return (tab);
}

int	*sort(int ac, int *numbers)
{
	int	i;
	int	tmp;

	i = 0;
	while (i < ac - 2)
	{
		if (numbers[i] > numbers[i + 1])
		{
			tmp = numbers[i];
			numbers[i] = numbers[i + 1];
			numbers[i + 1] = tmp;
			i = 0;
		}
		else
			i++;
	}
	return (numbers);
}

t_list	*indexation(int ac, char **av)
{
	int		i;
	int		j;
	t_list	*stack_a;
	int		*numbers;

	stack_a = 0;
	numbers = convert(ac, av);
	numbers = sort(ac, numbers);
	j = 1;
	while (av[j])
	{
		i = 0;
		while (i < ac - 1)
		{
			if (ft_atoi(av[j]) == numbers[i])
			{
				ft_lstadd_back(&stack_a, ft_lstnew(i), j - 1);
				break ;
			}
			i++;
		}
		j++;
	}
	free(numbers);
	return (stack_a);
}
