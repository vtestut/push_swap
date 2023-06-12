/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 13:56:07 by vtestut           #+#    #+#             */
/*   Updated: 2023/05/17 16:08:09 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] != '\0' && s2[i] != '\0') && (s1[i] == s2[i]))
	{
			i++;
	}
	return (s1[i] - s2[i]);
}

t_lst	*ft_lstlast(t_lst *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

t_lst	*ft_second_last_node(t_lst *lst)
{
	t_lst	*tmp;

	tmp = lst;
	while (tmp != NULL)
	{
		if (tmp->next->next == NULL)
			return (tmp);
		tmp = tmp->next;
	}
	return (0);
}
