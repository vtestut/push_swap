/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 13:51:22 by vtestut           #+#    #+#             */
/*   Updated: 2023/05/04 15:55:25 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_list *new_list(int ac, char **av)
{
	t_list	*tmp;
	t_list	*lst;
	int		i;

	lst = NULL;
	i = 1;
	while (i < ac)
	{
		tmp = malloc(sizeof(t_list));
		if (!tmp)
			return (NULL);
		tmp->content = ft_atoi(av[i++]);
		tmp->next = NULL;
		ft_lstaddback(&lst, tmp);
	}
	return (lst);
}

int	ft_lstsize(t_list *lst)
{
	int	i;

	if (lst == NULL)
		return (0);
	i = 0;
	while (lst != NULL)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

void	ft_lstaddback(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	tmp = *lst;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
}
