#include <iostream>
#include "pile.h"
#include "fileAttente.h"
using namespace std;

/*
 Fonction qui initialise une pile
 Para
Pile initPile(Pile pile){
    pile.tete = NULL;
=======
void desinitPile(Pile pile){

  while(pile.tete != NULL){
      depiler(Pile);
  }

}

void depiler(Pile pile){
    element *tmp;

    if(pile.tete != NULL) {
        if ((pile.tete).suivant == NULL) {
            tmp pile.tete;
            desinitFileAttente(tmp.file);
            delete tmp.file;
            delete tmp;
            initPile(pile);
        } else {
            tmp=pile.tete;
            pile.tete=tmp.suivant;
            delete tmp.file;
            delete tmp;
        }
    }
}


element sommet(Pile pile){
    return pile.tete;
}

