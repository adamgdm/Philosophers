/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoujdam <agoujdam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 23:21:13 by agoujdam          #+#    #+#             */
/*   Updated: 2023/07/12 05:00:21 by agoujdam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_check_arguments(int ac, char **av)
{
	int	i;
	int	acdup;

	i = 0;
	acdup = 1;
	while (acdup < ac)
	{
		while (av[acdup][i])
		{
			if (av[acdup][i] >= '0' && av[acdup][i] <= '9')
				i++;
			else
				return (1);
		}
		if (ft_atoi(av[acdup]) > 2147483647 || ft_atoi(av[acdup]) < 0)
			return (1);
		i = 0;
		if (ac)
			acdup++;
	}
	return (0);
}

int	ft_check_args(int ac, char **av)
{
	if (ft_atoi(av[1]) == 0)
	{
		printf("Error : Where's everyone?\n");
		return (1);
	}
	else if (ac == 6)
	{
		if (ft_atoi(av[5]) == 0)
		{
			printf("Error : Well they have to eat atleast once? No?\n");
			return (1);
		}
	}
	return (0);
}

long long	ft_atoi(char *str)
{
	size_t	result;
	int		sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\r'
		|| str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	if ((result > 2147483647 && sign == 1)
		|| (result > 2147483648 && sign == -1))
		return (99999999999);
	return (result * sign);
}

long int	ft_get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}
