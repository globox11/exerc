#ifndef SUDOKU_FUNCTIONS_H
#define SUDOKU_FUNCTIONS_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
/**
 * @brief initialise le tableau de sudoku
 */

/**
 * @brief supprime la liste d'exercice
 */

/**
 * @brief structure contenant un sudoku
 * @property identifiant chaine de caractère de 10 (attention il y a un piège)
 * @property matrice de caractères contenant les donnees du sudoku (9 par 9 case)
 * @property nb_iteration un entier non signé permettant de voir combien d'iteration on été réalisée
 */
struct sudoku_exercice {
    char identifiant[11];
    char matrice[9][9];
    unsigned int nb_iteration;
};

/**
 * @brief init_sudoku_exercice permet d'initialiser un sodoku exercice
 * @param exerc un pointer sur la structure à initialiser
 * @note memset ? tous les champs ne seront pas intialisés avec la même valeur
 */
void init_sudoku_exercice(struct sudoku_exercice* exerc);

/**
 * @brief structure de liste contenant un element sudoku exercice
 * @property prev un pointer sur l'element precedent
 * @property next un pointer sur l'element suivant
 * @property sudoku un pointeur sur l'exercice
 */
struct sudoku_element {
    struct sudoku_element* prev;
    struct sudoku_element* next;
    struct sudoku_exercice* sudoku;
};


/**
 * @brief structure encapsulant une liste de sudoku element. Permet de realiser toutes les opérations sur la liste
 * @property load un pointer sur la liste d'éléments (en fait sur le premier qui donne acces aux suivants).
 * @property first un pointer sur le premier element mais qui ne sera jamais modifié (permet de toujours conserver l'information, sécurité).
 * @property nb_element un entier non signé contenant le nombre d'élément présentement dans la liste.
 * @note il aurait été tout à fait possible de se passer de cette structure mais elle est pratique
 */
struct sudoku_list {
    struct sudoku_element* load;
    struct sudoku_element* first;
    unsigned int nb_element;
};

/**
 * @brief initialize une liste de sudoku
 * @param list_to_init un pointer sur la liste à initialiser
 * @note lors de l'initialisation, la liste doit être vide et ses variables complètement intialisées.
 * Si la liste n'est pas vide, faire un message d'erreur et ne rien faire de plus
 */
void init_list_sudoku(struct sudoku_list* list);

/**
 * @brief init_sudoku_element initialise un sudoku element
 * @param elem un pointer sur la structure à initialiser
 */
void init_sudoku_element(struct sudoku_element* elem);

/**
 * @brief creer un element en tête de liste
 * @param base_list un pointer sur la liste ou l'on va insérer le sudoku
 * @return un pointer sur le sudoku_element créé.
 * @note ne pas oublier d'initialiser correctement le sudoku element. Il sera alloué dynamiquement
 */
struct sudoku_element* create_front(struct sudoku_list* base_list);

/**
 * @brief creer un element en fin de liste
 * @param base_list un pointer sur la liste ou l'on va insérer le sudoku
 * @return un pointer sur le sudoku_element créé.
 * @note ne pas oublier d'initialiser correctement le sudoku element
 */
struct sudoku_element* create_end(struct sudoku_list* base_list);

/*
{
    struct sudoku_element* elem_create = malloc(sizeof(struct sudoku_element));
    init_sudoku_element(elem_create);

    elem_create->prev = get_last_element(base_list);
    if(elem_create->prev != NULL)
    {
        elem_create->prev->next = elem_create;
    } else {
        base_list->load = elem_create;
        base_list->first = base_list->load;
    }

    base_list->nb_element += 1;

    return elem_create;
}
*/

/**
 * @brief get_front_element
 * @param list un pointeur sur la liste dans laquelle l'on recherche l'element
 * @return un pointer sur le premier element
 */
struct sudoku_element* get_front_element(struct sudoku_list* list);

/**
 * @brief get_last_element
 * @param list un pointeur sur la liste dans laquelle l'on recherche l'element
 * @return un pointer sur le dernier element
 */
struct sudoku_element* get_last_element(struct sudoku_list* list);

/**
 * @brief delete_last_element supprime le dernier sudoku element d'une liste
 * @param list un pointer sur la la liste ou supprimer
 */
void delete_last_element(struct sudoku_list* list);
/*{
    struct sudoku_element* elem_last = get_last_element(list);

    if(elem_last == NULL)
    {
        return;
    }

    if(elem_last->prev == NULL)
    {
        list->load = NULL;
        list->first = list->load;
    } else {
        elem_last->prev->next = NULL;
    }

    list->nb_element -= 1;
    free(elem_last);
}*/

/**
 * @brief delete_first_element
 * @param list un pointer sur la la liste ou supprimer
 */
void delete_first_element(struct sudoku_list* list);
/*{
    if(get_front_element(list) == NULL)
    {
        return;
    }



    list->load = get_front_element(list)->next;
    list->first = list->load;
    free(list->load->prev);
    list->load->prev = NULL;

    ou ?

    struct sudoku_element* elem_new = get_front_element(list);
    if(elem_new->next != NULL)
    {
        elem_new->next->prev = NULL;
    }
    list->load = elem_new->next;
    list->first = list->load;
    list->nb_element -= 1;
    free(elem_new);
}*/


void delete_first_element(struct sudoku_list *list);

/**
 * @brief initialise le tableau de sudoku
 * @param list un pointer sur la liste ou l'on va stocker les resultats de la génération
 */
void init_tab_exercice(struct sudoku_list* list);

/**
 * @brief generate_id genere l'id d'un sudoku a partir du numero passe en parametre
 * @param num_sudoku le numero du sudoku.
 * @param dest le tableau de char ou l'id sera enregistre
 * @note l'id aura pour forme "sudokuXXXX" ou XXXX est un nombre fill 0
 */
void generate_id(int num_sudoku, char* dest);

/**
 * @brief delete_tab_exercice supprime la liste de sudoku
 * @param list un pointer sur la liste ou supprimer les element
 */
void delete_tab_exercice(struct sudoku_list* list);

/**
 * @brief copy_sudoku_element
 * @param from_data un pointer sur la structure qui sera copiée
 * @return un pointer sur la copie du sudoku exercice. allocation dynamique de memoire
 */
struct sudoku_exercice* copy_sudoku_exercice(struct sudoku_exercice* from_data);

/**
 * @brief print_sudoku_element affiche un sudoku element dans la console
 * @param elem un pointer sur l'element a afficher
 */
void print_sudoku_element(struct sudoku_element* elem);



//matrice possibilite element

/*
        *******************
        |2|.|4|.|5|1|.|8|.|
        |.|8|5|4|.|.|.|.|.|
        |.|.|.|.|8|.|6|.|.|
        |.|.|.|.|.|.|.|2|3|
        |.|1|.|.|.|.|.|.|6|
        |.|.|.|.|.|6|.|.|.|
        |.|7|.|2|.|4|.|.|.|
        |3|.|.|6|7|.|5|.|.|
        |4|.|.|.|.|.|.|7|.|
        *******************
*/

//matrice possility element
struct mpe {
    char element;
    struct mpe* next;
};


//matrice possility list
struct mpl {
    struct mpe* load;
    int nb_elem;
    struct mpe* current_element;
};

struct matrice_possibility {
    struct mpl* possibilities[9][9];
};




struct matrice_possibility* init_matrice();

int compute_matrice(struct matrice_possibility* matrice, struct sudoku_exercice *exerc);

int compute_possibility(struct matrice_possibility* matrice);

int compute_carre(struct matrice_possibility* matrice);

int compute_uplet(struct matrice_possibility* matrice, int line, int colonne);

int contain_char_mpe(char c, struct mpl* e);

int iterate_matrice(struct matrice_possibility* matrice, struct sudoku_exercice *exerc);

void delete_mpl(struct mpl* mpl_to_delete);

void delete_matrice(struct matrice_possibility* matrice);

enum add_element_status
{
    element_status_add = 0,
    element_status_not_possible,
    element_status_already_in_list
};

struct sudoku_exercice_solve {
    struct sudoku_exercice* exerc;
    struct matrice_possibility* matrice;
    int nb_iteration;
};

void delete_exercice_solve(struct sudoku_exercice_solve* del);

struct sudoku_exercice_solve* solve_exercice(struct sudoku_exercice* exerc);

int print_possibility_matrice(struct matrice_possibility* possibility);

int compute_complexity(struct matrice_possibility* possibility);

void fill_sudoku_exerc_with_matrice(struct sudoku_exercice* exerc, struct matrice_possibility* possi);


#endif // SUDOKU_FUNCTIONS_H
