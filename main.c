/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 12:12:23 by nfauconn          #+#    #+#             */
/*   Updated: 2022/04/08 18:02:29 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data		data;
	t_philo		*philo;

	init_data(&data);
	if (argc < 5 || argc > 6 || parse_fill(&data, argc, argv) == FAILURE)
	{
		error_arg("wrong arguments");
		return (FAILURE);
	}
	philo = (t_philo *)malloc(sizeof(t_philo) * (data.nb_philo + 1));
	if (!philo)
		return (FAILURE);
	init_philo(data, philo);
/* 	if (!philo)
		return (FAILURE); */
	if (simulation(data, philo) == FAILURE)
		return (FAILURE);
	free_and_destroy(philo);
	return (SUCCESS);
}
