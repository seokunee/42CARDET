/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 15:19:15 by seokchoi          #+#    #+#             */
/*   Updated: 2022/08/28 19:52:36 by seokchoi         ###   ########.fr       */
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
} t_data;

#endif