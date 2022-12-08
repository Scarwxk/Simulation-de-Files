#include "cas1.h"
#include <unistd.h>


int casN1()
{
    File_attente * files_attentes[NOMBRE_FILES];

    int position_file_courte = 0;
    int taille_file_courte = TAILLE_MAX_FILE;

    int file_rentable[2];

    srand(time(NULL));

    for (int numero_file = 0; numero_file < NOMBRE_FILES; numero_file++)
    {
        int taille_file_actuelle = rand() % TAILLE_MAX_FILE;

        if (taille_file_actuelle < taille_file_courte)
        {
            taille_file_courte = taille_file_actuelle;
            position_file_courte = numero_file;
        }

        files_attentes[numero_file] = initialisation_file(numero_file);

        for (int y = 1; y < taille_file_actuelle; y++)
        {
            insertion_file(files_attentes[numero_file], y);
        }
        afficherFile(files_attentes[numero_file]);
    }

    file_plus_courte_exec(files_attentes, file_rentable);

    // File avec le temps d'execution le plus court
    int file_taille_exec_min = file_rentable[0];
    // Ainsi que son numéro
    int numero_file_temps_exec_min = file_rentable[1];

    int personne_temps_exec_min = 1000;

    Personne * personne_test = malloc(sizeof( * personne_test));

    int flag = 1;

    while(personne_test != files_attentes[position_file_courte]->premiere_personne && flag == 1)
    {
        int personne_temps_exec_min = 1000;
        for (int numero_file = 0; numero_file < NOMBRE_FILES; numero_file++)
        {
            if(files_attentes[numero_file]-> premiere_personne == NULL)
            {

            }
            else
            {
                if(files_attentes[numero_file]->premiere_personne->temps_traitement < personne_temps_exec_min)
                {
                    personne_temps_exec_min = files_attentes[numero_file]->premiere_personne->temps_traitement;
                }

            }
            printf("\nFile n* %d , temps exec personne minimale %d \n", numero_file, personne_temps_exec_min);

        }

        for (int numero_file = 0; numero_file < NOMBRE_FILES; numero_file++)
            {
                if(files_attentes[numero_file] -> premiere_personne == NULL)
                {
                    printf("\nLa file n* %d est vide\n", numero_file);
                }
                else
                {
                    files_attentes[numero_file]->premiere_personne->temps_traitement -= personne_temps_exec_min;
                    printf("\nFile n* %d , nouveau temps d'exec %d \n", numero_file, files_attentes[numero_file]->premiere_personne->temps_traitement);
                    if(files_attentes[numero_file]->premiere_personne->temps_traitement == 0)
                    {
                        suppression(files_attentes[numero_file]);
                    }
                    if (files_attentes[position_file_courte]->premiere_personne == NULL)
                    {
                        flag = 0;
                    }
                }




        }
    }


    printf("\nLa file choisie par la derniere personne est la file n*%d \n\n",
           position_file_courte);



   //TODO INSERER SIMULATION VISUELLE


    printf("La file la plus courte au niveau du temps d'execution etait la file n*%d avec un temps d'execution de %d secondes\n", numero_file_temps_exec_min, file_taille_exec_min);
    return 0;
}
