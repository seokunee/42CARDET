/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 13:41:21 by seokchoi          #+#    #+#             */
/*   Updated: 2022/10/21 16:18:32 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static int	ft_ckeck_newline(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n' || str[i] == -1)
			return (i);
		i++;
	}
	return (-1);
}

static ssize_t	read_file(int fd, char **buf)
{
	ssize_t		rdsize;

	if (BUFFER_SIZE > (SIZE_MAX / 2))
		rdsize = read(fd, *buf, (SIZE_MAX / 2));
	else
		rdsize = read(fd, *buf, BUFFER_SIZE);
	return (rdsize);
}

static char	*find_line_and_update_str(char **line, ssize_t rdsize)
{
	char	*tmp;
	char	*top_line;
	int		n_index;

	if (rdsize < 0)
	{
		free(*line);
		return (NULL);
	}
	tmp = *line;
	top_line = NULL;
	n_index = ft_ckeck_newline(*line);
	if (n_index >= 0)
	{
		top_line = ft_substr(tmp, 0, n_index + 1);
		*line = ft_substr(tmp, n_index + 1, ft_strlen(*line) - n_index - 1);
	}
	else
	{
		top_line = ft_substr(tmp, 0, ft_strlen(*line));
		*line = NULL;
	}
	free(tmp);
	return (top_line);
}

static ssize_t	until_newline(ssize_t rdsize, char *buf, t_fd_list *list, int fd)
{
	char		*tmp;
	
	while (rdsize > 0)
	{
		buf[rdsize] = '\0';
		if (!list->str)
			list->str = ft_strdup("");
		if (!list->str)
			return (-2);
		tmp = list->str;
		list->str = ft_strjoin(tmp, buf);
		free(tmp);
		if (!list->str)
			return (-2);
		if (ft_ckeck_newline(list->str) >= 0)
			break ;
		rdsize = read_file(fd, &buf);
	}
	return (rdsize);
}

t_fd_list	*find_fd_linked_list(t_fd_list *list, int fd)
{
	t_fd_list *tmp;
	t_fd_list *last;

	tmp = list;
	if (tmp == NULL)
	{
		list = (t_fd_list*)malloc(sizeof(t_fd_list));
		list->next = NULL;
		list->fd = fd;
		return (list);
	}
	while (tmp)
	{
		if (tmp->fd == fd)
			break;
		last = tmp;
		tmp = tmp->next;
	}
	if (tmp == NULL)
	{
		list = (t_fd_list*)malloc(sizeof(t_fd_list));
		last->next = list;
		list->next = NULL;
		list->fd = fd;
		return (list);
	}
	return (tmp);
}

char	*get_next_line(int fd)
{
	static t_fd_list *list;
	char		*buf;
	ssize_t		rdsize;
	t_fd_list	*target;

	printf("1\n");
	if (BUFFER_SIZE < 1 || fd < 0 || fd > OPEN_MAX)
		return (NULL);
	printf("2\n");

	if (BUFFER_SIZE > (SIZE_MAX / 2))
		buf = (char *)malloc(sizeof(char) * ((SIZE_MAX / 2) + 1));
	else
		buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	printf("3\n");
	
	if (!buf)
		return (0);
	printf("4\n");
	
	target = find_fd_linked_list(list, fd);
	printf("5\n");

	rdsize = read_file(fd, &buf);
	printf("6\n");

	rdsize = until_newline(rdsize, buf, target, fd);
	printf("7\n");

	free(buf);
	if (rdsize == -2)
		return (NULL);
	if (target->str)
		return (NULL);
	printf("8\n");
	
	return (find_line_and_update_str(&target->str, rdsize));
}
