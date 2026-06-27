/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 22:14:06 by marvin            #+#    #+#             */
/*   Updated: 2026/05/10 22:14:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	invalid_entry(char *agv)
{
	long	nb;
	int		j;

	if (!agv[0])
		return (0);
	j = 0;
	nb = 0;
	while (agv[j])
	{
		if (!ft_isdigit(agv[j]) && !ft_isspace(agv[j]) && !(agv[j] == '+'
				&& ft_isdigit(agv[j + 1])))
			return (1);
		if (ft_isspace(agv[j]))
			nb = 0;
		if (ft_isdigit(agv[j]))
			nb = nb * 10 + (agv[j] - '0');
		if (nb > 2147483647)
			return (1);
		j++;
	}
	return (0);
}

int	no_entry(char *agv, int j)
{
	int	i;

	i = 0;
	if (!agv[i + j])
		return (1);
	while (agv[i + j])
	{
		if (!ft_isspace(agv[i + j]))
			return (0);
		i++;
	}
	return (1);
}

int	get_numbers(char **agv, int *numbers, int *p, int agc)
{
	int	i;
	int	j;

	i = 1;
	while (i < agc)
	{
		j = 0;
		if (invalid_entry(agv[i]))
			return (0);
		while (agv[i][j])
		{
			if (no_entry(agv[i], j))
				break ;
			if (*p >= 5)
				return (0);
			numbers[*p] = ft_atoi(agv[i] + j);
			while (ft_isspace(agv[i][j]))
				j++;
			while (agv[i][j] == '+' || ft_isdigit(agv[i][j]))
				j++;
			(*p)++;
		}
		i++;
	}
	return (1);
}

int	parse(int agc, char **agv, t_params *params)
{
	int	numbers[5];
	int	p;

	p = 0;
	numbers[4] = -1;
	if (!get_numbers(agv, numbers, &p, agc))
		return (0);
	if (p < 4)
		return (0);
	params->nb_philo = numbers[0];
	params->tt_die = numbers[1];
	params->tt_eat = numbers[2];
	params->tt_sleep = numbers[3];
	params->eat_limit = numbers[4];
	return (1);
}
