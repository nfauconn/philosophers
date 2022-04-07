/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 15:17:26 by nfauconn          #+#    #+#             */
/*   Updated: 2022/04/07 16:58:40 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_threads(t_data *data, t_philo **philo, pthread_t **threads)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		if (pthread_create(threads[i], NULL, &routine, (void*)philo[i]))
			return (FAILURE);
		printf("thread %d has started \n", philo[i]->pos);
		i++;

	}
	return (SUCCESS);
}

int	init_philo(t_data *data, t_philo **philo)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		philo[i]->pos = i + 1;
		pthread_mutex_init(&philo[i]->fork, NULL);
		if (i == 0)
			philo[i]->fork2 = NULL;
		else
			philo[i]->fork2 = &philo[i - 1]->fork;
	}
	return (SUCCESS);
}

void	init_data(t_data *data)
{
	data->nb_philo = 0;
	data->t_die = 0;
	data->t_eat = 0;
	data->t_sleep = 0;
	data->nb_meals = 0;
}

/* 
void	create_threads(t_data *data, int threads_nb)
{
	int			philo_numero;
	int			*philo_numero_addr;
	pthread_t	thread[threads_nb];

	
}
 */