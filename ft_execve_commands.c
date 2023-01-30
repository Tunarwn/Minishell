/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execve_commands.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturna <tturna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 10:45:50 by gsepetci          #+#    #+#             */
/*   Updated: 2023/01/30 20:22:20 by tturna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


char 	*ft_accessa(char *new_input, char *env)
{
	char **a;
	a = ft_split(env + 5, ':');
	int i = 0;
	while(a[i])
	{
		a[i] = ft_strjoin(a[i], "/");
		a[i] = ft_strjoin(a[i], new_input);
		if (!access(a[i], F_OK))
			return (a[i]);
		i++;
	}
	return (new_input);
}

void	ft_run_commands(char **new_input, int pid, char *env)
{
	char	*path;
	char	*temp;


	path = ft_accessa(*new_input, env);
	if(execve(path, new_input, NULL) == -1)
	{
		perror("");
		exit(1);
	}
	else
		exit(0);
}

static void	ft_close_pipe(int **fd, int i, int n)
{
	int	j;

	j = 0;
	if (n == 1)
	{
		while (j < i)
		{
			close(fd[j][0]);
			close(fd[j][1]);
			j++;
		}
	}
	else
	{
		close(fd[0][0]);
		close(fd[0][1]);
	}
}

static int	**ft_pipe_malloc(int **fd, int count)
{
	int	i;

	i = 0;
	fd = malloc((sizeof(int *) * count) + 1);
	while (i <= count)
		fd[i++] = malloc(sizeof(int) * 2);
	i = 0;
	while (i < count)
	{
		pipe(fd[i]);
		i++;
	}
	return (fd);
}

static void	ft_pipe_function_run(char ***str, char *input, char *env)
{
	int	**fd;
	int	pid;
	int	p;
	int	i;

	i = 0;
	p = 1;
	fd = ft_pipe_malloc(fd, ft_pipe_control(input));
	pid = fork();
	if (pid == 0)
	{
		dup2(fd[0][1], 1);
		ft_close_pipe(fd, i, 0);
		ft_run_commands(str[i++], 0, env);
	}
	while (str[i])
	{
		pid = fork();
		if (pid == 0)
		{
			dup2(fd[i - 1][0], 0);
			if (i != ft_pipe_control(input))
				dup2(fd[i][1], 1);
			ft_close_pipe(fd, i, 1);
			ft_run_commands(str[i], 0, env);
		}
		i++;
	}
	ft_close_pipe(fd, ft_pipe_control(input), 1);
	waitpid(pid, NULL, 0);
	ft_free(str, fd, 1);
}

int 	ft_dolarnumber(char *str)
{
	int i = 0;

	while(*str)
	{
		if (*str == '$')
			i++;
		str++;
	}
	return (i);
}

char	*ft_dolar(char *str)
{
	int i = 0;
	int j = 0;
	int t = 0;
	int y = 0;
	int p = 0;
	y = ft_dolarnumber(str);
	//printf("%d\n", y);
	char *b;
	char *a;
	a = malloc(sizeof(char *) * 1000);
	//printf("%s\n", str);
	while(str[j])
	{
		if (str[j] == '$')
		{
			char *c;
			c = malloc(sizeof(char *) * 1000);
			j++;
			while(str[j] != ' ' && str[j])
			{
				c[i] = str[j];
				i++;
				j++;;
			}
			c[i] = '\0';
			b = getenv(c);
			free(c);
			break;
		}
		j++;
	}
	j = 0;
	i = 0;
	int check = 0;
	//b = /Users/rartumlu
	//str = ls $HOME | ls $PWD
	//a = ls /Users/rartumlu | ls $PWD
	while(str[j])
	{
		if (str[j] == '$' && check == 0)
		{
			check = 1;
			while(str[j] != ' ' && str[j])
				j++;
			while(b[t])
			{
				a[i] = b[t];
				t++;
				i++;
			}
		}
		a[i] = str[j];
		i++;
		j++;
	}
	a[i] = '\0';
	return (a);
}

void	ft_execve_commands(char *input, char **env)
{
	char	**new_input;
	int		pipe_len;
	char	***temp;
	int		i;
	int		j;
	char	*n;

	n = malloc(sizeof(char *) * 1000);
	i = 2;
	pipe_len = ft_pipe_control(input);
	n = input;
	builtins(input);
	i = ft_dolarnumber(input);
	while(i > 0)
	{
		n = ft_dolar(n);
		i--;
	}
	i = 0;
	if (pipe_len == 0)
	{
		new_input = ft_split(n, ' ');
		i = fork();
		if (i == 0)
			ft_run_commands(new_input, 0, env[2]);
		wait(NULL);
		free(new_input);
	}
	else
	{
		temp = ft_pipe_arr(ft_pipe_control(n), n);
		ft_pipe_function_run(temp, n, env[2]);
	}
}
