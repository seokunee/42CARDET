/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 15:02:45 by seokchoi          #+#    #+#             */
/*   Updated: 2022/08/28 19:51:44 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// cmd 입력받은 명령어
// cmd_path
// void	check_cmd_path(t_data *data, char *cmd1, char *cmd)
// {
// 	int	i;

// 	i = 0;
// 	data->cmd1_path = NULL;
// 	data->cmd2_path = NULL;
// 	if (get_cmd_access(cmd1) == 1)
// 		data->cmd1_path = cmd1;
// 	if (get_cmd_access(cmd2) == 1)
// 		data->cmd1_path = cmd2;
// 	while (data->envp_path[i] && data->cmd1_path != NULL)
// 	{
// 		if ()
// 		i++;
// 	}
// 	while (data->)
// 	if (data->cmd1_path == NULL || data->cmd2_path == NULL)
// 		throw_error("Invalid command");
// }

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

void	set_fd_direction()
{

}

int	main(int ac, char **av, char **envp)
{
	t_data data;
	int		pid;

	if (ac != 5)
		return (0);
	
	init_cmd_data(av, &data, envp);
	data.cmd1_path = set_cmd_path(data.cmd1[0],data.envp_path);
	data.cmd2_path = set_cmd_path(data.cmd2[0],data.envp_path);

	printf("cmd1 = %s\n", data.cmd1_path);
	printf("cmd2 = %s\n", data.cmd2_path);

	pid = fork();
	if (pid < 0)
		throw_error("Fork Error!", 1);
	pipe(data.fd);
	if 
	if (pid == 0)
	{
		set_fd_direction();
		if (execve(data.cmd1_path, data.cmd1, envp) < 0)
			throw_error("command not found", 127);
	}
	else
	{
		waitpid(pid, NULL, WNOHANG);
		if (execve(data.cmd2_path, data.cmd2, envp) < 0)
			throw_error("command not found", 127);
	}
	return (0);
}


/*
	1. PATH가 적용된 cmd 찾아주기 

	2. 자식프로세서 동작

	3. 부모 프로세서 동작
*/