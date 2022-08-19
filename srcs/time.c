/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piow00 <piow00@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 16:56:11 by piow00            #+#    #+#             */
/*   Updated: 2022/08/18 16:50:33 by piow00           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void get_time_start(t_data *data)
{
    struct timeval ti;
    
    gettimeofday(&ti, NULL);
    data->start = ti.tv_sec * 1000 + ti.tv_usec / 1000;
}

int get_time_now(t_data *data)
{
    struct timeval ti;
    
    gettimeofday(&ti, NULL);
    data->now = ti.tv_sec * 1000 + ti.tv_usec / 1000;
    return (data->now - data->start);
}


void	ft_usleep(t_data *a, long time)
{
	long	i;
	
	i = get_time_now(a);
	while (!a->death)
	{
		if (get_time_now(a) - i >= time)
			break;
		//usleep(10);
	}
}