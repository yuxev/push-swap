/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aasselma <aasselma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 00:18:22 by aasselma          #+#    #+#             */
/*   Updated: 2023/04/27 17:40:00 by aasselma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		ft_exit();
	return (r * sign);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
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

int	get_max_num(int *stored, int len)
{
	int	j;
	int	max;
	int	index;

	index = 0;
	j = 0;
	max = 0;
	while (j != len)
	{
		if (max < stored[j])
		{
			max = stored[j];
			index = j;
		}
		j++;
	}
	return (index);
}
