/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meal_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <nfauconn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:26:04 by nfauconn          #+#    #+#             */
/*   Updated: 2022/04/14 19:45:50 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	meal_loop(t_philo *philo)
{
	if (philo->pos % 2 == 0)
		ft_sleep(philo, 10000);
	if (pthread_mutex_lock(&philo->fork) == SUCCESS)
	{
		ft_print(philo, "takes his fork");
		if (philo->data->nb_philo > 1)
		{	
			if (pthread_mutex_lock(philo->fork_neighbour) == SUCCESS)
			{
				ft_print(philo, "takes his neighbour's fork");
				philo->start_die = ft_get_time(philo->data->t0);
				ft_print(philo, "is eating");
				ft_sleep(philo, philo->data->t_eat);
				pthread_mutex_unlock(&philo->fork);
				pthread_mutex_unlock(philo->fork_neighbour);
				ft_print(philo, "is sleeping");
				ft_sleep(philo, philo->data->t_sleep);
				ft_print(philo, "his thinking");
			}
			else
				ft_sleep(philo, 10);
		}
		else
			ft_sleep(philo, philo->data->t_die);
	}
}
