/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <nfauconn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 12:12:57 by nfauconn          #+#    #+#             */
/*   Updated: 2022/04/06 17:50:34 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stddef.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

typedef unsigned long long	t_ull;

typedef enum s_bool
{
	true = 1,
	false = 0
}	t_bool;

typedef struct s_philo
{
	int				pos;
	pthread_mutex_t	fork;
}	t_philo;

typedef struct s_data
{
	int		number_of_philosophers;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	t_bool	is_number_of_times;
	int		number_of_times_each_philosopher_must_eat;
}	t_data;

void		error_arg(char *s);
int			ft_atoi(char *str);
void		init_data(t_data *data);
void		init_philo(t_philo *philo, int i);
int			main(int argc, char **argv);
int			parse_ok(t_data *data, int argc, char **argv);
int			start(t_data *data);

#endif