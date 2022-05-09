/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeojung <hyeojung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 19:47:39 by hyeojung          #+#    #+#             */
/*   Updated: 2022/05/09 17:22:35 by hyeojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_philo(t_info *info)
{
	int	i;

	i = -1;
	if (info->num_of_philo == 1)
		pthread_detach(info->philos[0].thread);
	while (++i < info->num_of_philo)
		pthread_join(info->philos[i].thread, NULL);
	free(info->philos);
	i = -1;
	while (++i < info->num_of_philo)
		pthread_mutex_destroy(&info->forks[i]);
	free(info->forks);
	pthread_mutex_destroy(&info->moniter);
	pthread_mutex_destroy(&info->print);
}

void	check_philo_done(t_info *info)
{
	int	i;

	while (!info->done)
	{
		i = -1;
		while (++i < info->num_of_philo && !info->dead)
		{
			pthread_mutex_lock(&info->moniter);
			if (get_time() - info->philos[i].last_eat > info->time_to_die)
			{
				print_state(&info->philos[i],
					get_time() - info->time_to_start, "died");
				info->dead = 1;
			}
			pthread_mutex_unlock(&info->moniter);
		}
		if (info->dead)
			break ;
		i = 0;
		while (info->num_of_must_eat != -1 && i < info->num_of_philo
			&& info->philos[i].num_of_eat >= info->num_of_must_eat)
			i++;
		if (info->num_of_philo == i)
			info->done = 1;
	}
}

void	*do_philo(void *void_philo)
{
	t_philo	*philo;

	philo = (t_philo *)void_philo;
	if (philo->id % 2 == 0)
		usleep(philo->info->time_to_eat * 1000);
	while (!philo->info->dead)
	{
		take_forks(philo);
		eating(philo);
		if (philo->info->done)
			break ;
		sleeping_and_thinking(philo);
	}
	return (0);
}

int	start_philo(t_info *info)
{
	int	i;

	info->time_to_start = get_time();
	i = -1;
	while (++i < info->num_of_philo)
	{
		info->philos[i].last_eat = info->time_to_start;
		info->philos[i].last_sleep = info->time_to_start;
		info->philos[i].num_of_eat = 0;
		if (pthread_create(&info->philos[i].thread, NULL,
				do_philo, &info->philos[i]))
			return (print_err("ERROR: create thread failed"));
	}
	check_philo_done(info);
	free_philo(info);
	return (0);
}
