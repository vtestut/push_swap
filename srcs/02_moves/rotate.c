/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 18:52:55 by vtestut           #+#    #+#             */
/*   Updated: 2023/05/17 12:49:07 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	rotate_a(t_ptr *a, int flag)
{
	t_lst	*start_a;
	t_lst	*last;
	t_lst	*tmp;

	start_a = a->top;
	if (ft_lstsize(start_a) > 1)
	{
		last = ft_lstlast(start_a);
		tmp = a->top->next;
		a->top = tmp;
		last->next = start_a;
		start_a->next = NULL;
		if (flag != 0)
			write(1, "ra\n", 3);
	}
}

void	rotate_b(t_ptr *b, int flag)
{
	t_lst	*start_b;
	t_lst	*last;
	t_lst	*tmp;

	start_b = b->top;
	if (ft_lstsize(start_b) > 1)
	{
		last = ft_lstlast(start_b);
		tmp = b->top->next;
		b->top = tmp;
		last->next = start_b;
		start_b->next = NULL;
		if (flag != 0)
			write(1, "rb\n", 3);
	}
}

void	rotate_r(t_ptr *a, t_ptr *b)
{
	if (ft_lstsize(a->top) > 1 && ft_lstsize(b->top) > 1)
	{
		rotate_a(a, 0);
		rotate_b(b, 0);
		write(1, "rr\n", 3);
	}
}
