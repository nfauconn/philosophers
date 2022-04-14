/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <nfauconn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 12:12:23 by nfauconn          #+#    #+#             */
/*   Updated: 2022/04/14 17:51:54 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data		data;
	t_philo		*philo;
	pthread_t	*threads;

	init_data(&data);
	if (argc < 5 || argc > 6 || parse_fill(&data, argc, argv) == FAILURE)
		return (FAILURE);
	philo = (t_philo *)malloc(sizeof(t_philo) * data.nb_philo);
	if (!philo)
		return (ft_error("malloc failure"));
	init_philo(&data, philo);
	threads = (pthread_t *)malloc(sizeof(pthread_t) * (data.nb_philo + 1));
	if (!threads)
		return (ft_error_exit(&data, philo, threads, "thread mem alloc failed"));
	if (simulation(&data, philo, threads) == FAILURE)
		return (ft_error_exit(&data, philo, threads, "simulation failure"));
	free_and_destroy(&data, philo);
	free(threads);
	return (SUCCESS);
}
