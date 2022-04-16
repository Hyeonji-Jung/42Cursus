/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeojung <hyeojung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 21:04:04 by hyeojung          #+#    #+#             */
/*   Updated: 2022/04/16 14:56:41 by hyeojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_filenames(char *command)
{
	char	**ret;

	ret = (char **)malloc(sizeof(char *) * 6);
	ret[0] = ft_strjoin("/usr/local/bin/", command);
	ret[1] = ft_strjoin("/usr/bin/", command);
	ret[2] = ft_strjoin("/bin/", command);
	ret[3] = ft_strjoin("/usr/sbin/", command);
	ret[4] = ft_strjoin("/sbin/", command);
	ret[5] = 0;
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
