#ifndef ARBRE_H_INCLUDED
#define ARBRE_H_INCLUDED

#include <iostream>
#include <cstring>
#include "liste.h"

using namespace std;

typedef struct n {
    char etiquette;
    struct n* ag;
    struct n* ad;
} noeud;

typedef noeud * abin;

void arbnouv (abin a);
void arbdetruit (abin a);

abin gauche (abin a);
abin droite (abin a);
abin enracine(const char etiq, abin ag, abin ad);
bool estVide (abin a);
int hauteur (abin a);
abin racine (abin a);
char charEtiquette (noeud * n);
Liste parcoursSuffixe(abin a);
Liste parcoursInfixe(abin a);
Liste parcoursPrefixe(abin a);
Liste parcoursLargeur(abin * file);

#endif // ARBRE_H_INCLUDED
