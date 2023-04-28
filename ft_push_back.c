#include "push_swap.h"

void ft_push_back(t_list **lst, int content)
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
    new_node->next = NULL;
    
    //Si la liste est vide, le nouveau noeud est la tête de liste
    if (*lst == NULL)
    {
        *lst = new_node;
        return;
    }
    
    // Trouver le dernier noeud de la liste
    t_list *last_node;
    
    last_node = *lst;
    while (last_node->next != NULL)
    {
        last_node = last_node->next;
    }
    
    // Ajouter le nouveau noeud à la fin de la liste
    last_node->next = new_node;
}
