/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_routines.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 03:11:32 by marvin            #+#    #+#             */
/*   Updated: 2026/05/12 03:11:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_routine(void *philo)
{
	t_philo	*phil;

	phil = (t_philo *)philo;
	action_first_think(&phil->data->params, phil, phil->id);
	while (1)
	{
		if (!action_try_eat(&phil->data->params, phil, phil->id))
			break ;
		if (!action_try_sleep(&phil->data->params, phil, phil->id))
			break ;
		if (!action_try_think(&phil->data->params, phil, phil->id))
			break ;
	}
	return (NULL);
}

int	monitor_routine_verify_meals(t_data *data)
{
	int	i;
	int	eat_lim;
	int	status;

	i = 0;
	eat_lim = 0;
	while (i < data->params.nb_philo)
	{
		status = monitor_read_meal(data, &data->philos[i], i + 1);
		if (status == 2)
			return (1);
		if (status == 1)
			eat_lim++;
		i++;
	}
	if (eat_lim == data->params.nb_philo)
	{
		monitor_setstop(data, -1, 0);
		return (1);
	}
	return (0);
}

void	*monitor_routine(void *data)
{
	int		status;
	t_data	*d;

	d = (t_data *)data;
	while (1)
	{
		status = monitor_routine_verify_meals(d);
		if (status == 1)
			break ;
		usleep(100);
	}
	return (NULL);
}
