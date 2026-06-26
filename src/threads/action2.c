/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 18:48:51 by marvin            #+#    #+#             */
/*   Updated: 2026/06/25 18:48:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	action_first_think2(t_params *p, t_philo *philo, int id)
{
	int	tt_think;
	int	real;
	int	impair_philo;
	int	pair;

	pair = 0;
	if (id % 2 == 0)
		pair = 1;
	impair_philo = id + pair;
	tt_think = p->tt_die * 2;
	if (p->nb_philo != 1)
		tt_think = pair * p->tt_eat + p->tt_eat * (impair_philo / 2)
			/ (p->nb_philo / 2);
	real = tt_think - (get_time_ms() - philo->last_meal);
	if (real > 0)
		ft_usleep(real);
	else
		ft_usleep(1);
}

int	action_first_think(t_params *p, t_philo *philo, int id)
{
	int	stop;
	int	real;

	stop = philo_print_getstop(philo->data, id, "is thinking", 1);
	if (!stop)
	{
		if (p->nb_philo % 2 == 1)
			action_first_think2(p, philo, id);
		else
		{
			real = p->tt_eat - (get_time_ms() - philo->last_meal);
			if (real < 0)
				real = 1;
			if (id % 2 == 0)
				ft_usleep(real);
		}
	}
	return (!stop);
}

int	action_try_think(t_params *p, t_philo *philo, int id)
{
	int	stop;
	int	tt_think;
	int	real;

	stop = philo_print_getstop(philo->data, id, "is thinking", 1);
	if (!stop)
	{
		if (p->nb_philo % 2 == 0)
		{
			tt_think = p->tt_eat - p->tt_sleep;
			real = tt_think - (get_time_ms() - philo->last_meal);
			if (real < 0 || p->tt_die <= real)
				real = 0;
			ft_usleep(real);
		}
		else
		{
			tt_think = p->tt_eat + p->tt_eat / 2 - p->tt_sleep;
			real = tt_think - (get_time_ms() - philo->last_meal);
			if (real < 0 || p->tt_die <= real)
				real = 0;
			ft_usleep(real);
		}
	}
	return (!stop);
}
