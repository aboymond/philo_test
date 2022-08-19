/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piow00 <piow00@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 12:48:46 by piow00            #+#    #+#             */
/*   Updated: 2022/08/19 17:14:15 by piow00           ###   ########.fr       */
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

// typedef struct s_philo
// {
// }	t_philo;

typedef struct s_data
{
	pthread_mutex_t		*fork;
	pthread_mutex_t		print;
	pthread_t			*philo;
	
	int					id;
	int					nb_philo;
	int					ti_eat;
	int					ti_die;
	int					ti_sleep;
	int					think;
	long				start;
	long				now;
	int					death;
	//t_philo				*p;
}	t_data;



int		check_args(int argc);
int		compt_philo_time(char **argv);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
void	*print_all(int num, t_data *a);
void 	get_time_start(t_data *data);
int 	get_time_now(t_data *data);
int     init_philo(t_data *a);
void    init_base(t_data *a, char **argv);
void	ft_usleep(t_data *a, long time);
void	e_error();

#endif