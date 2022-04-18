/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 12:30:23 by nfauconn          #+#    #+#             */
/*   Updated: 2022/04/18 12:48:48 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	if (philo->i->nb_philo == 1)
	{
		ft_print(philo, "has taken a fork");
		ft_sleep(philo, philo->i->t_die);
		return (NULL);
	}
	while (!philo->i->death	&& (philo->nb_meals > 0 || !philo->i->is_nb_meals))
	{
		if (philo->right_handed)
			meal_loop(philo, philo->fork_neighbour, &philo->fork);
		else
			meal_loop(philo, &philo->fork, philo->fork_neighbour);
		if (philo->nb_meals == 0 && philo->i->is_nb_meals)
		{
			ft_print(philo, "is finish");
			break ;
		}
	}
	return (NULL);
}

int	create_threads(t_infos *i, t_philo *philo, pthread_t *threads)
{
	int	index;

	index = 0;
	while (index < i->nb_philo && !philo[index].right_handed)
	{
		philo[index].start_die = actual_time(i->t0);
		if (pthread_create(&threads[index], NULL, &routine, &philo[index]) != SUCCESS)
			return (FAILURE);
		pthread_mutex_lock(&i->message);
		printf("thread[%d] created\n", index);
		pthread_mutex_unlock(&i->message);
		index += 2;
	}
	usleep(1000);
	index = 1;
	while (index < i->nb_philo && philo[index].right_handed)
	{
		if (pthread_create(&threads[index], NULL, &routine, &philo[index]) != SUCCESS)
			return (FAILURE);
		pthread_mutex_lock(&i->message);
		printf("thread[%d] created\n", index);
		pthread_mutex_unlock(&i->message);
		index += 2;
	}
	if (pthread_create(&threads[i->nb_philo], NULL, &check_death, philo) != SUCCESS)
		return (FAILURE);
	return (SUCCESS);
}

int	simulation(t_infos *i, t_philo *philo, pthread_t *threads)
{
	int	index;

	index = 0;
	while (index < i->nb_philo)
	{
		printf("philo[%d].pos = %d\n", index, philo[index].pos);
		printf("philo[%d].right_handed = %d\n", index, philo[index].right_handed);
		printf("philo[%d].first_fork = %d\n", index, philo[index].first_fork);
		printf("philo[%d].scnd_fork = %d\n", index, philo[index].scnd_fork);
		printf("philo[%d].nb_meals = %d\n", index, philo[index].nb_meals);
		printf("philo[%d].death = %d\n", index, philo[index].death);
		printf("philo[%d].start_die = %llu\n", index, philo[index].start_die);
		printf("philo[%d].fork = %p\n", index, &philo[index].fork);
		printf("philo[%d].fork_neighbour = %p\n\n", index, philo[index].fork_neighbour);	
		index++;
	}
	if (create_threads(i, philo, threads) != SUCCESS)
		return (ft_error("thread creation failed"));
 	if (join_threads(i, threads) != SUCCESS)
		return (ft_error("join thread failure"));
	return (SUCCESS);
}
