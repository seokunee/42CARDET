/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 15:02:45 by seokchoi          #+#    #+#             */
/*   Updated: 2022/07/26 17:00:27 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	get_cmd_access(char *cmd)
{
	if (access((const char *)cmd, X_OK) == -1)
		return (0); // 에러면 0
	return (1); // 성공이면 1
}

void	set_cmd_and_path(char **av, t_data *data)
{
	data->cmd1 = ft_split(av[2], ' ');
	data->cmd2 = ft_split(av[3], ' ');
	if (ft_strnstr(data->cmd1[0], "/bin/", 5) == 0)
		data->cmd1_path = ft_strjoin("/bin/",  data->cmd1[0]);
	if (ft_strnstr(data->cmd2[0], "/bin/", 5) == 0)
		data->cmd2_path = ft_strjoin("/bin/", data->cmd2[0]);
}

void	print_envp(char **envp)
{
	int	i;
	
	i = 0;
	while (envp[i])
	{
		// printf("%s", envp[i]);
		i++;
	}
}

int	main(int ac, char **av, char **envp)
{
	t_data data;
	int		pid;
	int		x;

	if (ac != 5)
		return (0);

	print_envp(envp);
	// 명령어 set
	set_cmd_and_path(av, &data);

	// 명령어 유무 및 실행 가능여부 확인
	printf("%s\n" , data.cmd1_path);
	printf("%s\n\n" , data.cmd2_path);

	printf("cmd1 : %d\n", get_cmd_access(data.cmd1_path));
	printf("cmd2 : %d\n", get_cmd_access(data.cmd2_path));

	pid = fork();
	// 명령어 실행
	if (pid > 0)
	{
		x = 1;
		printf("부모 pid : %d, x = %d\n", pid, x);
		execve(data.cmd1_path, data.cmd1, NULL);
	}
	else if (pid == 0)
	{
		x = 2;
		printf("자식 pid : %d, x = %d\n", pid, x);
		execve(data.cmd2_path, data.cmd2, NULL);
	}
	else
	{
		printf("fork error!");
	}
}