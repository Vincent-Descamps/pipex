/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescamp <vdescamp@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 12:21:54 by vdescamp          #+#    #+#             */
/*   Updated: 2022/06/20 10:06:56 by vdescamp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	ft_error(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
		write(2, &s[i], 1);
	exit (1);
}

int	main(int argc, char **argv, char **envp)
{
	if (argc != 5)
		ft_error("** Invalid number of arguments. **");
	pipex(argv, envp);
	return (0);
}
