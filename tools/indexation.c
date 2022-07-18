/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 12:50:36 by nloutfi           #+#    #+#             */
/*   Updated: 2022/07/13 13:57:41 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*indexation(t_array *arr, char **av)
{
	t_list	*stack;
	int	i;
	int j;

	i = 1;
	stack = 0;
	while (av[i])
	{
		j = 0;
		while (j < arr->size)
		{
			if (ft_atoi(av[i]) == arr->arr[j])
			{
				ft_lstadd_back(&stack, ft_lstnew(j), i - 1);
				break;
			}
			j++;
		}
		i++;
	}
	return (stack);
}