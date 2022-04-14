/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <nfauconn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 16:41:11 by nfauconn          #+#    #+#             */
/*   Updated: 2022/04/14 15:57:32 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_error_arg(char *s)
{
	printf("\nERROR\n");
	printf("%s\n\n", s);
	printf("format : ./philo number_of_philosophers ");
	printf("time_to_die time_to_eat time_to_sleep ");
	printf("[number_of_times_each_philosopher_must_eat]\n\n");
	printf("Please enter positive values (max : 200 philosophers / ");
	printf("INT_MAX for other arguments)");
	printf(" so the simulation can be played\n\n");
	return (FAILURE);
}

int	ft_error(char *s)
{
	printf("\nERROR\n");
	printf("%s\n\n", s);
	return (FAILURE);
}

int	ft_error_exit(t_data *data, t_philo *philo, pthread_t *threads, char *s)
{
	printf("\nERROR\n");
	printf("%s\n\n", s);
	free_and_destroy(data, philo);
	if (threads)
	{
		join_threads(data, threads);
		free(threads);
	}
	return (FAILURE);
}
