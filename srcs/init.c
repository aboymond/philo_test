/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piow00 <piow00@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 16:17:12 by piow00            #+#    #+#             */
/*   Updated: 2022/08/19 17:16:49 by piow00           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    init_base(t_data *a, char **argv)
{
	
	//a = malloc(sizeof(t_data));
    a->nb_philo = ft_atoi(argv[1]);
    a->ti_die = ft_atoi(argv[2]);
    a->ti_eat = ft_atoi(argv[3]);
    a->ti_sleep = ft_atoi(argv[4]);
	a->id = 1;
	a->philo = calloc(a->nb_philo, sizeof(pthread_t));
	pthread_mutex_init(&a->print, 0);
	get_time_start(a);
}

int     init_philo(t_data *a)
{
    int i = 0;
	pthread_create(a->philo + i, 0, print_all(0, a), 0);
	i++;
	pthread_create(a->philo + i, 0, print_all(0, a), 0);
	i++;
	pthread_create(a->philo + i, 0, print_all(0, a), 0);
	i++;
	pthread_create(a->philo + i, 0, print_all(0, a), 0);
	i++;
	pthread_create(a->philo + i, 0, print_all(0, a), 0);


    //printf("nb de philo = %d\n", a->nb_philo);
	// while(++i < a->nb_philo)
	// {
	// 	if(pthread_create(a->p->philo + i, 0, print_all(0, a), 0) != 0)
    //     {
	// 		perror("Failed to create thread");
	// 		return(1);
    //     }
	//     printf("Thread %d has started\n", i + 1);
	// }
    i = -1;
    while(++i < a->nb_philo)
	{
		if (pthread_join(a->philo[i], NULL) != 0)
			return (2);
		printf("Thread %d has finished\n", i);
	}
	pthread_mutex_destroy(&a->print);
	return (0);
}