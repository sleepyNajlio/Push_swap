/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 20:27:13 by nloutfi           #+#    #+#             */
/*   Updated: 2022/08/11 03:15:55 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				content;
	int				index;
	int				markup;
	struct s_list	*next;
}	t_list;

typedef struct s_array
{
	int	*arr;
	int	size;
}	t_array;

long long		ft_atoi(const char *str);
int				check_error(int ac, char **av);
void			create_arr(int ac, char **av, t_array **arr);
void			ft_lstadd_back(t_list **lst, t_list *new, int index);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
t_list			*ft_lstnew(int content);
t_list			*indexation(int ac, char **av);
void			markup(t_list **stack, int markup_mode);
t_list			*a_to_b(t_list **stack_a, int markup_mode, \
				int *moves, int phase);
void			push(t_list	**stack_1, t_list **stack_2);
void			swap(t_list	**stack);
void			ss(t_list **stack_a, t_list **stack_b);
void			rr(t_list **stack_a, t_list **stack_b, int dir);
void			rotate(t_list **stack, int d);
void			ft_lstadd_front(t_list **lst, t_list *new);
void			b_to_a(t_list **stack_a, t_list **stack_b, \
				int *moves, int phase);
void			moves_a(int *moves, int phase, int move, int dir);
int				direction(t_list **stack, int index);
int				choose_stack(t_list **stack_a, t_list **stack_b);
int				prepare_a(t_list **stack_a, int b_index);
void			move(t_list **stack_a, t_list **stack_b, int phase, int *moves);
void			free_stack(t_list *stack);
void			free_array(char **nums);
int				count(char **s);
char			**parsing(char **av);
char			**ft_split(char const *s, char c);
char			*ft_strdup(const char *str);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memcpy(void *dst, const void *src, size_t n);
int				test_markups(int markup_mode, char **nums);
int				tests(char **nums);
size_t			ft_strlen(const char *s);
char			*ft_strjoin(char const *s1, char const *s2);

#endif