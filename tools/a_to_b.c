/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 21:59:40 by nloutfi           #+#    #+#             */
/*   Updated: 2022/08/07 20:51:20 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_0(t_list *stack)
{
	t_list	*temp;
	int		start;

	temp = stack;
	start = 0;
	while (temp->next != stack)
	{
		if (temp->markup == 0)
			return (1);
		temp = temp->next;
	}
	if (temp->markup == 0)
		return (1);
	return (0);
}

int	count_markups(t_list **stack)
{
	t_list	*head;
	int		i;
	int		start;

	head = *stack;
	i = 0;
	start = 0;
	while (head != *stack || !start)
	{
		start = 1;
		if (head->markup == 1)
			i++;
		head = head->next;
	}
	return (i);
}

int	check_swap(t_list **stack, int markup_mode)
{
	int	a;
	int	b;

	a = count_markups(stack);
	swap(stack);
	markup(stack, markup_mode);
	b = count_markups(stack);
	swap(stack);
	markup(stack, markup_mode);
	if (a < b)
		return (1);
	return (0);
}

void	moves_a(int *moves, int phase, int move, int dir)
{
	if (phase == 1)
	{
		if (move == 1)
			write(1, "sa\n", 3);
		if (move == 2)
			write(1, "pb\n", 3);
		if (move == 3 && !dir)
			write(1, "ra\n", 3);
		if (move == 3 && dir)
			write(1, "rra\n", 4);
	}
	(*moves)++;
}

t_list	*a_to_b(t_list **stack_a, int markup_mode, int *moves, int phase)
{
	t_list	*stack_b;

	stack_b = 0;
	markup(stack_a, markup_mode);
	while (check_0(*stack_a))
	{
		if (check_swap(stack_a, markup_mode))
		{
			swap(stack_a);
			moves_a(moves, phase, 1, 0);
			markup(stack_a, markup_mode);
		}
		else if ((*stack_a)->markup == 0)
		{
			push(stack_a, &stack_b);
			moves_a(moves, phase, 2, 0);
		}
		else
		{
			rotate(stack_a, 0);
			moves_a(moves, phase, 3, 0);
		}
	}	
	return (stack_b);
}
