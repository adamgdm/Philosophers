/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_creation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoujdam <agoujdam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 23:21:16 by agoujdam          #+#    #+#             */
/*   Updated: 2023/07/12 05:00:30 by agoujdam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_philo	*ft_create_the_philosophers(int philo_numbers, t_mutex *mutex)
{
	t_philo	*philo;
	t_philo	*head;
	int		i;

	i = 0;
	philo = malloc(sizeof(t_philo) * philo_numbers);
	head = philo;
	while (i < philo_numbers)
	{
		philo[i].id = i + 1;
		philo[i].mutex = mutex;
		philo[i].times_eaten = 0;
		philo[i].last_meal = 0;
		philo[i].right_fork = i;
		if (i == philo_numbers - 1)
			philo[i].left_fork = 0;
		else
			philo[i].left_fork = i + 1;
		philo[i].last_meal = ft_get_time();
		i++;
	}
	return (head);
}

t_mutex	*ft_make_mutex(t_mutex *mutex, char **av, int ac)
{
	int	i;

	i = 0;
	pthread_mutex_init(&mutex->print, NULL);
	pthread_mutex_init(&mutex->check, NULL);
	pthread_mutex_init(&mutex->eat, NULL);
	pthread_mutex_init(&mutex->time, NULL);
	mutex->philo_numbers = ft_atoi(av[1]);
	mutex->t_die = ft_atoi(av[2]);
	mutex->t_eat = ft_atoi(av[3]);
	mutex->t_sleep = ft_atoi(av[4]);
	mutex->dead = 0;
	if (ac == 6)
		mutex->max_meals = ft_atoi(av[5]);
	else
		mutex->max_meals = -1;
	mutex->forks = malloc(sizeof(pthread_mutex_t) * mutex->philo_numbers);
	while (i < mutex->philo_numbers)
	{
		pthread_mutex_init(&mutex->forks[i], NULL);
		i++;
	}
	mutex->philo = ft_create_the_philosophers(mutex->philo_numbers, mutex);
	mutex->start = ft_get_time();
	return (mutex);
}
