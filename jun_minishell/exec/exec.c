/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 12:32:50 by chukim            #+#    #+#             */
/*   Updated: 2022/12/04 19:54:52 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_single_builtin_cmd(t_cmd *cmd)
{
	int	fd[2];

	fd[0] = dup(STDIN_FILENO);
	fd[1] = dup(STDOUT_FILENO);
	if (redirect_in(cmd) == 0 && redirect_out(cmd) == 0)
		run_builtin(cmd);
	else
		g_errno = errno;
	ft_dup2(fd[0], STDIN_FILENO);
	ft_dup2(fd[1], STDOUT_FILENO);
}

void	exec_multiple_cmd_in_child_process(t_cmd *cmd)
{
	ft_close(cmd->read_pipe[WRITE]);
	ft_close(cmd->write_pipe[READ]);
	ft_dup2(cmd->read_pipe[READ], STDIN_FILENO);
	ft_dup2(cmd->write_pipe[WRITE], STDOUT_FILENO);
	if (redirect_in(cmd) == 0 && redirect_out(cmd) == 0)
	{
		if (cmd->argc != 0)
			run_cmd(cmd);
		else
			exit(0);
	}
	else
		g_errno = 1;
	exit(g_errno);
}

void	exec_multiple_cmd(t_cmd *cmd, size_t cnt_of_cmd)
{
	int		read_pipe[2];
	int		write_pipe[2];
	pid_t	pid;
	size_t	i;

	i = 0;
	init_pipe(read_pipe, write_pipe); // 읽기 쓰기 파이프를 두개 만들었는데
	while (i < cnt_of_cmd)
	{
		update_pipe(read_pipe, write_pipe, i, cnt_of_cmd);
		cmd[i].read_pipe = read_pipe; // read만 살아있는 파이프
		cmd[i].write_pipe = write_pipe; // write만 살아있는 파이프
		pid = fork();
		if (pid == 0)
			exec_multiple_cmd_in_child_process(&cmd[i]); 
		ft_close(read_pipe[READ]);
		ft_close(read_pipe[WRITE]);
		i++;
	}
	set_signal(IGNORE);
	wait_child_process(pid);
}

void	exec(t_cmd *cmd)
{
	size_t	cnt_of_cmd;

	set_signal(DEFAULT); // 함수를 실행할 때는 시그널을 디폴트값으로 바꿔준다.
	// 그 의미는 quit가 들어오면 받아줄 수 있어야한다는 뜻. 자식 프로세스에서는
	cnt_of_cmd = get_cnt_of_cmd(cmd);
	if (cnt_of_cmd == 1 && cmd[0].argc && is_builtin(&(cmd[0])))
		exec_single_builtin_cmd(cmd);
	else
		exec_multiple_cmd(cmd, cnt_of_cmd);
	set_signal(SHELL);
}
