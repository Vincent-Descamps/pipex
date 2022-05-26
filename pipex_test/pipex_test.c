/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescamp <vdescamp@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 07:54:02 by vdescamp          #+#    #+#             */
/*   Updated: 2022/05/26 08:29:46 by vdescamp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

//test of execve command to reproduce ls -la shell command.

int	main(int ac, char **av, char **envp)
{
	char	*options[3] = {"ls", "-la", NULL};

	(void)ac;
	(void)av;
	execve("/bin/ls", options, envp);
	return (0);
}
