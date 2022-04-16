/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <nfauconn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 12:03:49 by nfauconn          #+#    #+#             */
/*   Updated: 2022/04/16 12:10:48 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_sleep(t_philo *philo, t_ull end_sleep)
{
	t_ull	t0;

	t0 = philo->i->t0;
	end_sleep += actual_time(t0);
	while (actual_time(t0) < end_sleep 
		&& actual_time(t0) - philo->start_die < (t_ull)philo->i->t_die)
		usleep(1000);
	if (actual_time(t0) - philo->start_die >= (t_ull) philo->i->t_die)
	{
		pthread_mutex_lock(&philo->i->death_mutex);
		philo->i->death = 1;
		ft_print(philo, "is dead\n");
	}
}

void	ft_print(t_philo *philo, char *s)
{
	if (philo->i->death == 0)
	{
		pthread_mutex_lock(&philo->i->message);
		printf("%8llu philo %d %s\n", actual_time(philo->i->t0), philo->pos + 1, s);
		pthread_mutex_unlock(&philo->i->message);
	}
	else if (philo->i->death == 1 && philo->i->print_ok)
	{
		pthread_mutex_lock(&philo->i->message);
		printf("%8llu philo %d is dead\n", actual_time(philo->i->t0), philo->pos + 1);
		philo->i->print_ok = 0;
		pthread_mutex_unlock(&philo->i->death_mutex);
		pthread_mutex_unlock(&philo->i->message);
	}
}

t_ull	actual_time(t_ull t0)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000 + t.tv_usec / 1000) - t0);
}

int	ft_atoi(char *str)
{
	int		i;
	t_ull	nb;

	i = 0;
	nb = 0;
	while (*str)
	{
		nb = nb * 10 + *str - 48;
		str++;
	}
	if (nb > 2147483647)
		return (-1);
	return (nb);
}
