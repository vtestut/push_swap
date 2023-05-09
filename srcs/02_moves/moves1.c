/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 13:43:45 by vtestut           #+#    #+#             */
/*   Updated: 2023/05/09 12:34:41 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	swap_a(t_top *stack_ptr)
{
	t_list	*tmp1;
	t_list	*tmp2;

	if (stack_ptr->top->next == NULL)
		return ;
	tmp1 = stack_ptr->top;
	tmp2 = stack_ptr->top->next;
	ft_pop_front(stack_ptr);
	ft_pop_front(stack_ptr);
	ft_push_front(stack_ptr, tmp1);
	ft_push_front(stack_ptr, tmp2);
	printf("sa\n");
}

void	swap_b(t_top *stack_ptr)
{
	t_list	*tmp1;
	t_list	*tmp2;

	if (stack_ptr->top->next == NULL)
		return ;
	tmp1 = stack_ptr->top;
	tmp2 = stack_ptr->top->next;
	ft_pop_front(stack_ptr);
	ft_pop_front(stack_ptr);
	ft_push_front(stack_ptr, tmp1);
	ft_push_front(stack_ptr, tmp2);
	printf("sb\n");
}

void	ss(t_top *a_ptr, t_top *b_ptr)
{
	swap_a(a_ptr);
	swap_b(b_ptr);
	printf("ss\n");
}

void	push_a(t_top *a, t_top *b)
{
	t_list	*tmp;

	if (b->top == NULL)
		return ;
	tmp = b->top;
	ft_pop_front(b);
	ft_push_front(a, tmp);
	printf("pa\n");
}

void	push_b(t_top *a, t_top *b)
{
	t_list	*tmp;

	if (a->top == NULL)
		return ;
	tmp = a->top;
	ft_pop_front(a);
	ft_push_front(b, tmp);
	printf("pb\n");
}
