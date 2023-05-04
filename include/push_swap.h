/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 14:04:24 by vtestut           #+#    #+#             */
/*   Updated: 2023/05/04 17:43:06 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>

typedef struct t_list
{
	int				content;
	int				index;
	struct t_list	*next;
}					t_list;

typedef struct t_top
{
	t_list		*top;
}					t_top;

//			MAIN
t_top 	*init_stack_a(int ac, char **av);
t_top 	*init_stack_b(void);
bool	check_args(int ac, char **av);

//			PARSING
bool	ft_isdigit(const int c);
bool	ft_isnum(const char *str);
int		*convert_params(int ac, char **av);
bool	is_sorted(int ac, int *args);
bool	check_double(int ac, char **av);

//			INDEX
int		find_max(t_list *start);
int		find_next_smallest(t_list *start, int min);
t_list	*find_smallest(t_list *start);
void	index_list(t_top *a);

//			LIST_UTILS
t_list	*new_list(int ac, char **av);
int		ft_lstsize(t_list *lst);
void	ft_lstaddback(t_list **lst, t_list *new);

//			UTILS
int		ft_isspace(char c);
int		ft_atoi(char *str);
void	display_list(t_top *lst);

//			MOVES_1
void	swap_a(t_top *stack_ptr);
void	swap_b(t_top *stack_ptr);
void	ss(t_top *a_ptr, t_top *b_ptr);
void	push_a(t_top *a, t_top *b);
void	push_b(t_top *a, t_top *b);

//			MOVES_2
void	rotate_a(t_top *a);;

//			LST_PUSH_POP
void 	ft_push_front(t_top *lst, t_list *tmp);
void	ft_pop_front(t_top *lst);
void	ft_push_back(t_top *lst, t_list *new);

//			SORT_3
void	ft_sort_3(t_top *a);


#endif