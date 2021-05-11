/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeojung <hyeojung@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 15:03:59 by hyeojung          #+#    #+#             */
/*   Updated: 2021/05/11 15:28:18 by hyeojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int main(void)
{
	char arr1[2] = {0,};
//	char arr2[2] = {0,};
	printf("ft: \t%zu %s\n", ft_strlcpy(arr1, "abcd", 4), arr1);
//	printf("real: \t%zu %s\n", strlcpy(arr2, "abcd", 4), arr2);
	return 0;
}
