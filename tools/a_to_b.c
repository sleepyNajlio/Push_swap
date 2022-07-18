/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 21:59:40 by nloutfi           #+#    #+#             */
/*   Updated: 2022/07/13 22:15:04 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list *a_to_b(t_list **stack_a, int markup_mode, int *moves, int phase)
{
	t_list *stack_b;
	
	stack_b = 0;
	markup(&stack_a, markup_mode);
	
}