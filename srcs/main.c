/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piow00 <piow00@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 12:44:30 by piow00            #+#    #+#             */
/*   Updated: 2022/08/18 17:00:13 by piow00           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
    
int main(int argc, char **argv)
{
    (void)argv;
    t_data a;

    if (check_args(argc) == -1)
        e_error();
    init_base(&a, argv);
    init_philo(&a);
    // print_all(0, &a);
    // print_all(1, &a);
    // print_all(2, &a);
    // print_all(3, &a);
    // print_all(4, &a);
}