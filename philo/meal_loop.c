/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meal_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:26:04 by nfauconn          #+#    #+#             */
/*   Updated: 2022/04/18 17:52:59 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* void	lock(t_philo *philo, int index, pthread_mutex_t *fork)
{
	pthread_mutex_lock(fork);
	philo->i->forks[index] = 1;
	pthread_mutex_unlock(fork);
	mutex_print(philo, "has taken a fork");
}

static void	unlock(t_philo *philo, int index, pthread_mutex_t *fork)
{
	pthread_mutex_lock(fork);
	philo->i->forks[index] = 0;
	pthread_mutex_unlock(fork);
}

void	meal_loop(t_philo *philo, pthread_mutex_t *fork_1, pthread_mutex_t *fork_2)
{
	if (philo->i->forks[philo->first_fork] == 0)
	{
		lock(philo, philo->first_fork, fork_1);
		if (philo->i->forks[philo->scnd_fork] == 0)
		{
			lock(philo, philo->scnd_fork, fork_2);
			ft_eat(philo);
			unlock(philo, philo->first_fork, fork_1);
			unlock(philo, philo->scnd_fork, fork_2);
			if (philo->i->is_nb_meals)
				philo->nb_meals--;
			ft_sleep(philo);
			ft_think(philo);
		}
	}
} */

void	meal_loop(t_philo *philo, pthread_mutex_t *fork_1, pthread_mutex_t *fork_2)
{
	while (!philo->i->end	&& (philo->nb_meals > 0 || !philo->i->is_nb_meals))
	{
		pthread_mutex_lock(fork_1);
		mutex_print(philo, "has taken a fork");
		if (philo->i->end)
			break ;
		pthread_mutex_lock(fork_2);
		mutex_print(philo, "has taken a fork");
		if (philo->i->end)
			break ;
		ft_eat(philo);
		pthread_mutex_unlock(&philo->fork);
		pthread_mutex_unlock(philo->fork_neighbour);
		if (philo->i->is_nb_meals)
			philo->nb_meals--;
		if (philo->i->end)
			break ;
		ft_sleep(philo);
		if (philo->i->end)
			break ;
		ft_think(philo);
	}
}
