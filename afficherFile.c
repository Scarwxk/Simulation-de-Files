#include "afficherFile.h"

void afficherFile(File_attente * file_attente)
{
    if (file_attente == NULL)
    {
        exit(EXIT_FAILURE);
    }

    Personne * personne_actuelle = file_attente -> premiere_personne;
    int temps_exec = 0;

    // Boucle pour naviguer parmi toutes les personnes présentes dans la file
    while (personne_actuelle != NULL)
    {
        printf("\nPersonne n* %d temps de traitement : %d",
               personne_actuelle -> numero_personne,
               personne_actuelle -> temps_traitement);

        temps_exec += personne_actuelle -> temps_traitement;
        personne_actuelle = personne_actuelle -> personne_suivante;
    }

    printf("\n\nTemps d'exec total de la file n*%d : %d \n\n",
           file_attente -> numero_file_attente, temps_exec);
}

