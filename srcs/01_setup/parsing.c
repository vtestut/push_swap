/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:35:10 by vtestut           #+#    #+#             */
/*   Updated: 2023/05/09 12:34:55 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

bool	ft_isdigit(const int c)
{
	if (c >= '0' && c <= '9')
		return (true);
	return (false);
}

bool	ft_isnum(const char *str)
{
	if (*str == '-')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (false);
		str++;
	}
	return (true);
}

int	*convert_params(int ac, char **av)
{
	int	i;
	int	j;
	int	*args;

	args = malloc(sizeof(int) * (ac - 1));
	if (!args)
	{
		printf("malloc error\n");
		return (false);
	}
	i = 1;
	j = 0;
	while (i < ac)
	{
		args[j] = ft_atoi(av[i]);
		j++;
		i++;
	}
	return (args);
}

bool	is_sorted(int ac, int *args)
{
	int	i;

	i = 0;
	while (i < ac - 1)
	{
		if (args[i] > args[i + 1])
			return (false);
		i++;
		if (i + 1 == ac -1)
			break;
	}
	return (true);
}

bool	check_double(int ac, char **av)
{
	int	i;
	int	j;
	int	*args;

	i = 0;
	j = 1;
	args = convert_params(ac, av);
	if (!args)
		return (false);
	while (i < ac - 1)
	{
		while (j < ac - 1)
		{
			if (args[j] == args[i])
			{
				printf("DOUBLES DETECTED\n");
				free(args);
				return (false);
			}
			j++;
		}
		i++;
		j = i + 1;
	}
	if (!is_sorted(ac, args))
	{
		free(args);
		return (false);
	}
	else
		printf("already sorted\n");
	free(args);
	return (true);
}
