/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 22:15:21 by marvin            #+#    #+#             */
/*   Updated: 2026/05/10 22:15:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_forks(t_data *data)
{
	int	i;

	data->forks = malloc(sizeof(pthread_mutex_t) * data->params.nb_philo);
	if (!data->forks)
		return (0);
	i = 0;
	while (i < data->params.nb_philo)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
		{
			while (--i >= 0)
				pthread_mutex_destroy(&data->forks[i]);
			free(data->forks);
			data->forks = 0;
			return (0);
		}
		i++;
	}
	return (1);
}

int	init_philos(t_data *data)
{
	int	i;

	i = 0;
	data->philos = malloc(sizeof(t_philo) * data->params.nb_philo);
	if (!data->philos)
		return (0);
	while (i < data->params.nb_philo)
	{
		data->philos[i].id = i + 1;
		data->philos[i].meals_eaten = 0;
		data->philos[i].data = data;
		data->philos[i].last_meal = 0;
		data->philos[i].left = &data->forks[i];
		data->philos[i].right = &data->forks[(i + 1) % data->params.nb_philo];
		if (pthread_mutex_init(&data->philos[i].meal_mutex, NULL) != 0)
		{
			while (--i >= 0)
				pthread_mutex_destroy(&data->philos[i].meal_mutex);
			free(data->philos);
			data->philos = 0;
			return (0);
		}
		i++;
	}
	return (1);
}

int	init_data(t_data *data)
{
	data->print_init = 0;
	data->forks = NULL;
	data->philos = NULL;
	if (!init_forks(data))
		return (0);
	if (!init_philos(data))
		return (0);
	if (pthread_mutex_init(&data->print_mutex, NULL) != 0)
		return (0);
	data->print_init = 1;
	return (1);
}

int	init_threads(t_data *data, t_philo *philos)
{
	int	i;

	i = 0;
	data->start = get_time_ms();
	while (i < data->params.nb_philo)
	{
		philos[i].last_meal = data->start;
		if (pthread_create(&philos[i].thread, 0, philo_routine, &philos[i]))
		{
			monitor_setstop(data, -1, 0);
			while (--i >= 0)
				pthread_join(philos[i].thread, NULL);
			return (0);
		}
		i++;
	}
	if (pthread_create(&data->thread, NULL, monitor_routine, data))
	{
		monitor_setstop(data, -1, 0);
		while (--i >= 0)
			pthread_join(philos[i].thread, NULL);
		return (0);
	}
	return (1);
}
