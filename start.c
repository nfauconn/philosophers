/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 12:23:38 by nfauconn          #+#    #+#             */
/*   Updated: 2022/04/07 17:21:34 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* static void	display(char **argv, t_data *data)
{
	printf("\n");
	printf("           nb_philo & forks = %10s | %d\n", argv[1], data->nb_philo);
	printf("                              t_die = %10s | %d ms\n", argv[2], data->t_die);
	printf("                              t_eat = %10s | %d ms\n", argv[3], data->t_eat);
	printf("                            t_sleep = %10s | %d ms\n", argv[4], data->t_sleep);
	if (data->is_nb_meals == true)
		printf("nb_meals = %10s | %d\n", argv[5], data->nb_meals);
	printf("\n\n");
} */

int				forks[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

void	*routine(void *ptr)
{
	t_philo	philo;

	philo = *(t_philo *)ptr;
	pthread_mutex_lock(&philo.fork);
	printf("philo %d takes a fork\n", philo.pos);
	pthread_mutex_unlock(&philo.fork);
	return (NULL);
}

int	start(t_data *data)
{
	t_philo		*philo;
	pthread_t	*threads;

	philo = (t_philo *)malloc(sizeof(t_philo) * data->nb_philo);
	threads = (pthread_t *)malloc(sizeof(pthread_t) * data->nb_philo);
	if (!philo || !threads)
		return (FAILURE);
	init_philo(data, &philo);
	if (create_threads(data, &philo, &threads) == FAILURE)
		return (FAILURE);
	if (join_threads(data, &philo, &threads) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
