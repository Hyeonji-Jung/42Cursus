/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeojung <hyeojung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 15:02:08 by hyeojung          #+#    #+#             */
/*   Updated: 2021/05/13 15:12:32 by hyeojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int main(void)
{
	char s[100];
	int i = 0;
	ft_strlcpy(s, "tripouille", 100);
	char	**arr = ft_split(s, '0');
	for (i = 0; arr[i]; i++)
	{
		printf("arr[%d]: %s\n", i, arr[i]);
		free(arr[i]);
	}
	printf("arr[%d]: %s\n", i, arr[i]);
	free(arr);
	return 0;
}
