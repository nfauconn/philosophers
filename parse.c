/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <nfauconn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 18:22:26 by nfauconn          #+#    #+#             */
/*   Updated: 2022/04/04 17:36:34 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	parse(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static long	fill_data(char *arg)
{
	long	data;

	data = ft_atoi(arg);
	if (data == -1)
		return (0);
	return ((int)data);
}

int	parse_ok(t_data *data, int argc, char **argv)
{
	if (!parse(argc, argv))
		return (0);
	data->number_of_philosophers = fill_data(argv[1]);
	data->time_to_die = fill_data(argv[2]);
	data->time_to_eat = fill_data(argv[3]);
	data->time_to_sleep = fill_data(argv[4]);
	if (argc == 6)
		data->number_of_times_each_philosopher_must_eat = fill_data(argv[5]);
	if (data->number_of_philosophers == 0 || data->time_to_die == 0
		|| data->time_to_eat == 0 || data->time_to_sleep == 0
		|| data->number_of_times_each_philosopher_must_eat == 0)
		return (0);
	return (1);
}
