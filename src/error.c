/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 22:15:02 by marvin            #+#    #+#             */
/*   Updated: 2026/05/10 22:15:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	error_init(void)
{
	printf("erreur d'initialisation\n");
	return (1);
}

int	error_arg(void)
{
	printf("erreur d'arguments : arg invalides\n");
	return (1);
}
