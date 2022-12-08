#include "initialisation.h"

File_attente * initialisation_file(int numero_file)
{
    // Allocation de mémoire
    File_attente * file_attente = malloc(sizeof( * file_attente));
    Personne * personne = malloc(sizeof( * personne));

    if (file_attente == NULL || personne == NULL)
    {
        exit(EXIT_FAILURE);
    }

    // Initialisation de la personne n*1
    personne -> numero_personne = 0;
    personne -> temps_traitement = TEMPS_EXEC_MAX;
    personne -> personne_suivante = NULL;

    // Attribution de la personne n*1 à la file
    file_attente -> premiere_personne = personne;
    file_attente -> numero_file_attente = numero_file;

    return file_attente;
}
