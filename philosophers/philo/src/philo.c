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
		if (get_time() > philo->time)
		{
			philo->done = 1;
			print_state(philo, DEAD);
			pthread_mutex_unlock(philo->info->stop);
			break ;
		}
		else if (philo->info->num_of_must_eat != -1
			&& philo->info->do_cnt >= philo->info->max_cnt)
		{
			philo->done = 1;
			print_state(philo, DONE);
			pthread_mutex_unlock(philo->info->stop);
		}
		pthread_mutex_unlock(philo->info->moniter);
	}
	return (0);
}

void	*do_philo(void *void_philo)
{
	t_philo	*philo;

	philo = (t_philo *)void_philo;
	philo->time = philo->info->time_to_start + philo->info->time_to_die;
	if (pthread_create(&philo->moniter, NULL, moniter_philo, (void *)philo))
	{
		print_err("ERROR: create thread failed");
		return (0);
	}
	pthread_detach(philo->moniter);
	while (1)
	{
		if (philo->done)
			break ;
		take_forks(philo);
		eating(philo);
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
		pthread_detach(info->philos[i].thread);
	}
	pthread_mutex_lock(info->stop);
	free_philo(info);
	return (0);
}
