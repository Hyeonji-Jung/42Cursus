/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeojung <hyeojung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 21:32:26 by hyeojung          #+#    #+#             */
/*   Updated: 2022/04/16 14:53:20 by hyeojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h" 

void	pipex(char **argv, char **envp, int pid)
{
	char	**parent_command;
	char	*parent_filename;
	char	**child_command;
	char	*child_filename;

	if (pid == 0)
	{
		child_command = ft_split(argv[2], ' ');
		child_filename = check_filename(get_filenames(child_command[0]));
		execve(child_filename, child_command, envp);
	}
	else
	{
		parent_command = ft_split(argv[3], ' ');
		parent_filename = check_filename(get_filenames(parent_command[0]));
		execve(parent_filename, parent_command, envp);
	}
}

void	init_pipex(int pipe_fd[2], int file_fd[2], int pid)
{
	if (pid == 0)
	{
		close(pipe_fd[1]);
		dup2(pipe_fd[0], STDIN_FILENO);
		close(pipe_fd[0]);
		dup2(file_fd[1], STDOUT_FILENO);
	}
	else
	{
		close(pipe_fd[0]);
		dup2(pipe_fd[1], STDOUT_FILENO);
		close(pipe_fd[1]);
		dup2(file_fd[0], STDIN_FILENO);
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
			print_err("ERROR: pipe execution failure");
		file_fd[0] = open(argv[1], O_RDONLY);
		file_fd[1] = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
		if (file_fd[0] == -1 || file_fd[1] == -1)
			print_err("ERROR: opening file failure");
		pid = fork();
		if (pid < 0)
			print_err("ERROR: fork execution failure");
		init_pipex(pipe_fd, file_fd, pid);
		pipex(argv, envp, pid);
	}
	else
		exit(EXIT_SUCCESS);
}
