#ifndef TYPEDEFS_H
#define TYPEDEFS_H

#include <stdio.h>

#include <stdlib.h>

#include <time.h>

#define TEMPS_EXEC_MAX rand() % 30 + 1
#define TAILLE_MAX_FILE 10
#define NOMBRE_FILES 20


typedef struct Personne {
    int numero_personne;
    int temps_traitement;
    struct Personne * personne_suivante;
}Personne;

typedef struct File_attente {
    Personne * premiere_personne;
    int numero_file_attente;
}File_attente;

#endif // TYPEDEFS_H



