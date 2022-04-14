/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <nfauconn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 15:17:26 by nfauconn          #+#    #+#             */
/*   Updated: 2022/04/14 16:58:54 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_philo(t_data *data, t_philo *philo)
{
	int		i;

	i = 0;
	while (i < data->nb_philo)
	{
		philo[i].pos = i;
		philo[i].data = data;
		pthread_mutex_init(&philo[i].fork, NULL);
		pthread_mutex_init(&philo[i].start_eat, NULL);
		pthread_mutex_init(&philo[i].nb_meals, NULL);
		i++;
	}
	pthread_mutex_init(&data->message, NULL);
	pthread_mutex_init(&data->nb_meals_all_philos, NULL);
}

void	init_data(t_data *data)
{
	data->nb_philo = 0;
	data->t_die = 0;
	data->t_eat = 0;
	data->t_sleep = 0;
	data->nb_meals = -1;
	data->death = 0;
	data->t0 = ft_get_time(0);
	data->print_ok = 1;
}
