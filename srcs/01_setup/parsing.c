/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:35:10 by vtestut           #+#    #+#             */
/*   Updated: 2023/05/17 17:10:21 by vtestut          ###   ########.fr       */
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
		{
			write(2, "Error\n", 6);
			return (false);
		}
		str++;
	}
	return (true);
}

int	*ft_convert_params(int ac, char **av)
{
	int		i;
	int		j;
	int		*args;

	args = malloc(sizeof(int) * (ac - 1));
	if (!args)
	{
		write(2, "Error\n", 6);
		return (false);
	}
	i = 1;
	j = 0;
	while (i < ac)
	{
		if (!ft_check_arg_size(av[i]))
		{
			write(2, "Error\n", 6);
			free(args);
			return (false);
		}
		args[j] = ft_atoi(av[i]);
		j++;
		i++;
	}
	return (args);
}

bool	ft_is_sorted(int ac, int *args)
{
	int	i;

	i = 0;
	while (i < ac - 1)
	{
		if (args[i] > args[i + 1])
			return (false);
		i++;
		if (i + 1 == ac -1)
			break ;
	}
	write(2, "Error\n", 6);
	free(args);
	return (true);
}

bool	ft_check_double(int ac, int *args)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < ac - 1)
	{
		while (j < ac - 1)
		{
			if (args[j] == args[i])
			{
				write(2, "Error\n", 6);
				free(args);
				return (false);
			}
			j++;
		}
		i++;
		j = i + 1;
	}
	return (true);
}
