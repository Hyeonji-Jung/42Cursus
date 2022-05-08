/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeojung <hyeojung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 21:24:44 by hyeojung          #+#    #+#             */
/*   Updated: 2022/05/08 04:49:27 by hyeojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_err(char *err)
{
	printf("%s\n", err);
	return (1);
}

void	print_state(t_philo *philo, int state)
{
	uint64_t	time;

	if (philo->info->done)
		return ;
	time = get_time() - philo->info->time_to_start;
	pthread_mutex_lock(philo->info->print);
	if (state == FORK)
		printf("%lld\t%d\thas taken a fork\n", time, philo->id);
	else if (state == EAT)
		printf("%lld\t%d\tis eating\n", time, philo->id);
	else if (state == SLEEP)
		printf("%lld\t%d\tis sleeping\n", time, philo->id);
	else if (state == THINK)
		printf("%lld\t%d\tis thinking\n", time, philo->id);
	pthread_mutex_unlock(philo->info->print);
}

void	print_finish(t_philo *philo, int state)
{
	uint64_t	time;

	time = get_time() - philo->info->time_to_start;
	if (state == DEAD)
		printf("%lld\t%d\tdied\n", time, philo->id);
}
