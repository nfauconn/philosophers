/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <nfauconn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 12:12:57 by nfauconn          #+#    #+#             */
/*   Updated: 2022/04/21 16:59:41 by nfauconn         ###   ########.fr       */
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
	int				finish_philo;
	int				print_ok;
	int				end;
	t_ull			t0;
	pthread_mutex_t	message;
	pthread_mutex_t	authorize_print_mutex;
	pthread_mutex_t	count_meals;
	pthread_mutex_t	end_mutex;
}	t_infos;

typedef struct s_philo
{
	int					pos;

	int					right_handed;
	int					nb_meals;
	t_infos				*i;
	t_ull				last_time_eat;
	pthread_mutex_t		meal_count;
	pthread_mutex_t		fork;
	pthread_mutex_t		*fork_neighbour;
	pthread_mutex_t		time;
}	t_philo;

int		all_finish(t_philo *philo);
t_ull	actual_time(t_ull t0);
void	*check_end(void *ptr);
int		create_threads(t_infos *i, t_philo *philo, pthread_t *threads);
int		end(t_philo *philo);
void	free_and_destroy(t_infos *i, t_philo *philo);
int		ft_atoi(char *str);
void	ft_eat(t_philo *philo);
int		ft_error(char *s);
int		ft_error_arg(char *s);
int		ft_error_exit(t_infos *i, t_philo *philo, pthread_t *threads, char *s);
void	ft_milli_sleep(t_philo *philo, t_ull end_sleep);
void	ft_sleep(t_philo *philo);
void	ft_think(t_philo *philo);
void	init_infos(t_infos *i);
void	init_philo(t_infos *i, t_philo *philo);
int		join_threads(t_infos *i, pthread_t *threads);
void	lock(t_philo *philo, pthread_mutex_t *fork);
int		main(int argc, char **argv);
void	meal_loop(t_philo *philo, pthread_mutex_t *f1, pthread_mutex_t *f2);
void	mutex_print(t_philo *philo, char *s);
int		parse_fill(t_infos *i, int argc, char **argv);
void	*routine(void *ptr);
int		simulation(t_infos *i, t_philo *philo, pthread_t *threads);
void	unlock(pthread_mutex_t *fork);

#endif