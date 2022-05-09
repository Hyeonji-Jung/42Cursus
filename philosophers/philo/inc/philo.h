/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeojung <hyeojung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 15:24:54 by hyeojung          #+#    #+#             */
/*   Updated: 2022/05/09 17:14:46 by hyeojung         ###   ########.fr       */
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
	pthread_mutex_t	moniter;
	pthread_mutex_t	print;
	pthread_mutex_t	*forks;
	struct s_philo	*philos;
}	t_info;

typedef struct s_philo
{
	int					id;
	int					num_of_eat;
	int					left;
	int					right;
	uint64_t			last_eat;
	uint64_t			last_sleep;
	pthread_t			thread;
	struct s_info		*info;
}	t_philo;

/* action.c */
void		take_forks(t_philo *philo);
void		eating(t_philo *philo);
void		sleeping_and_thinking(t_philo *philo);

/* main.c */
int			init_philo_info(int ac, char *av[], t_info *info);
int			init_philo_philos(t_info *info);
int			init_philo_mutex(t_info *info);
int			init_philo(int ac, char *av[], t_info *info);

/* philo.c */
void		free_philo(t_info *info);
void		check_philo_done(t_info *info);
void		*do_philo(void *void_philo);
int			start_philo(t_info *info);

/* util.c */
int			ft_atoi(char *str);
int			check_args(int ac, char *av[]);
uint64_t	get_time(void);
int			print_err(char *err);
void		print_state(t_philo *philo, uint64_t time, char *state);

#endif