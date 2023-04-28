/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 18:44:38 by vtestut           #+#    #+#             */
/*   Updated: 2023/04/28 20:00:06 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list *push_args(int argc, char **argv)
{
	int i;
	t_list *a;

	i = 1;
	a = ft_lstnew(ft_atoi(argv[i++]));
	while (i < argc)
	{
		ft_push_back(&a, ft_atoi(argv[i]));
		i++;
	}

	return (a);
}

void swap_a(t_stack *stack)
{
	if (stack->a->next == NULL)
		return;

	int tmp1;
	int tmp2;

	tmp1 = stack->a->content;
	tmp2 = stack->a->next->content;

	ft_pop_front(&(stack->a));
	ft_pop_front(&(stack->a));
	ft_push_front(&(stack->a), tmp1);
	ft_push_front(&(stack->a), tmp2);
}

void swap_b(t_stack *stack)
{
	if (stack->b->next == NULL)
		return;

	int tmp1;
	int tmp2;

	tmp1 = stack->b->content;
	tmp2 = stack->b->next->content;

	ft_pop_front(&(stack->b));
	ft_pop_front(&(stack->b));
	ft_push_front(&(stack->b), tmp1);
	ft_push_front(&(stack->b), tmp2);
}

void ss(t_stack *stack)
{
	swap_a(stack);
	swap_b(stack);
}

void push_a(t_stack *stack)
{
	if (!stack->b || !stack->b->content)
		return;

	int tmp;

	tmp = stack->b->content;
	ft_pop_front(&(stack->b));
	ft_push_front(&(stack->a), tmp);
}

void push_b(t_stack *stack)
{
	if (!stack->a || !stack->a->content)
		return;

	int tmp;

	tmp = stack->a->content;
	ft_pop_front(&(stack->a));
	ft_push_front(&(stack->b), tmp);
}

void rotate_a(t_stack *stack)
{
	int tmp;

	tmp = stack->a->content;
	ft_pop_front(&(stack->a));
	ft_push_back(&(stack->a), tmp);
}

void rotate_b(t_stack *stack)
{
	int tmp;

	tmp = stack->b->content;
	ft_pop_front(&(stack->b));
	ft_push_back(&(stack->b), tmp);
}

void rr(t_stack *stack)
{
	rotate_a(stack);
	rotate_b(stack);
}

void reverse_rotate_a(t_stack *stack)
{
	t_list *tmp;
	int num;

	tmp = stack->a;
	while(tmp->next)
	{
		tmp = tmp->next;
	}
	num = tmp->content;
	ft_pop_back(&(stack->a));
	ft_push_front(&(stack->a), num);
}

void reverse_rotate_b(t_stack *stack)
{
	t_list *tmp;
	int num;

	tmp = stack->b;
	while(tmp->next)
	{
		tmp = tmp->next;
	}
	num = tmp->content;
	ft_pop_back(&(stack->b));
	ft_push_front(&(stack->b), num);
}

void rrr(t_stack *stack)
{
	reverse_rotate_a(stack);
	reverse_rotate_b(stack);
}

void display_list(t_list *lst)
{
	t_list	*tmp;
	int		i;

	i = 1;
	tmp = lst;
	printf("node number[%d]'s content is equal to [%d]\n", i, tmp->content);
	while (tmp->next != NULL)
	{
		i++;
		tmp = tmp->next;
		printf("node number[%d]'s content is equal to [%d]\n", i, tmp->content);
	}
	printf("\n");
}

int main(int argc, char **argv)
{
	if (argc > 2)
	{
		t_stack stack;
		stack.a = push_args(argc, argv);
		stack.b = push_args(argc, argv);

		// swap_a(&stack);
		// swap_b(&stack);
		// ss(&stack);
		// push_a(&stack);
		// push_b(&stack);
		// rotate_a(&stack);
		// rotate_b(&stack);
		// rr(&stack);
		// reverse_rotate_a(&stack);
		// reverse_rotate_b(&stack);
		rrr(&stack);
		display_list(stack.a);
		display_list(stack.b);
	}
	return (0);
}