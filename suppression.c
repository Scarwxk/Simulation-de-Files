#include "suppression.h"

int suppression(File_attente * file_attente)
{
    if (file_attente == NULL)
    {
        return 0;
    }
    if (file_attente -> premiere_personne != NULL)
    {

        Personne * personne_supprimee = file_attente -> premiere_personne;
        file_attente -> premiere_personne =
            file_attente -> premiere_personne -> personne_suivante;
        free(personne_supprimee);
    }
    return 1;
}
