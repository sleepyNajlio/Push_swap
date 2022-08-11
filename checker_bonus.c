/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 02:22:06 by nloutfi           #+#    #+#             */
/*   Updated: 2022/08/11 06:51:15 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	phase(char *ins)
{
	if (!ft_strncmp(ins, "sa", 3)
		|| !ft_strncmp(ins, "ra", 3)
		|| !ft_strncmp(ins, "rra", 4))
		return (1);
	else if (!ft_strncmp(ins, "pb", 3))
		return (2);
	else
		return (3);
}

int	execute(t_list **stack_a, t_list **stack_b, char **instructions)
{
	int	i;
	int	size;
	int	count;

	size = ft_lstsize(*stack_a);
	i = 0;
	count = 0;
	while (instructions[i])
	{
		if (phase(instructions[i]) == 1)
			execution_1(stack_a, instructions[i]);
		else if (phase(instructions[i]) == 2)
		{
			if (count + 1 == size)
				return (1);
			push(stack_a, stack_b);
			count++;
		}
		else if (phase(instructions[i]) == 3)
			if (execution_2(stack_a, stack_b, instructions[i], &count))
				return (1);
		i++;
	}
	return (count);
}

char	**ft_instructions(void)
{
	char	*line;
	char	*ins;
	char	**instructions;

	line = get_next_line(0);
	if (!line)
		return (0);
	if (!ft_strncmp(line, "Error", 5))
	{
		write(2, "Error", 5);
		free(line);
		return (0);
	}
	ins = ft_strdup("\n");
	while (line)
	{
		ins = ft_strjoin(ins, line);
		line = get_next_line(0);
	}
	instructions = ft_split(ins, '\n');
	return (instructions);
}

void	checker(t_list *stack_a)
{
	int		check;
	char	**instructions;
	t_list	*stack_b;

	instructions = ft_instructions();
	stack_b = 0;
	check = 0;
	if (check_words(instructions))
		check = -1;
	if (instructions)
		check = execute(&stack_a, &stack_b, instructions);
	if (check == -1)
		write(2, "Error\n", 6);
	else if (check == 1 || verification(&stack_a))
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	free_stack(stack_a);
	free_array(instructions);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	char	**nums;

	(void)ac;
	nums = parsing(av);
	if (count(nums) > 2 && check_error(count(nums), nums))
	{
		stack_a = indexation(count(nums), nums);
		checker(stack_a);
	}
	free_array(nums);
	return (0);
}
