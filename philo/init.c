/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <nfauconn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 15:17:26 by nfauconn          #+#    #+#             */
/*   Updated: 2022/04/21 14:58:56 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	init_forks(t_infos *i, t_philo *philo, int index)
{
	pthread_mutex_init(&philo[index].fork, NULL);
	if (i->nb_philo == 1)
		philo[0].fork_neighbour = NULL;
	else
	{
		if (philo[index].pos == i->nb_philo - 1)
			philo[index].fork_neighbour = &philo[0].fork;
		else
			philo[index].fork_neighbour = &philo[index + 1].fork;
	}
}

void	init_philo(t_infos *i, t_philo *philo)
{
	int		index;

	index = 0;
	while (index < i->nb_philo)
	{
		philo[index].pos = index;
		if (index % 2)
			philo[index].right_handed = 1;
		else
			philo[index].right_handed = 0;
		philo[index].nb_meals = i->nb_meals;
		philo[index].last_time_eat = 0;
		philo[index].i = i;
		init_forks(i, philo, index);
		pthread_mutex_init(&philo[index].meal_count, NULL);
		pthread_mutex_init(&philo[index].time, NULL);
		index++;
	}
	pthread_mutex_init(&i->message, NULL);
	pthread_mutex_init(&i->authorize_print_mutex, NULL);
	pthread_mutex_init(&i->count_meals, NULL);
	pthread_mutex_init(&i->end_mutex, NULL);
}

void	init_infos(t_infos *i)
{
	i->nb_philo = 0;
	i->t_die = 0;
	i->t_eat = 0;
	i->t_sleep = 0;
	i->nb_meals = -1;
	i->finish_philo = 0;
	i->print_ok = 1;
	i->end = 0;
	i->t0 = actual_time(0);
}
