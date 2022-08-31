/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 15:02:45 by seokchoi          #+#    #+#             */
/*   Updated: 2022/08/31 15:36:01 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*set_cmd_path(char *cmd, char **envp_path)
{
	int		i;
	char	*cmd_path;

	i = 0;
	if (access((const char *)cmd, X_OK) == 0)
	{
		cmd_path = ft_strdup(cmd);
		return (cmd_path);
	}
	while (envp_path[i])
	{
		cmd_path = ft_strjoin_between(envp_path[i], cmd, '/');
		if (access((const char *)cmd_path, X_OK) == 0)
			return (cmd_path);
		free(cmd_path);
		i++;
	}
	throw_error("command not found", 127);
	return (NULL);
}

void	close_all_data(pid_t pid, pid_t pid2, t_data *data)
{
	close(data->fd[1]);
	close(data->fd[0]);
	waitpid(pid, NULL, 0);
	waitpid(pid2, NULL, 0);
	close(data->infile);
	close(data->outfile);
	free(data->cmd1_path);
	free(data->cmd2_path);
	free_sec_arr(data->cmd1);
	free_sec_arr(data->cmd2);
	free_sec_arr(data->envp_path);
}

void	init_cmd_data(char **av, t_data *data, char **envp)
{
	int	i;

	i = 0;
	data->cmd1 = ft_split(av[2], ' ');
	data->cmd2 = ft_split(av[3], ' ');
	data->cmd1_path = NULL;
	data->cmd2_path = NULL;
	while (envp[i])
	{
		if (ft_strncmp((const char *)envp[i], "PATH=", 5) == 0)
			break ;
		i++;
	}
	data->envp_path = ft_split(&envp[i][5], ':');
	data->infile = open(av[1], O_RDWR);
	data->outfile = open(av[4], O_RDWR | O_CREAT | \
		O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (data->infile == -1 || data->outfile == -1)
		throw_error("open file Error", 1);
	if (pipe(data->fd) == -1)
		throw_error("Pipe Error", 1);
	data->pid = fork();
	if (data->pid == -1)
		throw_error("Fork Error!", 1);
}

void	set_fd_direction(int fd_closed, int stdin, int stdout)
{
	close(fd_closed);
	if (dup2(stdin, STDIN_FILENO) == -1)
		throw_error("Dup2 Error", 1);
	if (dup2(stdout, STDOUT_FILENO) == -1)
		throw_error("Dup2 Error", 1);
	close(stdin);
	close(stdout);
}

int	main(int ac, char **av, char **envp)
{
	t_data	data;

	if (ac != 5)
		throw_error("Argument Error", 1);
	init_cmd_data(av, &data, envp);
	if (data.pid == 0)
	{
		data.cmd1_path = set_cmd_path(data.cmd1[0], data.envp_path);
		set_fd_direction(data.fd[0], data.infile, data.fd[1]);
		if (execve(data.cmd1_path, data.cmd1, envp) == -1)
			throw_error("command not found", 127);
	}
	data.pid2 = fork();
	if (data.pid2 == 0)
	{
		data.cmd2_path = set_cmd_path(data.cmd2[0], data.envp_path);
		set_fd_direction(data.fd[1], data.fd[0], data.outfile);
		if (execve(data.cmd2_path, data.cmd2, envp) == -1)
			throw_error("command not found", 127);
	}
	close_all_data(data.pid, data.pid2, &data);
	return (0);
}
