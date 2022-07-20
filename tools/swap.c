/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 04:32:06 by nloutfi           #+#    #+#             */
/*   Updated: 2022/07/19 05:06:14 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_list	**stack)
{
	int	temp;
	
	temp = (*stack)->next->content;
	(*stack)->next->content = (*stack)->content;
	(*stack)->content = temp;
}