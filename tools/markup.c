/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   markup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 22:13:05 by nloutfi           #+#    #+#             */
/*   Updated: 2022/07/19 02:56:31 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_markup(int t1, int t2, int markup_mode)
{
	if (markup_mode == 0)
	{
		if (t1 < t2)
			return (1);
		return (0);
	}
	if (t1 + 1 == t2)
		return (1);
	return (0);
}

int	m_h_helper(t_list *temp, int size, int markup_mode)
{
	int		i;
	t_list	*temp1;
	t_list	*temp2;

	temp1 = temp;
	temp2 = temp->next;
	i = 0;
	while (size)
	{
		if (check_markup(temp1->content, temp2->content, markup_mode))
		{
			temp1 = temp2;
			temp2 = temp2->next;
			i++;
		}
		else
			temp2 = temp2->next;
		size--;
	}
	return (i);
}

t_list	*markup_head(t_list *stack, int size, int markup_mode)
{
	t_list	*m_h;
	t_list	*temp;
	int		start;
	int		j;
	int		i;
	
	m_h = stack;
	temp = stack;
	start = 0;
	j = 0;
	while (temp != stack || !start)
	{
		start = 1;
		i = m_h_helper(temp, size, markup_mode);
		if (i > j)
		{
			j = i;
			m_h = temp;
		}
		temp = temp->next;
	}
	return (m_h);
}

void	markup(t_list **stack, int markup_mode)
{
	t_list	*m_h;
	t_list	*head;
	int		size;

	head = *stack;
	size = ft_lstsize(*stack);
	m_h = markup_head(*stack, size, markup_mode);
	while (*stack != m_h)
		*stack = (*stack)->next;
	(*stack)->markup = 1;
	while (--size)
	{
		(*stack) = (*stack)->next;;
		if (check_markup(m_h->content, (*stack)->content, markup_mode))
		{
			m_h = (*stack);
			(*stack)->markup = 1;
		}
		else
			(*stack)->markup = 0;
	}
	while ((*stack) != head)
		(*stack) = (*stack)->next;
}