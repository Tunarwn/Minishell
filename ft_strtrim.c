/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsepetci <gsepetci@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:02:44 by gsepetci          #+#    #+#             */
/*   Updated: 2023/01/11 15:36:48 by gsepetci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_char_in_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char *s1, char set)
{
	char	*str;
	int		i;
	int		s;
	int		j;

	j = 0;
	i = 0;
	s = ft_strlen(s1);
	while (s1[i] == set)
		i++;
	while (s1[s] == set)
		s--;
	str = malloc(sizeof(char) * (s - i + 1));
	while (i < s)
	{
		str[j] = s1[i];
		i++;
		j++;
	}
	free(s1);
	return (str);
}
