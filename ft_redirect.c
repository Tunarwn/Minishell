/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsepetci <gsepetci@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:44:16 by gsepetci          #+#    #+#             */
/*   Updated: 2023/01/25 17:02:04 by gsepetci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_redirect_count(char *str)
{
	int	i;
	int	c;

	c = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '<' || str[i] == '>')
		{
			c++;
			i++;
			if (str[i] == '<' || str[i] == '>')
				i++;
		}
		i++;
	}
	return (c * 2);
}

static char	*ft_first_redirect(char *str, char *temp)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if ((str[i + 1] == '<' || str[i + 1] == '>')
			&& str[i] != ' ' && str[i - 1] != ' ')
		{
			temp[j] = str[i];
			temp[++j] = ' ';
			temp[++j] = str[++i];
		}
		temp[j++] = str[i++];
	}
	return (temp);
}

static void	ft_i_and_j_add(int *i, int *j)
{
	*i = *i + 1;
	*j = *j + 1;
}

char	*ft_redirect(char *str, int j, int i)
{
	char	*temp;
	char	*last;

	temp = malloc(sizeof(char) * (ft_strlen(temp) + ft_redirect_count(str)));
	temp = ft_first_redirect(str, temp);
	last = ft_strdup(temp);
	free(str);
	while (last[i])
	{
		if ((last[i] == '<' || last[i] == '>'))
		{
			ft_i_and_j_add(&i, &j);
			if (last[i] == '<' || last[i] == '>')
				ft_i_and_j_add(&i, &j);
			if ((last[i - 1] == '<' || last[i - 1] == '>') && last[i] != ' ')
			{
				temp[j] = ' ';
				temp[++j] = last[i];
			}
		}
		temp[j++] = last[i++];
	}
	free(last);
	temp[j] = '\0';
	return (temp);
}
