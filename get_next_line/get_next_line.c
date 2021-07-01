/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeojung <hyeojung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 12:59:36 by hyeojung          #+#    #+#             */
/*   Updated: 2021/07/01 14:46:57 by hyeojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_nextline(char *str)
{
	char	*ret;
	int		i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i] || !(ret = (char*)malloc(ft_strlen(str) - i + 1)))
	{
		free(str);
		return (0);
	}
	*ret = 0;
	i++;
	ft_strlcat(ret, str + i, ft_strlen(str) - i + 1);
	free(str);
	return (ret);
}

char	*ft_get_line(char *str)
{
	char	*ret;
	int		i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!(ret = (char*)malloc(i + 1)))
		return (0);
	*ret = 0;
	ft_strlcat(ret, str, i + 1);
	return (ret);
}

int		gnl_err(int read_ret, char *st_buff, char *line)
{
	if (read_ret != 0 && (!st_buff || !line))
		return (-1);
	else if (read_ret == 0)
		return (0);
	else
		return (1);
}

int		get_next_line(int fd, char **line)
{
	int			read_ret;
	char		*buff;
	static char	*st_buff[OPEN_MAX];

	read_ret = 1;
	if (fd < 0 || fd >= OPEN_MAX || BUFFER_SIZE <= 0 || !line)
		return (-1);
	if (!(buff = (char*)malloc(BUFFER_SIZE + 1)))
		return (-1);
	while (!is_newline(st_buff[fd]) && read_ret != 0)
	{
		if ((read_ret = read(fd, buff, BUFFER_SIZE)) == -1)
		{
			free(buff);
			return (-1);
		}
		buff[read_ret] = 0;
		st_buff[fd] = ft_strjoin(st_buff[fd], buff);
	}
	free(buff);
	*line = ft_get_line(st_buff[fd]);
	st_buff[fd] = ft_nextline(st_buff[fd]);
	return (gnl_err(read_ret, st_buff[fd], *line));
}
