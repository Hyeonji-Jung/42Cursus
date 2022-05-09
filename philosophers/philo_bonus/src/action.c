/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeojung <hyeojung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 21:17:10 by hyeojung          #+#    #+#             */
/*   Updated: 2022/05/09 18:22:24 by hyeojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	take_forks(t_philo *philo)
{
	sem_wait(philo->info->forks);
	print_state(philo,
		get_time() - philo->info->time_to_start, "has taken a fork");
	sem_wait(philo->info->forks);
	print_state(philo,
		get_time() - philo->info->time_to_start, "has taken a fork");
}

void	eating(t_philo *philo)
{
	sem_wait(philo->info->moniter);
	philo->last_eat = get_time();
	print_state(philo,
		philo->last_eat - philo->info->time_to_start, "is eating");
	sem_post(philo->info->moniter);
	while (get_time() < philo->last_eat + philo->info->time_to_eat)
		;
	philo->num_of_eat++;
	sem_post(philo->info->forks);
	sem_post(philo->info->forks);
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
