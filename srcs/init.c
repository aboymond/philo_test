/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piow00 <piow00@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 16:17:12 by piow00            #+#    #+#             */
/*   Updated: 2022/09/02 11:57:30 by piow00           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_base(t_data *a, char **argv)
{
	a->start = 0;
	get_time_start(a);
	a->death = 0;
	a->nb_philo = ft_atoi(argv[1]);
	a->ti_die = ft_atoi(argv[2]);
	a->ti_eat = ft_atoi(argv[3]);
	a->ti_sleep = ft_atoi(argv[4]);
	a->nb_meal_arg = ft_atoi(argv[5]);
	a->now = 0;
	return (0);
}

int	init_philo(t_data *a)
{
	int	i;

	a->p = malloc(sizeof(t_philo) * a->nb_philo);
	if (!a->p)
		return (printf("Error : philo malloc failed\n"));
	i = -1;
	while (++i < a->nb_philo)
	{
		a->p[i].id = i;
		a->p[i].nb_meal = 0;
		a->p[i].last_meal = 0;
		a->p[i].data = a;
	}
	return (0);
}

int	philo(t_data *a)
{
	int	i;

	i = -1;
	get_time_start(a);
	while (++i < a->nb_philo)
		pthread_create(&a->p[i].philo, NULL, &routine, &a->p[i]);
	pthread_create(&a->checker, NULL, &check, a->p);
	i = -1;
	while (++i < a->nb_philo)
		pthread_join(a->p[i].philo, NULL);
	pthread_join(a->checker, NULL);
	// if (end(a))
	//     return (1);
	return (0);
}

int	init_mutex(t_data *a)
{
	int	i;

	i = -1;
	a->fork = malloc(sizeof(pthread_mutex_t) * a->nb_philo);
	if (!a->fork)
		return (printf("Error: malloc failled (a->fork)\n"));
	while (++i < a->nb_philo)
		if (pthread_mutex_init(&a->fork[i], NULL))
			return (printf("Error: init mutex failled\n"));
	if (pthread_mutex_init(&a->print, NULL))
		return (printf("Error: init mutex failled\n"));
	if (pthread_mutex_init(&a->check, NULL))
		return (printf("Error: init mutex failled\n"));
	return (0);
}
