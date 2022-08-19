/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piow00 <piow00@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 15:54:23 by piow00            #+#    #+#             */
/*   Updated: 2022/08/19 17:15:30 by piow00           ###   ########.fr       */
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


void	*print_all(int num, t_data *a)
{
	//ft_usleep(a, 100);
	pthread_mutex_lock(&a->print);
	printf("time = %d ms\tid = %d\t", get_time_now(a), a->id);
	if (num == 0)
		printf("has taken a fork\t🍴\n");
	if (num == 1)
		printf("is eating\t\t🍝\n");
	if (num == 2)
		printf("is sleeping\t\t😴\n");
	if (num == 3)
		printf("is thinking\t\t🤔\n");
	if (num == 4)
		printf("is died\t\t\t💀\n");
	pthread_mutex_unlock(&a->print);
	return (0);
}