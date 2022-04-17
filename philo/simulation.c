/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 12:30:23 by nfauconn          #+#    #+#             */
/*   Updated: 2022/04/17 16:27:11 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	philo->start_die = actual_time(philo->i->t0);
/* 	if (philo->right_handed)
		usleep(2000); */
	while (!philo->i->death && (philo->nb_meals > 0 || !philo->i->is_nb_meals))
	{
		if (philo->right_handed)
			meal_loop(philo, philo->fork_neighbour, &philo->fork);
		else
			meal_loop(philo, &philo->fork, philo->fork_neighbour);
		if (philo->death == 1)
		{
			pthread_mutex_lock(&philo->i->death_mutex);
			philo->i->death = 1;
			pthread_mutex_unlock(&philo->i->death_mutex);
			break ;
		}
	}
	return (NULL);
}

int	create_threads(t_infos *i, t_philo *philo, pthread_t *threads)
{
	int	index;

	index = 0;
	while (index < i->nb_philo)
	{
		if (pthread_create(&threads[index], NULL, &routine, &philo[index]) != SUCCESS)
			return (FAILURE);
		index++;
	}
	return (SUCCESS);
}

int	simulation(t_infos *i, t_philo *philo, pthread_t *threads)
{
	if (create_threads(i, philo, threads) != SUCCESS)
		return (ft_error("thread creation failed"));
 	if (join_threads(i, threads) != SUCCESS)
		return (ft_error("join thread failure"));
	return (SUCCESS);
}
