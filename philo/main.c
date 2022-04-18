/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 12:12:23 by nfauconn          #+#    #+#             */
/*   Updated: 2022/04/18 14:30:40 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_infos		i;
	t_philo		*philo;
	pthread_t	*threads;

	init_infos(&i);
	if (argc < 5 || argc > 6 || parse_fill(&i, argc, argv) == FAILURE)
		return (FAILURE);
	philo = (t_philo *)malloc(sizeof(t_philo) * i.nb_philo);
	if (!philo)
		return (ft_error("philo * malloc failure"));
/* 	i.forks = (int *)malloc(sizeof (int));
	if (!i.forks)
	{
		free(philo);
		return (ft_error("malloc failure"));
	}
	memset(i.forks, '0', i.nb_philo);
	printf("forks[3] = %d\n", i.forks[3]); */
	init_philo(&i, philo);
	threads = (pthread_t *)malloc(sizeof(pthread_t) * (i.nb_philo + 1));
	if (!threads)
		return (ft_error_exit(&i, philo, threads, "thread mem alloc failed"));
	if (simulation(&i, philo, threads) == FAILURE)
		return (FAILURE);
	free_and_destroy(&i, philo);
	free(threads);
	return (SUCCESS);
}
