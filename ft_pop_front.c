#include "push_swap.h"

void ft_pop_front(t_list **lst)
{
    // Si la liste est vide, il n'y a rien à supprimer
    if (*lst == NULL)
        return;
    
    // Stocker le pointeur vers le deuxième noeud
    t_list *next_node = (*lst)->next;
    
    // Libérer l'espace alloué pour la tête de liste
    free(*lst);
    
    // Mettre à jour le pointeur vers la tête de liste pour qu'il pointe vers le deuxième noeud
    *lst = next_node;
}
