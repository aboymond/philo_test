/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piow00 <piow00@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 13:00:42 by piow00            #+#    #+#             */
/*   Updated: 2022/08/05 16:22:57 by piow00           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int check_args(int argc)
{
	if (argc < 5)
	{
		printf("\033[1;31mError:\t./philo <philosophers> <die> <time to eat> <sleep>\n\033[0m");
		return (-1);
	}
	if (argc > 6)
	{
		printf("\033[1;31mError:\tTo many arguments\n\033[0m");
		return (-1);
	}
	return (0);
}
