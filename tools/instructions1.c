/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 10:35:12 by nloutfi           #+#    #+#             */
/*   Updated: 2022/07/24 10:38:49 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push(t_list	**stack_1, t_list **stack_2)
{
	t_list	*temp;
	ft_lstadd_front(stack_2, ft_lstnew((*stack_1)->content));
	temp = *stack_1;
	(*stack_1) = (*stack_1)->next;
	ft_lstlast(temp)->next = *stack_1;
	//free (temp);
}

void	rotate(t_list **stack, int d)
{
	if (d == 0)
		(*stack) = (*stack)->next;
	else
		*stack = ft_lstlast(*stack);
}

void	swap(t_list	**stack)
{
	int	temp;
	
	temp = (*stack)->next->content;
	(*stack)->next->content = (*stack)->content;
	(*stack)->content = temp;
}

void	rr(t_list **stack_a, t_list **stack_b, int dir)
{
	rotate(stack_a, dir);
	rotate(stack_b, dir);
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	swap(stack_a);
	swap(stack_b);
}