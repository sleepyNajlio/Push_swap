/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 01:37:38 by nloutfi           #+#    #+#             */
/*   Updated: 2022/08/07 20:30:56 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	test_markups(int markup_mode, char **nums)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		moves;
	int		dir;

	moves = 0;
	stack_a = indexation(count(nums), nums);
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

int	tests(char **nums)
{
	int	i;
	int	moves;
	int	test;
	int	chosen;

	i = 0;
	moves = 10000;
	while (i < 2)
	{
		test = test_markups(i, nums);
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
	int		moves;
	int		dir;
	char	**nums;

	moves = 0;
	(void)ac;
	nums = parsing(av);
	dir = 0;
	if (check_error(count(nums), nums) && count(nums) > 2)
	{
		stack_a = indexation(count(nums), nums);
		stack_b = a_to_b(&stack_a, tests(nums), &moves, 1);
		b_to_a(&stack_a, &stack_b, &moves, 1);
		dir = direction(&stack_a, 0);
		while (stack_a->content)
		{
			rotate(&stack_a, dir);
			moves_a(&moves, 1, 3, dir);
		}
		free_stack(stack_a);
	}
	free_array(nums);
	return (0);
}
