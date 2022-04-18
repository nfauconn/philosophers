/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 14:44:28 by user42            #+#    #+#             */
/*   Updated: 2022/04/18 14:58:28 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*check_death(void *ptr)
{
	t_philo	*philo;
	int		nb_philo;
	t_ull	t0;
	t_ull	t_die;
	int		index;

	philo = (t_philo *)ptr;
	nb_philo = philo[0].i->nb_philo;
	t0 = philo[0].i->t0;
	t_die = (t_ull)philo[0].i->t_die;
	index = 0;
	while (1)
	{
		if (index == nb_philo)
		{
			usleep(1000);
			index = 0;
		}
		if(actual_time(t0) - philo[index].start_die >= t_die)
		{
			pthread_mutex_lock(&philo[index].i->death_mutex);
			philo[index].i->death = 1;
			pthread_mutex_unlock(&philo[index].i->death_mutex);
			mutex_print(&philo[index], "is dead\n");
			break ;
		}
		index++;
	}
	return (NULL);
}