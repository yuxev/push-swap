/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aasselma <aasselma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 19:44:06 by aasselma          #+#    #+#             */
/*   Updated: 2023/04/26 22:25:09 by aasselma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_if_sorted(t_stack *stored_a)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (i != stored_a->len)
	{
		k = i;
		while (k != stored_a->len)
		{
			if (stored_a->stored[i] > stored_a->stored[k])
				return (1);
			k++;
		}
		i++;
	}
	return (0);
}

int	check_next(t_stack *stored_a, char *str, int *j, int *i)
{
	int		k;
	char	*s1;

	k = 0;
	if ((str[(*j)] >= '0' && str[(*j)] <= '9') || str[(*j)] == '-')
	{
		s1 = malloc(ft_cal_len(&str[(*j)]));
		while (str[(*j)])
		{
			s1[k] = str[(*j)];
			if (str[*j + 1] == ' ' || str[*j + 1] == '\0')
			{
				s1[k + 1] = '\0';
				ckeck_if_valid(ft_atoi(s1));
				k = 0;
				stored_a->stored[(*i)++] = ft_atoi(s1);
				free(s1);
				break ;
			}
			(*j)++;
			k++;
		}
	}
	return (1);
}

void	get_num(char *str, t_stack *stored_a)
{
	static int	i;
	int			j;
	int			l;

	l = i;
	j = 0;
	while (str[j])
	{
		if (check_next(stored_a, str, &j, &i) == 0)
		{
			write(2, "Error\n", 6);
			exit(0);
		}
		j++;
	}
	if (l == i)
	{
		write(2, "Error\n", 6);
		free(stored_a->stored);
		free(stored_a);
		exit(1);
	}
}

void	start_sort(t_stack *stored_a, t_stack *stored_b, int argc, char **argv)
{
	int	i;

	i = 0;
	stored_a->stored = malloc(stored_a->len * sizeof(int));
	stored_b->stored = malloc(stored_a->len * sizeof(int));
	while (i++ < argc - 1)
		get_num(argv[i], stored_a);
	stored_b->len = 0;
	check_if_double(stored_a);
	check_if_tidy(stored_a);
	if (stored_a->len == 3 || stored_a->len == 2)
		sort_three(stored_a, stored_a->stored);
	else if (stored_a->len >= 4 && stored_a->len <= 20)
		sort_five(stored_a, stored_b);
	else
		sort_stack(stored_a, stored_b);
}

int	main(int argc, char **argv)
{
	t_stack	*stored_a;
	t_stack	*stored_b;
	int		i;

	i = 1;
	stored_a = malloc(sizeof(t_stack));
	stored_b = malloc(sizeof(t_stack));
	if (argc >= 2)
	{
		while (i != argc)
		{
			ft_check_str(argv[i], stored_a);
			ft_cal_str(argv[i], stored_a);
			i++;
		}
		start_sort(stored_a, stored_b, argc, argv);
	}
}
