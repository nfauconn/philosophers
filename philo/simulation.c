/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <nfauconn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 12:30:23 by nfauconn          #+#    #+#             */
/*   Updated: 2022/04/16 15:18:25 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	philo->start_die = actual_time(philo->i->t0);
	while (!philo->i->death && (philo->nb_meals > 0 || !philo->i->is_nb_meals))
	{
		if (philo->right_handed)
		{
			philo->first_fork = philo->pos + 1;
			philo->scnd_fork = philo->pos;
			if (philo->nb_meals == philo->i->nb_meals)
				ft_sleep(philo, 10);
			meal_loop(philo, philo->fork_neighbour, &philo->fork);
		}
		else
		{
			philo->first_fork = philo->pos;
			if (philo->pos == 0)
			{
				philo->scnd_fork = philo->i->nb_philo - 1;
//				printf("philo n.1 est gaucher\n");		
			}
			else
				philo->scnd_fork = philo->pos - 1;
			meal_loop(philo, &philo->fork, philo->fork_neighbour);
		}
		if (philo->death == 1)
		{
			printf("ici\n");
			philo->i->death = 1;
			break ;
		}
		philo->nb_meals--;
	}
	return (NULL);
}

int	create_threads(t_infos *i, t_philo *philo, pthread_t *threads)
{
	int	index;

	index = 0;
	while (index < i->nb_philo)
	{
		if (pthread_create(&threads[index], NULL, &routine, &philo[index]) != SUCCESS)
			return (FAILURE);
		index++;
	}
	return (SUCCESS);
}

int	simulation(t_infos *i, t_philo *philo, pthread_t *threads)
{
	if (create_threads(i, philo, threads) != SUCCESS)
		return (ft_error("thread creation failed"));
 	if (join_threads(i, threads) != SUCCESS)
		return (ft_error("join thread failure"));
	return (SUCCESS);
}
