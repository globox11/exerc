#include "main_functions.h"

void afficher_bonjour()
{
    printf("bonjour\n");
}

void afficher_bonjour_num_etudiant(int etunum)
{
    printf("bonjour %d\n",etunum);
}

void init_operation(struct operation* oper)
{
    memset(oper,0,sizeof(struct operation));
}

void renseigner_operation(struct operation* current_oper, enum type_operation type_oper, double operande_01, double operande_02)
{
    init_operation(current_oper);
    current_oper->type_oper = type_oper;
    current_oper->operande_01 = operande_01;
    current_oper->operande_02 = operande_02;
}

void effectuer_operation(struct operation* oper)
{
    switch(oper->type_oper)
    {

    case operation_inconnue :
    {
        printf("l'operation est inconnue, abandon\n");
        return;
    }

    case operation_addition :
    {
        oper->resultat = oper->operande_01 + oper->operande_02;
        break;
    }

    case operation_soustraction :
    {
        oper->resultat = oper->operande_01 - oper->operande_02;
        break;
    }

    case operation_multiplication :
    {
        oper->resultat = oper->operande_01 * oper->operande_02;
        break;
    }

    case operation_division :
    {
        if(oper->operande_02 != 0.0)
        {
            printf("l'operation est une division, mais operande 02 est null, abandon\n");
        }
        oper->resultat = oper->operande_01 / oper->operande_02;
        break;
    }

    default :
    {
        printf("erreur quine devrait pas arriver puisque la structure est initialisee\n");
        return;
    }

    }

    printf("l'operation a ete calculee\n");
}

void afficher_operation(struct operation* data_a_afficher)
{
    printf("affichage d'une operation :\n\ttype operation : %d\n\toperande 01 : %f\n\toperande 02 : %f\n\tresultat : %f\n",
           ((int) data_a_afficher->type_oper),
           data_a_afficher->operande_01,
           data_a_afficher->operande_02,
           data_a_afficher->resultat);
}

struct operation* tester_operation()
{
    struct operation* ptr_oper = malloc((sizeof(struct operation))*5);

    for(int iter = 0 ; iter < 5 ; iter++)
    {
        struct operation* op_ptr = &(ptr_oper[iter]);
        init_operation(op_ptr);
        renseigner_operation(op_ptr, ((enum type_operation) iter), 3.0, 11.0);
        /*
        init_operation(&(ptr_oper[iter]));
        renseigner_operation(&(ptr_oper[iter]), ((enum type_operation) iter), 3.0, 11.0);
        */
    }

    for(int iter = 0 ; iter < 5 ; iter++)
    {
        effectuer_operation(&(ptr_oper[iter]));
        afficher_operation(&(ptr_oper[iter]));
    }
    return ptr_oper;
}
