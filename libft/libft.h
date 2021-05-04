/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeojung <hyeojung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 12:31:24 by hyeojung          #+#    #+#             */
/*   Updated: 2021/05/04 17:25:41 by hyeojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <limits.h>

void	*ft_bzero(void *dest, size_t size);
void	*ft_memset(void *dest, int c, size_t size);
void	*ft_memcpy(void *dest, const void *src, size_t size);
void	*ft_memccpy(void *dest, const void *src, int c, sizr_t size);
void	*ft_memchr(const void *s, int c, size_t size);
void	*ft_memmove(void *dest, const void *src, size_t size);

int		ft_isascii(int c);
int		ft_isalpha(int c);
int		ft_isalnum(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_memcmp(const void *dest, const void *src, size_t size);

size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);

#endif
