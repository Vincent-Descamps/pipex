/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retest.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescamp <vdescamp@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 11:01:26 by vdescamp          #+#    #+#             */
/*   Updated: 2022/06/06 11:41:36 by vdescamp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_path(char *cmd, char **envp)
{
	int		i;
	int		len;
	char	*env_path;
	char	**paths;
	char	*cmd_path;

	i = 0;
	while (envp[i])
	{
		env_path = ft_strnstr(envp[i], "PATH", 4);
		if (env_path)
		{
			len = ft_strlen(env_path);
			env_path = ft_substr(env_path, 5, len - 4);
			ft_printf("===>%s\n", env_path);
			break ;
		}
		i++;
	}
	paths = ft_split(env_path, ':');
	free (env_path);
	i = 0;
	while (paths[i])
	{
		paths[i] = ft_strjoin(paths[i], "/");
		i++;
	}
	/*for(int i = 0; i<6; i++)
		ft_printf("=> %s\n", paths[i]);*/
	i = 0;
	while (paths[i])
	{
		cmd_path = ft_strjoin(paths[i], cmd);
		if (access(cmd_path, F_OK && X_OK) == 0)
			return (cmd_path);
		free(cmd_path);
		i++;
	}
	return ("**error can't find path...**\n");
}

int	main(int argc, char **argv, char **envp)
{
	char	*cmd_path;
	char	*options[3] = {"ls", "-la", NULL};
	char	*cmd = "ls";

	(void)argc;
	(void)argv;
	cmd_path = get_path(cmd, envp);
	if (!cmd_path)
	{
		perror(cmd_path);
		return (-1);
	}
	execve(cmd_path, options, envp);
	printf("Victory!");
	free(cmd_path);
	return (0);
}
