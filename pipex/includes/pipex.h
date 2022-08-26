/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 15:19:15 by seokchoi          #+#    #+#             */
/*   Updated: 2022/08/01 14:48:41 by seokchoi         ###   ########.fr       */
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
	char *cmd1_path;
	char *cmd2_path;
	char **cmd1;
	char **cmd2;
	char **envp_path;
} t_data;


#endif