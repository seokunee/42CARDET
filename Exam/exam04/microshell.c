#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int ft_putstr_fd2(char *str, char *arg)
{
	while (*str)
		write(2, str++, 1);
	if (arg)
		while (*arg)
			write(2, arg++, 1);
	write(2, "\n", 1);
	return (1);
}

int ft_execute(char **av, int i, int tmp_fd, char **env)
{
	av[i] = NULL;
	dup2(tmp_fd, STDIN_FILENO); // 원래 상태로 돌려줌.
	close(tmp_fd);
	execve(av[0], av, env);
	return (ft_putstr_fd2("error: cannot execute ", av[0]));
}

int main(int ac, char **av, char **envp)
{
	int i;
	int fd[2];
	int tmp_fd;
	(void)ac;

	i = 0;
	tmp_fd = dup(STDIN_FILENO); // tmp_fd에 std in fd을 저장. 왜냐하면 나중에 바꾸면서 잃어버릴 수 있다.
	while (av[i] && av[i + 1]) // 이유는?
	{
		av = &av[i + 1]; // 초반의 av[0] == ./microshell 이기 때문에
		i = 0;
		while (av[i] && strcmp(av[i], ";") && strcmp(av[i], "|")) // ; or | 이 나올때까지 i를 돌린다.
			i++;
		if (strcmp(av[0], "cd") == 0)
		{
			if (i != 2)
				ft_putstr_fd2("error: cd: bad arguments", NULL);
			else if (chdir(av[1]) != 0)
				ft_putstr_fd2("error: cd: cannot change directory to ", av[1]);
		}
		else if (i != 0 && (av[i] == NULL || strcmp(av[i], ";") == 0)) // NULL 또는 ;를 만났다면
		{
			if (fork() == 0)
			{
				if (ft_execute(av, i, tmp_fd, envp))
					return (1);
			}
			else
			{
				close(tmp_fd);
				while (waitpid(-1, NULL, WUNTRACED) == 0)
					;
				tmp_fd = dup(STDIN_FILENO);
			}
		}
		else if (i != 0 && strcmp(av[i], "|") == 0) // pipe라면
		{
			// echo 123 w|r cat
			pipe(fd);
			if (fork() == 0)
			{
				dup2(fd[1], STDOUT_FILENO);
				close(fd[0]);
				close(fd[1]);
				if (ft_execute(av, i, tmp_fd, envp))
					return (1);
			}
			else
			{
				close(fd[1]); // 부모는 write부분을 안쓰니까 닫아줘야한다. 그럼 read는???
				close(tmp_fd); // tmp_fd는 stdin이 들어가 있는데
				tmp_fd = fd[0]; // | 다음에 나오는 명령어를 위해서 pipe의 read부분을 tmp_fd에 담아주는 것이다.
			}
		}
	}
	close(tmp_fd); //
	return (0);
}
