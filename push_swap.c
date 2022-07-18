/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 01:37:38 by nloutfi           #+#    #+#             */
/*   Updated: 2022/07/13 19:00:23 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	*stack_a;
	//t_list	*stack_b;
	t_array *arr;
	t_list *head;
	int		i;
	
	i = 0;
	arr = (t_array *)malloc(sizeof(t_array));
	if (ac > 2)
	{
		check_error(ac, av);
		create_arr(ac, av, &arr);
		// while (arr->arr[i])
		// 	printf("%d \n", arr->arr[i++]);
		stack_a = indexation(arr, av);
		head = stack_a;
		
		// while (head->next != stack_a)
		// {
		// 	printf("%d \n", head->content);
		// 	head = head->next;
		// }
		// printf("%d \n", head->content);
		
	}
	
}
