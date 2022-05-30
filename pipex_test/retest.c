#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include "../libft/libft.h"

int	main(int argc, char **argv, char **envp)
{
	int		i;
	int		len;
	char	*env_path;

	i = 0;
	while (envp[i])
	{
		env_path = ft_strnstr(envp[i], "PATH", 10);
		if (env_path)
		{
			len = ft_strlen(env_path);
			printf("%d\n", len);
			printf("env_path======>%s\n", env_path);
			break;
		}
		else
		{
			printf("nope...");
		}
		i++;
	}
	return (0);
}
