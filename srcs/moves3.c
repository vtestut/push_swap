/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 13:49:49 by vtestut           #+#    #+#             */
/*   Updated: 2023/05/04 16:56:56 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void reverse_rotate_a(t_top *a)
{
    t_list *last_node = a->top;
    t_list *second_last_node = NULL;

    if (last_node == NULL || last_node->next == NULL)
        return;
    while (last_node->next != NULL)
    {
        second_last_node = last_node;
        last_node = last_node->next;
    }
    second_last_node->next = NULL;
    last_node->next = a->top;
    a->top = last_node;
    printf("rra\n");
}

void reverse_rotate_b(t_top *b)
{
    t_list *last_node = b->top;
    t_list *second_last_node = NULL;

    if (last_node == NULL || last_node->next == NULL)
        return;
    while (last_node->next != NULL)
    {
        second_last_node = last_node;
        last_node = last_node->next;
    }
    second_last_node->next = NULL;
    last_node->next = b->top;
    b->top = last_node;
    printf("rrb\n");
}

void    rrr(t_top *a, t_top *b)
{
    reverse_rotate_a(a);
    reverse_rotate_b(b);
    printf("rrr\n");
}


// void reverse_rotate_a(t_top *a)
// {
//     t_top   *tmp;
//     t_list  *node;

//     tmp = a;
//     while (tmp->top->next)
//         tmp->top = tmp->top->next;
//     node = tmp->top;
//     ft_pop_back(tmp);
//     ft_push_front(tmp, node);
//     printf("rra\n");
// }

// void	reverse_rotate_a(t_stack *stack)
// {
// 	t_list	*tmp;
// 	int		num;

// 	tmp = stack->a;
// 	while (tmp->next)
// 		tmp = tmp->next;
// 	num = tmp->content;
// 	ft_pop_back(&(stack->a));
// 	ft_push_front(&(stack->a), num);
// }

// void	reverse_rotate_b(t_stack *stack)
// {
// 	t_list	*tmp;
// 	int		num;

// 	tmp = stack->b;
// 	while (tmp->next)
// 		tmp = tmp->next;
// 	num = tmp->content;
// 	ft_pop_back(&(stack->b));
// 	ft_push_front(&(stack->b), num);
// }