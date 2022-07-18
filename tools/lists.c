/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 13:13:54 by nloutfi           #+#    #+#             */
/*   Updated: 2022/07/13 13:22:43 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*ft_lstnew(int content)
{
	t_list	*lst;

	lst = malloc(sizeof(t_list));
	if (!lst)
		return (0);
	lst->content = content;
	lst->index = 0;
	lst->markup = 0;
	lst->next = 0;
	return (lst);
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*head;

	if (!lst)
		return (lst);
	head = lst;
	while (head->next && head->next != lst)
		head = head->next;
	return (head);
}

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*head;

	if (!lst)
		return (0);
	i = 0;
	head = lst;
	while (head->next != lst)
	{
		head = head->next;
		i++;
	}
	return (i + 1);
}

void	ft_lstadd_back(t_list **lst, t_list *new, int index)
{
	t_list	*tmp;
	t_list	*head;

	if (!lst)
		return ;
	if (!(*lst))
	{
		(*lst) = new;
		return ;
	}
	head = *lst;
	tmp = ft_lstlast(head);
	tmp->next = new;
	new->index = index;
	new->next = *lst;
}
