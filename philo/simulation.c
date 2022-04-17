/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 12:30:23 by nfauconn          #+#    #+#             */
/*   Updated: 2022/04/17 13:21:19 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	philo->start_die = actual_time(philo->i->t0);
	while (!philo->i->death && (philo->nb_meals > 0 || !philo->i->is_nb_meals))
	{
		if (philo->right_handed)
		{
/* 			if (philo->nb_meals == philo->i->nb_meals)
				ft_sleep(philo, 10); */
			if (philo->i->nb_philo % 2 && philo->pos == philo->i->nb_philo - 1)
				ft_sleep(philo, 10);
			meal_loop(philo, philo->fork_neighbour, &philo->fork);
		}
		else
			meal_loop(philo, &philo->fork, philo->fork_neighbour);
		if (philo->death == 1)
		{
			philo->i->death = 1;
			break ;
		}
		philo->nb_meals--;
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
