/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeojung <hyeojung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 19:47:39 by hyeojung          #+#    #+#             */
/*   Updated: 2022/05/09 15:10:57 by hyeojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*moniter_philo(void *void_philo)
{
	t_philo		*philo;
	uint64_t	curr_time;

	philo = (t_philo *)void_philo;
	while (!philo->info->done)
	{
		pthread_mutex_lock(&philo->moniter);
		pthread_mutex_lock(&philo->info->stop);
		curr_time = get_time();
		if (curr_time - philo->last_eat >= philo->info->time_to_die
			&& philo->info->done == 0)
		{
			philo->info->done = 1;
			printf("%lld\t%d\tdied\n",
				curr_time - philo->info->time_to_start, philo->id);
		}
		pthread_mutex_unlock(&philo->info->stop);
		pthread_mutex_unlock(&philo->moniter);
	}
	return (0);
}

void	*moniter_philo_must_eat(void *void_info)
{
	t_info	*info;

	info = void_info;
	while (!info->done)
	{
		pthread_mutex_lock(&info->stop);
		if (info->num_of_must_eat != -1
			&& info->do_cnt >= info->max_cnt)
			info->done = 1;
		pthread_mutex_unlock(&info->stop);
	}
	return (0);
}

void	*do_philo(void *void_philo)
{
	t_philo	*philo;

	philo = (t_philo *)void_philo;
	if (philo->id % 2 == 0)
		usleep(philo->info->time_to_eat * 1000);
	while (!philo->info->done)
	{
		take_forks(philo);
		eating(philo);
		sleeping_and_thinking(philo);
	}
	return (0);
}

int	start_philo(t_info *info)
{
	pthread_t	thread;
	int			i;

	info->time_to_start = get_time();
	i = -1;
	while (++i < info->num_of_philo)
	{
		info->philos[i].last_eat = info->time_to_start;
		if (pthread_create(&info->philos[i].thread, NULL,
				do_philo, &info->philos[i]))
			return (print_err("ERROR: create thread failed"));
		if (pthread_create(&thread, NULL, moniter_philo, &info->philos[i]))
			return (print_err("ERROR: create thread failed"));
		pthread_detach(thread);
	}
	if (info->num_of_must_eat != -1)
	{
		pthread_create(&thread, NULL, moniter_philo_must_eat, info);
		pthread_detach(thread);
	}
	free_philo(info);
	return (0);
}
