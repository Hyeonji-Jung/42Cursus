/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeojung <hyeojung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 21:04:04 by hyeojung          #+#    #+#             */
/*   Updated: 2022/04/16 23:25:28 by hyeojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_paths(char **envp)
{
	char	*ret;

	ret = 0;
	while (!ret && *envp)
	{
		ret = ft_strnstr(*envp, "PATH=", 5);
		if (ret)
			break ;
		envp++;
	}
	return (ft_split(ret + 5, ':'));
}

char	**get_filenames(char *command, char **envp)
{
	char	**ret;
	int		i;

	ret = get_paths(envp);
	i = 0;
	while (ret[i])
	{
		ret[i] = ft_strjoin(ret[i], "/");
		ret[i] = ft_strjoin(ret[i], command);
		i++;
	}
	return (ret);
}

char	*check_filename(char **filenames)
{
	while (*filenames)
	{
		if (access(*filenames, F_OK) == 0)
		{
			if (access(*filenames, X_OK) == 0)
				return (*filenames);
			perror("pipex: command not found");
			exit(126);
		}
		filenames++;
	}
	perror("pipex: command not found");
	exit(127);
}

void	print_err(char *err)
{
	perror(err);
	exit(EXIT_FAILURE);
}

void	open_err(char *filename)
{
	char	*err;
	int		len;

	len = ft_strlen(filename) + 8;
	err = (char *)malloc(len);
	*err = 0;
	ft_strlcat(err, "pipex: ", len);
	ft_strlcat(err, filename, len);
	print_err(err);
}
