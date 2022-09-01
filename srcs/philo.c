/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboymond <aboymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 14:35:37 by piow00            #+#    #+#             */
/*   Updated: 2022/09/01 16:26:33 by aboymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_sleep(t_data *a, t_philo *philo)
{
	print_all(a, SLEEP, philo);
	ft_usleep(a, a->ti_sleep);
	print_all(a, THINK, philo);
	return (0);
}

int	eat(t_data *a, t_philo *philo)
{
	//ft_usleep(a, 200);
	print_all(a, EAT, philo);
	philo->last_meal = get_time_now(a);
	ft_usleep(a, a->ti_eat);
	return (0);
}

int	forks(t_data *a, t_philo *philo)
{
	//ft_usleep(a, 200);
	pthread_mutex_lock(&a->fork[(philo->id) % a->nb_philo]);
	print_all(a, FORK_G, philo);
	if (a->nb_philo == 1)
	{
		(pthread_mutex_unlock(&a->fork[(philo->id) % a->nb_philo]));
		return (1);
	}
	pthread_mutex_lock(&a->fork[(philo->id - 1) % a->nb_philo]);
	print_all(a, FORK_D, philo);
	eat(a, philo);
	pthread_mutex_unlock(&a->fork[(philo->id) % a->nb_philo]);
	pthread_mutex_unlock(&a->fork[(philo->id - 1) % a->nb_philo]);
	return (0);
}

void	*routine(void *arg)
{
	t_philo		*philo;
	t_data		*a;

	philo = arg;
	a = philo->data;
	if (philo->id % 2 != 0)
		ft_usleep(a, a->ti_sleep);
	while (/*a->enough < a->nb_philo && !a->death*/1)
	{
		if (forks(a, philo))
			break ;
		philo_sleep(a, philo);
	}
	return (NULL);
}

void	*check(void *arg)
{
	t_philo	*philo;
	t_data	*b;
	int		i;

	i = 0;
	philo = arg;
	b = philo->data;
	while (1)
	{
		if (get_time_now(b) - b->p[i].last_meal >= b->ti_die)
			print_all(b, DIE, philo);
	}
}
