/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 18:53:24 by vtestut           #+#    #+#             */
/*   Updated: 2023/05/17 17:05:38 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	push_a(t_ptr *a, t_ptr *b)
{
	t_lst	*tmp;

	tmp = b->top;
	b->top = tmp->next;
	tmp->next = a->top;
	a->top = tmp;
	write(1, "pa\n", 3);
}

void	push_b(t_ptr *a, t_ptr *b)
{
	t_lst	*tmp;

	tmp = a->top;
	a->top = tmp->next;
	tmp->next = b->top;
	b->top = tmp;
	write(1, "pb\n", 3);
}

void	swap_a(t_ptr *lst)
{
	int		n;
	t_lst	*tmp;
	t_lst	*start;
	int		new;

	start = lst->top;
	tmp = start->next;
	n = ft_lstsize(start);
	if (n > 1)
	{
		new = start->content;
		start->content = tmp->content;
		tmp->content = new;
		write(1, "sa\n", 3);
	}
}

void	swap_b(t_ptr *lst)
{
	int		n;
	int		new;
	t_lst	*tmp;
	t_lst	*start;

	start = lst->top;
	tmp = start->next;
	n = ft_lstsize(start);
	if (n > 1)
	{
		new = start->content;
		start->content = tmp->content;
		tmp->content = new;
		write(1, "sb\n", 3);
	}
}

void	swap_s(t_ptr *a, t_ptr *b)
{
	swap_a(a);
	swap_b(b);
	write(1, "ss\n", 3);
}
