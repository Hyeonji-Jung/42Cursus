/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeojung <hyeojung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 15:24:54 by hyeojung          #+#    #+#             */
/*   Updated: 2022/05/09 14:49:57 by hyeojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

# define FORK	2
# define EAT	3
# define SLEEP	4
# define THINK	5
# define DEAD	6
# define DONE	7

typedef struct s_info
{
	int				num_of_philo;
	int				num_of_must_eat;
	int				do_cnt;
	int				max_cnt;
	int				done;
	uint64_t		time_to_start;
	uint64_t		time_to_die;
	uint64_t		time_to_eat;
	uint64_t		time_to_sleep;
	pthread_mutex_t	*forks;
	pthread_mutex_t	stop;
	struct s_philo	*philos;
}	t_info;

typedef struct s_philo
{
	int				id;
	pthread_t		thread;
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
	pthread_mutex_t	moniter;
	uint64_t		dead_time;
	uint64_t		last_eat;
	struct s_info	*info;
}	t_philo;

int			ft_atoi(char *str);
int			print_err(char *err);
int			check_args(int ac, char *av[]);
int			init_philo(int ac, char *av[], t_info *info);
int			init_philo_info(int ac, char *av[], t_info *info);
int			init_philo_philos(t_info *info);
int			init_philo_mutex(t_info *info);
int			start_philo(t_info *info);
int			threading(t_info *info);
uint64_t	get_time(void);
void		take_forks(t_philo *philo);
void		eating(t_philo *philo);
void		sleeping_and_thinking(t_philo *philo);
void		free_philo(t_info *info);
void		*do_philo(void *void_philo);
void		*moniter_philo(void *void_philo);
void		*moniter_philo_must_eat(void *void_info);

#endif