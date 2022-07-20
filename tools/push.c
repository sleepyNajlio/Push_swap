/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 04:40:18 by nloutfi           #+#    #+#             */
/*   Updated: 2022/07/20 03:13:47 by nloutfi          ###   ########.fr       */
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