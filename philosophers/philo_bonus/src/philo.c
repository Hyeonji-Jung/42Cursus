/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeojung <hyeojung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 19:47:39 by hyeojung          #+#    #+#             */
/*   Updated: 2022/05/09 18:32:47 by hyeojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	free_philo(t_info *info)
{
	int	i;
	int	status;

	i = -1;
	while (++i < info->num_of_philo)
	{
		waitpid(-1, &status, 0);
		if (status != 0)
		{
			i = -1;
			while (++i < info->num_of_philo)
				kill(info->philos[i].process_id, SIGKILL);
			break ;
		}
	}
	sem_close(info->moniter);
	sem_close(info->print);
	sem_close(info->forks);
	sem_unlink("moniter_philo");
	sem_unlink("print_philo");
	sem_unlink("forks_philo");
}

void	*check_philo_dead(void *void_philo)
{
	t_philo	*philo;

	philo = (t_philo *)void_philo;
	while (1)
	{
		sem_wait(philo->info->moniter);
		if (get_time() - philo->last_eat > philo->info->time_to_die)
		{
			print_state(philo,
				get_time() - philo->info->time_to_start, "died");
			philo->info->dead = 1;
			sem_wait(philo->info->print);
			exit(1);
		}
		sem_post(philo->info->moniter);
		if (philo->info->dead)
			break ;
		if (philo->info->num_of_must_eat != -1
			&& philo->num_of_eat >= philo->info->num_of_must_eat)
			break ;
	}
	return (0);
}

void	do_philo(t_philo *philo)
{
	philo->last_eat = philo->info->time_to_start;
	philo->last_sleep = philo->info->time_to_start;
	philo->num_of_eat = 0;
	if (pthread_create(&philo->moniter_dead, NULL,
		check_philo_dead, (void *)philo))
	{
		print_err("ERROR: create thread failed");
		return ;
	}
	if (philo->id % 2 == 0)
		usleep(philo->info->time_to_eat * 1000);
	while (!philo->info->dead)
	{
		take_forks(philo);
		eating(philo);
		if (philo->info->num_of_must_eat != -1
			&& philo->num_of_eat >= philo->info->num_of_must_eat)
			break ;
		sleeping_and_thinking(philo);
	}
	pthread_join(philo->moniter_dead, NULL);
	if (philo->info->dead)
		exit(1);
	exit(0);
}

int	start_philo(t_info *info)
{
	int	i;

	info->time_to_start = get_time();
	i = -1;
	while (++i < info->num_of_philo)
	{
		info->philos[i].process_id = fork();
		if (info->philos[i].process_id < 0)
			return (1);
		if (info->philos[i].process_id == 0)
			do_philo(&info->philos[i]);
	}
	free_philo(info);
	return (0);
}
