/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_sleep_think.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <nfauconn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 14:45:58 by user42            #+#    #+#             */
/*   Updated: 2022/04/21 15:02:34 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_milli_sleep(t_philo *philo, t_ull end_sleep)
{
	t_ull	t0;

	t0 = philo->i->t0;
	end_sleep += actual_time(t0);
	while (!end(philo) && actual_time(t0) < end_sleep)
		usleep(1000);
}

void	ft_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->time);
	philo->last_time_eat = actual_time(philo->i->t0);
	pthread_mutex_unlock(&philo->time);
	mutex_print(philo, "is eating");
	ft_milli_sleep(philo, philo->i->t_eat);
}

void	ft_sleep(t_philo *philo)
{
	mutex_print(philo, "is sleeping");
	ft_milli_sleep(philo, philo->i->t_sleep);
}

void	ft_think(t_philo *philo)
{
	mutex_print(philo, "is thinking");
	ft_milli_sleep(philo, 1);
}
