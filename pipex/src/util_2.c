/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeojung <hyeojung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 21:04:04 by hyeojung          #+#    #+#             */
/*   Updated: 2022/04/16 17:16:40 by hyeojung         ###   ########.fr       */
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
		if (access(*filenames, F_OK | X_OK) == 0)
			return (*filenames);
		filenames++;
	}
	perror("ERROR: access file failure");
	exit(EXIT_FAILURE);
}

void	print_err(char *err)
{
	perror(err);
	exit(EXIT_FAILURE);
}
