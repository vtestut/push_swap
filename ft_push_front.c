#include "push_swap.h"

void	ft_push_front(t_list **lst, int content)
{
    // Allouer de l'espace pour un nouveau noeud
    t_list *new_node = (t_list*) malloc(sizeof(t_list));
    if (new_node == NULL)
    {
        fprintf(stderr, "Erreur : impossible d'allouer de la mémoire.\n");
        exit(EXIT_FAILURE);
    }
    
    // Remplir les champs du nouveau noeud
    new_node->content = content;
    new_node->next = *lst;
    
    // Mettre à jour la tête de liste pour qu'elle pointe vers le nouveau noeud
    *lst = new_node;
}

