/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboymond <aboymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 12:48:46 by piow00            #+#    #+#             */
/*   Updated: 2022/08/31 19:55:03 by aboymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <limits.h>
#include <sys/time.h>

#define	RD	\033[1;31m
#define	GN	\033[1;32m
#define	ED	\033[0m
#define FORK_G	-1
#define FORK_D	0
#define EAT		1
#define SLEEP	2
#define THINK	3
#define DIE		4

typedef struct s_philo
{
	pthread_t			philo;
	int					id;
	int					nb_meal;
	long				last_meal;
	struct s_data		*data;
	
}	t_philo;

typedef struct s_data
{
	pthread_mutex_t		*fork;
	pthread_mutex_t		print;
	pthread_mutex_t		check;
	pthread_t			checker;
	
	int					nb;\
	int					nb_philo;
	int					ti_eat;
	int					ti_die;
	int					ti_sleep;
	int					think;
	long				start;
	size_t				now;
	int					death;
	long				time;
	t_philo				*p;
}	t_data;



int		check_args(int argc);
int		compt_philo_time(char **argv);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
int		print_all(t_data *a, int num, t_philo *philo);
int		init_mutex(t_data *a);
void 	get_time_start(t_data *data);
int 	get_time_now(t_data *data);
int     init_philo(t_data *a);
int    init_base(t_data *a, char **argv);
void	ft_usleep(t_data *a, long time);
void	e_error();
int		philo_sleep(t_data *a, t_philo *philo);
int		eat(t_data *a, t_philo *philo);
void	*routine(void *arg);
void	detach_philo(t_data *a);
int		forks(t_data *a, t_philo *philo);
int		philo(t_data *a);
void	*check(void *arg);

#endif