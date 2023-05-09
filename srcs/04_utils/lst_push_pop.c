/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_push_pop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:55:16 by vtestut           #+#    #+#             */
/*   Updated: 2023/05/09 12:33:14 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	ft_pop_front(t_top *lst)
{
	t_list	*next_node;

	if (lst == NULL)
		return ;
	next_node = lst->top->next;
	//free(lst);
	lst->top = next_node;
}

void	ft_push_front(t_top *lst, t_list *new)
{
	new->next = lst->top;
	lst->top = new;
}

void	ft_push_back(t_top *lst, t_list *new)
{
	t_list *last_node;
	
	new->next = NULL;
	if (lst->top == NULL)
	{
		lst->top = new;
		return ;
	}
	last_node = lst->top;
	while(last_node->next != NULL)
		last_node = last_node->next;
	last_node->next  = new;
}

void	ft_pop_back(t_top *lst)
{
	t_list *second_last_node;
	t_list *tmp;

	tmp = lst->top;
	if (tmp == NULL)
		return ;
	if (tmp->next == NULL)
	{
		free(tmp);
		tmp = NULL;
		return ;
	}
	second_last_node = tmp;
	while (second_last_node->next != NULL)
		second_last_node = second_last_node->next;
	free(second_last_node->next);
	second_last_node->next = NULL;
}

// void	ft_pop_back(t_list **lst)s
// {
// 	t_list	*second_last_node;

// 	if (*lst == NULL)
// 		return ;
// 	if ((*lst)->next == NULL)
// 	{
// 		free(*lst);
// 		*lst = NULL;
// 		return ;
// 	}
// 	second_last_node = *lst;
// 	while (second_last_node->next->next != NULL)
// 		second_last_node = second_last_node->next;
// 	free(second_last_node->next);
// 	second_last_node->next = NULL;
// }

// void	ft_push_back(t_list **lst, int n)
// {
// 	t_list	*new_node;
// 	t_list	*last_node;

// 	new_node = (t_list *)malloc(sizeof(t_list));
// 	if (new_node == NULL)
// 	{
// 		fprintf(stderr, "Error : Memory allocation failed.\n");
// 		exit(EXIT_FAILURE);
// 	}
// 	new_node->n = n;
// 	new_node->next = NULL;
// 	if (*lst == NULL)
// 	{
// 		*lst = new_node;
// 		return ;
// 	}
// 	last_node = *lst;
// 	while (last_node->next != NULL)
// 		last_node = last_node->next;
// 	last_node->next = new_node;
// }



