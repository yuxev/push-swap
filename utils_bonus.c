/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aasselma <aasselma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 00:18:22 by aasselma          #+#    #+#             */
/*   Updated: 2023/04/27 18:45:51 by aasselma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_exit_2(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

long	ft_atoi(char *s)
{
	long	r;
	long	sign;
	long	i;
	int		z;

	z = 0;
	r = 0;
	sign = 1;
	i = 0;
	while (s[i] == '0')
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		r = r * 10 + s[i++] - '0';
		z++;
	}
	if (z > 11)
		ft_exit_2();
	return (r * sign);
}

int	ft_cal_len(char	*str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
		if (str[i + 1] == ' ' || str[i + 1] == '\0')
			return (i);
	}
	return (0);
}

void	ft_cal_str(char	*str, t_stack *stored_a)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] >= '0' && str[i] <= '9'))
		{
			if (str[i + 1] == ' ' || str[i + 1] == '\0')
				stored_a->len++;
		}
		i++;
	}
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;
	int	x;

	x = 0;
	i = 0;
	while (s1[i])
	{
		if (s1[i] != s2[x])
			return (0);
		i++;
		x++;
	}
	return (1);
}
