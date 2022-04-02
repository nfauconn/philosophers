/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <nfauconn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 12:23:38 by nfauconn          #+#    #+#             */
/*   Updated: 2022/04/02 17:22:13 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

pthread_mutex_t	mutex;

static void	display(char **argv, t_data *data)
{
	printf("\n");
	printf("           number_of_philosophers & forks = %10s | %zu\n", argv[1], data->number_of_philosophers);
	printf("                              time_to_die = %10s | %zu ms\n", argv[2], data->time_to_die);
	printf("                              time_to_eat = %10s | %zu ms\n", argv[3], data->time_to_eat);
	printf("                            time_to_sleep = %10s | %zu ms\n", argv[4], data->time_to_sleep);
	if (data->is_number_of_times == true)
		printf("number_of_times_each_philosopher_must_eat = %10s | %zu\n", argv[5], data->number_of_times_each_philosopher_must_eat);
	printf("\n\n");
}

static void	*routine()
{
	int	i;

	i = 0;
	while (i < 100)
	{
		pthread_mutex_lock(&mutex);
		printf("%d\n", i);
		i++;
		pthread_mutex_unlock(&mutex);
	}
	return (NULL);
}

int	start(t_data *data, char **argv)
{
	size_t			i;
	pthread_t	philo[200];

	i = 0;
	display(argv, data);
	pthread_mutex_init(&mutex, NULL);
	while (i < data->number_of_philosophers)
	{
		if (pthread_create(&philo[i], NULL, &routine, NULL))
			printf("failed to create thread\n");
		printf("thread %zu has started \n", i);
		i++;
	}
	i = 0;
	while (i < data->number_of_philosophers)
	{
		if (pthread_join(philo[i], NULL))
			printf("failed to join thread\n");
		printf("thread %zu has finished \n", i);
		i++;
	}
	pthread_mutex_destroy(&mutex);	
	return (0);
}
