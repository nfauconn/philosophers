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

void	*check_end(void *ptr)
{
	t_philo	*philo;
	int		nb_philo;
	t_ull	t0;
	t_ull	t_die;
	int		index;
	int		count;

	philo = (t_philo *)ptr;
	nb_philo = philo[0].i->nb_philo;
	t0 = philo[0].i->t0;
	t_die = (t_ull)philo[0].i->t_die;
	index = 0;
	count = 0;
	while (!philo->i->end)
	{
		if (index == nb_philo)
			index = 0;
		if (actual_time(t0) - philo[index].start_die >= t_die)
		{
			pthread_mutex_lock(&philo->i->end_mutex);
			philo->i->end = 1;
			pthread_mutex_unlock(&philo->i->end_mutex);
			mutex_print(&philo[index], "is dead\n");
			break ;
		}
		if (philo->i->is_nb_meals && philo[index].nb_meals == philo->i->nb_meals)
		{
			pthread_mutex_lock(&philo->i->count_meals);
			count++;
			if (count == philo->i->nb_philo && !philo->i->end)
			{
				pthread_mutex_lock(&philo->i->end_mutex);
				write(1, "end\n", 4);
				philo->i->end = 1;
				pthread_mutex_unlock(&philo->i->end_mutex);
			}
			pthread_mutex_unlock(&philo->i->count_meals);
			break ;
		}
		index++;
	}
	return (NULL);
}