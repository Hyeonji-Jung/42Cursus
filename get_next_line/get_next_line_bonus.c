/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeojung <hyeojung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 12:59:36 by hyeojung          #+#    #+#             */
/*   Updated: 2021/06/01 18:52:52 by hyeojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_nextline(char *str)
{
	char	*ret;
	int		i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (0);
	}
	if (!(ret = (char*)malloc(ft_strlen(str) - i + 1)))
		return (0);
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

	if (!str)
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!(ret = (char*)malloc(i + 1)))
		return (0);
	*ret = 0;
	ft_strlcat(ret, str, i + 1);
	return (ret);
}

int		get_next_line(int fd, char **line)
{
	int			read_ret;
	static char	*static_buff[OPEN_MAX];
	char		*buff;

	read_ret = 1;
	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0 || !line)
		return (-1);
	if (!(buff = (char*)malloc(BUFFER_SIZE + 1)))
		return (-1);
	while (!is_newline(static_buff[fd]) && read_ret != 0)
	{
		if ((read_ret = read(fd, buff, BUFFER_SIZE)) == -1)
		{
			free(buff);
			return (-1);
		}
		buff[read_ret] = 0;
		static_buff[fd] = ft_strjoin(static_buff[fd], buff);
	}
	free(buff);
	*line = ft_get_line(static_buff[fd]);
	static_buff[fd] = ft_nextline(static_buff[fd]);
	if (!read_ret)
		return (0);
	return (1);
}
