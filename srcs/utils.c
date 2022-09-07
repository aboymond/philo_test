/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboymond <aboymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 15:54:23 by piow00            #+#    #+#             */
/*   Updated: 2022/09/05 12:45:41 by aboymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}

int	ft_atoi(const char *str)
{
	int			i;
	long int	res;
	int			negat;

	negat = 1;
	res = 0;
	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\r' || str[i] == '\f' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			negat = negat * (-1);
		i++;
	}
	while (str[i] && (ft_isdigit(str[i]) == 1))
	{
		if (res > LONG_MAX / 10)
			return (-1);
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (negat * res);
}

int	print_all(t_data *a, int num, t_philo *philo)
{
	pthread_mutex_lock(&a->print);
	a->time = get_time_now(a);
	if (a->finish == 0)
	{
		printf("time = %ld ms\tphilo id = %d\t", a->time, philo->id + 1);
		if (num == FORK_G)
			printf("has taken a fork left\t🍴\n");
		if (num == FORK_D)
			printf("has taken a fork right\t🍴\n");
		if (num == EAT)
			printf("is eating\t\t🍝\n");
		if (num == SLEEP)
			printf("is sleeping\t\t😴\n");
		if (num == THINK)
			printf("is thinking\t\t🤔\n");
		if (num == DIE)
		{
			printf("is died\t\t\t💀\n");
			a->finish = 1;
		}
	}
	pthread_mutex_unlock(&a->print);
	return (0);
}
