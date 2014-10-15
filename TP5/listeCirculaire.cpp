#include <iostream>

#include "listeCirculaire.h"

using namespace std;


void initListeCirculaire(maillon **m){
    *m = NULL;
}

void afficherListe(maillon *p) {
        maillon *tmp;

        tmp=p;
        cout << "Maillon " << (*p).numero << endl;
        tmp=(*tmp).suivant;
        while (tmp != p) {
            cout << "Maillon " << (*tmp).numero << endl;
            tmp=(*tmp).suivant;
        }
}

