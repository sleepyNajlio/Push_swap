/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 02:38:04 by nloutfi           #+#    #+#             */
/*   Updated: 2022/08/07 20:53:22 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	number_of_strings(char const *s, char c)
{
	int	i;
	int	j;
	int	n;

	i = 0;
	n = 0;
	while (s[i])
	{
		j = 0;
		while (s[i] != c && s[i])
		{
			j = 1;
			i++;
		}
		if (j == 1)
			n++;
		if (s[i])
			i++;
	}
	return (n);
}

char	*malloc_free(char **x, int k, int j)
{
	x[k] = malloc(j + 1);
	if (!x[k])
	{
		while (k > 0)
		{
			free(x[k - 1]);
			k--;
		}
		free(x);
		x = NULL;
		return (0);
	}
	return (x[k]);
}

void	ft_split_1(char const *s, char c, char **x, int n)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (n > 0)
	{
		j = 0;
		while (s[i] == c)
			i++;
		while (s[i + j] != c && s[i + j])
			j++;
		if (!malloc_free(x, k, j))
			return ;
		if (ft_memmove(x[k], &s[i], j))
		{
			x[k][j] = 0;
			k++;
			n--;
			i = i + j;
		}
	}
	x[k] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**x;
	int		n;

	if (!s)
		return (0);
	n = number_of_strings(s, c);
	x = malloc((n + 1) * sizeof(char *));
	if (!x)
		return (0);
	ft_split_1(s, c, x, n);
	return (x);
}
