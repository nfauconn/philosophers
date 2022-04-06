/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <nfauconn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 12:23:38 by nfauconn          #+#    #+#             */
/*   Updated: 2022/04/06 18:06:49 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* static void	display(char **argv, t_data *data)
{
	printf("\n");
	printf("           number_of_philosophers & forks = %10s | %d\n", argv[1], data->number_of_philosophers);
	printf("                              time_to_die = %10s | %d ms\n", argv[2], data->time_to_die);
	printf("                              time_to_eat = %10s | %d ms\n", argv[3], data->time_to_eat);
	printf("                            time_to_sleep = %10s | %d ms\n", argv[4], data->time_to_sleep);
	if (data->is_number_of_times == true)
		printf("number_of_times_each_philosopher_must_eat = %10s | %d\n", argv[5], data->number_of_times_each_philosopher_must_eat);
	printf("\n\n");
} */

int				forks[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

static void	*routine(void *ptr)
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
	int			i;
	t_philo		**philo;			//	int			*philo_numero_addr;
	pthread_t	*thread;

	philo = (t_philo *)malloc(sizeof(t_philo) * data->number_of_philosophers);
	thread = (pthread_t *)malloc(sizeof(pthread_t) * data->number_of_philosophers);
//	create_threads(data, data->number_of_philosophers);
	i = 0;
	while (i < data->number_of_philosophers)
	{
		init_philo(&philo[i], i);
		if (pthread_create(&thread[i], NULL, &routine, (void*)&philo[i]))
			printf("failed to create thread\n"); //ERROR -->quitter
		printf("thread %d has started \n", i);
		i++;
	}
	i = 0;
	while (i < data->number_of_philosophers)
	{
		if (pthread_join(thread[i], NULL))
			printf("failed to join thread\n"); //ERROR-->quitter
		printf("thread %d has finished \n", i);
		i++;
	}
	i = 0;
	while (i < data->number_of_philosophers)
	{
		pthread_mutex_destroy(&philo[i].fork);
		i++;
	}
	return (0);
}
