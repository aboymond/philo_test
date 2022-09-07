/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboymond <aboymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 12:44:30 by piow00            #+#    #+#             */
/*   Updated: 2022/09/05 12:32:27 by aboymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	a;

	if (check_args(argc) == -1)
		return (0);
	if (init_base(&a, argv, argc) == 1)
		return (printf("Error init !\n"));
	init_mutex(&a);
	init_philo(&a);
	philo(&a);
	return (0);
}
