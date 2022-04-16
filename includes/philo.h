/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <nfauconn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 12:12:57 by nfauconn          #+#    #+#             */
/*   Updated: 2022/04/16 11:37:30 by nfauconn         ###   ########.fr       */
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

typedef struct s_data
{
	int				nb_philo;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				nb_meals;
	int				print_ok;
	int				death;
	t_ull			t0;
	pthread_mutex_t	message;
	pthread_mutex_t	nb_meas_all_philos;
 	pthread_mutex_t	death_mutex;
}	t_data;

typedef struct s_philo
{
	int					pos;
	int					nb_meals;
	int					death;
	t_data				*data;
	t_ull				start_die;
	pthread_mutex_t		fork;
	pthread_mutex_t		*fork_neighbour;
}	t_philo;

//void		*check_death(void *ptr);
t_ull		actual_time(t_ull t0);
int			create_threads(t_data *data, t_philo *philo, pthread_t *threads);
void		free_and_destroy(t_data *data, t_philo *philo);
int			ft_atoi(char *str);
int			ft_error(char *s);
int			ft_error_arg(char *s);
int			ft_error_exit(t_data *data, t_philo *philo, pthread_t *threads, char *s);
void		ft_print(t_philo *philo, char *s);
void		ft_sleep(t_philo *philo, t_ull end_sleep);
void		init_data(t_data *data);
void		init_philo(t_data *data, t_philo *philo);
int			join_threads(t_data *data, pthread_t *threads);
int			main(int argc, char **argv);
void		meal_loop(t_philo *philo);
int			parse_fill(t_data *data, int argc, char **argv);
void		*routine(void *ptr);
int			simulation(t_data *data, t_philo *philo, pthread_t *threads);

#endif