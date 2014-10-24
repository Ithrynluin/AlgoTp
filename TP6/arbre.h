#ifndef ARBRE_H_INCLUDED
#define ARBRE_H_INCLUDED

#include <iostream>

typedef struct n {
    char etiquette;
    struct n* ag;
    struct n* ad;
} noeud;

typedef noeud * abin;

void arbnouv (abin a);
void arbdetruit (abin a);
noeud gauche (abin a);
noeud droite (abin a);
abin gauche (abin a);
abin droite (abin a);
abin enracine(const char etiq, abin ag, abin ad);
bool estVide (abin a);
noeud racine (abin a);

#endif // ARBRE_H_INCLUDED
