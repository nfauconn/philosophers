/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <nfauconn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 16:41:11 by nfauconn          #+#    #+#             */
/*   Updated: 2022/04/02 11:55:21 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	error_arg(char *s)
{
	printf("\nERROR\n");
	printf("%s\n\n", s);
	printf("format : ./philo number_of_philosophers ");
	printf("time_to_die time_to_eat time_to_sleep ");
	printf("[number_of_times_each_philosopher_must_eat]\n\n");
	printf("Please enter positive values (max : UINT_MAX)");
	printf(" so the simulation can be played\n\n");
}
