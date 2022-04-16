/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <nfauconn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:17:51 by user42            #+#    #+#             */
/*   Updated: 2022/04/16 11:34:41 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	join_threads(t_data *data, pthread_t *threads)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		if (pthread_join(threads[i], NULL))
			return (FAILURE);
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
		pthread_mutex_destroy(&philo[i].fork);
		i++;
	}
	pthread_mutex_destroy(&data->message);
	pthread_mutex_destroy(&data->death_mutex);
	free(philo);
}
/* 
void	simulation_end(t_data *data)
{

}
 */