#include <iostream>

#include "listeCirculaire.h"

using namespace std;


void initListeCirculaire(maillon **m){
    *m = NULL;
}

/*
Procédure permettant l'affichage d'une liste circulaire
Paramètre entrée: liste initialisée
Paramètre sortie: affichage de la liste
Pré-condition: la liste ne doit pas etre vide
*/
void afficherListe(maillon *p) {
        maillon *tmp;

        if (p != null) {
            tmp=p;
            while ((*tmp).suivant != p) {
                cout << "Maillon " << (*tmp).numero << endl;
                tmp=(*tmp).suivant;
            }
        }
}
/*
Fonction permettant d'accéder au maillon précédent celui qui est point" en entrée
Paramètre entrée : liste initialisée
Paramètre sortie : retourne le maillon précédent
Pré-condition : la liste doit etre initialisée
*/
maillon * precedent(maillon *p) {
    maillon *tmp;

    tmp=p;
    if (p != null) {
        while ((*tmp).suivant != p) {
            tmp=(*tmp).suivant;
        }
    }
    return tmp;
}
/*
Procédure pour effectuer une rotation
*/
void rotation(maillon *p) {
    p = (*p).suivant;
}

