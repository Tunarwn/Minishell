/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsepetci <gsepetci@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 11:37:31 by gsepetci          #+#    #+#             */
/*   Updated: 2023/01/24 19:38:40 by gsepetci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		a;
	char	*src;
	char	*dest;
	char	*dizi;

	i = 0;
	a = 0;
	src = (char *)s1;
	if (!s1)
		return (0);
	dest = (char *)s2;
	dizi = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)));
	if (!dizi)
		return (0);
	while (src[i] != '\0')
	{
		dizi[i] = src[i];
		i++;
	}
	while (dest[a] != '\0')
		dizi[i++] = dest[a++];
	dizi[i] = '\0';
	return (dizi);
}

char	*ft_get_str(char *str, int n, int i, int s)
{
	char	*temp;
	int		j;

	j = 0;
	while (s < n)
	{
		i++;
		if (str[i] == '|' || str[i] == '\0')
			s++;
	}
	i--;
	while (str[--i] != '|' && i > -1)
		j++;
	temp = (char *)malloc(sizeof(char) * (j + 1));
	j = 0;
	i++;
	while (str[i] != '|' && str[i] != '\0')
		temp[j++] = str[i++];
	temp[j] = '\0';
	return (temp);
}
