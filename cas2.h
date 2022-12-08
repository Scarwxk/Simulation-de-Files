#ifndef CAS2_H
#define CAS2_H

#include "typedefs.h"
#include "initialisation.h"
#include "insertion_file.h"
#include "suppression.h"
#include "afficherFile.h"
#include "file_plus_court_exec.h"

/*
Cas où 5 guichets se remplissent avec temps d'attente respectifs au personne
Comparaison de tous les temps d'attentes pour pouvoir attribuer la prochaine personne au guichet qui sera libre le plus rapidement.
Une fois l'attribution effectuée, on soustrait le temps d'attente à tout les autres guichets.
On répète ensuite jusqu'à ce que toutes les personnes soient passées.
*/
int casN2();

#endif // CAS2_H

