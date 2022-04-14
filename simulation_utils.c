/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <nfauconn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 12:03:49 by nfauconn          #+#    #+#             */
/*   Updated: 2022/04/14 15:10:47 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_sleep(t_philo *philo, int time)
{
	int	i;

	i = 0;
	while (i < time && ft_get_time(philo->data->t0) - philo->t0 < (t_ull) philo->data->t_die)
	{
		usleep(1000);
		i++;
	}
	if (ft_get_time(philo->data->t0) - philo->t0 >= (t_ull) philo->data->t_die)
	{
/* 		pthread_mutex_lock(&philo->data->death_mutex);
 */		philo->data->death = 1;
		ft_print(philo, "is dead\n");
	}
}

void	ft_print(t_philo *philo, char *s)
{
	if (philo->data->print_ok)
	{
		pthread_mutex_lock(&philo->data->message);
		printf("%8llu philo %d %s\n", ft_get_time(philo->data->t0), philo->pos + 1, s);
		pthread_mutex_unlock(&philo->data->message);
	}
}
