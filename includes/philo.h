/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <nfauconn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 12:12:57 by nfauconn          #+#    #+#             */
/*   Updated: 2022/04/16 12:22:14 by nfauconn         ###   ########.fr       */
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

typedef struct s_infos
{
	int				nb_philo;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				nb_meals;
	int				is_nb_meals;
	int				print_ok;
	int				death;
	t_ull			t0;
	pthread_mutex_t	message;
 	pthread_mutex_t	death_mutex;
}	t_infos;

typedef struct s_philo
{
	int					pos;
	int					nb_meals;
	int					death;
	t_infos				*i;
	t_ull				start_die;
	pthread_mutex_t		fork;
	pthread_mutex_t		*fork_neighbour;
}	t_philo;

t_ull		actual_time(t_ull t0);
int			create_threads(t_infos *i, t_philo *philo, pthread_t *threads);
void		free_and_destroy(t_infos *i, t_philo *philo);
int			ft_atoi(char *str);
int			ft_error(char *s);
int			ft_error_arg(char *s);
int			ft_error_exit(t_infos *i, t_philo *philo, pthread_t *threads, char *s);
void		ft_print(t_philo *philo, char *s);
void		ft_sleep(t_philo *philo, t_ull end_sleep);
void		init_infos(t_infos *i);
void		init_philo(t_infos *i, t_philo *philo);
int			join_threads(t_infos *i, pthread_t *threads);
int			main(int argc, char **argv);
void		meal_loop(t_philo *philo);
int			parse_fill(t_infos *i, int argc, char **argv);
void		*routine(void *ptr);
int			simulation(t_infos *i, t_philo *philo, pthread_t *threads);

#endif