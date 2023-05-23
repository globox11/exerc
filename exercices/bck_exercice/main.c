#include "main_functions.h"
#include "sudoku_functions.h"

int main(int argc, char* argv[])
{

    struct sudoku_exercice_solve* tab_solve[200];

    struct sudoku_list* main_list = malloc(sizeof(struct sudoku_list));
    main_list->first = NULL;
    main_list->load = NULL;
    init_list_sudoku(main_list);

    init_tab_exercice(main_list);

    int iter = 0;
    struct sudoku_element* elem = main_list->load;
    while(elem != NULL)
    {
        print_sudoku_element(elem);
        tab_solve[iter] = solve_exercice(elem->sudoku);
        printf("\n\n");
        elem = elem->next;
        iter++;
    }
    delete_tab_exercice(main_list);
    free(main_list);
    return 0;
}


void test_insert_first_delete_last()
{
    struct sudoku_list* main_list = malloc(sizeof(struct sudoku_list));
    main_list->first = NULL;
    main_list->load = NULL;
    init_list_sudoku(main_list);
    //creation
    for(int iter = 0 ; iter < 10 ; iter++)
    {
        create_front(&(*main_list));
    }
    //affichage du nombre d'element dans la liste
    printf("nombre d'element dans la liste avant suppression %d\n",(*main_list).nb_element);
    //suppression
    for(int iter = 0 ; iter < 10 ; iter++)
    {
        delete_last_element(main_list);
    }
    //affichage du nom d'element dans la liste
    printf("nombre d'element dans la liste apres suppression %d\n",(*main_list).nb_element);
    free(main_list);
}

void test_insert_last_delete_first()
{
    struct sudoku_list* main_list = malloc(sizeof(struct sudoku_list));
    main_list->first = NULL;
    main_list->load = NULL;
    init_list_sudoku(main_list);
    //creation
    for(int iter = 0 ; iter < 10 ; iter++)
    {
        create_end(&(*main_list));
    }
    //affichage du nombre d'element dans la liste
    printf("nombre d'element dans la liste avant suppression %d\n",(*main_list).nb_element);
    //suppression
    for(int iter = 0 ; iter < 10 ; iter++)
    {
        delete_first_element(main_list);
    }
    //affichage du nom d'element dans la liste
    printf("nombre d'element dans la liste apres suppression %d\n",(*main_list).nb_element);
    free(main_list);
}
