/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboymond <aboymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 16:56:11 by piow00            #+#    #+#             */
/*   Updated: 2022/09/05 12:12:34 by aboymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	get_time_start(t_data *data)
{
	struct timeval	ti;

	gettimeofday(&ti, NULL);
	data->start = (ti.tv_sec * 1000 + ti.tv_usec / 1000);
}

int	get_time_now(t_data *data)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	data->now = (t.tv_sec * 1000 + t.tv_usec / 1000);
	return (data->now - data->start);
}

void	ft_usleep(t_data *a, long time)
{
	long	i;

	i = get_time_now(a);
	while (!a->finish)
	{
		if (get_time_now(a) - i >= time)
			break ;
	}
}
