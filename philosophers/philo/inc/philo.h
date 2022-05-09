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
	pthread_t			thread;
	struct s_info		*info;
}						t_philosopher;

int						write_error(char *str);
int						error_manager(int error);
int						init_all(t_rules *rules, char **argv);
int						ft_atoi(const char *str);
void					action_print(t_rules *rules, int id, char *string);
long long				timestamp(void);
long long				time_diff(long long past, long long pres);
void					smart_sleep(long long time, t_rules *rules);
int						launcher(t_rules *rules);
void					exit_launcher(t_rules *rules, t_philosopher *philos);

#endif