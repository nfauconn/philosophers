/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:17:51 by user42            #+#    #+#             */
/*   Updated: 2022/04/07 17:23:33 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	join_threads(t_data *data, t_philo **philo, pthread_t **threads)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		if (pthread_join(*threads[i], NULL))
			return (FAILURE);
		printf("thread %d has finished \n", i);
		i++;
	}
	i = 0;
	while (i < data->nb_philo)
	{
		pthread_mutex_destroy(&philo[i]->fork);
		i++;
	}
	return (SUCCESS);
}
