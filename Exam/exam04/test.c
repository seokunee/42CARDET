#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int ft_putchar_fd2(char *msg, char *path)
{
	while (*msg)
		write(2, msg++, 1);
	if (path)
		while (*path)
			write(2, path++, 1);
	write(2, "\n", 1);
	return (1);
}

int ft_execute(char **av, int i, int tmp_fd, char **env)
{
	av[i] = NULL; // execve에서 stop 포인트를 알아야하기 때문에.
	dup2(tmp_fd, STDIN_FILENO);
	close(tmp_fd);
	execve(av[0], av, env);
	return (ft_putchar_fd2("error: cannot execute ", av[0]));
}

int main(int ac, char **av, char **env)
{
	int i;
	int tmp_fd;
	(void)ac;

	i = 0;
	tmp_fd = dup(STDIN_FILENO);
	while (av[i] && av[i + 1])
	{
		av[i] = &av[i + 1];
		i = 0;
		while (av[i] && strcmp(av[i], ";") && strcmp(av[i], "|"))
			i++;
		if (strcmp(av[0], "cd") == 0)
		{
			if (i != 2)
				ft_putchar_fd2("error: cd: bad arguments", NULL);
			else if (chdir(av[1]) != 0)
				ft_putchar_fd2("error: cd: cannot change directory ", av[1]);
		}
		else if (i != 0 && av[i] == NULL && strcmp(av[i], ";") == 0)
		{
			if (fork() == 0)
			{
				if (ft_execute(av, i, tmp_fd, env))
					return (1);
			}
			else
			{
				close(tmp_fd); // ft_execute에서 tmp_fd를 쓰니까 닫아줘야함....?
				while (waitpid(-1, NULL, 0) != -1)
					;
				tmp_fd = dup(STDIN_FILENO); // 다시 사용할 수 있도록 세팅해준다.
			}
		}
		else if (i != 0 && strcmp(av[i], "|"))
		{
			pipe(fd);
			if (fork() == 0)
			{

			}
			else
			{

			}
		}

	}
	close(tmp_fd);
	return (0);
}
