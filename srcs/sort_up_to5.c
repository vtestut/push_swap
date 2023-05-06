/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:59:48 by vtestut           #+#    #+#             */
/*   Updated: 2023/05/04 17:47:27 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	pushmin(t_top *a, int min)
{
	t_list  *start;
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
			rotate_a(a);
		if (count > len / 2)
			reverse_rotate_a(a);
		start = a->top;
	}
}

void	flag5(t_list *temp, t_top *a, t_top *b)
{
	t_list	*min;

	min = find_smallest(temp);
	pushmin(a, min->content);
	push_b(a, b);
	ft_sort_3(a);
	push_a(a, b);
	push_a(a, b);
}

void	ft_sort_5(t_top *a, t_top *b, int n)
{
	t_list	*start;
	t_list	*min;
	t_list	*temp;

	start = a->top;
	min = find_smallest(start);
	pushmin(a, min->content);
	if (min->next == NULL)
		temp = a->top;
	else
		temp = min->next;
	push_b(a, b);
	if (n == 5)
		flag5(temp, a, b);
	if (n == 4)
	{
		ft_sort_3(a);
		push_a(a, b);
	}
}

void	ft_sort_3(t_top *a)
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
		reverse_rotate_a(a);
	}
	else if ((first > second) && (first > third) && (second < third))
		rotate_a(a);
	else if ((first < second) && (first < third) && (second > third))
	{
		swap_a(a);
		rotate_a(a);
	}
	else if ((first < second) && (first > third) && (second > third))
		reverse_rotate_a(a);
}