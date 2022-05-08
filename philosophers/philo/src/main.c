/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeojung <hyeojung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 15:26:41 by hyeojung          #+#    #+#             */
/*   Updated: 2022/05/08 04:50:11 by hyeojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_philo_info(int ac, char *av[], t_info *info)
{
	info->num_of_philo = ft_atoi(av[1]);
	info->num_of_must_eat = -1;
	info->time_to_die = (uint64_t)ft_atoi(av[2]);
	info->time_to_eat = (uint64_t)ft_atoi(av[3]);
	info->time_to_sleep = (uint64_t)ft_atoi(av[4]);
	if (ac == 6)
		info->num_of_must_eat = ft_atoi(av[5]);
	info->do_cnt = 0;
	info->max_cnt = -1;
	if (info->num_of_must_eat != -1)
		info->max_cnt = info->num_of_philo * info->num_of_must_eat;
	return (0);
}

int	init_philo_philos(t_info *info)
{
	int	i;

	i = -1;
	info->philos = (t_philo *)malloc(sizeof(t_philo) * info->num_of_philo);
	if (info->philos == NULL)
		return (print_err("ERROR: memory allocation failed"));
	info->forks = (pthread_mutex_t *)malloc \
			(sizeof(pthread_mutex_t) * info->num_of_philo);
	if (info->forks == NULL)
		return (print_err("ERROR: memory allocation failed"));
	while (++i < info->num_of_philo)
	{
		pthread_mutex_init(&info->forks[i], NULL);
		info->philos[i].id = i + 1;
		if (i == 0)
			info->philos[i].left = &info->forks[info->num_of_philo - 1];
		else
			info->philos[i].left = &info->forks[i - 1];
		info->philos[i].right = &info->forks[i];
		info->philos[i].done = 0;
		info->philos[i].time = 0;
		info->philos[i].last_eat = 0;
		info->philos[i].info = info;
	}
	return (0);
}

int	init_philo_mutex(t_info *info)
{
	info->moniter = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	if (info->moniter == NULL)
		return (print_err("ERROR: memory allocation failed"));
	pthread_mutex_init(info->moniter, NULL);
	info->print = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	if (info->print == NULL)
		return (print_err("ERROR: memory allocation failed"));
	pthread_mutex_init(info->print, NULL);
	info->stop = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	if (info->stop == NULL)
		return (print_err("ERROR: memory allocation failed"));
	pthread_mutex_init(info->stop, NULL);
	return (0);
}

int	init_philo(int ac, char *av[], t_info *info)
{
	if (check_args(ac, av))
		return (print_err("ERROR: wrong argc"));
	else
	{
		if (init_philo_info(ac, av, info))
			return (1);
		if (init_philo_philos(info))
			return (1);
		if (init_philo_mutex(info))
			return (1);
	}
	return (0);
}

int	main(int ac, char *av[])
{
	t_info	info;

	memset(&info, 0, sizeof(info));
	if (ac != 5 && ac != 6)
		return (print_err("ERROR: wrong argc"));
	if (init_philo(ac, av, &info))
		return (1);
	if (start_philo(&info))
		return (1);
	return (0);
}
