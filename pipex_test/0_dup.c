/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_dup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescamp <vdescamp@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 11:09:21 by vdescamp          #+#    #+#             */
/*   Updated: 2022/05/26 11:37:02 by vdescamp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	int		fd_cpy;
	int		reader;
	char	buffer[15];

	// Imprimer le PID de notre processus
	// pour pouvoir regarder les fd ouverts
	// par ce processus.
	printf("Mon PID est : %d\n", getpid());
	//On recupere un fd en ouvrant un fichier
	fd = open("test.txt", O_RDONLY);
	if(!fd)
		return (1);
	// On duplique ce fd sur le fd inutilisé
	// le plus petit
	fd_cpy = dup(fd);
	if(!fd_cpy)
		return (1);
	// lecture de fd
	reader = read(fd, buffer, 10);
	if (reader == -1)
		return (1);
	buffer[reader] = '\0';
	printf("fd %d contient : %s\n", fd, buffer);
	//lecture du fd_cpy
	reader = read(fd_cpy, buffer, 10);
	if (reader == -1)
		return (1);
	buffer[reader] = '\0';
	printf("fd_cpy %d contient : %s\n", fd_cpy, buffer);
	// Boucle infinie pour pouvoir aller
	// voir les fd ouverts par ce processus
	// avec ls -la /proc/PID/fd
	while (1)
		;
	return (0);
}
