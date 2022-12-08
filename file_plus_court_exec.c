#include "file_plus_court_exec.h"

void file_plus_courte_exec(File_attente * file_attente[NOMBRE_FILES], int data_return[2])
{
    int temps_exec_min = 32 * TAILLE_MAX_FILE;
    int file_temps_exec_min = 0;
    for (int numero_file_attente = 0; numero_file_attente < NOMBRE_FILES; numero_file_attente++)
    {
        Personne * personne_actuelle = file_attente[numero_file_attente] -> premiere_personne;
        int temps_exec = 0;

        // Boucle pour naviguer parmi toutes les personnes présentes dans la file
        while (personne_actuelle != NULL)
        {
            temps_exec += personne_actuelle -> temps_traitement;
            personne_actuelle = personne_actuelle -> personne_suivante;
        }

        if (temps_exec < temps_exec_min)
        {
            temps_exec_min = temps_exec;
            file_temps_exec_min = numero_file_attente;
        }
    }
    data_return[0] = temps_exec_min;
    data_return[1] = file_temps_exec_min;
}
