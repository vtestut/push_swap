/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_up_to5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:59:48 by vtestut           #+#    #+#             */
/*   Updated: 2023/05/17 12:55:11 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	ft_small_on_top(t_ptr *a, int min)
{
	t_lst	*start;
	int		count;
	int		len;

	count = 0;
	start = a->top;
	len = ft_lstsize(start);
	while (start->content != min)
	{
		count++;
		start = start->next;
	}
	start = a->top;
	while (start->content != min)
	{
		if (count <= len / 2)
			rotate_a(a, 1);
		if (count > len / 2)
			reverse_rotate_a(a, 1);
		start = a->top;
	}
}

void	ft_sort_5(t_lst *tmp, t_ptr *a, t_ptr *b)
{
	t_lst	*min;

	min = ft_find_smallest(tmp);
	ft_small_on_top(a, min->content);
	push_b(a, b);
	ft_sort_3(a);
	push_a(a, b);
	push_a(a, b);
}

void	ft_sort_3(t_ptr *a)
{
	int	first;
	int	second;
	int	third;

	first = a->top->content;
	second = a->top->next->content;
	third = a->top->next->next->content;
	if ((first > second) && (first < third) && (second < third))
		swap_a(a);
	else if ((first > second) && (second > third) && (first > third))
	{
		swap_a(a);
		reverse_rotate_a(a, 1);
	}
	else if ((first > second) && (first > third) && (second < third))
		rotate_a(a, 1);
	else if ((first < second) && (first < third) && (second > third))
	{
		swap_a(a);
		rotate_a(a, 1);
	}
	else if ((first < second) && (first > third) && (second > third))
		reverse_rotate_a(a, 1);
}

void	ft_small_sort(t_ptr *a, t_ptr *b, int n)
{
	t_lst	*start;
	t_lst	*min;
	t_lst	*tmp;

	start = a->top;
	min = ft_find_smallest(start);
	ft_small_on_top(a, min->content);
	if (min->next == NULL)
		tmp = a->top;
	else
		tmp = min->next;
	push_b(a, b);
	if (n == 4)
	{
		ft_sort_3(a);
		push_a(a, b);
	}
	else if (n == 5)
		ft_sort_5(tmp, a, b);
}
