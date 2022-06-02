/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retest.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescamp <vdescamp@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 11:01:26 by vdescamp          #+#    #+#             */
/*   Updated: 2022/06/02 11:15:10 by vdescamp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int		i;
	int		len;
	char	*env_path;
	char	**paths;
	char	*tmp;

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
	for(int i = 0; i<6; i++)
		ft_printf("=> %s\n", paths[i]);
	i = 0;
	while (paths[i])
	{

	}
	return (0);
}
