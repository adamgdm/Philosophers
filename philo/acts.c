/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   acts.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoujdam <agoujdam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 23:21:09 by agoujdam          #+#    #+#             */
/*   Updated: 2023/07/11 23:21:52 by agoujdam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_usleep(long int time)
{
	long int	start;

	start = ft_get_time();
	while (ft_get_time() - start < time)
		usleep(50);
}

void	ft_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->mutex->forks[philo->left_fork]);
	ft_print(philo, "has taken a fork", 0);
	pthread_mutex_lock(&philo->mutex->forks[philo->right_fork]);
	ft_print(philo, "has taken a fork", 0);
	ft_print(philo, "is eating", 0);
	pthread_mutex_lock(&philo->mutex->time);
	philo->last_meal = ft_get_time();
	pthread_mutex_unlock(&philo->mutex->time);
	ft_usleep(philo->mutex->t_eat);
	pthread_mutex_lock(&philo->mutex->eat);
	philo->times_eaten++;
	pthread_mutex_unlock(&philo->mutex->eat);
	pthread_mutex_unlock(&philo->mutex->forks[philo->left_fork]);
	pthread_mutex_unlock(&philo->mutex->forks[philo->right_fork]);
}

void	ft_sleep(t_philo *philo)
{
	ft_print(philo, "is sleeping", 0);
	ft_usleep(philo->mutex->t_sleep);
}

void	ft_think(t_philo *philo)
{
	ft_print(philo, "is thinking", 0);
}

void	ft_print(t_philo *philo, char *str, int is_dead)
{
	pthread_mutex_lock(&philo->mutex->print);
	printf("%ld %d %s\n", ft_get_time() - philo->mutex->start, philo->id, str);
	if (is_dead)
		return ;
	pthread_mutex_unlock(&philo->mutex->print);
}
