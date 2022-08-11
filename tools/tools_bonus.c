/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 17:09:47 by nloutfi           #+#    #+#             */
/*   Updated: 2022/08/11 19:48:19 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*str2;
	unsigned char	*str1;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
	{
		return (0);
	}
	while (i < n - 1 && str1[i] != '\0')
	{
		if (str1[i] != str2[i])
		{
			return (str1[i] - str2[i]);
		}
		i++;
	}
	return (str1[i] - str2[i]);
}

int	check_words(char **instructions)
{
	int	i;

	i = 0;
	while (instructions && instructions[i])
	{
		if (!ft_strncmp(instructions[i], "sa", 3)
			|| !ft_strncmp(instructions[i], "ra", 3)
			|| !ft_strncmp(instructions[i], "rra", 4)
			|| !ft_strncmp(instructions[i], "rrr", 4)
			|| !ft_strncmp(instructions[i], "rrb", 4)
			|| !ft_strncmp(instructions[i], "sb", 3)
			|| !ft_strncmp(instructions[i], "rr", 3)
			|| !ft_strncmp(instructions[i], "rb", 3)
			|| !ft_strncmp(instructions[i], "ss", 3)
			|| !ft_strncmp(instructions[i], "pa", 3)
			|| !ft_strncmp(instructions[i], "pb", 3))
			i++;
		else
			return (1);
	}
	return (0);
}

void	execution_1(t_list **stack_a, char *instruction)
{
	if (!ft_strncmp(instruction, "sa", 3))
		swap(stack_a);
	else if (!ft_strncmp(instruction, "ra", 3))
		rotate(stack_a, 0);
	else
		rotate(stack_a, 1);
}

int	execution_2(t_list **stack_a, t_list **stack_b, \
char *instruction, int *count)
{
	if (!(*count))
		return (1);
	if (!ft_strncmp(instruction, "pa", 3))
	{
		push(stack_b, stack_a);
		count--;
	}
	else if (!ft_strncmp(instruction, "rrr", 4))
		rr(stack_a, stack_b, 1);
	else if (!ft_strncmp(instruction, "rr", 3))
		rr(stack_a, stack_b, 0);
	else if (!ft_strncmp(instruction, "rrb", 4))
		rotate(stack_b, 1);
	else if (!ft_strncmp(instruction, "rb", 3))
		rotate(stack_b, 0);
	else if (ft_strncmp(instruction, "ss", 3))
		ss(stack_a, stack_b);
	return (0);
}

int	verification(t_list **stack_a)
{
	t_list	*head;
	int		start;

	head = *stack_a;
	while (head->next != *stack_a)
	{
		start = 1;
		if (head->content > head->next->content)
			return (1);
		head = head->next;
	}
	return (0);
}
