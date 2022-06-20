/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescamp <vdescamp@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 11:20:48 by vdescamp          #+#    #+#             */
/*   Updated: 2022/06/17 13:37:28 by vdescamp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	process_1(char **argv, char **envp, int ends)
{
	int		fd;
	char	*path;
	char	*cmd;
	char	**options;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		ft_error("**Error in output file**");
	dup2(fd, STDIN_FILENO);
	close(fd);
	options = ft_split(argv[2], ' ');
	cmd = get_cmd(argv[2]);
	path = get_path(cmd, envp);
	dup2(ends, STDOUT_FILENO);
	execve(path, options, envp);
	ft_error("**Error in first process**");
}

void	process_2(char **argv, char **envp, int ends)
{
	int		fd;
	char	*path;
	char	*cmd;
	char	**options;

	fd = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd < 0)
		ft_error("**Error in output file**");
	dup2(fd, STDOUT_FILENO);
	close(fd);
	options = ft_split(argv[3], ' ');
	cmd = get_cmd(argv[3]);
	path = get_path(cmd, envp);
	dup2(ends, STDIN_FILENO);
	execve(path, options, envp);
	ft_error("**Error in second process**");
}

int	pipex(char **argv, char **envp)
{
	pid_t	pid1;
	pid_t	pid2;
	int		ends[2];

	if (pipe(ends) == -1)
		return (1);
	pid1 = fork();
	if (pid1 == -1)
		ft_error("**Error in first process**");
	if (pid1 == 0)
		process_1(argv, envp, ends[1]);
	close(ends[1]);
	pid2 = fork();
	if (pid2 == -1)
		ft_error("**Error in second process**");
	if (pid2 == 0)
	{
		process_2(argv, envp, ends[0]);
	}
	close(ends[0]);
	close(ends[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}
