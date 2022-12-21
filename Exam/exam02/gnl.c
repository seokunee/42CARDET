#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

// char *ft_strjoin(char *s1, char *s2, int len)
// {
// 	char *new;
// 	int	i = 0;
// 	int	j = 0;
// 	int	k = 0;

// 	new = malloc(len + 1);
// 	while (s1[i])
// 		new[k++] = s1[i++];
// 	new[k++] = s1[j++];
// 	new[k] = '\0';
// 	return (new);
// }

// char *get_next_line(int fd)
// {
// 	char 		buf[1];
// 	char 		*tmp;
// 	ssize_t		size;
// 	size_t		len;
// 	char		*str;
// 	len = 1;
// 	size = 1;
// 	size = read(fd, buf, 1);
// 	if (size < 1)
// 	{
// 		str = malloc(1);
// 		*str = '\0';
// 		return (str);
// 	}
// 	str = malloc(2);
// 	str[0] = buf[0];
// 	str[1] = '\0';
// 	while (size)
// 	{
// 		size = read(fd, buf, 1);
// 		if (size == 0)
// 			break;
// 		len++;
// 		tmp = str;
// 		str = ft_strjoin(str, buf, len);
// 		free(tmp);
// 	}
// 	return (str);
// }



// char *to_do(size_t a,int b)
// {
// 	char	*str;
// 	char	c = 0;
// 	char 	k = read(b, &c, 1);
// 	if(k < 0 || k == 0 && a == 0)
// 		return NULL;
// 	if (k == 0 || c == '\n')
// 		str = malloc(a+2);
// 	else 
// 		str = to_do(a+1,b);
// 	if (str)
// 	{
// 		str[a] = c;
// 		str[a+1] = str[a+1] * (c != '\n');
// 	}
// 	return str;
// }

// char *get_next_line(int fd)
// {
// 	return to_do(0,fd);
// }

// char *too_do(int len, int fd)
// {
// 	char c;
// 	int k = read(fd, &c, 1);
// 	char *str;

// 	if (k < 0 || k == 0 && len == 0)
// 		return (NULL);
// 	if (k == 0 || c == '\n')
// 		str = malloc(len + 2);
// 	else
// 		str = too_do(len + 1, fd);
// 	if (str)
// 	{
// 		str[len] = c;
// 		str[len + 1] = str[len + 1] * (c != '\n');
// 	}
// 	return (str);
// }


// char *tooo_do(int len, int fd)
// {
// 	char *str;
// 	char c;
// 	int	k = read(fd, &c, 1);
	
// 	if (k < 0 || k == 0 && len == 0)
// 		return NULL;
// 	if (k == 0 || c == '\n')
// 		str = malloc(len + 2);
// 	else
// 		str = tooo_do(len + 1, fd);
// 	if (str)
// 	{
// 		str[len] = c;
// 		str[len + 1] = str[len + 1] * (c != '\n');
// 	}
// 	return (str);
// }

// char *get_next_line(int fd)
// {
// 	return (tooo_do(0, fd));
// }


char *doo(int len, int fd)
{
	char *str;
	char c;
	int k = read(fd, &c, 1);

	if (k < 0 || k == 0 && len == 0)
		return (NULL);
	if (k == 0 || c == '\n')
		str = malloc(len + 2);
	else
		str = doo(len + 1, fd);
	if (str)
	{
		str[len] = c;
		str[len + 1] = str[len + 1] * (c != '\n');
	}
	return (str);
}
char *get_next_line(int fd)
{
	return (doo(0, fd));
}

#include <stdio.h>

int main()
{
	int	fd;
	char *str;

	fd = open("./file", O_RDONLY);
	while (1)
	{
		str = get_next_line(fd);
		if (!str)
			break;
		printf("%s", str);
		free(str);
	}
	return (0);
}


