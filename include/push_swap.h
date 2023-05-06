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

typedef struct t_algo_values
{
	t_list			*node;
	int				rra;
	int				rrb;
	int				ra;
	int				rb;
	int				rr;
	int				rrr;

}					t_algo_values;

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

//			MOVES_1
void	swap_a(t_top *stack_ptr);
void	swap_b(t_top *stack_ptr);
void	ss(t_top *a_ptr, t_top *b_ptr);
void	push_a(t_top *a, t_top *b);
void	push_b(t_top *a, t_top *b);

//			MOVES_2
void	rotate_a(t_top *a);
void	rotate_b(t_top *b);
void	rr(t_top *a, t_top *b);

//			MOVES_3
void	reverse_rotate_a(t_top *a);
void	reverse_rotate_b(t_top *b);
void    rrr(t_top *a, t_top *b);

//			SORT_UP_TO_5
void	pushmin(t_top *a, int min);
void	flag5(t_list *temp, t_top *a, t_top *b);
void	ft_sort_5(t_top *a, t_top *b, int n);
void	ft_sort_3(t_top *a);

//			SORT_UP_TO_500
void	test_instr(t_top *a, t_top *b);
void	zero_zero(t_algo_values go_zero, t_top *a);
void	push_zero(t_top *a, t_list *zero);
void	ft_big_sort(t_top *a, t_top *b);

//			MEDIAN
void	pushto_median(t_list *start, t_top *b, t_top *a, int median);
void	presort(int median, t_top *b, t_top *a);
t_list	*find_max_nnode(t_list *start);

//			NUMBER_OF_MOVES
t_algo_values	count_moves_a(t_list *node_a, t_top *a, t_algo_values current);
t_list			*get_nearest_max(t_list *b_node, t_top *a);
t_algo_values	number_moves(t_top *a, t_list *b_node, t_top *b, t_algo_values cur);
int				calc_instructions(t_algo_values current, t_algo_values next_node);

//			MOVE_FAST
t_algo_values	max_pul_rr(t_algo_values current);
t_algo_values	max_pull_rrr(t_algo_values current);
void			run_rotate(t_algo_values current, t_top *a, t_top *b);
void			run_reverse_rotate(t_algo_values current, t_top *a, t_top *b);
void			movefastest(t_algo_values current, t_top *a, t_top *b);

//			LIST_UTILS
t_list	*fill_list_a(int ac, char **av);
int		ft_lstsize(t_list *lst);
void	ft_lstaddback(t_list **lst, t_list *new);
void	free_list(t_list *head, t_top *main);

//			UTILS
int		ft_isspace(char c);
int		ft_atoi(char *str);
void	display_list(t_top *lst);

//			LST_PUSH_POP
void 	ft_push_front(t_top *lst, t_list *tmp);
void	ft_pop_front(t_top *lst);
void	ft_push_back(t_top *lst, t_list *new);
void	ft_pop_back(t_top *lst);





#endif