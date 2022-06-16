/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescamp <vdescamp@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 12:22:41 by vdescamp          #+#    #+#             */
/*   Updated: 2022/06/16 14:07:17 by vdescamp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include "../libft/libft.h"
# include "../printf/ft_printf.h"

int		ft_printf(const char *format, ...);
int		pipex(char **argv, char **envp);
char	*get_cmd(char *cmd);
char	*get_path(char *cmd, char **envp);

#endif
