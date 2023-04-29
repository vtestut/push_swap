/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 13:43:45 by vtestut           #+#    #+#             */
/*   Updated: 2023/04/29 15:25:41 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap_a(t_stack *stack)
{
	int	tmp1;
	int	tmp2;

	if (stack->a->next == NULL)
		return ;
	tmp1 = stack->a->content;
	tmp2 = stack->a->next->content;
	ft_pop_front(&(stack->a));
	ft_pop_front(&(stack->a));
	ft_push_front(&(stack->a), tmp1);
	ft_push_front(&(stack->a), tmp2);
}

void	swap_b(t_stack *stack)
{
	int	tmp1;
	int	tmp2;

	if (stack->b->next == NULL)
		return ;
	tmp1 = stack->b->content;
	tmp2 = stack->b->next->content;
	ft_pop_front(&(stack->b));
	ft_pop_front(&(stack->b));
	ft_push_front(&(stack->b), tmp1);
	ft_push_front(&(stack->b), tmp2);
}

void	ss(t_stack *stack)
{
	swap_a(stack);
	swap_b(stack);
}

void	push_a(t_stack *stack)
{
	int	tmp;

	if (!stack->b || !stack->b->content)
		return ;
	tmp = stack->b->content;
	ft_pop_front(&(stack->b));
	ft_push_front(&(stack->a), tmp);
}

void	push_b(t_stack *stack)
{
	int	tmp;

	if (!stack->a || !stack->a->content)
		return ;
	tmp = stack->a->content;
	ft_pop_front(&(stack->a));
	ft_push_front(&(stack->b), tmp);
}
