/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 02:17:56 by marvin            #+#    #+#             */
/*   Updated: 2026/05/12 02:17:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	cleanup_philos(t_data *data)
{
	int	i;

	i = 0;
	if (!data->philos)
		return ;
	while (i < data->params.nb_philo)
	{
		pthread_mutex_destroy(&data->philos[i].meal_mutex);
		i++;
	}
	free(data->philos);
}

void	cleanup_forks(t_data *data)
{
	int	i;

	i = 0;
	if (!data->forks)
		return ;
	while (i < data->params.nb_philo)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	free(data->forks);
}

int	cleanup(t_data *data)
{
	cleanup_philos(data);
	cleanup_forks(data);
	if (data->print_init)
		pthread_mutex_destroy(&data->print_mutex);
	return (1);
}
