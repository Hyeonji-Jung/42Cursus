/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeojung <hyeojung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 19:47:39 by hyeojung          #+#    #+#             */
/*   Updated: 2022/05/08 04:49:49 by hyeojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*moniter_philo(void *void_philo)
{
	t_philo	*philo;

	philo = (t_philo *)void_philo;
	while (1)
	{
		pthread_mutex_lock(philo->info->moniter);
		if (get_time() - philo->last_eat >= philo->info->time_to_die)
		{
			philo->info->done = 1;
			print_finish(philo, DEAD);
			pthread_mutex_unlock(philo->info->stop);
			break ;
		}
		if (philo->info->done)
		{
			pthread_mutex_unlock(philo->info->stop);
			break ;
		}
		pthread_mutex_unlock(philo->info->moniter);
	}
	return (0);
}

int	check_philo(t_philo *philo)
{
	if (philo->info->num_of_must_eat != -1
		&& philo->info->do_cnt >= philo->info->max_cnt)
	{
		// pthread_mutex_lock(philo->info->moniter);
		philo->info->done = 1;
		pthread_mutex_unlock(philo->info->stop);
		// pthread_mutex_unlock(philo->info->moniter);
		return (1);
	}
	return (0);
}

void	*do_philo(void *void_philo)
{
	t_philo	*philo;

	philo = (t_philo *)void_philo;
	philo->time = philo->info->time_to_start + philo->info->time_to_die;
	philo->last_eat = philo->info->time_to_start;
	if (pthread_create(&philo->moniter, NULL, moniter_philo, (void *)philo))
	{
		print_err("ERROR: create thread failed");
		return (0);
	}
	while (1)
	{
		if (philo->info->done)
			break ;
		take_forks(philo);
		eating(philo);
		if (check_philo(philo))
			break ;
		sleeping_and_thinking(philo);
	}
	return (0);
}

int	start_philo(t_info *info)
{
	int	i;

	info->time_to_start = get_time();
	pthread_mutex_lock(info->stop);
	i = -1;
	while (++i < info->num_of_philo)
	{
		if (pthread_create(&info->philos[i].thread, NULL,
				do_philo, (void *)&info->philos[i]))
			return (print_err("ERROR: create thread failed"));
		usleep(300);
		if (info->num_of_philo == 1)
			pthread_detach(info->philos[0].thread);
	}
	i = -1;
	while (++i < info->num_of_philo)
	{
		pthread_join(info->philos[i].thread, NULL);
		pthread_join(info->philos[i].moniter, NULL);
	}
	free_philo(info);
	return (0);
}
