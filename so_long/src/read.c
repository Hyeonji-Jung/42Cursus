/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeojung <hyeojung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 18:37:02 by hyeojung          #+#    #+#             */
/*   Updated: 2021/10/04 18:55:41 by hyeojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_file(char *s)
{
	int	fd;

	fd = open(s, O_RDONLY);
	printf("file: %s, fd: %d\n", s, fd);
	if (fd < 0)
		print_err("Can`t read file");
}
