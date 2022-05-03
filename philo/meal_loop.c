/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meal_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <nfauconn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:26:04 by nfauconn          #+#    #+#             */
/*   Updated: 2022/04/21 15:03:33 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	lock(t_philo *philo, pthread_mutex_t *fork)
{
	pthread_mutex_lock(fork);
	mutex_print(philo, "has taken a fork");
}

void	unlock(pthread_mutex_t *fork)
{
	pthread_mutex_unlock(fork);
}

static void	drop_forks(t_philo *p, pthread_mutex_t *f1, pthread_mutex_t *f2)
{
	unlock(f1);
	unlock(f2);
	pthread_mutex_lock(&p->meal_count);
	if (p->nb_meals > 0)
		p->nb_meals--;
	if (p->nb_meals == 0)
	{
		pthread_mutex_lock(&p->i->count_meals);
		p->i->finish_philo++;
		pthread_mutex_unlock(&p->i->count_meals);
	}
	pthread_mutex_unlock(&p->meal_count);
}

void	meal_loop(t_philo *philo, pthread_mutex_t *f1, pthread_mutex_t *f2)
{
	while (!end(philo))
	{
		lock(philo, f1);
		if (end(philo))
		{
			unlock(f1);
			return ;
		}
		lock(philo, f2);
		if (end(philo))
		{
			unlock(f1);
			unlock(f2);
			return ;
		}
		ft_eat(philo);
		drop_forks(philo, f1, f2);
		if (end(philo))
			return ;
		ft_sleep(philo);
		if (end(philo))
			return ;
		ft_think(philo);
	}
}
