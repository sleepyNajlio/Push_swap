/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 09:56:58 by nloutfi           #+#    #+#             */
/*   Updated: 2022/08/02 15:40:30 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	direction(t_list **stack, int index)
{
	t_list	*head;
	int		j;
	int		i;
	
	i = 0;
	j = 0;
	head = *stack;
	while (head->content != index)
	{
		rotate(&head, 0);
		i++;
	}
	head = *stack;
	while (head->content != index)
	{
		rotate(&head, 1);
		j++;
	}
	if (j < i)
		return (1);
	return (0);
}

void	moves_b(int *moves, int phase, int move, int dir)
{
	if (phase == 1)
	{
		if (dir)
		{
			if (move == 1)
				write(1,"rrr\n", 4);
			if (move == 2)
				write(1, "rrb\n", 4);
		}
		else
		{
			if (move == 1)
				write(1,"rr\n", 3);
			if (move == 2)
				write(1, "rb\n", 3);
		}
	}
	(*moves)++;
}


void	move(t_list **stack_a, t_list **stack_b, int phase, int *moves)
{
	int	a_index;
	int	b_index;
	int	a_d;
	int	b_d;
	
	b_index = choose_stack(stack_a, stack_b);
	a_index = prepare_a(stack_a, b_index);
	a_d = direction(stack_a, a_index);
	b_d = direction(stack_b, b_index);
	while (a_d == b_d && (*stack_a)->content != a_index && (*stack_b)->content != b_index)
	{
		rr(stack_a, stack_b, a_d);
		moves_b(moves, phase, 1, b_d);
	}
	while ((*stack_a)->content != a_index)
	{
		rotate(stack_a, a_d);
		moves_a(moves, phase, 3, a_d);
	}
	while((*stack_b)->content != b_index)
	{
		rotate(stack_b, b_d);
		moves_b(moves, phase, 2, b_d);
	}
}

void	free_stack(t_list *stack)
{
	t_list	*temp;
	int		start;
	t_list	*head;

	start = 0;
	head = stack;
	while (head != stack || !start)
	{
		start = 1;
		temp = head->next;
		free(head);
		head = temp;
	}
}

void	free_array(t_array *arr)
{
	int *tab;
	if (arr->arr)
	{
		tab = arr->arr;
		free(tab);
	}
	free(arr);
}