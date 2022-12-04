/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 16:01:34 by junkpark          #+#    #+#             */
/*   Updated: 2022/12/04 21:43:26 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_pipe(int *read_pipe, int *write_pipe)
{
	read_pipe[READ] = 0; // 일단은 read[READ]은 파일 디스크립터 0 표준입력을 가진다?
	read_pipe[WRITE] = -1; // read[WRITE]는 없음.
	write_pipe[READ] = -1;  // read[READ] = 
	write_pipe[WRITE] = 1; // 
}

void	update_pipe(int *read_pipe, int *write_pipe, int i, int cnt_of_cmd)
{
	if (0 < i && i + 1 <= cnt_of_cmd) // 첫번째 명령어가 아닌경우
	{
		read_pipe[READ] = write_pipe[READ]; // read와 write 파이프가 같다.
		read_pipe[WRITE] = write_pipe[WRITE];
	}
	if (i + 1 == cnt_of_cmd) // 명령어가 하나밖에 안들어온경우
	{
		write_pipe[READ] = -1; // 
		write_pipe[WRITE] = STDOUT_FILENO;
	}
	if (0 <= i && i + 1 < cnt_of_cmd) // 명령어의 개수보다 하나 적에 파이프가 필요하므로
		pipe(write_pipe); // 근데 위에처럼 세팅해주는 이유는 무엇일까???????
}
