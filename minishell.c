/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturna <tturna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 21:21:57 by gsepetci          #+#    #+#             */
/*   Updated: 2023/01/30 16:53:27 by tturna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int index __attribute((unused)),
	char **str __attribute((unused)), char **env)
{
	char	*input;

	while (1)
	{
		input = readline("\033[0;34mminishell-> \033[0m");
		if(input)
			add_history(input);
		ft_execve_commands(input, env);
		wait(NULL);
	}
}
