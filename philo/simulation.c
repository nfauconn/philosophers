/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <nfauconn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 12:30:23 by nfauconn          #+#    #+#             */
/*   Updated: 2022/04/21 15:01:13 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	if (philo->right_handed)
		usleep(1000);
	if (philo->i->nb_philo == 1)
	{
		lock(philo, &philo->fork);
		ft_milli_sleep(philo, philo->i->t_die);
		unlock(&philo->fork);
		return (NULL);
	}
	if (philo->right_handed)
		meal_loop(philo, philo->fork_neighbour, &philo->fork);
	else
		meal_loop(philo, &philo->fork, philo->fork_neighbour);
	return (NULL);
}

int	create_threads(t_infos *i, t_philo *philo, pthread_t *threads)
{
	int	index;

	index = 0;
	while (index < i->nb_philo)
	{
		philo[index].last_time_eat = actual_time(i->t0);
		if (pthread_create(&threads[index], NULL, &routine, &philo[index]))
			return (FAILURE);
		index ++;
	}
	if (pthread_create(&threads[i->nb_philo], NULL, &check_end, philo))
		return (FAILURE);
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
