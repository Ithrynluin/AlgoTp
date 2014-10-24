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
<<<<<<< HEAD
noeud gauche (abin a);
noeud droite (abin a);
=======

abin gauche (abin a);
abin droite (abin a);

>>>>>>> ead7f41054a8ef02c1a9f21bf899f65438201e38
abin enracine(const char etiq, abin ag, abin ad);
bool estVide (abin a);
noeud racine (abin a);

#endif // ARBRE_H_INCLUDED
