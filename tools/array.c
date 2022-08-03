/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 10:35:15 by nloutfi           #+#    #+#             */
/*   Updated: 2022/07/31 20:20:27 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
// void	ft_swap(t_array *arr, int i, int j;)
// {
// 	int *temp;

// 	temp = a;
// 	*a = *b;
// 	*b = *temp;
// }
void	sort_array(t_array *arr)
{
	int i;
	int temp;
	
	i = 0;
	while (i < arr->size - 1)
	{
		if (arr->arr[i] > arr->arr[i + 1])
		{
			temp = arr->arr[i];
			arr->arr[i] = arr->arr[i +1];
			arr->arr[i + 1] = temp;
			i = 0;
		}
		else
			i++;
	}

}

void	create_arr(int ac, char **av, t_array **arr)
{
	int	*tab;
	int	i;
	int j;
	
	i = 1;
	j = 0;
	(*arr)->size = ac - 1;
	tab = malloc(sizeof(int) * (*arr)->size);
	if (!tab)
		return ;
	while (av[i])
		tab[j++] = ft_atoi(av[i++]);
	(*arr)->arr = tab;
	sort_array(*arr);
}