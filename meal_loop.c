/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meal_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <nfauconn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:26:04 by nfauconn          #+#    #+#             */
/*   Updated: 2022/04/16 11:30:11 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	meal_loop(t_philo *philo)
{
	if (philo->pos % 2 == 0 && philo->nb_meals == philo->data->nb_meals)
		ft_sleep(philo, 2);
	pthread_mutex_lock(&philo->fork);
	ft_print(philo, "takes his fork");
	if (philo->data->nb_philo > 1)
	{	
		pthread_mutex_lock(philo->fork_neighbour);
		ft_print(philo, "takes his neighbour's fork");
		philo->start_die = actual_time(philo->data->t0);
		ft_print(philo, "is eating");
		ft_sleep(philo, philo->data->t_eat);
		pthread_mutex_unlock(&philo->fork);
		pthread_mutex_unlock(philo->fork_neighbour);
		ft_print(philo, "is sleeping");
		ft_sleep(philo, philo->data->t_sleep);
		ft_print(philo, "his thinking");
	}
	else
		ft_sleep(philo, philo->data->t_die);
}
/* 
void	meal_loop(t_philo *philo)
{
	if (philo->pos % 2 == 0 && philo->nb_meals == philo->data->nb_meals)
		ft_sleep(philo, 2);
	if (pthread_mutex_lock(&philo->fork) == SUCCESS)
	{
		ft_print(philo, "takes his fork");
		if (philo->data->nb_philo > 1)
		{	
			if (pthread_mutex_lock(philo->fork_neighbour) == SUCCESS)
			{
				ft_print(philo, "takes his neighbour's fork");
				philo->start_die = actual_time(philo->data->t0);
				ft_print(philo, "is eating");
				ft_sleep(philo, philo->data->t_eat);
				pthread_mutex_unlock(&philo->fork);
				pthread_mutex_unlock(philo->fork_neighbour);
				ft_print(philo, "is sleeping");
				ft_sleep(philo, philo->data->t_sleep);
				ft_print(philo, "his thinking");
			}
			else
				ft_sleep(philo, 2);
		}
		else
			ft_sleep(philo, philo->data->t_die);
	}
	else
		ft_sleep(philo, 2);
}
 */