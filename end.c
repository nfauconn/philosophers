/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <nfauconn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:17:51 by user42            #+#    #+#             */
/*   Updated: 2022/04/08 12:47:19 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	join_threads(t_data data, t_philo *philo, pthread_t **threads)
{
	int	i;

	i = 0;
	while (i < data.nb_philo)
	{
		if (pthread_join(*threads[i], NULL))
			return (FAILURE);
		printf("philo %d has finished \n", philo[i].pos);
		i++;
	}
	i = 0;
	while (i < data.nb_philo)
	{
		pthread_mutex_destroy(&philo[i].fork);
		i++;
	}
	return (SUCCESS);
}

void	free_and_destroy(t_data *data, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		free(&philo[i]);
		i++;
	}
	free(philo);
}
