#include "push_swap.h"

t_list *ft_lstnew(int content)
{
	t_list	*new_list;

	new_list = malloc(sizeof(t_list));
	if (!new_list)
		return (NULL);

	new_list->content = content;
	new_list->next = NULL;
	
	return (new_list);
}
