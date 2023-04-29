/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 13:47:52 by vtestut           #+#    #+#             */
/*   Updated: 2023/04/29 15:27:10 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rotate_a(t_stack *stack)
{
	int	tmp;

	tmp = stack->a->content;
	ft_pop_front(&(stack->a));
	ft_push_back(&(stack->a), tmp);
}

void	rotate_b(t_stack *stack)
{
	int	tmp;

	tmp = stack->b->content;
	ft_pop_front(&(stack->b));
	ft_push_back(&(stack->b), tmp);
}

void	rr(t_stack *stack)
{
	rotate_a(stack);
	rotate_b(stack);
}

void	reverse_rotate_a(t_stack *stack)
{
	t_list	*tmp;
	int		num;

	tmp = stack->a;
	while (tmp->next)
		tmp = tmp->next;
	num = tmp->content;
	ft_pop_back(&(stack->a));
	ft_push_front(&(stack->a), num);
}

void	reverse_rotate_b(t_stack *stack)
{
	t_list	*tmp;
	int		num;

	tmp = stack->b;
	while (tmp->next)
		tmp = tmp->next;
	num = tmp->content;
	ft_pop_back(&(stack->b));
	ft_push_front(&(stack->b), num);
}
