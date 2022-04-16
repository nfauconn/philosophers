/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <nfauconn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 12:30:23 by nfauconn          #+#    #+#             */
/*   Updated: 2022/04/16 11:30:11 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	philo->start_die = actual_time(philo->data->t0);
	while (!philo->data->death && (philo->nb_meals > 0 || philo->nb_meals == -1))
	{
		meal_loop(philo);
		if (philo->death == 1)
		{
			philo->data->death = 1;
			break ;
		}
		philo->nb_meals--;
	}
	return (NULL);
}

int	create_threads(t_data *data, t_philo *philo, pthread_t *threads)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		if (pthread_create(&threads[i], NULL, &routine, &philo[i]) != SUCCESS)
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}

int	simulation(t_data *data, t_philo *philo, pthread_t *threads)
{
	if (create_threads(data, philo, threads) != SUCCESS)
		return (ft_error("thread creation failed"));
 	if (join_threads(data, threads) != SUCCESS)
		return (ft_error("join thread failure"));
	return (SUCCESS);
}
