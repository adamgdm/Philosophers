/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoujdam <agoujdam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 05:00:50 by agoujdam          #+#    #+#             */
/*   Updated: 2023/07/12 05:01:42 by agoujdam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_mutex	t_mutex;

typedef struct s_philos
{
	struct s_philos		*next;
	struct s_philos		*previous;
	int					id;
	int					right_fork;
	int					left_fork;
	int					times_eaten;
	long int			last_meal;
	pthread_t			thread;
	t_mutex				*mutex;
}						t_philo;

typedef struct s_mutex
{
	int					philo_numbers;
	long int			start;
	long int			t_die;
	long int			t_eat;
	long int			t_sleep;
	int					t_eaten;
	int					max_meals;
	int					dead;
	t_philo				*philo;
	pthread_mutex_t		*forks;
	pthread_mutex_t		eat;
	pthread_mutex_t		print;
	pthread_mutex_t		check;
	pthread_mutex_t		time;
}						t_mutex;

void					ft_usleep(long int time);
void					ft_eat(t_philo *philo);
void					ft_sleep(t_philo *philo);
void					ft_think(t_philo *philo);
void					ft_die(t_philo *philo);
void					ft_print(t_philo *philo, char *str, int is_dead);

void					ft_check_everything(t_mutex *mutex);
void					ft_check_meals(t_mutex *mutex);
void					ft_check_death(t_philo *philo);

void					ft_start_sim(t_mutex *mutex, int i, int ison);
void					*ft_simulation(void *arg);
void					ft_end_sim(t_mutex *mutex);

t_philo					*ft_create_the_philosophers(int philo_numbers,
							t_mutex *mutex);
t_mutex					*ft_make_mutex(t_mutex *mutex, char **av, int ac);

int						ft_check_arguments(int ac, char **av);
int						ft_check_args(int ac, char **av);
long long				ft_atoi(char *str);
long int				ft_get_time(void);

#endif
