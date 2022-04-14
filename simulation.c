/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <nfauconn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 12:30:23 by nfauconn          #+#    #+#             */
/*   Updated: 2022/04/14 16:43:33 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*check_death(void *ptr)
{
	int		i;
	t_data	*data;

	data = (t_data *)ptr;
	i = 0;
	while (i++ < data->nb_meals || data->nb_meals == -1)
	{
		if (data->death == 1)
		{
			data->print_ok = 0;
/* 			simulation_end(data);
 */		}
	}
	return (NULL);
}

void	*routine(void *ptr)
{
	int		i;
	t_philo	*philo;

	philo = (t_philo *)ptr;
	philo->t0 = ft_get_time(philo->data->t0);
	i = 0;
	while ((i++ < philo->data->nb_meals || philo->data->nb_meals == -1) && philo->data->death == 0)
	{
		if (philo->pos == 0)
			meal_loop(philo, philo->data->nb_philo - 1, philo->pos);
		else
			meal_loop(philo, philo->pos - 1, philo->pos);
	}
	return (NULL);
}

int	create_threads(t_data *data, t_philo *philo, pthread_t *threads)
{
	int	i;

	i = 0;
	while (i < data->nb_philo && !(i % 2))
	{
		if (pthread_create(&threads[i], NULL, &routine, &philo[i]) != SUCCESS)
			return (FAILURE);
		i += 2;
	}
	i = 1;
	while (i < data->nb_philo && (i % 2))
	{
		if (pthread_create(&threads[i], NULL, &routine, &philo[i]) != SUCCESS)
			return (FAILURE);
		i+= 2;
	}
	if (pthread_create(&threads[i], NULL, &check_death, data) != SUCCESS)
		return (FAILURE);
	return (SUCCESS);
}

int	simulation(t_data *data, t_philo *philo, pthread_t *threads)
{
	if (create_threads(data, philo, threads) != SUCCESS)
		return (ft_error("thread creation failed"));
 	if (join_threads(data, threads) != SUCCESS)
		return (FAILURE);
	return (SUCCESS);
}
