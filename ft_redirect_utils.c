/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirect_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rartumlu <rartumlu@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 19:25:44 by gsepetci          #+#    #+#             */
/*   Updated: 2023/01/25 20:15:29 by rartumlu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free(char ***temp, int **str, int k)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (k == 0)
	{
		while (temp[i])
		{
			j = 0;
			while (temp[i][j])
				free(temp[i][j++]);
			i++;
		}
	}
	else
	{
		while (temp[i][j])
			free(temp[i][j++]);
	}
}

void	ft_free_2(char ***temp, char **str, int k)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (k == 0)
	{
		while (temp[i])
		{
			j = 0;
			while (temp[i][j])
				free(temp[i][j++]);
			i++;
		}
	}
	else
	{
		while (temp[j])
			free(temp[j++]);
	}
}

int	ft_redirect_there_is(char **str)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (str[i])
	{
		if (ft_strcmp(str[i], "<") == 0)
			return (i);
		else if (ft_strcmp(str[i], "<<") == 0)
			return (i);
		else if (ft_strcmp(str[i], ">") == 0)
			return (i);
		else if (ft_strcmp(str[i], ">>") == 0)
			return (i);
		i++;
	}
	return (0);
}