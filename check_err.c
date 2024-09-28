/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_err.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aasselma <aasselma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 02:23:23 by aasselma          #+#    #+#             */
/*   Updated: 2023/04/27 17:40:15 by aasselma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check_str(char *str, t_stack *stored_a)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((!(str[i] >= '0' && str[i] <= '9') && str[i] != ' ')
			&& (str[i] != '+' && str[i] != '-'))
		{
			write(2, "Error\n", 6);
			free(stored_a->stored);
			exit(1);
		}
		if (((str[i] == '+' || str[i] == '-')
				&& ((str[i - 1] >= '0' && str[i - 1] <= '9')
					|| !(str[i + 1] >= '0' && str[i + 1] <= '9'))))
		{
			write(2, "Error\n", 6);
			free(stored_a->stored);
			exit(1);
		}
		i++;
	}
}

void	check_if_double(t_stack *stored_a)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (i != stored_a->len)
	{
		while (k != stored_a->len)
		{
			if (stored_a->stored[i] == stored_a->stored[k] && i != k)
			{
				write(2, "Error\n", 6);
				free(stored_a->stored);
				exit(1);
			}
			k++;
		}
		k = 0;
		i++;
	}
}

void	check_if_tidy(t_stack *stored_a)
{
	int	i;
	int	k;
	int	c;

	c = 0;
	i = 0;
	k = 0;
	while (i != stored_a->len)
	{
		k = i;
		while (k != stored_a->len)
		{
			if (stored_a->stored[i] > stored_a->stored[k])
				c++;
			k++;
		}
		k = 0;
		i++;
	}
	if (c == 0)
	{
		free(stored_a->stored);
		exit(0);
	}
}

void	ckeck_if_valid(long long num)
{
	if (num > INT_MAX || num < INT_MIN)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
}

void	ft_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
