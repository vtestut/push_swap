/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 13:51:22 by vtestut           #+#    #+#             */
/*   Updated: 2023/04/29 15:22:59 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_list	*ft_lstnew(int content)
{
	t_list	*new_list;

	new_list = malloc(sizeof(t_list));
	if (!new_list)
		return (NULL);
	new_list->content = content;
	new_list->next = NULL;
	return (new_list);
}

void	ft_pop_back(t_list **lst)
{
	t_list	*second_last_node;

	if (*lst == NULL)
		return ;
	if ((*lst)->next == NULL)
	{
		free(*lst);
		*lst = NULL;
		return ;
	}
	second_last_node = *lst;
	while (second_last_node->next->next != NULL)
		second_last_node = second_last_node->next;
	free(second_last_node->next);
	second_last_node->next = NULL;
}

void	ft_pop_front(t_list **lst)
{
	t_list	*next_node;

	if (*lst == NULL)
		return ;
	next_node = (*lst)->next;
	free(*lst);
	*lst = next_node;
}

void	ft_push_back(t_list **lst, int content)
{
	t_list	*new_node;
	t_list	*last_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error : Memory allocation failed.\n");
		exit(EXIT_FAILURE);
	}
	new_node->content = content;
	new_node->next = NULL;
	if (*lst == NULL)
	{
		*lst = new_node;
		return ;
	}
	last_node = *lst;
	while (last_node->next != NULL)
		last_node = last_node->next;
	last_node->next = new_node;
}

void	ft_push_front(t_list **lst, int content)
{
	t_list	*new_node;

	new_node = (t_list *) malloc(sizeof(t_list));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error : Memory allocation failed.\n");
		exit(EXIT_FAILURE);
	}
	new_node->content = content;
	new_node->next = *lst;
	*lst = new_node;
}
