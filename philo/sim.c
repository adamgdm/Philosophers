/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sim.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoujdam <agoujdam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 23:21:22 by agoujdam          #+#    #+#             */
/*   Updated: 2023/07/12 05:02:05 by agoujdam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_sbhallah(t_mutex *mutex)
{
	ft_print(&mutex->philo[0], "has taken a fork", 0);
	ft_usleep(mutex->t_die);
	ft_print(&mutex->philo[0], "died", 1);
}

void	ft_start_sim(t_mutex *mutex, int i, int ison)
{
	if (mutex->philo_numbers == 1)
	{
		ft_sbhallah(mutex);
		mutex->dead = 1;
	}
	else
	{
		while (mutex->philo_numbers > i)
		{
			mutex->philo[i].last_meal = ft_get_time();
			pthread_create(&mutex->philo[i].thread, NULL, ft_simulation,
				&mutex->philo[i]);
			pthread_detach(mutex->philo[i].thread);
			i = i + 2;
			if (i >= mutex->philo_numbers && !ison)
			{
				usleep(30000);
				i = 0;
				ison = 1;
			}
		}
		while (!mutex->dead)
			ft_check_everything(mutex);
	}
}

void	*ft_simulation(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		if (philo->mutex->max_meals
			&& philo->times_eaten == philo->mutex->max_meals)
			return (0);
		ft_eat(philo);
		ft_sleep(philo);
		ft_think(philo);
	}
	return (NULL);
}
