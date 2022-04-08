/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <nfauconn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 12:23:38 by nfauconn          #+#    #+#             */
/*   Updated: 2022/04/08 11:22:57 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	pthread_mutex_lock(&philo->fork_l);
	sleep(1);
	printf("philo %d takes a fork\n", philo->pos);
	pthread_mutex_unlock(&philo->fork_l);
	return (NULL);
}

int	create_threads(t_data data, t_philo *philo, pthread_t **threads)
{
	int	i;

	i = 0;
	while (i < data.nb_philo)
	{
		if (pthread_create(threads[i], NULL, &routine, &philo[i]))
			return (FAILURE);
		printf("philo %d has taken the fork \n", philo[i].pos);
		i++;
	}
	return (SUCCESS);
}

int	simulation(t_data data, t_philo *philo)
{
	pthread_t	*threads;

	threads = (pthread_t *)malloc(sizeof(pthread_t) * (data.nb_philo + 1));
	if (!threads)
		return (FAILURE);
	if (create_threads(data, philo, &threads) == FAILURE)
		return (FAILURE);
	if (join_threads(data, philo, &threads) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
