/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 15:17:26 by nfauconn          #+#    #+#             */
/*   Updated: 2022/04/17 13:29:34 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	init_forks_indexes(t_infos *i, t_philo *philo)
{
	int	index;

	index = 0;
	while (index < i->nb_philo)
	{
		if (index % 2 == 0)
		{
			philo[index].right_handed = 1;
			philo[index].first_fork = philo->pos;
			if (philo[index].pos == 0)
				philo[index].scnd_fork = philo[index].i->nb_philo + 1;
			else
				philo[index].scnd_fork = philo[index].pos + 1;
		}
		else
		{
			philo[index].first_fork = philo[index].pos;
			if (philo[index].pos == 0)
				philo[index].scnd_fork = philo[index].i->nb_philo + 1;
			else
				philo[index].scnd_fork = philo[index].pos + 1;
		}
		index++;
	}
}

void	init_philo(t_infos *i, t_philo *philo)
{
	int		index;

	index = 0;
	while (index < i->nb_philo)
	{
		philo[index].pos = index;
		philo[index].death = 0;
		philo[index].nb_meals = i->nb_meals;
		philo[index].i = i;
		pthread_mutex_init(&philo[index].fork, NULL);
		if (i->nb_philo == 1)
			philo[index].fork_neighbour = NULL;
		else if (philo[index].pos == philo->i->nb_philo - 1)
			philo[index].fork_neighbour = &philo[0].fork;
		else
			philo[index].fork_neighbour = &philo[index + 1].fork;
		index++;
	}
	init_forks_indexes(i, philo);
	pthread_mutex_init(&i->message, NULL);
	pthread_mutex_init(&i->death_mutex, NULL);
}

void	init_infos(t_infos *i)
{
	int	index;

	index = 0;
	i->nb_philo = 0;
 	while (i->forks[index])
	 	i->forks[index++] = 0;
	i->t_die = 0;
	i->t_eat = 0;
	i->t_sleep = 0;
	i->nb_meals = -1;
	i->is_nb_meals = 0;
	i->death = 0;
	i->t0 = actual_time(0);
	i->print_ok = 1;
}
