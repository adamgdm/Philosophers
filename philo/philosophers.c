/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoujdam <agoujdam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 23:21:19 by agoujdam          #+#    #+#             */
/*   Updated: 2023/07/12 05:00:33 by agoujdam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int ac, char **av)
{
	t_mutex	*mutex;

	if ((ac != 6 && ac != 5))
		printf("Invalid Number Of Arguments!\n");
	else if (ft_check_args(ac, av))
		return (1);
	else if (ft_check_arguments(ac, av))
		printf("Invalid Arguments!\n");
	else
	{
		mutex = malloc(sizeof(t_mutex));
		if (!mutex)
			return (1);
		mutex = ft_make_mutex(mutex, av, ac);
		ft_start_sim(mutex, 1, 0);
	}
	return (0);
}
