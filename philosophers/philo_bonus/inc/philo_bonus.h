/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeojung <hyeojung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 15:24:54 by hyeojung          #+#    #+#             */
/*   Updated: 2022/05/09 18:19:08 by hyeojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <signal.h>
# include <pthread.h>
# include <semaphore.h>
# include <sys/time.h>
# include <sys/wait.h>

typedef struct s_info
{
	int				num_of_philo;
	uint64_t		time_to_die;
	uint64_t		time_to_eat;
	uint64_t		time_to_sleep;
	uint64_t		time_to_start;
	int				num_of_must_eat;
	int				dead;
	int				done;
	sem_t			*moniter;
	sem_t			*print;
	sem_t			*forks;
	struct s_philo	*philos;
}	t_info;

typedef struct s_philo
{
	int					id;
	int					num_of_eat;
	uint64_t			last_eat;
	uint64_t			last_sleep;
	pid_t				process_id;
	pthread_t			moniter_dead;
	struct s_info		*info;
}	t_philo;

/* action.c */
void		take_forks(t_philo *philo);
void		eating(t_philo *philo);
void		sleeping_and_thinking(t_philo *philo);

/* main.c */
int			init_philo_info(int ac, char *av[], t_info *info);
int			init_philo_philos(t_info *info);
int			init_philo_sem(t_info *info);
int			init_philo(int ac, char *av[], t_info *info);

/* philo.c */
void		free_philo(t_info *info);
void		*check_philo_dead(void *void_philo);
void		do_philo(t_philo *philo);
int			start_philo(t_info *info);

/* util.c */
int			ft_atoi(char *str);
int			check_args(int ac, char *av[]);
uint64_t	get_time(void);
int			print_err(char *err);
void		print_state(t_philo *philo, uint64_t time, char *state);

#endif