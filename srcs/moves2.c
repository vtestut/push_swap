/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 13:47:52 by vtestut           #+#    #+#             */
/*   Updated: 2023/05/04 17:49:20 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rotate_a(t_top *a)
{
	t_list	*tmp;

	tmp = a->top;
	ft_pop_front(a);
	ft_push_back(a, tmp);
	printf("ra\n");
}

// void	rotate_a(t_stack *stack)
// {
// 	int	tmp;

// 	tmp = stack->a->content;
// 	ft_pop_front(&(stack->a));
// 	ft_push_back(&(stack->a), tmp);
// }

// void	rotate_b(t_stack *stack)
// {
// 	int	tmp;

// 	tmp = stack->b->content;
// 	ft_pop_front(&(stack->b));
// 	ft_push_back(&(stack->b), tmp);
// }

// void	rr(t_stack *stack)
// {
// 	rotate_a(stack);
// 	rotate_b(stack);
// }
