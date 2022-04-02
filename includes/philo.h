/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <nfauconn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 12:12:57 by nfauconn          #+#    #+#             */
/*   Updated: 2022/04/02 15:18:19 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdint.h>
# include <pthread.h>

typedef unsigned long long	t_ull;

typedef enum s_bool
{
	true = 1,
	false = 0
}	t_bool;

typedef struct s_data
{
	size_t	number_of_philosophers;
	size_t	time_to_die;
	size_t	time_to_eat;
	size_t	time_to_sleep;
	t_bool	is_number_of_times;
	size_t	number_of_times_each_philosopher_must_eat;
}	t_data;

void			error_arg(char *s);
long long		ft_atoll(char *str);
void			init_data(t_data *data);
int				main(int argc, char **argv);
int				parse_ok(t_data *data, int argc, char **argv);
int				start(t_data *data, char **argv);

#endif