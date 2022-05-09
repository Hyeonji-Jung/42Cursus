/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeojung <hyeojung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 18:37:50 by hyeojung          #+#    #+#             */
/*   Updated: 2022/05/09 18:23:11 by hyeojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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

uint64_t	get_time(void)
{
	struct timeval	curr;

	gettimeofday(&curr, NULL);
	return ((curr.tv_sec * 1000) + (curr.tv_usec / 1000));
}

int	print_err(char *err)
{
	printf("%s\n", err);
	return (1);
}

void	print_state(t_philo *philo, uint64_t time, char *state)
{
	sem_wait(philo->info->print);
	if (!philo->info->dead)
		printf("%lld\t%d\t%s\n", time, philo->id, state);
	sem_post(philo->info->print);
}
