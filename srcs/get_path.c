/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescamp <vdescamp@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 12:25:02 by vdescamp          #+#    #+#             */
/*   Updated: 2022/06/16 14:02:39 by vdescamp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_cmd_path(char **paths, char	*cmd)
{
	char	*cmd_path;
	int		i;

	i = 0;
	while (paths[i])
	{
		cmd_path = ft_strjoin(paths[i], cmd);
		if (!access(cmd_path, 0))
			return (cmd_path);
		free(cmd_path);
		i++;
	}
	return ("**error can't find path...**\n");
}

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
			break ;
		}
		i++;
	}
	paths = ft_split(env_path, ':');
	free (env_path);
	i = -1;
	while (paths[++i])
		paths[i] = ft_strjoin(paths[i], "/");
	return (get_cmd_path(paths, cmd));
}
