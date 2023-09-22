#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

static void	perr(char *str, char *arg)
{
	while (*str)
		write(2, str++, 1);
	if (arg)
		while (*arg)
			write(2, arg++, 1);
	write(2, "\n", 1);
}

static void	duplicate_pipe(int tmp_fd, int *fd, int last_cmd)
{
	if (tmp_fd != -1)
	{
		dup2(tmp_fd, STDIN_FILENO);
		if (last_cmd != 1)
			dup2(fd[1], STDOUT_FILENO);
	}
	else if (fd[0] != -1)
	{
		dup2(fd[0], STDIN_FILENO);
		if (last_cmd != 1)
			dup2(fd[1], STDOUT_FILENO);
	}
	if (fd[0] != -1)
	{
		close(fd[0]);
		close(fd[1]);
	}
	if (tmp_fd != -1)
		close(tmp_fd);
}

static int	exec(char **cmd, char **envp, int tmp_fd, int fd, int last_cmd)
{
	int	fd[2];

	pipe(fd);
	if (fork() == 0)
	{
		duplicate_pipe(tmp_fd, fd, last_cmd);
		if (execve(cmd[0], cmd, envp) == 1)
			perr("error: cannot execute ", cmd[0]);
	}
	else
	{

	}
}

int	main(int argc, char **argv, char **envp)
{
	int		i;
	int		j;
	int		last_cmd;
	int		piped;
	int		fd[2];
	int		tmp_fd;
	char	*cmd[1024];

	i = 1;
	piped = 0;
	tmp_fd = -1;
	while (i < argc)
	{
		if (argv[i] != NULL && strcmp(argv[i], "cd") == 0)
		{
			if (argv[i + 1] == NULL)
				return (perr("error: cd: bad arguments", NULL), 1);
			else if (chdir(argv[i + 1]) == -1)
				return (perr("error: cd: cannot change directory to ", argv[i + 1]), 1);
			i += 2;
		}
		else if (argv[i] != NULL && strcmp(argv[i], "|") == 0)
		{
			pipe(fd);
			piped = 1;
			i++;
		}
		/* else if (argv[i] != NULL && strcmp(argv[i], ";") == 0)
		{

		} */
		else
		{
			j = i;
			while (argv[i] != NULL && strcmp(argv[i], "|") != 0)
				cmd[j++] = argv[i++];
			cmd[j] = NULL;
			last_cmd = 0;
			if (argv[i] && strcmp(argv[i], "|") == 0 && strcmp(argv[i], ";") != 0)
			{
				if (piped == 0)
					pipe(fd);
			}
			else
				last_cmd = 1;
			exec(cmd, envp, &tmp_fd, fd, last_cmd);
			piped = 0;
		}
		i++;
	}
}