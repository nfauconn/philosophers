/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <nfauconn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:17:51 by user42            #+#    #+#             */
/*   Updated: 2022/04/20 17:07:20 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	join_threads(t_infos *i, pthread_t *threads)
{
	int	index;

	index = 0;
	while (index <= i->nb_philo)
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
		pthread_mutex_destroy(&philo[index].meal_count);
		pthread_mutex_destroy(&philo[index].fork);
		pthread_mutex_destroy(&philo[index].time);
		index++;
	}
	pthread_mutex_destroy(&i->count_meals);
	pthread_mutex_destroy(&i->message);
	pthread_mutex_destroy(&i->authorize_print_mutex);
	pthread_mutex_destroy(&i->end_mutex);
	if (philo)
		free(philo);
}
