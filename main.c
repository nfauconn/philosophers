/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 12:12:23 by nfauconn          #+#    #+#             */
/*   Updated: 2022/04/07 16:51:36 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	data;
	t_bool	ret;

	init_data(&data);
	if ((argc == 5 || argc == 6) && parse_ok(&data, argc, argv))
	{
		if (argc == 5)
			data.nb_meals = -1;
		ret = start(&data);
		if (ret == FAILURE)
			return (FAILURE);
	}
	else
		error_arg("wrong arguments");
	return (0);
}
