/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 01:37:38 by nloutfi           #+#    #+#             */
/*   Updated: 2022/08/02 17:20:03 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int test_markup(t_array *arr, int markup_mode, char **av)
{

	t_list	*stack_a;
	t_list	*stack_b;
	int		moves;
	int		dir;
	
	moves = 0;
	stack_a = indexation(arr,av);
	stack_b = a_to_b(&stack_a, markup_mode, &moves, 0);
	b_to_a(&stack_a, &stack_b, &moves, 0);
	dir = direction(&stack_a, 0);
	while (stack_a->content)
	{
		rotate(&stack_a, dir);
		moves_a(&moves, 0, 3, dir);
	}
	free_stack(stack_a);
	return (moves);
}


int test(t_array *arr, char **av)
{
	int	i;
	int	moves;
	int	test;
	int	chosen;
	
	i = 0;
	moves = 10000;
	while(i < 2)
	{
		test = test_markup(arr, i, av);
		if (test < moves)
		{
			moves = test;
			chosen = i;
		}
		i++;
	}
	return (chosen);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_array *arr;
	int		moves;
	int		dir;
	
	//./pu	atexit(leak_report);
	moves = 0;
	arr = (t_array *)malloc(sizeof(t_array));
	if (check_error(ac, av) && ac > 2)
	{
		create_arr(ac, av, &arr);
		stack_a = indexation(arr, av);
		stack_b = a_to_b(&stack_a, test(arr, av), &moves, 1);
		b_to_a(&stack_a, &stack_b, &moves, 1);
		dir = direction(&stack_a, 0);
		while (stack_a->content)
		{
			rotate(&stack_a, dir);
			moves_a(&moves, 1, 3, dir);
		}
		free_stack(stack_a);
	}
	free_array(arr);
	//system("leaks push_swap");
	return (0);
	
}
