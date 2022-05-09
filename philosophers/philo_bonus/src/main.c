/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeojung <hyeojung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 15:26:41 by hyeojung          #+#    #+#             */
/*   Updated: 2022/05/09 17:47:59 by hyeojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	init_philo_info(int ac, char *av[], t_info *info)
{
	info->num_of_philo = ft_atoi(av[1]);
	info->time_to_die = (uint64_t)ft_atoi(av[2]);
	info->time_to_eat = (uint64_t)ft_atoi(av[3]);
	info->time_to_sleep = (uint64_t)ft_atoi(av[4]);
	info->num_of_must_eat = -1;
	if (ac == 6)
		info->num_of_must_eat = ft_atoi(av[5]);
	return (0);
}

int	init_philo_philos(t_info *info)
{
	int	i;

	info->philos = (t_philo *)malloc(sizeof(t_philo) * info->num_of_philo);
	if (info->philos == NULL)
		return (print_err("ERROR: memory allocation failed"));
	i = -1;
	while (++i < info->num_of_philo)
	{
		info->philos[i].id = i + 1;
		info->philos[i].info = info;
	}
	return (0);
}

int	init_philo_sem(t_info *info)
{
	sem_unlink("moniter_philo");
	sem_unlink("print_philo");
	sem_unlink("forks_philo");
	info->moniter = sem_open("moniter_philo", O_CREAT, 0600, 1);
	info->print = sem_open("print_philo", O_CREAT, 0600, 1);
	info->forks = sem_open("forks_philo", O_CREAT, 0600, info->num_of_philo);
	if (info->moniter <= 0 || info->print <= 0 || info->forks <= 0)
		return (1);
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
		if (init_philo_sem(info))
			return (1);
		if (init_philo_philos(info))
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
