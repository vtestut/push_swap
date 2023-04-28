/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 18:44:38 by vtestut           #+#    #+#             */
/*   Updated: 2023/04/28 19:02:20 by vtestut          ###   ########.fr       */
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

void swap_b(t_list *b)
{
	if (b->next == NULL)
		return;

	int tmp1;
	int tmp2;

	tmp1 = b->content;
	tmp2 = b->next->content;

	ft_pop_front(&b);
	ft_pop_front(&b);
	ft_push_front(&b, tmp1);
	ft_push_front(&b, tmp2);
}

// void ss(t_list *a, t_list *b)
// {
// 	swap_a(a);
// 	swap_b(b);
// }

void push_a(t_list *a, t_list *b)
{
	if (!b || !b->content)
		return;

	int tmp;

	tmp = b->content;
	ft_pop_front(&b);
	ft_push_front(&a, tmp);
}

void push_b(t_list *b, t_list *a)
{
	if (!a || !a->content)
		return;

	int tmp;

	tmp = a->content;
	ft_pop_front(&a);
	ft_push_front(&b, tmp);
}

void rotate_a(t_list *a)
{
	int tmp;

	tmp = a->content;
	ft_pop_front(&a);
	ft_push_back(&a, tmp);
	//display_list(a);
}

void rotate_b(t_list *b)
{
	int tmp;

	tmp = b->content;
	ft_pop_front(&b);
	ft_push_back(&b, tmp);
}

void rr(t_list *a, t_list *b)
{
	rotate_a(a);
	rotate_b(b);
	// display_list(a);
	// display_list(b);
}

void reverse_rotate_a(t_list *a)
{
	t_list *tmp;
	int num;

	tmp = a;
	while(tmp->next)
	{
		tmp = tmp->next;
	}
	num = tmp->content;
	ft_pop_back(&a);
	ft_push_front(&a, num);
}

// t_list *reverse_rotate_a(t_list *a)
// {
// 	t_list *tmp;
// 	int num;

// 	tmp = a;
// 	while(tmp->next)
// 	{
// 		tmp = tmp->next;
// 	}
// 	num = tmp->content;
// 	ft_pop_back(&a);
// 	ft_push_front(&a, num);
// 	display_list(a);
// 	return (a);
// }

void reverse_rotate_b(t_list *b)
{
	t_list *tmp;
	int num;

	tmp = b;
	while(tmp->next)
	{
		tmp = tmp->next;
	}
	num = tmp->content;
	ft_pop_back(&b);
	ft_push_front(&b, num);
}

void rrr(t_list *a, t_list *b)
{
	reverse_rotate_a(a);
	reverse_rotate_b(b);
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

		swap_a(&stack);
		// swap_b(&stack);
		// ss(a, b);
		// push_a(a, b);
		// push_b(b, a);
		// rotate_a(a);
		//rotate_b(b);
		// rr(a, b);
		// reverse_rotate_a(a);
		// reverse_rotate_b(b);
		// rrr(a, b);
		display_list(stack.a);
		// display_list(&stack);
		//display_list(b);
	}
	return (0);
}