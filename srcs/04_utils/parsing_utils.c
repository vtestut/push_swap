/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:56:06 by vcheckut          #+#    #+#             */
/*   Updated: 2023/05/17 17:13:16 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	ft_is_space(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r'
		|| c == ' ')
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	int	count[3];

	if (!str || str[0] == 0)
		return (0);
	if (ft_is_space(*str))
		return (ft_atoi(str + 1));
	if (str[0] == '+' || str[0] == '-')
		count[0] = 0;
	else
		count[0] = -1;
	if (str[0] == '-')
		count[2] = -1;
	else
		count[2] = 1;
	count[1] = 0;
	while (str[++count[0]])
	{
		if (str[count[0]] < '0' || str[count[0]] > '9')
			return (count[1] * count[2]);
		count[1] = 10 * count[1] + str[count[0]] - '0';
	}
	return (count[1] * count[2]);
}

int	ft_count_num(int n)
{
	int	i;

	i = 1;
	if (n < 0)
	{
		i = 2;
		n = -n;
	}
	while (n / 10)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*rez;
	int			i;
	long int	num;

	num = (long)n;
	i = ft_count_num(num) - 1;
	rez = malloc(i + 1 * sizeof(char) + 1);
	if (!rez)
		return (NULL);
	rez[i + 1] = '\0';
	if (num == 0)
		rez[0] = '0';
	if (num < 0)
	{
		rez[0] = 45;
		num = -1 * num;
	}
	while (num > 0)
	{
		rez[i] = '0' + num % 10;
		num = num / 10;
		i--;
	}
	return (rez);
}

bool	ft_check_arg_size(char *arg)
{
	char	*check;

	check = ft_itoa(ft_atoi(arg));
	if (ft_strcmp(check, arg) != 0)
		return (free(check), false);
	return (free(check), true);
}
