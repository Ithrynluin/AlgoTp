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
            cout << "Maillon " << (*p).numero << endl;
            tmp=(*tmp).suivant;
            while (tmp != p) {
                cout << "Maillon " << (*tmp).numero << endl;
                tmp=(*tmp).suivant;
            }
        }
}

