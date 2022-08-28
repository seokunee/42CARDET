/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 15:02:45 by seokchoi          #+#    #+#             */
/*   Updated: 2022/08/28 20:32:59 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	throw_error(char *message, int status)
{
	perror(message);
	exit(status);
}

char	*ft_strjoin_between(char const *s1, char const *s2, char c)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;
	size_t	j;
	char	*str;

	if (!s1 || !s2)
		return (0);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (s1_len + s2_len + 2));
	if (!str)
		return (0);
	i = 0;
	j = 0;
	while (j < s1_len)
		str[i++] = s1[j++];
	str[i++] = c;
	j = 0;
	while (j < s2_len)
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}

char	*set_cmd_path(char *cmd, char **envp_path)
{
	int	i;
	char * cmd_path;

	i = 0;
	if (access((const char *)cmd, X_OK) == 0)
	{
		cmd_path = ft_strdup(cmd);
		return (cmd_path);
	}
	while(envp_path[i])
	{
		cmd_path = ft_strjoin_between(envp_path[i], cmd, '/');
		printf("cmd_path = %s\n", cmd_path);	
		if (access((const char*)cmd_path, X_OK) == 0)
			return (cmd_path);
		free(cmd_path);
		i++;
	}
	throw_error("command not found", 127);
	return (NULL);
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
			break;
		i++;
	}
	data->envp_path = ft_split(&envp[i][5], ':');
}

void	set_fd_direction(int fd_closed, int stdin, int stdout)
{
	close(fd_closed);
	if (dup2(stdin, STDIN_FILENO))
		throw_error("Dup2 Error", 1);
	if (dup2(stdout, STDERR_FILENO))
		throw_error("Dup2 Error", 1);
	close(stdin);
	close(stdout);	
}

int	main(int ac, char **av, char **envp)
{
	t_data data;
	int		pid;

	if (ac != 5)
		return (0);
	
	data.infile = open(av[1], O_RDWR);
	data.outfile = open(av[4], O_RDWR);
	init_cmd_data(av, &data, envp);
	data.cmd1_path = set_cmd_path(data.cmd1[0],data.envp_path);
	data.cmd2_path = set_cmd_path(data.cmd2[0],data.envp_path);

	pid = fork();
	if (pid < 0)
		throw_error("Fork Error!", 1);
	if (pipe(data.fd) < 0)
		throw_error("Pipe Error", 1);
	if (pid == 0)
	{
		set_fd_direction(data.fd[0], data.infile, data.fd[1]);
		if (execve(data.cmd1_path, data.cmd1, envp) < 0)
			throw_error("command not found", 127);
	}
	else
	{
		set_fd_direction(data.fd[1], data.fd[0], data.outfile);
		waitpid(pid, NULL, WNOHANG);
		if (execve(data.cmd2_path, data.cmd2, envp) < 0)
			throw_error("command not found", 127);
	}
	return (0);
}
