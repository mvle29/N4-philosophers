/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 21:36:36 by marvin            #+#    #+#             */
/*   Updated: 2026/05/10 21:36:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	join_threads(t_data *data)
{
	int	i;

	i = 0;
	pthread_join(data->thread, NULL);
	while (i < data->params.nb_philo)
	{
		pthread_join(data->philos[i].thread, NULL);
		i++;
	}
}

long	get_time_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	ft_usleep(long ms)
{
	long	start;

	start = get_time_ms();
	while (get_time_ms() - start < ms)
		usleep(100);
}

int	main(int agc, char **agv)
{
	t_data	data;

	memset(&data, 0, sizeof(t_data));
	if (!parse(agc, agv, &data.params) || data.params.nb_philo == 0)
		return (error_arg());
	if (!init_data(&data))
	{
		cleanup(&data);
		return (error_init());
	}
	if (!init_threads(&data, data.philos))
	{
		printf("sim couldnt start\n");
		cleanup(&data);
		return (error_init());
	}
	join_threads(&data);
	cleanup(&data);
	return (0);
}
