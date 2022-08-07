/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 06:38:04 by nloutfi           #+#    #+#             */
/*   Updated: 2022/08/07 21:03:06 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	max(t_list *head, t_list **stack_a)
{
	int	start;
	int	index;

	start = 0;
	while (head != *stack_a || !start)
	{
		start = 1;
		if (head->content > head->next->content)
			index = head->next->content;
		head = head->next;
	}
	return (index);
}

int	prepare_a(t_list **stack_a, int b_index)
{
	int		start;
	int		index;
	t_list	*head;

	start = 0;
	head = *stack_a;
	index = 2147483647;
	while (head != *stack_a || !start)
	{
		start = 1;
		if (head->content > b_index && head->content < index)
			index = head->content;
		head = head->next;
	}
	if (index == 2147483647)
	{
		index = max(head, stack_a);
	}
	return (index);
}

int	choose_stack_h(t_list **stack_a, t_list **stack_b, t_list *temp)
{
	int		m;
	t_list	*stack;
	int		a;
	int		d;

	m = 0;
	stack = temp;
	d = direction(&stack, (*stack_b)->content);
	while (stack != *stack_b)
	{
		rotate(&stack, d);
		m++;
	}
	a = prepare_a(stack_a, temp->content);
	stack = *stack_a;
	d = direction(stack_a, a);
	while (stack->content != a)
	{
		rotate(&stack, d);
		m++;
	}
	return (m);
}

int	choose_stack(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;
	int		index;
	int		start;
	int		i;
	int		moves;

	temp = *stack_b;
	index = temp->content;
	start = 0;
	moves = 10000;
	while (temp != *stack_b || !start)
	{
		start = 1;
		i = choose_stack_h(stack_a, stack_b, temp);
		if (i < moves)
		{
			index = temp->content;
			moves = i;
		}
		temp = temp->next;
	}
	return (index);
}

void	b_to_a(t_list **stack_a, t_list **stack_b, int *moves, int phase)
{
	int	n;
	int	index;

	if (*stack_b)
	{
		n = ft_lstsize(*stack_b);
		while (n)
		{
			index = choose_stack(stack_a, stack_b);
			move(stack_a, stack_b, phase, moves);
			push(stack_b, stack_a);
			if (phase == 1)
			{
				write(1, "pa\n", 3);
			}
			(*moves)++;
			n--;
		}
	}
}
