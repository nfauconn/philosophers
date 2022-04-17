/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meal_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:26:04 by nfauconn          #+#    #+#             */
/*   Updated: 2022/04/17 12:37:45 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	lock(t_philo *philo, int index, pthread_mutex_t *fork)
{
	pthread_mutex_lock(fork);
	philo->i->forks[index] = 1;
	pthread_mutex_unlock(fork);
	ft_print(philo, "has taken a fork");
}

static void	unlock(t_philo *philo, int index, pthread_mutex_t *fork)
{
	pthread_mutex_lock(fork);
	philo->i->forks[index] = 0;
	pthread_mutex_unlock(fork);
}

void	meal_loop(t_philo *philo, pthread_mutex_t *fork_1, pthread_mutex_t *fork_2)
{
	if (philo->i->forks[philo->first_fork] == 0 && !philo->i->death)
		lock(philo, philo->first_fork, fork_1);
	if (philo->i->nb_philo > 1)
	{
		if (philo->i->forks[philo->scnd_fork] == 0 && !philo->i->death)
		{
			lock(philo, philo->scnd_fork, fork_2);
			ft_print(philo, "is eating");
			philo->start_die = actual_time(philo->i->t0);
			ft_sleep(philo, philo->i->t_eat);
			unlock(philo, philo->first_fork, fork_1);
			unlock(philo, philo->scnd_fork, fork_2);
			ft_print(philo, "is sleeping");
			ft_sleep(philo, philo->i->t_sleep);
			ft_print(philo, "his thinking");
		}
		else
			ft_sleep(philo, 10);
	}
	else
		ft_sleep(philo, philo->i->t_die);
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