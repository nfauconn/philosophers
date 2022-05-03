/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_end.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 14:44:28 by user42            #+#    #+#             */
/*   Updated: 2022/04/18 14:58:28 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	is_finish(t_philo *philo)
{
	int	ret;

	ret = 0;
	pthread_mutex_lock(&philo->i->count_meals);
	if (philo->i->finish_philo == philo->i->nb_philo)
		ret = 1;
	pthread_mutex_unlock(&philo->i->count_meals);
	return (ret);
}

static int	check_death(t_philo *philo, int index, t_ull t0, t_ull t_die)
{
	t_ull	time_since_last_meal;

	pthread_mutex_lock(&philo[index].time);
	time_since_last_meal = actual_time(t0) - philo[index].last_time_eat;
	pthread_mutex_unlock(&philo[index].time);
	if (time_since_last_meal >= t_die)
	{
		pthread_mutex_lock(&philo->i->end_mutex);
		philo->i->end = 1;
		pthread_mutex_unlock(&philo->i->end_mutex);
		mutex_print(&philo[index], "is dead\n");
		return (1);
	}
	return (0);
}

int	end(t_philo *philo)
{
	int	ret;

	pthread_mutex_lock(&philo->i->end_mutex);
	ret = philo->i->end;
	pthread_mutex_unlock(&philo->i->end_mutex);
	return (ret);
}

void	*check_end(void *ptr)
{
	t_philo	*philo;
	int		index;

	philo = (t_philo *)ptr;
	index = 0;
	while (!end(philo))
	{
		if (index == philo->i->nb_philo)
			index = 0;
		if (check_death(philo, index, philo->i->t0, philo->i->t_die))
			break ;
		if (is_finish(&philo[index]))
		{
			pthread_mutex_lock(&philo->i->end_mutex);
			philo->i->end = 1;
			pthread_mutex_unlock(&philo->i->end_mutex);
			break ;
		}
		index++;
	}
	return (NULL);
}
