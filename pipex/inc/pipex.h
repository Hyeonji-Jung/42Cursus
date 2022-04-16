/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeojung <hyeojung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 21:26:57 by hyeojung          #+#    #+#             */
/*   Updated: 2022/04/16 23:24:32 by hyeojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <sys/wait.h>
# include <sys/errno.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>

int		ft_strlen(char *str);
int		ft_strncmp(char *s1, char *s2, size_t size);
void	ft_strlcat(char *dest, char *src, size_t size);
void	print_err(char *err);
void	open_err(char *err);
char	*check_filename(char **filenames);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strnstr(char *str, char *find, size_t size);
char	**ft_split(char const *s, char c);
char	**get_filenames(char *command, char **envp);

#endif