/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeojung <hyeojung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 16:43:39 by hyeojung          #+#    #+#             */
/*   Updated: 2021/10/04 18:46:49 by hyeojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_file(char *s)
{
	int	flag;

	flag = 0;
	while (*s)
		if (*s++ == '.')
			if (*s++ == 'b')
				if (*s++ == 'e')
					if (*s++ == 'r')
						if (*s++ == 0)
							flag = 1;
	if (!flag)
		print_err("Invalid Filename");
	else
		read_file();
}

void	check_map(char *s)
{
	(void)s;
}

void	print_err(char *s)
{
	ft_putstr(s);
	exit(-1);
}
