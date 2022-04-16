/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meal_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <nfauconn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:26:04 by nfauconn          #+#    #+#             */
/*   Updated: 2022/04/16 15:20:51 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	meal_loop(t_philo *philo, pthread_mutex_t *fork_1, pthread_mutex_t *fork_2)
{
	if (philo->i->forks[philo->first_fork] == 0)
	{
		pthread_mutex_lock(fork_1);
		philo->i->forks[philo->first_fork] = 1;
		pthread_mutex_unlock(fork_1);
		ft_print(philo, "has taken a fork");
	}
	if (!philo->i->death) // continuer avec index first et scnd fork
	{
		if (philo->i->nb_philo > 1)
		{
			pthread_mutex_lock(fork_2);
			ft_print(philo, "has taken a fork");
			philo->start_die = actual_time(philo->i->t0);
			ft_print(philo, "is eating");
			ft_sleep(philo, philo->i->t_eat);
			pthread_mutex_unlock(fork_1);
			pthread_mutex_unlock(fork_2);
			ft_print(philo, "is sleeping");
			ft_sleep(philo, philo->i->t_sleep);
			ft_print(philo, "his thinking");
		}
		else
		{
			
			ft_sleep(philo, philo->i->t_die);
		}
	}
}
/* 
void	meal_loop(t_philo *philo)
{
	if (philo->pos % 2 != 0 && philo->nb_meals == philo->i->nb_meals)
		ft_sleep(philo, 10);
	if (pthread_mutex_lock(&philo->fork) == SUCCESS)
	{
		ft_print(philo, "takes his fork");
		if (philo->i->nb_philo > 1)
		{	
			if (pthread_mutex_lock(philo->fork_neighbour) == SUCCESS)
			{
				ft_print(philo, "takes his neighbour's fork");
				philo->start_die = actual_time(philo->i->t0);
				ft_print(philo, "is eating");
				ft_sleep(philo, philo->i->t_eat);
				pthread_mutex_unlock(&philo->fork);
				pthread_mutex_unlock(philo->fork_neighbour);
				ft_print(philo, "is sleeping");
				ft_sleep(philo, philo->i->t_sleep);
				ft_print(philo, "his thinking");
			}
			else
				ft_sleep(philo, 2);
		}
		else
		{
			ft_sleep(philo, philo->i->t_die);
			pthread_mutex_unlock(&philo->fork);

		}
	}
	else
		ft_sleep(philo, 2);
}
 */