#include "cas2.h"

int casN2()
{
    File_attente * file_attente;

    file_attente = initialisation_file(0);

    srand(time(NULL));

    int taille_file = 7 + rand() % TAILLE_MAX_FILE;
    printf("%d\n", taille_file);

    for (int y = 1; y < taille_file; y++)
    {
        insertion_file(file_attente, y);
    }

    int guichet1, guichet2, guichet3, guichet4, guichet5, temps_exec_total, temps_exec_guichet1, temps_exec_guichet2, temps_exec_guichet3,
    temps_exec_guichet4, temps_exec_guichet5, nb_personnes_passees_guichet1, nb_personnes_passees_guichet2, nb_personnes_passees_guichet3,
    nb_personnes_passees_guichet4, nb_personnes_passees_guichet5;

    temps_exec_total = 0;
    temps_exec_guichet1 = 0;
    temps_exec_guichet2 = 0;
    temps_exec_guichet3 = 0;
    temps_exec_guichet4 = 0;
    temps_exec_guichet5 = 0;
    nb_personnes_passees_guichet1 = 0;
    nb_personnes_passees_guichet2 = 0;
    nb_personnes_passees_guichet3 = 0;
    nb_personnes_passees_guichet4 = 0;
    nb_personnes_passees_guichet5 = 0;

    guichet1 = TEMPS_EXEC_MAX;

    guichet2 = TEMPS_EXEC_MAX;

    guichet3 = TEMPS_EXEC_MAX;

    guichet4 = TEMPS_EXEC_MAX;

    guichet5 = TEMPS_EXEC_MAX;

    printf("Guichet 1 : %d\nGuichet 2 : %d\nGuichet 3 : %d\nGuichet 4 : %d\nGuichet 5 : %d\n",
           guichet1, guichet2, guichet3, guichet4, guichet5);

    while (file_attente -> premiere_personne -> personne_suivante != NULL)
    {

        if (guichet1 <= guichet2 && guichet1 <= guichet3 && guichet1 <= guichet4 && guichet1 <= guichet5 && file_attente -> premiere_personne -> personne_suivante != NULL)
        {
            temps_exec_total += guichet1;
            printf("\nGuichet n*1 libre\nTemps du guichet : %d\nTemps d'execution total : %d\n", guichet1, temps_exec_total);
            guichet2 -= guichet1;
            guichet3 -= guichet1;
            guichet4 -= guichet1;
            guichet5 -= guichet1;
            suppression(file_attente);
            guichet1 = TEMPS_EXEC_MAX;
            guichet1 = file_attente->premiere_personne->temps_traitement;
            printf("\nGuichet 1 : %d\nGuichet 2 : %d\nGuichet 3 : %d\nGuichet 4 : %d\nGuichet 5 : %d\n",
                   guichet1, guichet2, guichet3, guichet4, guichet5);
        }

        if (guichet2 < guichet1 && guichet2 <= guichet3 && guichet2 <= guichet4 && guichet2 <= guichet5 && file_attente -> premiere_personne -> personne_suivante != NULL)
        {
            temps_exec_total += guichet2;
            printf("\nGuichet n*2 libre\nTemps du guichet : %d\nTemps d'execution total : %d\n", guichet2, temps_exec_total);
            guichet1 -= guichet2;
            guichet3 -= guichet2;
            guichet4 -= guichet2;
            guichet5 -= guichet2;
            suppression(file_attente);
            guichet2 = TEMPS_EXEC_MAX;
            guichet2 = file_attente->premiere_personne->temps_traitement;
            printf("\nGuichet 1 : %d\nGuichet 2 : %d\nGuichet 3 : %d\nGuichet 4 : %d\nGuichet 5 : %d\n",
                   guichet1, guichet2, guichet3, guichet4, guichet5);
        }

        if (guichet3 < guichet1 && guichet3 <= guichet2 && guichet3 <= guichet4 && guichet3 <= guichet5 && file_attente -> premiere_personne -> personne_suivante != NULL)
        {
            temps_exec_total += guichet3;
            printf("\nGuichet n*3 libre\nTemps du guichet : %d\nTemps d'execution total : %d\n", guichet3, temps_exec_total);
            guichet1 -= guichet3;
            guichet2 -= guichet3;
            guichet4 -= guichet3;
            guichet5 -= guichet3;
            suppression(file_attente);
            guichet3 = TEMPS_EXEC_MAX;
            guichet3 = file_attente->premiere_personne->temps_traitement;
            printf("\nGuichet 1 : %d\nGuichet 2 : %d\nGuichet 3 : %d\nGuichet 4 : %d\nGuichet 5 : %d\n",
                   guichet1, guichet2, guichet3, guichet4, guichet5);
        }

        if (guichet4 < guichet1 && guichet4 <= guichet2 && guichet4 <= guichet3 && guichet4 <= guichet5 && file_attente -> premiere_personne -> personne_suivante != NULL)
        {
            temps_exec_total += guichet4;
            printf("\nGuichet n*4 libre\nTemps du guichet : %d\nTemps d'execution total : %d\n", guichet4, temps_exec_total);
            guichet1 -= guichet4;
            guichet2 -= guichet4;
            guichet3 -= guichet4;
            guichet5 -= guichet4;
            suppression(file_attente);
            guichet4 = TEMPS_EXEC_MAX;
            guichet4 = file_attente->premiere_personne->temps_traitement;
            printf("\nGuichet 1 : %d\nGuichet 2 : %d\nGuichet 3 : %d\nGuichet 4 : %d\nGuichet 5 : %d\n",
                   guichet1, guichet2, guichet3, guichet4, guichet5);
        }

        if (guichet5 < guichet1 && guichet5 <= guichet2 && guichet5 <= guichet3 && guichet5 <= guichet4 && file_attente -> premiere_personne -> personne_suivante != NULL)
        {
            temps_exec_total += guichet5;
            printf("\nGuichet n*5 libre\nTemps du guichet : %d\nTemps d'execution total : %d\n", guichet5, temps_exec_total);
            guichet1 -= guichet5;
            guichet2 -= guichet5;
            guichet3 -= guichet5;
            guichet4 -= guichet5;
            suppression(file_attente);
            guichet5 = file_attente->premiere_personne->temps_traitement;
            guichet5 = TEMPS_EXEC_MAX;
            printf("\nGuichet 1 : %d\nGuichet 2 : %d\nGuichet 3 : %d\nGuichet 4 : %d\nGuichet 5 : %d\n",
                   guichet1, guichet2, guichet3, guichet4, guichet5);
        }
    }
    return 0;
}
