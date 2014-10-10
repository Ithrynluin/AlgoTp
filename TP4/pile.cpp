#include <iostream>
#include "pile.h"
#include "fileAttente.h"
using namespace std;

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


