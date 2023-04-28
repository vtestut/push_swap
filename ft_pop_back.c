#include "push_swap.h"

void ft_pop_back(t_list **lst)
{
    // Si la liste est vide, il n'y a rien à supprimer
    if (*lst == NULL)
        return;
    
    // Si la liste contient un seul élément, supprimer la tête de liste
    if ((*lst)->next == NULL)
    {
        free(*lst);
        *lst = NULL;
        return;
    }
    
    // Trouver l'avant-dernier noeud de la liste
    t_list *second_last_node = *lst;
    while (second_last_node->next->next != NULL)
    {
        second_last_node = second_last_node->next;
    }
    
    // Libérer l'espace alloué pour le dernier noeud
    free(second_last_node->next);
    
    // Mettre à jour le pointeur next de l'avant-dernier noeud pour qu'il pointe vers NULL
    second_last_node->next = NULL;
}