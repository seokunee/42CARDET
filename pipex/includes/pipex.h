/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 15:19:15 by seokchoi          #+#    #+#             */
/*   Updated: 2022/08/30 21:11:29 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h> /* fork, execve */
# include <fcntl.h>  /* open */
# include <stdlib.h> 
# include <stdio.h> 
# include <stdio.h> 
# include "libft.h"

typedef struct s_data
{
	char *cmd1_path; /* cmd_path는 찐임*/
	char *cmd2_path;
	char **cmd1; /* 인자로 들어온 애들이 split 해서 들어있음. */
	char **cmd2;
	char **envp_path;
	int	fd[2];
	int	infile;
	int outfile;
	pid_t	pid;
	pid_t	pid2;
} t_data;

char	*set_cmd_path(char *cmd, char **envp_path);
void	close_all_data(pid_t pid, pid_t pid2, t_data *data);
void	init_cmd_data(char **av, t_data *data, char **envp);
void	set_fd_direction(int fd_closed, int stdin, int stdout);

void	throw_error(char *message, int status);
void	free_sec_arr(char **arr);
char	*ft_strjoin_between(char const *s1, char const *s2, char c);

#endif