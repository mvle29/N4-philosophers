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

int	action_first_think(t_params *p, t_philo *philo, int id)
{
	int	stop;

	stop = philo_print_getstop(philo->data, id, "is thinking", 1);
	if (!stop)
	{
		if (p->nb_philo % 2 == 1)
		{
			if (p->nb_philo == 1)
				ft_usleep((p->tt_die * 2));
			else if (id % 2 == 1)
				ft_usleep((p->tt_eat * (id / 2)) / (p->nb_philo / 2));
			else
				ft_usleep(p->tt_eat + (p->tt_eat * ((id - 1) / 2))
					/ ((p->nb_philo / 2) - 1));
		}
		else
		{
			if (id % 2 == 0)
				ft_usleep(p->tt_eat);
		}
	}
	return (!stop);
}

int	action_try_think(t_params *p, t_philo *philo, int id)
{
	int	stop;
	int	tt_think;

	stop = philo_print_getstop(philo->data, id, "is thinking", 1);
	if (!stop)
	{
		if (p->nb_philo % 2 == 0)
		{
			tt_think = p->tt_eat - p->tt_sleep;
			if (tt_think < 0)
				tt_think = 1;
			ft_usleep(tt_think);
		}
		else
		{
			tt_think = p->tt_eat + p->tt_eat / 2 - p->tt_sleep;
			if (tt_think < 0)
				tt_think = 1;
			ft_usleep(tt_think);
		}
	}
	return (!stop);
}

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
