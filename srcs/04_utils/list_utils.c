/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 13:51:22 by vtestut           #+#    #+#             */
/*   Updated: 2023/05/17 17:00:14 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	ft_lstsize(t_lst *lst)
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

void	ft_lstaddback(t_lst **lst, t_lst *new)
{
	t_lst	*tmp;

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

t_lst	*ft_fill_a(int ac, char **av)
{
	t_lst	*tmp;
	t_lst	*lst;
	int		i;

	lst = NULL;
	i = 1;
	while (i < ac)
	{
		tmp = malloc(sizeof(t_lst));
		if (!tmp)
			return (NULL);
		tmp->content = ft_atoi(av[i++]);
		tmp->next = NULL;
		ft_lstaddback(&lst, tmp);
	}
	return (lst);
}

// void	ft_free_all(t_lst *head, t_ptr *main)
// {
// 	t_lst	*current;
// 	t_lst	*next;

// 	current = head;
// 	while (current != NULL)
// 	{
// 		next = current->next;
// 		free(current);
// 		current = next;
// 	}
// 	free(main);
// }

void	ft_free_all(t_lst *a_top, t_ptr *a, t_lst *b_top, t_ptr *b)
{
	t_lst	*tmp1;
	t_lst	*next1;
	t_lst	*tmp2;
	t_lst	*next2;

	tmp1 = a_top;
	while (tmp1 != NULL)
	{
		next1 = tmp1->next;
		free(tmp1);
		tmp1 = next1;
	}
	tmp2 = b_top;
	while (tmp2 != NULL)
	{
		next2 = tmp2->next;
		free(tmp2);
		tmp2 = next2;
	}
	free(a);
	free(b);
}
