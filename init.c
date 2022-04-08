/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 15:17:26 by nfauconn          #+#    #+#             */
/*   Updated: 2022/04/08 18:05:34 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_philo(t_data data, t_philo *philo)
{
	int		i;
	i = 0;
	while (i < data.nb_philo)
	{
		philo[i].pos = i + 1;
		pthread_mutex_init(&philo[i].fork_l, NULL);
		pthread_mutex_init(&philo[i].fork_r, NULL);
		i++;
	}
}

void	init_data(t_data *data)
{
	data->nb_philo = 0;
	data->t_die = 0;
	data->t_eat = 0;
	data->t_sleep = 0;
	data->nb_meals = -1;
}
