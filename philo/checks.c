/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoujdam <agoujdam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 23:21:11 by agoujdam          #+#    #+#             */
/*   Updated: 2023/07/11 23:21:12 by agoujdam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_check_everything(t_mutex *mutex)
{
	int	i;

	i = 0;
	while (!mutex->dead)
	{
		ft_check_death(&mutex->philo[i]);
		ft_check_meals(mutex);
		if (i == mutex->philo_numbers - 1)
			i = 0;
		else
			i++;
	}
}

void	ft_check_meals(t_mutex *mutex)
{
	int	i;

	i = 0;
	if (mutex->max_meals != -1)
	{
		while (mutex->philo_numbers > i)
		{
			pthread_mutex_lock(&mutex->eat);
			if (mutex->philo[i].times_eaten < mutex->max_meals)
			{
				pthread_mutex_unlock(&mutex->eat);
				break ;
			}
			else
			{
				pthread_mutex_unlock(&mutex->eat);
				i++;
			}
		}
		if (mutex->philo_numbers == i)
			mutex->dead = 1;
	}
}

void	ft_check_death(t_philo *philo)
{
	pthread_mutex_lock(&philo->mutex->check);
	pthread_mutex_lock(&philo->mutex->time);
	if (ft_get_time() - philo->last_meal > philo->mutex->t_die)
	{
		pthread_mutex_unlock(&philo->mutex->time);
		ft_print(philo, "\033[0;31mdied \033[0m", 1);
		philo->mutex->dead = 1;
	}
	pthread_mutex_unlock(&philo->mutex->time);
	pthread_mutex_unlock(&philo->mutex->check);
}
