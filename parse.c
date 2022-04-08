/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <nfauconn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 18:22:26 by nfauconn          #+#    #+#             */
/*   Updated: 2022/04/08 10:59:07 by nfauconn         ###   ########.fr       */
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

int	parse_fill(t_data *data, int argc, char **argv)
{
	if (!parse(argc, argv))
		return (0);
	data->nb_philo = fill_data(argv[1]);
	data->t_die = fill_data(argv[2]);
	data->t_eat = fill_data(argv[3]);
	data->t_sleep = fill_data(argv[4]);
	if (argc == 6)
		data->nb_meals = fill_data(argv[5]);
	if (data->nb_philo == 0 || data->t_die == 0
		|| data->t_eat == 0 || data->t_sleep == 0
		|| data->nb_meals == 0)
		return (FAILURE);
	return (SUCCESS);
}
