/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeojung <hyeojung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 21:17:10 by hyeojung          #+#    #+#             */
/*   Updated: 2022/05/08 04:15:52 by hyeojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
		pthread_mutex_lock(philo->left);
	else
		pthread_mutex_lock(philo->right);
	print_state(philo, FORK);
	if (philo->id % 2 == 0)
		pthread_mutex_lock(philo->right);
	else
		pthread_mutex_lock(philo->left);
	print_state(philo, FORK);
}

void	eating(t_philo *philo)
{
	print_state(philo, EAT);
	philo->last_eat = philo->last_eat
		+ philo->info->time_to_eat + philo->info->time_to_sleep;
	philo->time = philo->last_eat + philo->info->time_to_die;
	while (get_time() < philo->last_eat)
		;
	philo->info->do_cnt++;
	pthread_mutex_unlock(philo->left);
	pthread_mutex_unlock(philo->right);
}

void	sleeping_and_thinking(t_philo *philo)
{
	u_int64_t	sleep_time;

	print_state(philo, SLEEP);
	sleep_time = philo->last_eat + philo->info->time_to_sleep;
	while (get_time() < sleep_time)
		;
	print_state(philo, THINK);
}
