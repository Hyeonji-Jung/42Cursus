/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeojung <hyeojung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 21:17:10 by hyeojung          #+#    #+#             */
/*   Updated: 2022/05/09 14:49:40 by hyeojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
		pthread_mutex_lock(philo->left);
	else
		pthread_mutex_lock(philo->right);
	printf("%lld\t%d\thas taken a fork\n",
		get_time() - philo->info->time_to_start, philo->id);
	if (philo->id % 2 == 0)
		pthread_mutex_lock(philo->right);
	else
		pthread_mutex_lock(philo->left);
	printf("%lld\t%d\thas taken a fork\n",
		get_time() - philo->info->time_to_start, philo->id);
}

void	eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->moniter);
	philo->last_eat = get_time();
	philo->dead_time = philo->last_eat + philo->info->time_to_die;
	pthread_mutex_lock(&philo->info->stop);
	if (!philo->info->done)
		printf("%lld\t%d\t %s\n",
			philo->last_eat - philo->info->time_to_start, philo->id, "is eating");
	philo->info->do_cnt++;
	pthread_mutex_unlock(&philo->info->stop);
	usleep(philo->info->time_to_eat * 1000);
	pthread_mutex_unlock(philo->left);
	pthread_mutex_unlock(philo->right);
	pthread_mutex_unlock(&philo->moniter);
}

void	sleeping_and_thinking(t_philo *philo)
{
	if (philo->info->done)
		return ;
	printf("%lld\t%d\tis sleeping\n",
		get_time() - philo->info->time_to_start, philo->id);
	usleep(philo->info->time_to_sleep * 1000);
	printf("%lld\t%d\tis thinking\n",
		get_time() - philo->info->time_to_start, philo->id);
	usleep(100);
}
