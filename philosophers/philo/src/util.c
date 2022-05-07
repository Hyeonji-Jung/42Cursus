/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeojung <hyeojung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 18:37:50 by hyeojung          #+#    #+#             */
/*   Updated: 2022/05/08 04:24:25 by hyeojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(char *str)
{
	long long	num;
	int			sign;

	num = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
		num = num * 10 + (*(str++) - '0');
	return (num * sign);
}

int	check_args(int ac, char *av[])
{
	int	i;
	int	j;

	i = 0;
	while (++i < ac)
	{
		j = -1;
		while (av[i][++j])
			if (av[i][j] < '0' || av[i][j] > '9')
				return (1);
	}
	return (0);
}

void	free_philo(t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->num_of_philo)
		pthread_mutex_destroy(&info->forks[i]);
	free(info->forks);
	pthread_mutex_destroy(info->moniter);
	free(info->moniter);
	pthread_mutex_destroy(info->print);
	free(info->print);
	pthread_mutex_destroy(info->stop);
	free(info->stop);
}

uint64_t	get_time(void)
{
	struct timeval	curr;

	gettimeofday(&curr, NULL);
	return ((curr.tv_sec * 1000) + (curr.tv_usec / 1000));
}
