/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 21:37:02 by marvin            #+#    #+#             */
/*   Updated: 2026/05/10 21:37:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include "libft.h"
# include <string.h>

typedef struct s_params
{
	int	nb_philo;
	int	tt_eat;
	int	tt_die;
	int	tt_sleep;
	int	eat_limit;
}	t_params;

typedef struct s_data	t_data;

typedef struct s_philo
{
	pthread_t			thread;
	int					id;
	int					meals_eaten;
	long				last_meal;
	pthread_mutex_t		meal_mutex;
	pthread_mutex_t		*right;
	pthread_mutex_t		*left;
	t_data				*data;
}	t_philo;

typedef struct s_data
{
	pthread_t			thread;
	int					stop;
	long				start;
	int					print_init;
	pthread_mutex_t		print_mutex;
	pthread_mutex_t		*forks;
	t_philo				*philos;
	t_params			params;
}	t_data;
//tt = time_to

long	get_time_ms(void);
void	ft_usleep(long ms);

int		parse(int agc, char **agv, t_params *params);

int		init_data(t_data *data);
int		init_threads(t_data *data, t_philo *philos);

void	*monitor_routine(void *data);
void	*philo_routine(void *philo);

int		action_first_think(t_params *p, t_philo *philo, int id);
int		action_try_think(t_params *p, t_philo *philo, int id);
int		action_try_eat(t_params *p, t_philo *philo, int id);
int		action_try_sleep(t_params *p, t_philo *philo, int id);

void	monitor_setstop(t_data *data, int id, int death);
int		philo_print_getstop(t_data *data, int id, char *to_print, int print);
int		monitor_read_meal(t_philo *philo);
void	philo_set_meal(t_philo *philo);

int		cleanup(t_data *data);

int		error_init(void);
int		error_arg(void);

#endif
