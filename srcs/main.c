/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescamp <vdescamp@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 12:21:54 by vdescamp          #+#    #+#             */
/*   Updated: 2022/06/07 15:05:51 by vdescamp         ###   ########.fr       */
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

	if (pipe(ends) == -1)
		return (1);
	pid1 = fork();
	if (pid1 == -1)
		return (1);
	else if (pid1 == 0)
	{
		//child 1
		printf("child 1 here pid : %d\n", pid1);
		return (0);
	}
	else if (pid1 > 0)
	{
		pid2 = fork();
		if (pid2 == -1)
			return (1);
		else if (pid2 == 0)
		{
			//child 2
			printf("Child 2 herepid : %d\n", pid2);
			return (2);
		}
		else if (pid2 > 0)
		{
			//parent
			printf("I'm the Mama!!\n");
		}
	}
	return (0);
}
