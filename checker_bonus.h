/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 02:23:38 by nloutfi           #+#    #+#             */
/*   Updated: 2022/08/11 06:53:09 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "push_swap.h"
# include "tools/get_next_line.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		check_words(char **instructions);
void	execution_1(t_list **stack_a, char *instruction);
int		execution_2(t_list **stack_a, t_list **stack_b, \
		char *instruction, int *count);
int		verification(t_list **stack_a);

#endif