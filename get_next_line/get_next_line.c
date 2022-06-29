/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 13:41:21 by seokchoi          #+#    #+#             */
/*   Updated: 2022/04/12 20:55:15 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_ckeck_newline(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
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

static ssize_t	until_newline(ssize_t rdsize, char *buf, char **strs, int fd)
{
	char		*tmp;

	while (rdsize > 0)
	{
		buf[rdsize] = '\0';
		if (!strs[fd])
			strs[fd] = ft_strdup("");
		if (!strs[fd])
			return (-2);
		tmp = strs[fd];
		strs[fd] = ft_strjoin(tmp, buf);
		free(tmp);
		if (!strs[fd])
			return (-2);
		if (ft_ckeck_newline(strs[fd]) >= 0)
			break ;
		rdsize = read_file(fd, &buf);
	}
	return (rdsize);
}

char	*get_next_line(int fd)
{
	static char	*strs[OPEN_MAX];
	char		*buf;
	ssize_t		rdsize;

	if (BUFFER_SIZE < 1 || fd < 0 || fd > OPEN_MAX)
		return (NULL);
	if (BUFFER_SIZE > (SIZE_MAX / 2))
		buf = (char *)malloc(sizeof(char) * ((SIZE_MAX / 2) + 1));
	else
		buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (0);
	rdsize = read_file(fd, &buf);
	rdsize = until_newline(rdsize, buf, strs, fd);
	free(buf);
	if (rdsize == -2)
		return (NULL);
	if (!strs[fd])
		return (NULL);
	return (find_line_and_update_str(&strs[fd], rdsize));
}
