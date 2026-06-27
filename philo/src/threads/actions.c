/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 18:07:55 by marvin            #+#    #+#             */
/*   Updated: 2026/05/15 18:07:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	action_try_useforks(pthread_mutex_t	*forka, pthread_mutex_t	*forkb,
		t_philo *philo, int id)
{
	int	stop;

	pthread_mutex_lock(forka);
	stop = philo_print_getstop(philo->data, id, "has taken a fork", 1);
	if (stop)
	{
		pthread_mutex_unlock(forka);
		return (0);
	}
	pthread_mutex_lock(forkb);
	stop = philo_print_getstop(philo->data, id, "has taken a fork", 1);
	if (stop)
	{
		pthread_mutex_unlock(forka);
		pthread_mutex_unlock(forkb);
		return (0);
	}
	return (1);
}

int	action_try_eat(t_params *p, t_philo *philo, int id)
{
	int	useforks;
	int	stop;

	if (id % 2 == 1)
		useforks = action_try_useforks(philo->left, philo->right, philo, id);
	else
		useforks = action_try_useforks(philo->right, philo->left, philo, id);
	if (!useforks)
		return (0);
	philo_set_meal(philo);
	stop = philo_print_getstop(philo->data, philo->id, "is eating", 1);
	if (!stop)
		ft_usleep(p->tt_eat);
	pthread_mutex_unlock(philo->left);
	pthread_mutex_unlock(philo->right);
	return (!stop);
}

int	action_try_sleep(t_params *p, t_philo *philo, int id)
{
	int	stop;

	(void)id;
	stop = philo_print_getstop(philo->data, philo->id, "is sleeping", 1);
	if (!stop)
		ft_usleep(p->tt_sleep);
	return (!stop);
}
