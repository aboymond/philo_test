/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboymond <aboymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 12:44:30 by piow00            #+#    #+#             */
/*   Updated: 2022/08/31 17:24:17 by aboymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	a;

	(void)argv;
	if (check_args(argc) == -1)
		e_error();
	init_base(&a, argv);
	init_mutex(&a);
	init_philo(&a);
	philo(&a);
}
