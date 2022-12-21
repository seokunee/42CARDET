#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

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


