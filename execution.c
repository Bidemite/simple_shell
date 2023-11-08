#include "shell.h"

/**
 * execution - An executes commands entered by the users,
 *@cp: The command,
 *@cmd: It is vector array of pointers to commands,
 * Return: 0 will be returned.
 */
void execution(char *cp, char **cmd)
{
	pid_t child_pid;
	int status;
	char **env = environ;

	child_pid = fork();
	if (child_pid < 0)
		perror(cp);
	if (child_pid == 0)
	{
		execve(cp, cmd, env);
		perror(cp);
		free(cp);
		free_buffers(cmd);
		exit(98);
	}
	else
		wait(&status);
}
