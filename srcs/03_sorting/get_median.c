/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_median.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 12:34:13 by vtestut           #+#    #+#             */
/*   Updated: 2023/05/17 13:13:06 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/*	push dans B en mettant les plus petites valeures dans la moitie basse	*/
void	ft_push_to_median(t_lst *start, t_ptr *b, t_ptr *a, int median)
{
	if (start->index <= median)
	{
		push_b(a, b);
		rotate_b(b, 1);
	}
	else
		push_b(a, b);
}

/*	Place le plus grand index en bas de A et push le reste dans B			*/
void	ft_median_sort(int median, t_ptr *b, t_ptr *a)
{
	int		max;
	t_lst	*start;

	start = a->top;
	max = ft_lstsize(start) - 1;
	while (start->next != NULL)
	{
		if (start->index != max)
			ft_push_to_median(start, b, a, median);
		else
			rotate_a(a, 1);
		start = a->top;
	}
}

t_lst	*ft_max_a(t_lst *start)
{
	t_lst	*max;

	max = start;
	while (start != NULL)
	{
		if (start->content > max->content)
			max = start;
		start = start->next;
	}
	return (max);
}
