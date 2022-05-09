/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeojung <hyeojung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 21:17:10 by hyeojung          #+#    #+#             */
/*   Updated: 2022/05/09 17:22:46 by hyeojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
		pthread_mutex_lock(&philo->info->forks[philo->left]);
	else
		pthread_mutex_lock(&philo->info->forks[philo->right]);
	print_state(philo,
		get_time() - philo->info->time_to_start, "has taken a fork");
	if (philo->id % 2 == 0)
		pthread_mutex_lock(&philo->info->forks[philo->right]);
	else
		pthread_mutex_lock(&philo->info->forks[philo->left]);
	print_state(philo,
		get_time() - philo->info->time_to_start, "has taken a fork");
}

void	eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->moniter);
	philo->last_eat = get_time();
	print_state(philo,
		philo->last_eat - philo->info->time_to_start, "is eating");
	pthread_mutex_unlock(&philo->info->moniter);
	while (get_time() < philo->last_eat + philo->info->time_to_eat)
		;
	philo->num_of_eat++;
	pthread_mutex_unlock(&philo->info->forks[philo->left]);
	pthread_mutex_unlock(&philo->info->forks[philo->right]);
}

void	sleeping_and_thinking(t_philo *philo)
{
	philo->last_sleep = get_time();
	print_state(philo,
		philo->last_sleep - philo->info->time_to_start, "is sleeping");
	while (get_time() < philo->last_sleep + philo->info->time_to_sleep)
		;
	print_state(philo,
		get_time() - philo->info->time_to_start, "is thinking");
	usleep(200);
}
