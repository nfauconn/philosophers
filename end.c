/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <nfauconn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:17:51 by user42            #+#    #+#             */
/*   Updated: 2022/04/16 12:12:40 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	join_threads(t_infos *i, pthread_t *threads)
{
	int	index;

	index = 0;
	while (index < i->nb_philo)
	{
		if (pthread_join(threads[index], NULL))
			return (FAILURE);
		index++;
	}
	return (SUCCESS);
}

void	free_and_destroy(t_infos *i, t_philo *philo)
{
	int	index;

	index = 0;
	while (index < i->nb_philo)
	{
		pthread_mutex_destroy(&philo[index].fork);
		index++;
	}
	pthread_mutex_destroy(&i->message);
	pthread_mutex_destroy(&i->death_mutex);
	free(philo);
}
/* 
void	simulation_end(t_infos *i)
{

}
 */