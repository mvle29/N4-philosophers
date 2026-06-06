/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_mutex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 03:43:22 by marvin            #+#    #+#             */
/*   Updated: 2026/05/16 03:43:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_print_getstop(t_data *data, int id, char *to_print, int print)
{
	int	stop;

	pthread_mutex_lock(&data->print_mutex);
	stop = data->stop;
	if (print && !stop)
		printf("%ld %d %s\n", get_time_ms() - data->start, id, to_print);
	pthread_mutex_unlock(&data->print_mutex);
	return (stop);
}

void	monitor_setstop(t_data *data, int id, int death)
{
	pthread_mutex_lock(&data->print_mutex);
	if (death == 1 && id > 0)
		printf("%ld %d %s\n", get_time_ms() - data->start, id, "died");
	data->stop = 1;
	pthread_mutex_unlock(&data->print_mutex);
}
