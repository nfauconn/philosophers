/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <nfauconn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 18:22:26 by nfauconn          #+#    #+#             */
/*   Updated: 2022/04/21 13:11:28 by nfauconn         ###   ########.fr       */
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
				return (FAILURE);
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

static long	fill_i(char *arg)
{
	long	i;

	i = ft_atoi(arg);
	if (i == -1)
		return (0);
	return ((int)i);
}

int	parse_fill(t_infos *i, int argc, char **argv)
{
	if (parse(argc, argv) == FAILURE)
		return (ft_error_arg("wrong arguments"));
	i->nb_philo = fill_i(argv[1]);
	i->t_die = fill_i(argv[2]);
	i->t_eat = fill_i(argv[3]);
	i->t_sleep = fill_i(argv[4]);
	if (argc == 6)
		i->nb_meals = fill_i(argv[5]);
	if (i->nb_philo == 0 || i->t_die == 0
		|| i->t_eat == 0 || i->t_sleep == 0
		|| i->nb_meals == 0)
		return (ft_error_arg("wrong arguments"));
	return (SUCCESS);
}
