/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe_arr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsepetci <gsepetci@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:57:34 by gsepetci          #+#    #+#             */
/*   Updated: 2023/01/25 17:02:00 by gsepetci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*ft_space_to_ascii(char *str)
{
	int	i;
	int	s;
	int	k;

	k = 0;
	s = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == 34 || str[i] == 39)
			s++;
		i++;
	}
	if (s % 2 == 1)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == 34 || str[i] == 39)
			k++;
		if (k > 0 && k <= s && str[i] == ' ')
			str[i] = 126;
		i++;
	}
	return (str);
}

static char	**ft_ascii_to_space(char **str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == 126)
				str[i][j] = ' ';
			j++;
		}
		i++;
	}
	return (str);
}

char	***ft_pipe_arr(int pipe_len, char *input)
{
	char	***new_arr;
	int		i;
	char	*temp;
	int		arr_index;

	new_arr = (char ***)malloc((ft_pipe_control(input) + 2) * sizeof(char *));
	i = 0;
	arr_index = 0;
	while (i <= ft_strlen(input))
	{
		if (input[i] == '|' || input[i] == '\0')
		{
			temp = ft_strtrim(ft_space_to_ascii(ft_get_str(input,
							arr_index, -1, -1)), ' ');
			if (ft_redirect_count(temp) > 0)
				temp = ft_redirect(temp, 0, 0);
			new_arr[arr_index] = ft_split(temp, ' ');
			new_arr[arr_index] = ft_ascii_to_space(new_arr[arr_index]);
			free(temp);
			arr_index++;
		}
		i++;
	}
	new_arr[arr_index] = NULL;
	return (new_arr);
}
