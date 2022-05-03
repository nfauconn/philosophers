/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <nfauconn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 12:03:49 by nfauconn          #+#    #+#             */
/*   Updated: 2022/04/21 14:49:36 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	unauthorize_print(t_infos *i)
{
	pthread_mutex_lock(&i->authorize_print_mutex);
	i->print_ok = 0;
	pthread_mutex_unlock(&i->authorize_print_mutex);
}

static int	is_print_ok(t_infos *i)
{
	int	ret;

	pthread_mutex_lock(&i->authorize_print_mutex);
	ret = i->print_ok;
	pthread_mutex_unlock(&i->authorize_print_mutex);
	return (ret);
}

void	mutex_print(t_philo *philo, char *s)
{
	if (end(philo))
	{
		pthread_mutex_lock(&philo->i->message);
		if (is_print_ok(philo->i))
		{
			printf("%8llu philo", actual_time(philo->i->t0));
			printf(" %d %s\n", philo->pos + 1, s);
		}
		unauthorize_print(philo->i);
		pthread_mutex_unlock(&philo->i->message);
	}
	if (!end(philo))
	{
		pthread_mutex_lock(&philo->i->message);
		if (!end(philo) && is_print_ok(philo->i))
		{
			printf("%8llu philo", actual_time(philo->i->t0));
			printf(" %d %s\n", philo->pos + 1, s);
		}
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
