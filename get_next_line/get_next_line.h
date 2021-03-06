/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeojung <hyeojung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 12:59:12 by hyeojung          #+#    #+#             */
/*   Updated: 2021/06/26 17:20:15 by hyeojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

int		get_next_line(int fd, char **line);
int		gnl_err(int read_ret, char *st_buff, char *line);
int		is_newline(char *str);

size_t	ft_strlen(const char *str);

void	ft_strlcat(char *dest, char *src, size_t size);

char	*ft_nextline(char *str);
char	*ft_get_line(char *str);
char	*ft_strjoin(char *s1, char *s2);

#endif
