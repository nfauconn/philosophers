/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_sleep_think.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 14:45:58 by user42            #+#    #+#             */
/*   Updated: 2022/04/18 14:58:28 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_milli_sleep(t_philo *philo, t_ull end_sleep)
{
	t_ull	t0;

	t0 = philo->i->t0;
	end_sleep += actual_time(t0);
	while (!philo->i->death && actual_time(t0) < end_sleep) 
		usleep(1000);
}

void	ft_eat(t_philo *philo)
{
	philo->start_die = actual_time(philo->i->t0);
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
	usleep(200);
}
