/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meal_mutex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 03:43:45 by marvin            #+#    #+#             */
/*   Updated: 2026/05/16 03:43:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*end == 1 : meals limite atteinte (pas de print de death)
end == 1 : (utilise aussi en cas d erreur mutex lock / unlock pr end le prog)
end == 2 : philo est mort (print de death)*/

int	monitor_read_meal(t_data *data, t_philo *philo, int i)
{
	int	end;
	int	meals_lim;

	end = 0;
	meals_lim = philo->data->params.eat_limit;
	pthread_mutex_lock(&philo->meal_mutex);
	if (get_time_ms() - philo->last_meal >= philo->data->params.tt_die)
	{
		monitor_setstop(data, i, 1);
		end = 2;
	}
	else if (meals_lim >= 0 && philo->meals_eaten >= meals_lim)
		end = 1;
	pthread_mutex_unlock(&philo->meal_mutex);
	return (end);
}

void	philo_set_meal(t_philo *philo)
{
	pthread_mutex_lock(&philo->meal_mutex);
	philo->last_meal = get_time_ms();
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->meal_mutex);
}
