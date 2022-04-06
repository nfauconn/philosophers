/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <nfauconn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 15:17:26 by nfauconn          #+#    #+#             */
/*   Updated: 2022/04/06 18:08:40 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_philo(t_philo *philo, int i)
{
	philo->pos = i + 1;
	pthread_mutex_init(&philo->fork, NULL);
}

void	init_data(t_data *data)
{
	data->number_of_philosophers = 0;
	data->time_to_die = 0;
	data->time_to_eat = 0;
	data->time_to_sleep = 0;
	data->is_number_of_times = 0;
	data->number_of_times_each_philosopher_must_eat = 0;
}

/* 
void	create_threads(t_data *data, int threads_nb)
{
	int			philo_numero;
	int			*philo_numero_addr;
	pthread_t	thread[threads_nb];

	
}
 */