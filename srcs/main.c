/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescamp <vdescamp@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 12:21:54 by vdescamp          #+#    #+#             */
/*   Updated: 2022/06/09 12:36:20 by vdescamp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
/*
int	main(int argc, char **argv, char **envp)
{
	char	*cmd_path;
	char	*options[3] = {"ps", "-e", NULL};
	char	*cmd = "ps";

	(void)argc;
	(void)argv;
	cmd_path = get_path(cmd, envp);
	if (!cmd_path)
	{
		perror(cmd_path);
		return (-1);
	}
	//system("leaks a.out");
	execve(cmd_path, options, envp);
	printf("Victory!");
	free(cmd_path);
	return (0);
}
*/
int	main(int argc, char **argv, char **envp)
{
	pid_t	pid1;
	pid_t	pid2;
	int		ends[2];
	char	*cmd1 = "ls";
	char	*cmd2 = "wc";
	char	*options1[3] = {"ls", "-la", NULL};
	char	*options2[3] = {"wc", 0, NULL};
	char	*path;

	if (pipe(ends) == -1)
		return (1);
	pid1 = fork();
	if (pid1 == -1)
		return (1);
	if (pid1 == 0)
	{
		//child 1
		dup2(ends[1], STDOUT_FILENO);
		close(ends[0]);
		close(ends[1]);
		path = get_path(cmd1, envp);
		execve(path, options1, envp);
		free(path);
	}
	pid2 = fork();
	if (pid2 == -1)
		return (1);
	if (pid2 == 0)
	{
		//child 2
		dup2(ends[0], STDIN_FILENO);
		close(ends[0]);
		close(ends[1]);
		path = get_path(cmd2, envp);
		execve(path, options2, envp);
		free(path);
	}
	close(ends[0]);
	close(ends[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}
