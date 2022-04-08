/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 12:12:57 by nfauconn          #+#    #+#             */
/*   Updated: 2022/04/08 18:05:14 by user42           ###   ########.fr       */
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
	FAILURE = 1,
	SUCCESS = 0
}	t_bool;

typedef struct s_philo
{
	int				pos;
	pthread_mutex_t	fork_l;
	pthread_mutex_t	fork_r;
//	pthread_mutex_t	message;
}	t_philo;

typedef struct s_data
{
	int		nb_philo;
	int		t_die;
	int		t_eat;
	int		t_sleep;
	int		nb_meals;
}	t_data;

int			create_threads(t_data data, t_philo *philo, pthread_t *threads);
void		error_arg(char *s);
void		free_and_destroy(t_philo *philo);
int			ft_atoi(char *str);
void		init_data(t_data *data);
void		init_philo(t_data data, t_philo *philo);
int			join_threads(t_data data, t_philo *philo, pthread_t *threads);
int			main(int argc, char **argv);
int			parse_fill(t_data *data, int argc, char **argv);
void		*routine(void *ptr);
int			simulation(t_data data, t_philo *philo);

#endif