/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeojung <hyeojung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 21:32:26 by hyeojung          #+#    #+#             */
/*   Updated: 2022/04/17 00:28:57 by hyeojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h" 

void	open_file(char *infile, char *outfile, int *in_fd, int *out_fd)
{
	*in_fd = open(infile, O_RDONLY);
	*out_fd = open(outfile, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (*in_fd == -1)
		open_err(infile);
}

void	pipex(char **argv, char **envp, int pid)
{
	char	**parent_command;
	char	**child_command;
	int		status;

	if (pid == 0)
	{
		child_command = ft_split(argv[2], ' ');
		if (execve(check_filename(get_filenames(child_command[0], envp)),
			child_command, envp) == -1)
			print_err("err");
	}
	else
	{
		waitpid(pid, &status, 0);
		parent_command = ft_split(argv[3], ' ');
		execve(check_filename(get_filenames(parent_command[0], envp)),
			parent_command, envp);
	}
}

void	init_pipex(int pipe_fd[2], int file_fd[2], int pid)
{
	if (pid == 0)
	{
		close(pipe_fd[0]);
		dup2(pipe_fd[1], STDOUT_FILENO);
		close(pipe_fd[1]);
		dup2(file_fd[0], STDIN_FILENO);
	}
	else
	{
		close(pipe_fd[1]);
		dup2(pipe_fd[0], STDIN_FILENO);
		close(pipe_fd[0]);
		dup2(file_fd[1], STDOUT_FILENO);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int		pipe_fd[2];
	int		file_fd[2];
	int		pipe_ret;
	pid_t	pid;

	if (argc == 5)
	{
		pipe_ret = pipe(pipe_fd);
		if (pipe_ret == -1)
			print_err("pipex: pipe execution failure");
		open_file(argv[1], argv[4], &file_fd[0], &file_fd[1]);
		pid = fork();
		if (pid < 0)
			print_err("pipex: fork execution failure");
		init_pipex(pipe_fd, file_fd, pid);
		pipex(argv, envp, pid);
		exit(EXIT_SUCCESS);
	}
	print_err("pipex: require 4 arguments");
}
