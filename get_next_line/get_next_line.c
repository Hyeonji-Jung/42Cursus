/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeojung <hyeojung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 12:59:36 by hyeojung          #+#    #+#             */
/*   Updated: 2021/05/21 15:29:44 by hyeojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"



int	get_next_line(int fd, char **line)
{
	int			read_fd;
	static char	*static_buff[OPEN_MAX];
	char		*buff;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0 || !line)
		return (-1);
	if (!(buff = (char*)malloc(BUFFER_SIZE + 1)))
		return (-1);
	if ((read_fd = read(fd, buff, BUFFER_SIZE)) == -1)
	{
		free(buff);
		return (-1);
	}
}
