/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <nfauconn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 12:12:23 by nfauconn          #+#    #+#             */
/*   Updated: 2022/04/16 12:13:42 by nfauconn         ###   ########.fr       */
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
		return (ft_error("malloc failure"));
	init_philo(&i, philo);
	threads = (pthread_t *)malloc(sizeof(pthread_t) * (i.nb_philo));
	if (!threads)
		return (ft_error_exit(&i, philo, threads, "thread mem alloc failed"));
	if (simulation(&i, philo, threads) == FAILURE)
		return (FAILURE);
	free_and_destroy(&i, philo);
	free(threads);
	return (SUCCESS);
}
