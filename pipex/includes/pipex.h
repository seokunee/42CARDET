/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 15:19:15 by seokchoi          #+#    #+#             */
/*   Updated: 2022/08/31 14:10:09 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h> /* fork, execve, close, read, write, exit, access, dup2 */
# include <fcntl.h>  /* open */
# include <stdlib.h> /* malloc, free */
# include <stdio.h> /* perror */
# include <sys/wait.h> /* waitpid */
# include "libft.h"

typedef struct s_data
{
	char	*cmd1_path;
	char	*cmd2_path;
	char	**cmd1;
	char	**cmd2;
	char	**envp_path;
	int		fd[2];
	int		infile;
	int		outfile;
	pid_t	pid;
	pid_t	pid2;
}			t_data;

char	*set_cmd_path(char *cmd, char **envp_path);
void	close_all_data(pid_t pid, pid_t pid2, t_data *data);
void	init_cmd_data(char **av, t_data *data, char **envp);
void	set_fd_direction(int fd_closed, int stdin, int stdout);

void	throw_error(char *message, int status);
void	free_sec_arr(char **arr);
char	*ft_strjoin_between(char const *s1, char const *s2, char c);

#endif