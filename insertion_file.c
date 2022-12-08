#include "insertion_file.h"

void insertion_file(File_attente * file_attente, int numero_personne)
{
    /* Création du nouvel élément */
    Personne * nouvelle_personne = malloc(sizeof( * nouvelle_personne));

    if (file_attente == NULL || nouvelle_personne == NULL)
    {
        exit(EXIT_FAILURE);
    }

    nouvelle_personne -> numero_personne = numero_personne;
    nouvelle_personne -> temps_traitement = TEMPS_EXEC_MAX;

    /* Insertion de la personne au début de la file_attente */
    nouvelle_personne -> personne_suivante = file_attente -> premiere_personne;
    file_attente -> premiere_personne = nouvelle_personne;
}
