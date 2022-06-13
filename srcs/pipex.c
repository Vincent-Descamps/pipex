/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescamp <vdescamp@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 11:20:48 by vdescamp          #+#    #+#             */
/*   Updated: 2022/06/13 12:48:36 by vdescamp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
void	process_1()
{
	//process du child1
}

void	process_2()
{
	//process du child2
}

int	pipex(char **argv, char **envp)
{
	pid_t	pid1;
	pid_t	pid2;
	int		ends[2];
	int		fd[2];
	/*char	*cmd1 = "ls";
	char	*cmd2 = "wc";
	char	*options1[3] = {"ls", "-la", NULL};
	char	*options2[3] = {"wc", 0, NULL};*/
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
