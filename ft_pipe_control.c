/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe_control.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsepetci <gsepetci@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:34:50 by gsepetci          #+#    #+#             */
/*   Updated: 2023/01/04 14:42:31 by gsepetci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_pipe_tirnak_kontrol(char *s, int pos)
{
	int	i;
	int	e;

	i = 0;
	e = 0;
	while (i < pos)
	{
		if (s[i] == 34 && e == 0)
			e = 1;
		else if (s[i] == 34 && e == 1)
			e = 0;
		i++;
	}
	if (e == 1)
		return (1);
	return (0);
}

int	ft_pipe_control(char *str)
{
	int	i;
	int	pipe_len;

	pipe_len = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '|' && ft_pipe_tirnak_kontrol(str, i) == 0)
			pipe_len++;
		i++;
	}
	return (pipe_len);
}
