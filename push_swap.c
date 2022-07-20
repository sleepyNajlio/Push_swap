/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 01:37:38 by nloutfi           #+#    #+#             */
/*   Updated: 2022/07/20 01:38:31 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_array *arr;
	t_list	*head;
	int		i;
	
	i = 0;
	arr = (t_array *)malloc(sizeof(t_array));
	if (ac > 2)
	{
		check_error(ac, av);
		create_arr(ac, av, &arr);
		stack_a = indexation(arr, av);
		head = stack_a;
		stack_b = a_to_b(&stack_a, 0, &i, 1);
		
	}
	
}
