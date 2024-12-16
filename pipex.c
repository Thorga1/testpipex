/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tordner <tordner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 13:25:52 by tordner           #+#    #+#             */
/*   Updated: 2024/12/04 15:03:12 by tordner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	setup_pipe(int pipefd[2])
{
	if (pipe(pipefd) == -1)
	{
		write(1, "Error creating pipe\n", 21);
		return (1);
	}
	return (0);
}

void	execute_command(char *cmd, char **envp)
{
	char	**args;
	char	*full_path;
	char	*path_env;

	args = ft_split(cmd, ' ');
	if (!args || !args[0])
	{
		write(1, "Error: Command parsing failed\n", 30);
		exit(1);
	}
	path_env = get_path_env(envp);
	if (!path_env)
	{
		write(1, "Error: PATH not found\n", 22);
		exit(1);
	}
	full_path = find_command(ft_split(path_env, ':'), args[0]);
	if (!full_path)
	{
		write(1, "Error: Command not found\n", 25);
		exit(1);
	}
	execve(full_path, args, envp);
	write(1, "Error: Command execution failed\n", 32);
	exit(1);
}

void	run_child_process(int pipefd[2], int infile, char *cmd, char **envp)
{
	close(pipefd[0]);
	dup2(infile, 0);
	dup2(pipefd[1], 1);
	close(infile);
	close(pipefd[1]);
	execute_command(cmd, envp);
}

void	run_parent_process(int pipefd[2], int outfile, char *cmd, char **envp)
{
	close(pipefd[1]);
	dup2(pipefd[0], 0);
	dup2(outfile, 1);
	close(pipefd[0]);
	close(outfile);
	execute_command(cmd, envp);
}

int	main(int ac, char **av, char **envp)
{
	int		pipefd[2];
	int		infile;
	int		outfile;
	pid_t	pid;

	if (errors(ac, av) || setup_files(av, &infile, &outfile) \
	|| setup_pipe(pipefd))
		return (1);
	pid = fork();
	if (pid == -1)
	{
		write(1, "Error forking process\n", 23);
		close_files(infile, outfile);
		return (1);
	}
	if (pid == 0)
		run_child_process(pipefd, infile, av[2], envp);
	else
		run_parent_process(pipefd, outfile, av[3], envp);
	return (0);
}
