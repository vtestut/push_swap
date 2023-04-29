/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 13:56:07 by vtestut           #+#    #+#             */
/*   Updated: 2023/04/29 15:27:56 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r'
		|| c == ' ')
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	long long int	ct[3];

	if (!str || str[0] == 0)
		return (0);
	if (ft_isspace(*str))
		return (ft_atoi(str + 1));
	if (str[0] == '+' || str[0] == '-')
		ct[0] = 0;
	else
		ct[0] = -1;
	if (str[0] == '-')
		ct[2] = -1;
	else
		ct[2] = 1;
	ct[1] = 0;
	while (str[++ct[0]])
	{
		if (str[ct[0]] < '0' || str[ct[0]] > '9')
			return (ct[1] * ct[2]);
		ct[1] = 10 * ct[1] + str[ct[0]] - '0';
	}
	return (ct[1] * ct[2]);
}

t_list	*push_args(int argc, char **argv)
{
	int		i;
	t_list	*new_lst;

	i = 1;
	new_lst = ft_lstnew(ft_atoi(argv[i++]));
	while (i < argc)
	{
		ft_push_back(&new_lst, ft_atoi(argv[i]));
		i++;
	}
	return (new_lst);
}

void	display_list(t_list *lst)
{
	t_list	*tmp;
	int		i;

	i = 1;
	tmp = lst;
	printf("node number[%d]'s content is equal to [%d]\n", i, tmp->content);
	while (tmp->next != NULL)
	{
		i++;
		tmp = tmp->next;
		printf("node number[%d]'s content is equal to [%d]\n", i, tmp->content);
	}
	printf("\n");
}
