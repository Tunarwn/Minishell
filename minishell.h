/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturna <tturna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 21:23:38 by gsepetci          #+#    #+#             */
/*   Updated: 2023/01/31 12:32:29 by tturna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <readline/readline.h>
# include <readline/history.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/wait.h>
# include <stdlib.h>

char	**ft_split(char const *s, char c);
char	*ft_strtrim(char *s1, char set);
int		ft_split_len(char **dizi);
int		ft_strlen(const char *str);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strdup(const char *s1);
char	**ft_strdup_2(char **s1);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_execve_commands(char *input, char **env);
void	ft_run_commands(char **new_input, int pid, char *env);
int		ft_redirect_count(char *str);
int		ft_redirect_there_is(char **str);
char	*ft_redirect(char *str, int j, int i);
int		ft_pipe_control(char *str);
char	***ft_pipe_arr(int pipe_len, char *input);
int		ft_pipe_tirnak_kontrol(char *s, int pos);
char	*ft_get_str(char *str, int n, int i, int s);
void	ft_free(char ***temp, int **str, int k);
void	*builtins(char *cmd);
void	is_exits(char *ex);
int		ex_re(char *exst);

#endif
