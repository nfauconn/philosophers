/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meal_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <nfauconn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:26:04 by nfauconn          #+#    #+#             */
/*   Updated: 2022/04/14 16:29:58 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	eat(t_philo * philo, int right, int left)
{
	if (pthread_mutex_lock(&philo->data->forks[left]) == SUCCESS)
	{
		ft_print(philo, "takes his fork");
		if (philo->data->nb_philo > 1)
		{
			pthread_mutex_lock(&philo->data->forks[right]);
			ft_print(philo, "takes his neighbour's fork");
			philo->t0 = ft_get_time(philo->data->t0);
			ft_print(philo, "is eating");
			ft_sleep(philo, philo->data->t_eat);
			pthread_mutex_unlock(&philo->data->forks[left]);
			pthread_mutex_unlock(&philo->data->forks[right]);
		}
		else
		{
			// printf("unlock\n");
			pthread_mutex_unlock(&philo->data->forks[left]);
			return (FAILURE);
		}
	}
	else
	{
		return (FAILURE);
	}
	return (SUCCESS);
}

void	meal_loop(t_philo *philo, int right_fork, int left_fork)
{
	while (1)
	{
		if (eat(philo, right_fork, left_fork) == SUCCESS && philo->data->print_ok)
		{
			ft_print(philo, "is sleeping");
			ft_sleep(philo, philo->data->t_sleep);
			ft_print(philo, "his thinking");
			return ;
		}
		else
		{
			ft_sleep(philo, 10);
		}
	}
}
