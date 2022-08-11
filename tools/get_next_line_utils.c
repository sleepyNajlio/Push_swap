/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 03:21:49 by nloutfi           #+#    #+#             */
/*   Updated: 2022/08/11 03:33:25 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == (char)c)
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_join_n(char *s1, char *s2, int n)
{
	int				i;
	int				s1_len;
	char			*appended;

	i = 0;
	if (!s1 && !s2)
		return (0);
	s1_len = ft_strlen(s1);
	appended = (char *)malloc(sizeof(char) * (s1_len + n + 1));
	if (!appended)
		return (NULL);
	while (s1 && i < s1_len)
	{
		appended[i] = s1[i];
		i++;
	}
	if (s1)
		ft_free(s1);
	while (i - s1_len < n)
	{
		appended[i] = s2[i - s1_len];
		i++;
	}
	appended[i] = '\0';
	return (appended);
}

void	ft_free(char *s)
{
	if (s)
		free(s);
	s = NULL;
}
